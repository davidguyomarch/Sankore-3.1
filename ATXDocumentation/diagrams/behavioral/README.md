# Behavioral Diagrams

## Sequence Diagram - Document Open

```mermaid
sequenceDiagram
    participant User
    participant DocCtrl as UBDocumentController
    participant BoardCtrl as UBBoardController
    participant Persist as UBPersistenceManager
    participant Cache as UBSceneCache
    participant Adaptor as UBSvgSubsetAdaptor
    participant Scene as UBGraphicsScene
    participant View as UBBoardView

    User->>DocCtrl: Select document
    DocCtrl->>BoardCtrl: setActiveDocumentScene(proxy, index)
    BoardCtrl->>Persist: persistCurrentScene() [save current]
    Persist->>Adaptor: persistScene(proxy, scene, idx)
    BoardCtrl->>Persist: loadDocumentScene(proxy, index)
    Persist->>Cache: value(proxy, index)
    alt Cache hit
        Cache-->>Persist: scene (from cache)
    else Cache miss
        Persist->>Adaptor: loadScene(proxy, index)
        Adaptor->>Scene: create + populate items
        Adaptor-->>Persist: scene
    end
    Persist-->>BoardCtrl: scene
    BoardCtrl->>View: setScene(scene)
    BoardCtrl-->>User: Display page
```

## Sequence Diagram - Freehand Drawing

```mermaid
sequenceDiagram
    participant Tablet as Input Device
    participant View as UBBoardView
    participant Scene as UBGraphicsScene
    participant Stroke as UBGraphicsStroke
    participant Polygon as UBGraphicsPolygonItem
    participant Undo as QUndoStack

    Tablet->>View: mousePressEvent(pos, pressure)
    View->>Scene: inputDevicePress(scenePos, pressure)
    Scene->>Scene: initStroke()
    Scene->>Stroke: create new stroke

    loop Mouse/Tablet Move
        Tablet->>View: mouseMoveEvent(pos, pressure)
        View->>Scene: inputDeviceMove(scenePos, pressure)
        Scene->>Scene: drawLineTo(endPoint, width)
        Scene->>Polygon: create polygon item
        Scene->>Stroke: add polygon to stroke
        Scene->>Scene: addItem(polygon)
    end

    Tablet->>View: mouseReleaseEvent()
    View->>Scene: inputDeviceRelease()
    Scene->>Undo: push(UBGraphicsItemUndoCommand)
```

## Sequence Diagram - Import File

```mermaid
sequenceDiagram
    participant User
    participant AppCtrl as UBApplicationController
    participant DocMgr as UBDocumentManager
    participant Adaptor as UBImportAdaptor
    participant Persist as UBPersistenceManager
    participant BoardCtrl as UBBoardController

    User->>AppCtrl: importFile(path)
    AppCtrl->>DocMgr: importFile(path)
    DocMgr->>DocMgr: Find matching adaptor by extension
    DocMgr->>Adaptor: importFile(path, group)
    Adaptor->>Persist: createDocument(group, name)
    Persist-->>Adaptor: documentProxy
    Adaptor->>Adaptor: Parse file, create scenes
    Adaptor->>Persist: persistDocumentScene(proxy, scene, i)
    Adaptor-->>DocMgr: documentProxy
    DocMgr-->>AppCtrl: documentProxy
    AppCtrl->>BoardCtrl: setActiveDocumentScene(proxy, 0)
```

## Activity Diagram - Content Addition

```
[Start] → User drops content on board
    │
    ▼
[Determine content type from URL/MIME]
    │
    ├── Image → Download → addPixmap() → UBGraphicsPixmapItem
    ├── SVG → Download → addSvg() → UBGraphicsSvgItem  
    ├── Video → Download → addVideo() → UBGraphicsVideoItem
    ├── Audio → Download → addAudio() → UBGraphicsAudioItem
    ├── Widget (.wgt) → Extract ZIP → addW3cWidget() → UBGraphicsWidgetItem
    ├── PDF → Import as pages → Multiple UBGraphicsPDFItems
    └── Other → Embed in WebWidget → UBGraphicsProxyWidget
    │
    ▼
[Position item at drop/center point]
    │
    ▼
[Push UBGraphicsItemUndoCommand]
    │
    ▼
[Persist to document directory]
    │
    ▼
[End]
```

## State Machine - Drawing Tool

```
                    ┌──────────┐
     ┌──────────── │   Pen    │ ◄─────────────┐
     │             └────┬─────┘               │
     │                  │ select marker        │ select pen
     │                  ▼                      │
     │             ┌──────────┐               │
     │      ┌───── │  Marker  │ ──────────────┘
     │      │      └──────────┘
     │      │ select eraser
     │      ▼
     │ ┌──────────┐
     │ │  Eraser  │
     │ └──────────┘
     │      │ select selector
     │      ▼
     │ ┌──────────┐
     └►│ Selector │◄── select from any state
       └──────────┘
            │ select hand/zoom/pointer
            ▼
       ┌──────────┐
       │  Other   │ (Hand, ZoomIn, ZoomOut, Pointer, Line, Text, Capture)
       └──────────┘
```
