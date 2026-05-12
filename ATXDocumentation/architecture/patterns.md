# Architectural Patterns

## Design Patterns Identified

### 1. Singleton Pattern
Used extensively for global managers:
- `UBPersistenceManager::persistenceManager()` - Document storage
- `UBDrawingController::drawingController()` - Drawing state
- `UBSettings` - Application settings
- `UBApplication::app()` - Application instance access

### 2. MVC (Modified Model-View-Controller)
- **Model**: `UBGraphicsScene` + domain items (UBGraphicsPixmapItem, etc.)
- **View**: `UBBoardView` (QGraphicsView), palette widgets
- **Controller**: `UBBoardController`, `UBDrawingController`, `UBApplicationController`

### 3. Observer Pattern (Qt Signals/Slots)
Pervasive use of Qt's signal/slot mechanism for:
- Tool change notifications (`stylusToolChanged`)
- Scene state changes (`activeSceneChanged`, `pageChanged`)
- Document lifecycle events (`documentCreated`, `documentWillBeDeleted`)
- UI state synchronization (`penColorChanged`, `zoomChanged`)

### 4. Command Pattern (Undo/Redo)
- `QUndoStack` managed by `UBApplication`
- Custom undo commands: `UBGraphicsItemUndoCommand`, `UBGraphicsItemTransformUndoCommand`, `UBGraphicsItemGroupUndoCommand`, `UBDocumentUndoCommand`, `UBPageSizeUndoCommand`
- Base class: `UBAbstractUndoCommand`

### 5. Strategy Pattern
- **Drawing tools**: Different behavior per `UBStylusTool::Enum` (Pen, Marker, Eraser, Selector, etc.)
- **Import/Export adaptors**: Polymorphic `UBImportAdaptor` / `UBExportAdaptor` subclasses
- **Handle builders**: `UBAbstractHandlesBuilder` for different shape editing strategies

### 6. Factory Pattern
- `UBShapeFactory` - Creates geometric shapes on the board
- Document creation in `UBPersistenceManager::createDocument()`

### 7. Adaptor Pattern
- `UBSvgSubsetAdaptor` - Adapts domain objects to/from SVG format
- `UBCFFSubsetAdaptor` - Adapts to/from CFF/IWB format
- `UBMetadataDcSubsetAdaptor` - Dublin Core metadata adaptor

### 8. Proxy Pattern
- `UBDocumentProxy` - Lightweight proxy representing a document without loading full content
- `UBGraphicsProxyWidget` - Proxy for embedding QWidgets in QGraphicsScene

### 9. Delegate Pattern
- `UBGraphicsItemDelegate` - Handles item interaction (resize frame, context actions)
- Specialized: `UBGraphicsMediaItemDelegate`, `UBGraphicsTextItemDelegate`, `UBGraphicsGroupContainerItemDelegate`

### 10. Facade Pattern
- `UBApplication` serves as a facade providing static access to all subsystems
- `UBBoardController` facades board operations (adds media, manages pages)

### 11. Template Method Pattern
- `UBCoreGraphicsScene::drawBackground()` overridden by `UBGraphicsScene`
- `UBImportAdaptor` / `UBExportAdaptor` define import/export workflows

### 12. Composite Pattern
- `UBGraphicsGroupContainerItem` - Groups multiple graphics items as one
- Document tree structure (`UBDocumentTreeNode`, `UBDocumentTreeModel`)

## Architectural Styles

### Event-Driven Architecture
- All user interactions processed through Qt's event loop
- Mouse/tablet pressure events drive drawing operations
- Timer-based auto-save (`UBAutoSaver`)

### Layered Architecture
```
┌─────────────────────────────────────┐
│ Presentation (gui, board views)     │
├─────────────────────────────────────┤
│ Application (controllers)           │
├─────────────────────────────────────┤
│ Domain (scene, items, undo)         │
├─────────────────────────────────────┤
│ Infrastructure (adaptors, network)  │
├─────────────────────────────────────┤
│ Frameworks (utilities)              │
└─────────────────────────────────────┘
```

### Plugin Architecture
- CFF adaptor as a compile-time plugin
- Widget system supports W3C widgets (`.wgt` packages)

## Anti-Patterns Identified

### 1. God Class
- `UBBoardController` (~200+ public methods/slots) - Does too much
- `UBGraphicsScene` (~100+ methods) - Combines rendering, input, item management

### 2. Tight Coupling via Statics
- `UBApplication::boardController`, `UBApplication::mainWindow` etc. accessed globally
- Makes testing and module isolation difficult

### 3. Platform-Specific Code Scattered
- `#ifdef Q_WS_MAC`, `#ifdef Q_WS_WIN` throughout codebase
- Platform utils partially centralized but not fully

### 4. Mixed Abstraction Levels
- `UBApplicationController` uses deprecated `QHttp`/`QFtp` alongside modern `QNetworkAccessManager`

## Cross-References
- [System Overview](system-overview.md)
- [Components](components.md)
- [Complexity Analysis](../analysis/complexity-analysis.md)
- [Technical Debt](../technical-debt/summary.md)
