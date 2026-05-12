# Data Models

## Document Model

### UBDocumentProxy (`src/document/UBDocumentProxy.h`)
Lightweight representation of a document without loading scene content.

**Properties:**
- `uuid` - Unique document identifier
- `metaData` - QMap of metadata (title, author, version, etc.)
- `persistencePath` - File system path to document folder
- `pageCount` - Number of scenes/pages

**Document Storage Structure (on disk):**
```
document-uuid/
├── metadata.rdf         # Dublin Core metadata (via UBMetadataDcSubsetAdaptor)
├── page001.svg          # Scene content as SVG subset
├── page002.svg
├── ...
├── images/              # Referenced images
├── objects/             # Embedded objects
├── videos/              # Video files
├── audios/              # Audio files
├── widgets/             # W3C widget packages
├── files/               # Attached files
└── teacherGuide/        # Teacher guide content
```

### UBDocumentTreeNode / UBDocumentTreeModel
Tree structure for document organization (folders/documents).

### UBDocumentContainer (`src/document/UBDocumentContainer.h`)
Base class for controllers that manage a document (extended by UBBoardController).

## Scene Model

### UBGraphicsScene (`src/domain/UBGraphicsScene.h`)
The canvas model containing all visual items.

**Key Data:**
- `mDocument` (UBDocumentProxy*) - Parent document
- `mDarkBackground` (bool) - Background color mode
- `mCrossedBackground` (bool) - Grid overlay
- `mBackgroundObject` (QGraphicsItem*) - Background image/object
- `mNominalSize` (QSize) - Page dimensions
- `mViewState` (SceneViewState) - Zoom/scroll state
- `mFastAccessItems` (QList) - Cached items list

### SceneViewState (inner class of UBGraphicsScene)
```cpp
struct SceneViewState {
    qreal zoomFactor;
    int horizontalPosition;
    int verticalPostition;
    QPointF lastSceneCenter;
};
```

## Graphics Item Data

### Common Item Properties (stored as QGraphicsItem data)
All items carry metadata via `QGraphicsItem::setData()`:
- UUID (unique identifier)
- Z-value (layer position)
- Lock state
- Source URL
- Rendering quality

### UBGraphicsPolygonItem (Stroke Data)
- Polygon path (QPolygonF)
- Line width
- Color (adapts to background)
- Stroke grouping (UBGraphicsStroke)

### UBGraphicsStroke (`src/domain/UBGraphicsStroke.h`)
Groups multiple polygon items into a single logical stroke.

### UBStrokeProperty (`src/domain/UBStrokeProperty.h`)
Encapsulates stroke visual properties (width, color, style).

## Handle Data

### UBAbstractHandle
- Position in scene coordinates
- Handle type (diagonal, horizontal, vertical, free)
- Associated editable item

## Z-Layer Model

### ItemLayerTypeData (UBZLayerController)
```cpp
struct ItemLayerTypeData {
    qreal bottomLimit;   // Bottom Z bound
    qreal topLimit;      // Top Z bound
    qreal curValue;      // Current assigned value
    qreal incStep;       // Increment step
};
```

Layer types (ordered bottom to top):
1. Background objects
2. Drawing annotations
3. Regular objects
4. Tools (ruler, compass)
5. Cache/curtain overlays

## Settings Model

### UBSettings (`src/core/UBSettings.h`)
Singleton storing all application preferences using QSettings.

Key setting groups:
- Board colors (pen/marker colors for dark/light backgrounds)
- Tool widths (pen, marker, eraser sizes)
- Application paths (document repository, library)
- Display preferences (toolbar position, multi-screen)
- Network (proxy settings)

## Download Model

### sDownloadFileDesc (`src/core/UBDownloadManager.h`)
Structure describing a file download:
- URL, destination path
- Progress state
- Associated board position/size

## Teacher Guide Data

### tIDataStorage (`src/interfaces/IDataStorage.h`)
```cpp
struct tIDataStorage {
    QString name;
    QMap<QString, QString> attributes;
    eElementType type;  // START, END, UNIQUE
};
```

## Cross-References
- [Program Structure](program-structure.md)
- [Interfaces](interfaces.md)
- [API Reference](api-reference.md)
- [Dependencies](../architecture/dependencies.md)
