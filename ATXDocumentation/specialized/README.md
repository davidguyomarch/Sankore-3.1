# Specialized Documentation

## UI Component Patterns

### Palette System Architecture
Open-Sankoré uses an extensive floating palette system for tool access:

**Palette Hierarchy:**
- `UBFloatingPalette` - Base class for all floating palettes
  - Translucent, draggable, auto-hide capable
  - Can be docked to screen edges
- `UBActionPalette` - Grid of action buttons
- `UBDockPalette` - Side-docked panels (Left/Right)
  - Collapsible with tab navigation
  - Contains multiple `UBDockPaletteWidget` instances

**Key Palettes:**
| Palette | Purpose | Location |
|---------|---------|----------|
| UBStylusPalette | Drawing tool selection | Board toolbar |
| UBDrawingPalette | Shape/drawing tools | Sub-palette of stylus |
| UBZoomPalette | Zoom controls | Board corner |
| UBNavigatorPalette | Page thumbnail strip | Left dock |
| UBKeyboardPalette | Virtual keyboard | Floating |
| UBColorPicker | Color selection | Drawing context |
| UBRegularShapesPalette | Polygon shapes | Sub-palette |
| UBFavoriteToolPalette | User favorites | Floating |
| UBClockPalette | Clock display | Floating |

**Platform-Specific Keyboard:**
- `UBKeyboardPalette_mac.cpp` - macOS keyboard layout
- `UBKeyboardPalette_win.cpp` - Windows keyboard layout  
- `UBKeyboardPalette_linux.cpp` - Linux keyboard layout

## Document Format Handling

### SVG Subset Format (Primary)
- Custom SVG subset used for scene persistence
- Handled by `UBSvgSubsetAdaptor`
- Stores all item types as SVG elements with custom attributes
- Not standard SVG - uses proprietary extensions for Sankoré items

### .ubz Document Format
- ZIP archive containing:
  - SVG scene files (one per page)
  - Metadata (Dublin Core RDF)
  - Referenced media files (images, videos, audio)
  - Widget packages
  - Thumbnails
- Handled by `UBExportDocument` / `UBImportDocument`

### CFF/IWB Format (Common File Format)
- IWB interoperability standard
- Plugin-based implementation (`plugins/cffadaptor/`)
- Enables exchange with other interactive whiteboard software
- `UBCFFSubsetAdaptor` handles parsing/generation

### PDF Handling
- **Import**: `UBImportPDF` renders PDF pages to scene items
- **Export**: `UBExportPDF` / `UBExportFullPDF` renders scenes to PDF
- **Merging**: `src/pdf-merger/` combines multiple PDFs
- Uses custom PDF parsing (not Poppler/Qt PDF)

## Infrastructure & Deployment

### Multi-Screen Display
- `UBDisplayManager` manages primary/secondary screens
- Control view: Teacher's screen (interactive)
- Display view: Presentation screen (audience-facing)
- Configurable via preferences

### Auto-Save System
- `UBAutoSaver` (src/network/UBAutoSaver.h) - Timer-based
- Triggers scene persistence at configurable intervals
- Saves on page navigation as well

### Single Instance Management
- `QtSingleApplication` prevents multiple launches
- Second instance sends file path to first
- macOS: Apple Events for Dock clicks

## Geometry Tools Implementation

### Measurement Tools
All tools inherit from `UBAbstractDrawRuler`:
- **Ruler**: Straight edge with measurement markings, can draw lines along edge
- **Triangle**: Set square (45° or 30-60-90°) with angle measurement
- **Protractor**: Full 360° angle measurement tool
- **Compass**: Circle drawing tool with radius adjustment
- **Aristo**: Combined protractor and ruler

### Tool Features
- Draggable positioning on board
- Rotation via gesture/handle
- Drawing along tool edges
- Measurement display (degrees, centimeters)
- Z-layer: Tools always above content items

## Cross-References
- [Components](../architecture/components.md)
- [Modules](../reference/modules.md)
- [UI Diagrams](../diagrams/structural/README.md)
