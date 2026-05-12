# Structural Diagrams

## Component Diagram - System Modules

```mermaid
graph TB
    subgraph Application
        UBApp[UBApplication]
        UBAppCtrl[UBApplicationController]
    end

    subgraph Board
        UBBoard[UBBoardController]
        UBDraw[UBDrawingController]
        UBView[UBBoardView]
        UBPalette[UBBoardPaletteManager]
        UBFeatures[UBFeaturesController]
    end

    subgraph Domain
        UBScene[UBGraphicsScene]
        UBItems[Graphics Items]
        UBShapes[UBShapeFactory]
        UBUndo[Undo Commands]
        UBZLayer[UBZLayerController]
    end

    subgraph GUI
        UBMainWin[UBMainWindow]
        UBPalettes[Palette System]
        UBDocNav[UBDocumentNavigator]
    end

    subgraph Persistence
        UBPersist[UBPersistenceManager]
        UBCache[UBSceneCache]
        UBAdapt[Adaptors]
    end

    subgraph Web
        UBWebCtrl[UBWebController]
        UBWebKit[QtWebKit]
    end

    subgraph Network
        UBHttp[UBHttpGet]
        UBCookie[UBCookieJar]
    end

    UBApp --> UBAppCtrl
    UBApp --> UBBoard
    UBApp --> UBWebCtrl
    UBAppCtrl --> UBBoard
    UBAppCtrl --> UBWebCtrl
    UBBoard --> UBScene
    UBBoard --> UBView
    UBBoard --> UBPalette
    UBBoard --> UBShapes
    UBBoard --> UBPersist
    UBScene --> UBItems
    UBScene --> UBZLayer
    UBScene --> UBUndo
    UBPersist --> UBAdapt
    UBPersist --> UBCache
    UBWebCtrl --> UBWebKit
    UBBoard --> UBHttp
```

## Class Hierarchy - Domain Graphics Items

```mermaid
classDiagram
    class UBItem {
        <<interface>>
        +uuid() QUuid
        +deepCopy() UBItem*
        +sourceUrl() QUrl
    }
    
    class UBGraphicsItem {
        <<interface>>
        +type() int
        +Delegate() UBGraphicsItemDelegate*
        +remove(canUndo)
    }

    class QGraphicsItem {
        <<Qt>>
    }

    QGraphicsItem <|-- UBGraphicsPixmapItem
    QGraphicsItem <|-- UBGraphicsSvgItem
    QGraphicsItem <|-- UBGraphicsTextItem
    QGraphicsItem <|-- UBGraphicsPolygonItem
    QGraphicsItem <|-- UBGraphicsMediaItem
    QGraphicsItem <|-- UBGraphicsPDFItem
    QGraphicsItem <|-- UBGraphicsWidgetItem
    QGraphicsItem <|-- UBGraphicsGroupContainerItem
    QGraphicsItem <|-- UBGraphicsRectItem
    QGraphicsItem <|-- UBGraphicsEllipseItem
    QGraphicsItem <|-- UBGraphicsLineItem

    UBGraphicsMediaItem <|-- UBGraphicsVideoItem
    UBGraphicsMediaItem <|-- UBGraphicsAudioItem

    UBItem <|.. UBGraphicsPixmapItem
    UBItem <|.. UBGraphicsSvgItem
    UBItem <|.. UBGraphicsTextItem
    UBItem <|.. UBGraphicsMediaItem
    UBItem <|.. UBGraphicsWidgetItem

    UBGraphicsItem <|.. UBGraphicsPixmapItem
    UBGraphicsItem <|.. UBGraphicsSvgItem
    UBGraphicsItem <|.. UBGraphicsTextItem
    UBGraphicsItem <|.. UBGraphicsMediaItem
    UBGraphicsItem <|.. UBGraphicsWidgetItem
```

## Package Dependency Graph

```
┌─────────────────────────────────────────────────────┐
│                    gui (23.6K LOC)                    │
│  Palettes, MainWindow, Thumbnails, Features          │
└────────────┬─────────────────────┬──────────────────┘
             │                     │
             ▼                     ▼
┌─────────────────────┐  ┌─────────────────────┐
│  board (9.8K LOC)   │  │ document (4.7K LOC)  │
│  Controllers, View  │  │ Proxy, Container     │
└────────┬────────────┘  └─────────┬───────────┘
         │                         │
         ▼                         ▼
┌─────────────────────────────────────────────────────┐
│               domain (21.5K LOC)                     │
│  Scene, Items, Shapes, Undo, Handles, Z-Layer        │
└────────────┬────────────────────────────────────────┘
             │
             ▼
┌─────────────────────┐  ┌─────────────────────┐
│  core (10.2K LOC)   │  │ adaptors (11.3K LOC) │
│  App, Persist, Cfg  │  │ SVG, PDF, CFF, Img   │
└────────┬────────────┘  └─────────────────────┘
         │
         ▼
┌─────────────────────────────────────────────────────┐
│            frameworks (4.0K LOC)                      │
│  FileUtils, Geometry, Crypto, Platform, String        │
└─────────────────────────────────────────────────────┘
```
