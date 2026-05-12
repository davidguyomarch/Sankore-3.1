# Complexity Analysis

## High-Complexity Files

### UBSvgSubsetAdaptor.cpp (4,245 lines)
- **Cyclomatic Complexity**: Very High
- **Responsibilities**: Serializes/deserializes ALL graphics item types to/from custom SVG subset
- **Branching**: Extensive type-checking switches for each item type during both read and write
- **Risk**: Any new item type requires modification; format versioning is complex

### UBDocumentController.cpp (3,417 lines)
- **Cyclomatic Complexity**: High
- **Responsibilities**: Document list UI, drag-drop, thumbnails, sorting, import/export UI
- **Risk**: UI and business logic mixed

### UBBoardController.cpp (3,024 lines)
- **Cyclomatic Complexity**: Very High
- **Responsibilities**: Page management, content addition, zoom/scroll, background, clipboard, tools
- **Method Count**: ~200+ methods/slots
- **Risk**: God class; changes have wide blast radius

### UBGraphicsScene.cpp (2,589 lines)
- **Cyclomatic Complexity**: High
- **Responsibilities**: Drawing input, item management, z-layers, magnifier, background
- **State Variables**: ~25 member variables tracking scene state
- **Risk**: Central class; bugs affect all operations

## Complexity Hotspots by Pattern

### Long Methods (Estimated)
- `UBSvgSubsetAdaptor::persistScene()` - serializes entire scene
- `UBSvgSubsetAdaptor::loadScene()` - deserializes entire scene
- `UBBoardController::downloadFinished()` - handles all content types
- `UBBoardController::processMimeData()` - handles all clipboard data types
- `UBDocumentController::*` - complex UI state management

### Deep Nesting
- SVG parsing with nested XML elements
- Platform-conditional code (`#ifdef` chains)
- Tool-specific behavior in switch statements
- Event handling in UBBoardView (mouse/tablet/touch branching)

### High Fan-Out
- `UBBoardController` depends on: core (6 classes), domain (10+), gui (8+), adaptors (3), network, podcast, tools, document
- `UBApplication::exec()` initializes all subsystems sequentially

## Threading Complexity

### Thread Usage
| Location | Pattern | Risk |
|----------|---------|------|
| `UBDownloadThread` | QThread subclass for downloads | Moderate - standard pattern |
| `UBFeaturesController` | Background scanning thread | Moderate |
| `UBPersistenceManager` | QMutex for deleted list | Low - simple locking |
| `UniboardSankoreTransition` | Threaded migration | Low - one-time operation |
| `UBQuickTimeFile` | Recording thread (macOS) | High - platform-specific |
| `UBDocumentNavigator` | Background thumbnail generation | Moderate |
| OpenMP (`UBGraphicsScene`) | Parallel image processing | Low - data parallel only |

### Concurrency Risks
- `mDeletedListMutex` in PersistenceManager - single mutex for document deletion
- Scene modification from multiple threads possible during download callbacks
- No atomic operations observed; relies on Qt's thread safety guarantees

## Coupling Metrics (Estimated)

### Afferent Coupling (incoming dependencies)
| Class | Dependents |
|-------|-----------|
| UBApplication | Nearly all classes (via static members) |
| UBSettings | All modules that read settings |
| UBGraphicsScene | board, gui, adaptors, document |
| UBBoardController | gui, core, web, podcast |
| UBPersistenceManager | core, board, document, adaptors |

### Efferent Coupling (outgoing dependencies)
| Class | Dependencies |
|-------|-------------|
| UBBoardController | ~25+ classes across 8 modules |
| UBSvgSubsetAdaptor | All domain item types |
| UBApplication::exec | All controller types |

## Maintainability Index Estimate

Based on file size, coupling, and complexity:

| Module | Maintainability | Reason |
|--------|----------------|--------|
| frameworks | High | Small, focused utilities |
| interfaces | High | Simple contracts |
| network | High | Small, focused |
| tools | Medium | Self-contained but large files |
| domain | Medium | Many classes but focused |
| core | Low | High coupling, singletons |
| board | Low | God classes, high coupling |
| adaptors | Low | Very large files, format complexity |
| gui | Low | Large, many interdependencies |

## Cross-References
- [Code Metrics](code-metrics.md)
- [Dependency Analysis](dependency-analysis.md)
- [Maintenance Burden](../technical-debt/maintenance-burden.md)
