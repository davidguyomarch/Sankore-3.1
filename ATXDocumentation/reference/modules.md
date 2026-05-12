# Modules

## Module Overview

| Module | Files (approx) | Primary Responsibility |
|--------|----------------|----------------------|
| core | 17 | Application lifecycle, settings, persistence |
| board | 5 | Board interaction control |
| domain | 57 | Graphics items, scene, shapes, undo |
| gui | 63 | Palettes, widgets, main window |
| adaptors | 19 | Import/export format handling |
| web | 12 | Browser integration |
| document | 4 | Document model/controller |
| network | 6 | HTTP/download operations |
| frameworks | 14 | Cross-cutting utilities |
| tools | 10 | Geometry measurement tools |
| podcast | 8+ | Screen recording |
| desktop | 2+ | Desktop annotation mode |
| pdf | 2+ | PDF rendering |
| pdf-merger | 5+ | PDF document combination |
| transition | 2+ | Legacy data migration |
| interfaces | 1 | Abstract contracts |
| customWidgets | 2+ | Reusable UI components |
| api | 4 | JavaScript widget bridge |
| globals | 1 | Shared definitions |

## Module Details

### core (`src/core/`)
**Key Classes:**
- `UBApplication` - Application entry point, global static accessors
- `UBApplicationController` - Mode management (Board/Web/Document)
- `UBPersistenceManager` - Document CRUD, scene caching
- `UBSettings` - Application preferences
- `UBDocumentManager` - Import/export coordination
- `UBDownloadManager` / `UBDownloadThread` - Async downloads
- `UBDisplayManager` - Multi-screen management
- `UBSceneCache` - LRU scene cache
- `UBIdleTimer` - Idle detection
- `UBMimeData` - Custom drag/drop data
- `UBForeignObjectsHandler` - External asset management
- `UBPreferencesController` - Preferences dialog controller

### board (`src/board/`)
**Key Classes:**
- `UBBoardController` - Central board operations
- `UBBoardView` - QGraphicsView with input handling
- `UBDrawingController` - Tool state singleton
- `UBBoardPaletteManager` - Palette coordination
- `UBFeaturesController` - Library browser

### domain (`src/domain/`)
**Key Classes:**
- `UBGraphicsScene` - The canvas (QGraphicsScene subclass)
- `UBZLayerController` - Z-order management
- `UBShapeFactory` - Shape creation
- Graphics items (Pixmap, SVG, Text, PDF, Media, Widget, Polygon, etc.)
- Handle classes (Abstract, Diagonal, Horizontal, Vertical, Free)
- Editable items (polygon, regular shape, circle, square)
- Undo commands (item, transform, group, text, document, page size)
- `UBGraphicsStroke` - Stroke grouping
- `UBGraphicsItemDelegate` - Item interaction delegate
- `UBGraphicsDelegateFrame` - Resize/rotate frame
- `UBAlignObjectManager` - Object alignment

### gui (`src/gui/`)
**Key Classes:**
- `UBMainWindow` - Application main window
- Palette system (30+ palette classes)
- `UBDocumentNavigator` - Page thumbnail strip
- `UBThumbnailWidget` - Thumbnail grid
- `UBKeyboardPalette` - Virtual keyboard (platform-specific)
- `UBFeaturesWidget` - Library browser widget
- `UBTeacherGuideWidget` - Teacher guide panel
- `UBResources` - Shared resource loading
- `UBScreenMirror` - Screen mirroring widget

### adaptors (`src/adaptors/`)
**Key Classes:**
- `UBSvgSubsetAdaptor` - Primary document format (SVG)
- `UBCFFSubsetAdaptor` - IWB Common File Format
- `UBImportDocument` / `UBExportDocument` - .ubz format
- `UBImportPDF` / `UBExportPDF` - PDF handling
- `UBExportFullPDF` - Full PDF with annotations
- `UBImportImage` - Image files
- `UBImportCFF` / `UBExportCFF` - CFF format
- `UBExportWeb` - HTML export
- `UBMetadataDcSubsetAdaptor` - Dublin Core metadata
- `UBThumbnailAdaptor` - Thumbnail generation
- `UBWebPublisher` - Web publishing
- `UBIniFileParser` - INI file parsing

### web (`src/web/`)
**Key Classes:**
- `UBWebController` - Browser mode controller
- `UBWebPage` - Custom QWebPage subclass
- `UBTrapFlashController` - Flash content capture
- `UBOEmbedParser` - OEmbed URL resolution
- `UBWebKitUtils` - WebKit DOM utilities
- `UBWebPluginWidget` - Plugin rendering
- `browser/` subdirectory - Full browser UI

### network (`src/network/`)
**Key Classes:**
- `UBNetworkAccessManager` - Custom network manager
- `UBHttpGet` - HTTP GET operations
- `UBHttpFileDownloader` - Batch file downloads
- `UBCookieJar` - Cookie persistence
- `UBAutoSaver` - Auto-save timer
- `UBServerXMLHttpRequest` - XMLHttpRequest for widgets

### frameworks (`src/frameworks/`)
**Key Classes:**
- `UBFileSystemUtils` - File/directory operations
- `UBGeometryUtils` - Geometric calculations
- `UBImageUtils` - Image processing (with OpenMP)
- `UBCryptoUtils` - Cryptographic operations
- `UBPlatformUtils` - Platform abstraction (Mac/Win/Linux)
- `UBStringUtils` - String manipulation
- `UBVersion` - Version parsing/comparison
- `UBBase32` - Base32 encoding
- `UBWidgetUtils` - Widget utilities
- `UBTrashRegistery` - Deleted item tracking

### tools (`src/tools/`)
**Key Classes:**
- `UBGraphicsRuler` - Straight-edge ruler
- `UBGraphicsTriangle` - Set square
- `UBGraphicsProtractor` - Angle measurement
- `UBGraphicsCompass` - Circle drawing
- `UBGraphicsAristo` - Aristo protractor
- `UBGraphicsCurtainItem` - Screen mask/curtain
- `UBGraphicsCache` - Spotlight/cache tool
- `UBToolsManager` - Tool registry

### podcast (`src/podcast/`)
**Key Classes:**
- `UBPodcastController` - Recording orchestration
- `UBAbstractVideoEncoder` - Encoder interface
- Platform backends: `quicktime/`, `windowsmedia/`
- `youtube/` - YouTube upload
- `intranet/` - Intranet publishing

### document (`src/document/`)
**Key Classes:**
- `UBDocumentProxy` - Document metadata proxy
- `UBDocumentContainer` - Document holder base
- `UBDocumentController` - Document management UI controller
- `UBSortFilterProxyModel` - Document list filtering

### plugins/cffadaptor
**Purpose:** IWB Common File Format import/export plugin for interoperability with other IWB software.

## Module Dependencies Summary

```
frameworks ← (no dependencies, base layer)
    ↑
core ← frameworks, domain (partial)
    ↑
domain ← core, frameworks
    ↑
board ← core, domain, gui, document
    ↑
gui ← core, domain, board
    ↑
adaptors ← core, domain, frameworks
    ↑
web ← core, network
    ↑
network ← core, frameworks
    ↑
podcast ← board, core
```

## Cross-References
- [Program Structure](program-structure.md)
- [System Overview](../architecture/system-overview.md)
- [Dependencies](../architecture/dependencies.md)
