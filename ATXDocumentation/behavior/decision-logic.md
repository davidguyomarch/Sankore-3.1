> ⚠️ **Early Access**: Behavior documentation is in early access. Please review critically.

# Decision Logic

## Tool Selection Decision Tree

```
User selects tool → UBDrawingController::setStylusTool(tool)
├── Pen → Enable freehand drawing mode
│   └── Color/width from current pen settings
├── Marker → Enable semi-transparent drawing
│   └── Alpha from marker settings
├── Eraser → Enable erase mode
│   └── Width from eraser settings
├── Selector → Enable item selection/manipulation
│   └── Show delegate frame on selected items
├── Hand → Enable viewport panning
├── ZoomIn/ZoomOut → Enable zoom tool
├── Pointer → Show laser pointer cursor
├── Line → Enable straight line drawing
├── Text → Enable text creation at click
├── RichText → Enable rich text creation
└── Capture → Enable screen region capture
```

## Drawing Input Decision Logic

### inputDevicePress Decision
```
Event received → Check current tool
├── Drawing tool (Pen/Marker/Line)?
│   ├── Yes → initStroke(), begin drawing
│   └── No → forward to item/scene handling
├── Eraser?
│   └── Begin erase path
├── Selector?
│   ├── Item under cursor? → Begin drag/resize
│   └── No item → Begin rubber band selection
└── Other tools → Tool-specific behavior
```

### Color Selection Decision
```
Need current color → Check background
├── Dark background?
│   └── Use penColorOnDarkBackground / markerColorOnDarkBackground
└── Light background?
    └── Use penColorOnLightBackground / markerColorOnLightBackground
```

### inferOpposite Color Logic
When background changes, pen/marker colors adapt:
- If current color too similar to new background → infer contrasting color
- Maintains readability across background changes

## Content Type Decision (downloadFinished)

```
Download complete → Examine content type / file extension
├── Image (png, jpg, gif, bmp, tiff)?
│   └── addPixmap() → UBGraphicsPixmapItem
├── SVG?
│   └── addSvg() → UBGraphicsSvgItem
├── PDF?
│   └── Import as document pages
├── Widget (.wgt)?
│   └── expandWidgetToTempDir() → addW3cWidget()
├── Video (mp4, avi, mov)?
│   └── addVideo() → UBGraphicsVideoItem
├── Audio (mp3, wav)?
│   └── addAudio() → UBGraphicsAudioItem
└── Other/HTML?
    └── Embed in web widget proxy
```

## Z-Layer Decision (UBZLayerController)

```
Item added to scene → Determine layer type
├── Background object → bottommost layer
├── Regular annotation (stroke) → annotation layer
├── Object (image, widget, etc.) → object layer
├── Tool (ruler, compass) → tool layer
└── Cache/curtain overlay → topmost layer

Item reorder request (bring to front/send to back):
├── up → Move to top within its layer type
├── down → Move to bottom within its layer type
├── top → Assign maximum Z in layer
└── bottom → Assign minimum Z in layer
```

## Document Structure Decision

```
Importing file → Check extension against registered adaptors
├── .ubz → UBImportDocument (native format)
├── .pdf → UBImportPDF
├── .png/.jpg/.gif/.bmp/.tiff → UBImportImage
├── .iwb → UBImportCFF (Common File Format)
├── .ubx → UBImportDocumentSetAdaptor
└── Unknown → No import possible
```

## Scene Persistence Decision

```
Scene needs saving?
├── Page navigation → Persist current before loading new
├── Auto-save timer → Persist if dirty
├── Application closing → Persist all dirty scenes
├── Export requested → Persist to ensure latest state
└── Scene cache eviction → Persist before removing from cache
```

## Background Disposition Decision

```
Image set as background → Apply disposition:
├── Center → Position at center, no scaling
├── Adjust → Scale to fit page, preserve aspect ratio
├── Mosaic → Tile across entire page
├── Fill → Scale to cover page (may crop)
└── Extend → Stretch to fill (may distort)
```

## Platform-Specific Decisions

```
Runtime platform check:
├── Q_WS_MAC:
│   ├── Use Carbon/Cocoa event handling
│   ├── QuickTime for video encoding
│   ├── Foundation framework utilities
│   └── .app bundle resource paths
├── Q_WS_WIN:
│   ├── QAxContainer for ActiveX
│   ├── Windows Media for encoding
│   ├── Registry-based paths
│   └── Multi-process compilation (/MP)
└── linux-*:
    ├── X11 for window management
    ├── Standard filesystem paths
    └── libcrypto for crypto
```

## Mode Switching Decision

```
User action → Determine target mode:
├── Board button → showBoard()
│   └── If already in Board → no-op
├── Web button → showInternet()
│   └── Switch to web view, freeze widgets
├── Document button → showDocument()
│   └── Switch to document manager
├── Desktop button → showDesktop()
│   └── Minimize app, show desktop annotations
└── Tutorial button → showTutorial()
    └── Open tutorial content
```

## Cross-References
- [Business Logic](business-logic.md)
- [Workflows](workflows.md)
- [Error Handling](error-handling.md)
