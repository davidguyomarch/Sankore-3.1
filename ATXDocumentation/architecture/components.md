# Components

## Core Components

### UBApplication (`src/core/UBApplication.h`)
- **Role**: Application entry point, extends QtSingleApplication
- **Responsibilities**: 
  - Application lifecycle management
  - Event filtering (file open on macOS)
  - Static access to all controllers (boardController, webController, documentController)
  - Global undo stack management
  - Translation/localization setup
  - MIME type definitions for Uniboard documents
- **Key Static Members**: `applicationController`, `boardController`, `webController`, `documentController`, `mainWindow`

### UBApplicationController (`src/core/UBApplicationController.h`)
- **Role**: Mode controller orchestrating Board/Web/Document views
- **Responsibilities**:
  - Mode switching (Board, Internet, Document, Tutorial)
  - Display management (multi-screen support)
  - Desktop annotation control
  - Screen mirroring
  - Software update checking (via QHttp/QFtp - deprecated APIs)
  - Clipboard operations (cut/copy/paste)
- **Modes**: Board=0, Internet, Document, Tutorial, ParaschoolEditor, WebDocument

### UBPersistenceManager (`src/core/UBPersistenceManager.h`)
- **Role**: Singleton managing document storage and retrieval
- **Responsibilities**:
  - Document CRUD operations (create, duplicate, delete)
  - Scene persistence (save/load via SVG adaptor)
  - Document tree structure (folder model)
  - Scene caching (UBSceneCache)
  - Media file management (images, videos, audio, widgets)
  - Teacher guide content storage
- **Key Directories**: imageDirectory, objectDirectory, videoDirectory, audioDirectory, widgetDirectory

### UBSettings (`src/core/UBSettings.h`)
- **Role**: Application-wide settings management
- **Responsibilities**: Persisting user preferences, tool configurations, color palettes

### UBDocumentManager (`src/core/UBDocumentManager.h`)
- **Role**: Document import coordination
- **Responsibilities**: Registering import/export adaptors, orchestrating file imports

## Board Components

### UBBoardController (`src/board/UBBoardController.h`)
- **Role**: Central controller for the interactive whiteboard
- **Responsibilities**:
  - Scene management (add/delete/duplicate/navigate pages)
  - Content addition (media, widgets, URLs, text)
  - View management (zoom, scroll, pan)
  - Color management (pen/marker colors on dark/light backgrounds)
  - Clipboard operations
  - Shape factory integration
  - Background management (dark/light, crossed, image backgrounds)
  - Document navigator coordination
- **Extends**: UBDocumentContainer

### UBDrawingController (`src/board/UBDrawingController.h`)
- **Role**: Singleton managing current drawing tool state
- **Responsibilities**:
  - Tool selection (pen, eraser, marker, selector, hand, zoom, pointer, line, text, capture)
  - Color/width index management
  - Desktop mode tracking
  - Ruler activation state

### UBBoardView (`src/board/UBBoardView.h`)
- **Role**: QGraphicsView for rendering the board scene
- **Responsibilities**: Mouse/touch event handling, tool cursor management

### UBBoardPaletteManager (`src/board/UBBoardPaletteManager.h`)
- **Role**: Manages all floating palette widgets in board mode

### UBFeaturesController (`src/board/UBFeaturesController.h`)
- **Role**: Library/features browser controller

## Domain Components

### UBGraphicsScene (`src/domain/UBGraphicsScene.h`)
- **Role**: The canvas - extends UBCoreGraphicsScene and UBItem
- **Responsibilities**:
  - Input device handling (press/move/release for drawing)
  - Item management (add/remove with Z-layer control)
  - Drawing operations (line-to, arc-to, erase)
  - Content addition (widgets, media, SVG, text, PDF)
  - Background rendering (dark/light, grid)
  - Group creation
  - Magnifier control
  - Rendering contexts (Screen, NonScreen, PdfExport, Podcast)
  - Undo/redo stack integration
- **Inner Classes**: SceneViewState, UBZLayerController

### UBZLayerController (`src/domain/UBGraphicsScene.h`)
- **Role**: Z-order management for graphics items
- **Responsibilities**: Layer type assignment, Z-level generation, item reordering

### Graphics Items Hierarchy
All items inherit from QGraphicsItem and implement UBItem interface:
- **UBAbstractGraphicsItem** → Base for custom items
- **UBGraphicsPolygonItem** → Freehand strokes/lines
- **UBGraphicsPixmapItem** → Images
- **UBGraphicsSvgItem** → SVG content
- **UBGraphicsTextItem** → Rich text
- **UBGraphicsPDFItem** → PDF pages
- **UBGraphicsMediaItem** → Base for media (→ UBGraphicsVideoItem, UBGraphicsAudioItem)
- **UBGraphicsWidgetItem** → Embedded web widgets (W3C, Apple)
- **UBGraphicsGroupContainerItem** → Item groups
- **Shape Items**: UBGraphicsRectItem, UBGraphicsEllipseItem, UBGraphicsLineItem, UBGraphicsFreehandItem
- **Editable Shapes**: UBEditableGraphicsPolygonItem, UBEditableGraphicsRegularShapeItem, UB1HEditableGraphicsCircleItem, UB1HEditableGraphicsSquareItem

### Handle System
- **UBAbstractHandle** → Base handle class
- **UBDiagonalHandle**, **UBHorizontalHandle**, **UBVerticalHandle**, **UBFreeHandle**
- **UBAbstractHandlesBuilder** → Handle creation strategies
- **UB2HandlesEditable**, **UB3HandlesEditable** → Editable item mixins

### Undo Commands
- **UBAbstractUndoCommand** → Base
- **UBGraphicsItemUndoCommand** → Item add/remove
- **UBGraphicsItemTransformUndoCommand** → Transform operations
- **UBGraphicsItemGroupUndoCommand** → Group/ungroup
- **UBGraphicsTextItemUndoCommand** → Text edits
- **UBDocumentUndoCommand** → Document-level operations
- **UBPageSizeUndoCommand** → Page resize

### UBShapeFactory (`src/domain/UBShapeFactory.h`)
- **Role**: Factory for creating geometric shapes on the board

## Adaptor Components

### Import Adaptors
- **UBImportAdaptor** → Base class for import operations
- **UBImportDocument** → .ubz document import
- **UBImportDocumentSetAdaptor** → Document set import
- **UBImportPDF** → PDF file import
- **UBImportImage** → Image file import
- **UBImportCFF** → Common File Format (IWB) import

### Export Adaptors
- **UBExportAdaptor** → Base class for export operations
- **UBExportDocument** → .ubz document export
- **UBExportDocumentSetAdaptor** → Document set export
- **UBExportPDF** → PDF export
- **UBExportFullPDF** → Full PDF with annotations
- **UBExportWeb** → Web format export
- **UBExportCFF** → CFF/IWB export

### Serialization Adaptors
- **UBSvgSubsetAdaptor** → SVG serialization (primary document format)
- **UBCFFSubsetAdaptor** → CFF format parsing
- **UBMetadataDcSubsetAdaptor** → Dublin Core metadata
- **UBThumbnailAdaptor** → Thumbnail generation

## GUI Components

### Main Window
- **UBMainWindow** (`src/gui/UBMainWindow.h`) → Top-level application window

### Palette System (extensive)
- **UBFloatingPalette** → Base for floating palettes
- **UBStylusPalette** → Drawing tool selection
- **UBDrawingPalette** → Shape drawing tools
- **UBColorPicker** → Color selection
- **UBDockPalette** → Dockable panel base (Left/Right)
- **UBActionPalette** → Action button groups
- **UBNavigatorPalette** → Page thumbnails navigation
- **UBZoomPalette** → Zoom controls
- **UBKeyboardPalette** → Virtual keyboard
- **UBRegularShapesPalette** → Regular shapes selection
- **UBShapesPalette** → Shape tools
- Various property palettes (stroke, fill, arrows, cell, etc.)

### Teacher Guide
- **UBTeacherGuideWidget** → Teacher guide panel
- **UBTeacherGuideResourceEditionWidget** → Resource editing
- **UBTeacherGuideResourcesPresentationWidget** → Resource display

## Network Components
- **UBNetworkAccessManager** → Custom QNetworkAccessManager
- **UBHttpGet** → HTTP download operations
- **UBHttpFileDownloader** → File download management
- **UBCookieJar** → Cookie persistence
- **UBAutoSaver** → Auto-save timer
- **UBServerXMLHttpRequest** → XMLHttpRequest for embedded widgets

## Web Components
- **UBWebController** → Web browser mode controller
- **UBWebPage** → Custom QWebPage
- **UBTrapFlashController** → Flash content capture
- **UBOEmbedParser** → OEmbed URL resolution
- **UBWebKitUtils** → WebKit utilities

## Podcast Components
- **UBPodcastController** → Screen recording orchestration
- **UBAbstractVideoEncoder** → Encoder interface
- Platform-specific: QuickTime (macOS), Windows Media (Windows)
- **YouTube publishing** integration
- **Intranet publishing** support

## Cross-References
- [System Overview](system-overview.md)
- [Dependencies](dependencies.md)
- [Program Structure](../reference/program-structure.md)
