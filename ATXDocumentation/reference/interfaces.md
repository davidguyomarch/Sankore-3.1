# Interfaces

## Core Interfaces

### UBItem (`src/domain/UBItem.h`)
Base interface for all board content items.

```cpp
class UBItem {
public:
    virtual QUuid uuid() const;
    virtual void setUuid(const QUuid& pUuid);
    virtual RenderingQuality renderingQuality() const;
    virtual void setRenderingQuality(RenderingQuality pRenderingQuality);
    virtual UBItem* deepCopy() const = 0;              // Pure virtual
    virtual void copyItemParameters(UBItem *copy) const = 0;  // Pure virtual
    virtual UBGraphicsScene* scene();
    virtual QUrl sourceUrl() const;
    virtual void setSourceUrl(const QUrl& pSourceUrl);
};
```

### UBGraphicsItem (`src/domain/UBItem.h`)
Interface for graphics items with delegate support.

```cpp
class UBGraphicsItem {
public:
    virtual int type() const = 0;
    UBGraphicsItemDelegate *Delegate() const;
    static void assignZValue(QGraphicsItem*, qreal value);
    static bool isRotatable(QGraphicsItem *item);
    static bool isFlippable(QGraphicsItem *item);
    static bool isLocked(QGraphicsItem *item);
    static QUuid getOwnUuid(QGraphicsItem *item);
    void remove(bool canUndo = true);
    virtual void clearSource();
};
```

### IDataStorage (`src/interfaces/IDataStorage.h`)
Interface for teacher guide data persistence.

```cpp
class IDataStorage {
public:
    virtual QVector<tIDataStorage*> save(int pageIndex) = 0;
};
```

### UBImportAdaptor (`src/adaptors/UBImportAdaptor.h`)
Base interface for file import operations.

Key methods:
- `supportedExtentions()` - Returns list of handled file extensions
- `importFile()` - Performs the import operation
- `isDocumentBased()` - Whether import creates a new document

### UBExportAdaptor (`src/adaptors/UBExportAdaptor.h`)
Base interface for file export operations.

Key methods:
- `exportName()` - Display name for export format
- `exportExtention()` - File extension
- `persist()` - Execute export to file

### UBEditable (`src/domain/UBEditable.h`)
Interface for items with editing handles.

### UBShapeEditable (`src/domain/UBShapeEditable.h`)
Extended interface for shape editing with specific handle patterns.

### UBResizableGraphicsItem (`src/domain/UBResizableGraphicsItem.h`)
Interface for items that can be resized.

## Abstract Base Classes

### UBAbstractGraphicsItem (`src/domain/UBAbstractGraphicsItem.h`)
Abstract base for custom drawn graphics items (strokes, paths).

### UBAbstractGraphicsPathItem (`src/domain/UBAbstractGraphicsPathItem.h`)
Abstract base for path-based graphics items.

### UBAbstractEditableGraphicsPathItem (`src/domain/UBAbstractEditableGraphicsPathItem.h`)
Abstract base for editable path items with handle support.

### UBAbstractHandle (`src/domain/UBAbstractHandle.h`)
Abstract base for resize/edit handles on shapes.

### UBAbstractHandlesBuilder (`src/domain/UBAbstractHandlesBuilder.h`)
Abstract factory for creating handle configurations.

### UBAbstractUndoCommand (`src/domain/UBAbstractUndoCommand.h`)
Base class for custom undo commands.

### UBAbstractVideoEncoder (`src/podcast/UBAbstractVideoEncoder.h`)
Abstract base for platform-specific video encoding.

### UBAbstractDrawRuler (`src/tools/UBAbstractDrawRuler.h`)
Abstract base for geometry drawing tools.

### UBCoreGraphicsScene (`src/frameworks/UBCoreGraphicsScene.h`)
Core scene base class in the frameworks layer.

### UBAbstractSubPalette (`src/gui/UBAbstractSubPalette.h`)
Abstract base for sub-palette UI widgets.

### UBAbstractTeacherGuide (`src/gui/UBAbstractTeacherGuide.h`)
Abstract base for teacher guide widget implementations.

## Widget API Interfaces (JavaScript)

### UBWidgetUniboardAPI (`src/api/UBWidgetUniboardAPI.h`)
JavaScript API exposed to embedded widgets:
- Properties: `pageCount`, `currentPageNumber`, `uuid`, `lang`, `messages`, `datastore`
- Drawing: `setTool()`, `setPenColor()`, `setMarkerColor()`, `drawLineTo()`, `eraseLineTo()`
- Navigation: `zoom()`, `move()`, `centerOn()`, `pageThumbnail()`
- Content: `addObject()`, `addText()`, `clear()`, `setBackground()`
- Widget: `resize()`, `setPreference()`, `preference()`, `preferenceKeys()`
- Utility: `showMessage()`, `loadUrl()`, `locale()`, `isDarkBackground()`

### UBW3CWidgetAPI (`src/api/UBW3CWidgetAPI.h`)
W3C Widget specification API implementation.

### UBWidgetMessageAPI (`src/api/UBWidgetMessageAPI.h`)
Inter-widget messaging API.

### UBLibraryAPI (`src/api/UBLibraryAPI.h`)
Library access API for widgets.

## Cross-References
- [Program Structure](program-structure.md)
- [Data Models](data-models.md)
- [API Reference](api-reference.md)
