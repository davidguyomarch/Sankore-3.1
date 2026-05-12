> ⚠️ **Early Access**: Behavior documentation is in early access. Please review critically.

# Business Logic

## Application Initialization Logic

### Startup Sequence (UBApplication::exec)
1. Set pixmap cache limit (100MB)
2. Configure WebKit settings (Java, plugins, local storage, offline cache)
3. Create frameless main window
4. Connect main actions (Board, Web, Document, Quit)
5. Initialize `UBBoardController` → `init()` → `setupLayout()`
6. Initialize `UBWebController` and `UBDocumentController`
7. Set default stylus tool to Pen
8. Create `UBApplicationController` with views and main window
9. Connect mode change signals
10. Initialize preferences controller
11. Apply toolbar settings (position, text display)
12. Configure multi-screen layout
13. Import file if provided via command line
14. Install Apple Event handler (macOS - dock click)
15. Show Board or Desktop mode per settings
16. Start Qt event loop

### Single Instance Enforcement
- Uses `QtSingleApplication` to prevent multiple instances
- `handleOpenMessage()` - Receives file open requests from second instance
- On macOS: FileOpen event handled via `eventFilter()`

### Translation Setup
- Priority: command-line `-lang` → saved preference → system language → "en_US" fallback
- Checks availability via `UBPlatformUtils::availableTranslations()`
- Falls back to 2-letter code if full locale unavailable

## Board Interaction Logic

### Drawing Pipeline (UBGraphicsScene)
1. **inputDevicePress(scenePos, pressure)**
   - Initializes stroke (`initStroke()`)
   - Records start position
   - Creates initial polygon item based on tool type
2. **inputDeviceMove(scenePos, pressure)**
   - Calculates line from previous to current position
   - Width scaled by pressure (for tablets)
   - Tool-dependent behavior:
     - Pen/Marker: `drawLineTo()` → creates `UBGraphicsPolygonItem`
     - Eraser: `eraseLineTo()` → removes intersecting items
     - Compass: `drawArcTo()` → creates arc polygon
3. **inputDeviceRelease()**
   - Finalizes current stroke
   - Groups polygon items into `UBGraphicsStroke`
   - Pushes undo command

### Tool State Management (UBDrawingController)
- Singleton holds current tool state
- Tool change triggers:
  - `stylusToolChanged` signal → UI updates
  - Cursor change on board view
  - Drawing mode activation/deactivation
- Tool types: Pen, Marker, Eraser, Selector, Play, Hand, ZoomIn, ZoomOut, Pointer, Line, Text, RichText, Capture

### Shape Creation (UBShapeFactory)
Shape types: Ellipse, Circle, Rectangle, Square, Line, Pen, RegularPolygon, Polygon
- Shape factory receives mouse events from board view
- Creates appropriate graphics item based on selected shape type
- Manages edit mode (handles visible/active)
- Applies current stroke/fill colors and properties

### Page Navigation
- `previousScene()` / `nextScene()` - Sequential navigation
- `firstScene()` / `lastScene()` - Jump to extremes
- `setActiveDocumentScene(proxy, index)` - Direct navigation
- On page change: persist current scene → load target → update views

## Document Management Logic

### Document Creation (UBPersistenceManager)
1. Generate unique UUID and path
2. Create directory structure (images/, objects/, videos/, etc.)
3. Optionally add empty first page
4. Persist metadata (Dublin Core via RDF)
5. Emit `documentCreated` signal
6. Register in document tree model

### Scene Persistence
- **Save**: `persistDocumentScene(proxy, scene, index)`
  - Delegates to `UBSvgSubsetAdaptor::persistScene()`
  - Serializes all items to SVG subset format
  - Updates thumbnail via `UBThumbnailAdaptor`
- **Load**: `loadDocumentScene(proxy, index)`
  - Checks cache first (`UBSceneCache`)
  - Loads from SVG file via `UBSvgSubsetAdaptor`
  - Returns hydrated `UBGraphicsScene`

### Scene Cache (UBSceneCache)
- LRU cache for loaded scenes
- Avoids reloading from disk on page navigation
- Automatically persists dirty scenes when evicting

### Document Import Pipeline
1. `UBDocumentManager` checks registered adaptors
2. Finds matching `UBImportAdaptor` by file extension
3. Adaptor performs format-specific import:
   - PDF: Renders pages to images, creates scenes
   - Image: Creates single-page document with image
   - .ubz: Unzips and registers document
   - CFF/IWB: Parses XML, recreates items

## Content Addition Logic

### URL Download Workflow (UBBoardController::downloadURL)
1. Determine content type from URL
2. Create `UBHttpGet` request
3. On completion: `downloadFinished()` callback
4. Based on content type:
   - Image → `addPixmap()`
   - SVG → `addSvg()`
   - PDF → `addPDFItem()`
   - Widget (.wgt) → `addW3cWidget()`
   - Video/Audio → `addVideo()`/`addAudio()`
   - Other → embed in web widget

### Widget Integration
- W3C widgets loaded from `.wgt` ZIP packages
- Extracted to temp directory
- Rendered via QGraphicsProxyWidget + QWebView
- JavaScript API injected (UBWidgetUniboardAPI)
- Widget state persisted via document datastore

## Background Management

### Background Types
- Dark/Light (color mode)
- Crossed (grid overlay)
- Image background with disposition:
  - Center: Centered, no scaling
  - Adjust: Fit to page preserving aspect
  - Mosaic: Tiled pattern
  - Fill: Scale to fill
  - Extend: Stretch to fill

## Clipboard Operations

### Cut/Copy/Paste Flow
- **Copy**: Selected items serialized to UBMimeData (custom MIME type)
- **Cut**: Copy + remove items (with undo command)
- **Paste**: Deserialize from clipboard → create new items at position
- Supports: internal items, external images, text, URLs

## Cross-References
- [Workflows](workflows.md)
- [Decision Logic](decision-logic.md)
- [Error Handling](error-handling.md)
- [Components](../architecture/components.md)
