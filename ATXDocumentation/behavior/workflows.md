> ⚠️ **Early Access**: Behavior documentation is in early access. Please review critically.

# Workflows

## Application Lifecycle Workflow

### Startup
1. `main()` → Create `UBApplication` instance
2. Parse command-line arguments
3. Setup translators and locale
4. Initialize platform utilities
5. Load settings
6. Create main window and controllers
7. Import file if specified
8. Enter event loop in Board or Desktop mode

### Shutdown
1. `closing()` slot triggered
2. Persist current scene
3. Close all open widgets
4. Destroy singletons (PersistenceManager, DrawingController, Settings, etc.)
5. Clean up temp files (`deleteAllTempDirCreatedDuringSession`)
6. Delete main window

## Document Management Workflows

### Create New Document
1. User action triggers `UBBoardController::addScene()` or menu
2. `UBPersistenceManager::createDocument(groupName, name)`
3. Generate UUID path
4. Create directory structure
5. Create initial empty scene
6. Persist metadata
7. Emit `documentCreated` signal
8. Navigate to new document

### Open Existing Document
1. User selects document in Document Mode
2. `UBBoardController::setActiveDocumentScene(proxy, index)`
3. Persist current scene (if dirty)
4. Load target scene from cache or SVG file
5. Update board view
6. Update display view
7. Update thumbnails and navigator
8. Emit `activeSceneChanged`

### Save Document (Auto/Manual)
1. `UBAutoSaver` timer fires OR page change triggers save
2. `UBBoardController::persistCurrentScene()`
3. → `UBPersistenceManager::persistDocumentScene(proxy, scene, index)`
4. → `UBSvgSubsetAdaptor::persistScene()` - serialize items to SVG
5. → `UBThumbnailAdaptor::persistScene()` - generate thumbnail
6. Update metadata if changed

### Import Document
1. User triggers import (file dialog or drag-drop)
2. `UBApplicationController::importFile(path)`
3. `UBDocumentManager` finds matching adaptor
4. Adaptor creates document:
   - PDF: Render pages → images → scenes
   - Image: Single page with image as background
   - .ubz: Unzip, register proxy
   - CFF: Parse IWB XML → recreate scene items
5. Switch to imported document

### Export Document
1. User selects export format
2. `UBExportAdaptor::persist()` called
3. Format-specific export:
   - PDF: Render scenes to PDF pages
   - Full PDF: Include annotations
   - .ubz: ZIP document directory
   - CFF: Convert to IWB format
   - Web: Generate HTML
4. Save to user-selected path

## Board Interaction Workflows

### Freehand Drawing
1. Stylus/mouse press on board
2. `UBBoardView` routes to `UBGraphicsScene::inputDevicePress()`
3. Init new stroke
4. On move: `inputDeviceMove()` → `drawLineTo()` → create polygon items
5. Width modulated by pressure (tablet) or fixed (mouse)
6. Color adapts to background (dark/light)
7. On release: finalize stroke, group polygons, push undo command

### Add Media to Board
1. User drags media file/URL to board OR uses menu
2. `UBBoardController::downloadURL()` or direct `addVideo()`/`addAudio()`
3. Download file if remote URL
4. Create appropriate graphics item (Video/Audio/Image/Widget)
5. Position at drop point or center
6. Add to scene with undo command
7. Persist media file to document directory

### Group/Ungroup Items
1. User selects multiple items
2. Triggers `groupButtonClicked()`
3. If items not grouped: `UBGraphicsScene::createGroup(items)` → `UBGraphicsGroupContainerItem`
4. If items grouped: ungroup, restore individual items
5. Push `UBGraphicsItemGroupUndoCommand`

### Page Size Change
1. User selects page size (Wide 16:9, Wide 16:10, Regular 4:3)
2. `UBBoardController::setWidePageSize()` / `setRegularPageSize()`
3. `UBGraphicsScene::setNominalSize()`
4. Push `UBPageSizeUndoCommand`
5. Adjust views and backgrounds

## Web Integration Workflows

### Embed Web Content
1. User in web mode finds content
2. Trap Flash/content via `UBTrapFlashController`
3. Or use OEmbed URL resolution
4. Create `UBGraphicsWidgetItem` or proxy widget
5. Switch to board mode
6. Add widget to current scene

### Widget Execution
1. Widget loaded (`.wgt` package extracted)
2. QWebView created within QGraphicsProxyWidget
3. JavaScript API injected (`window.sankore = UBWidgetUniboardAPI`)
4. Widget can: draw on board, access datastore, send messages
5. Widget state persisted per document via `UBDocumentDatastoreAPI`

## Podcast/Recording Workflow

### Screen Recording
1. User activates podcast via `togglePodcast()`
2. `UBPodcastController` initializes encoder
3. Platform-specific backend:
   - macOS: QuickTime screen capture
   - Windows: Windows Media encoder
4. Captures board view frames
5. On stop: finalize video file
6. Optional: publish to YouTube or intranet

## Mode Switching Workflow

### Board → Web → Document
1. User clicks mode button
2. `UBApplication::showBoard()` / `showInternet()` / `showDocument()`
3. `UBApplicationController::showBoard()` etc.
4. Hide current mode views
5. Show target mode views
6. Emit `mainModeChanged` signal
7. Update palette visibility
8. Freeze/unfreeze widgets as needed

## Cross-References
- [Business Logic](business-logic.md)
- [Decision Logic](decision-logic.md)
- [Components](../architecture/components.md)
