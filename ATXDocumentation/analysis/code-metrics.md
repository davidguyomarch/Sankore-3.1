# Code Metrics

## Codebase Size

| Metric | Value |
|--------|-------|
| Total Lines of Code (C++ .h/.cpp) | ~125,772 |
| Source Modules | 19 |
| Total Source Files | ~554 |
| Plugin Files | Additional (cffadaptor) |

## Module Size Distribution

| Module | Lines | Files | Avg Lines/File |
|--------|-------|-------|---------------|
| gui | 23,627 | 131 | 180 |
| domain | 21,511 | 115 | 187 |
| adaptors | 11,302 | 43 | 263 |
| web | 10,702 | 40 | 268 |
| core | 10,165 | 33 | 308 |
| board | 9,835 | 10 | 984 |
| pdf-merger | 7,075 | 56 | 126 |
| tools | 5,699 | 20 | 285 |
| podcast | 5,221 | 22 | 237 |
| document | 4,676 | 8 | 585 |
| frameworks | 4,050 | 25 | 162 |
| desktop | 2,302 | 13 | 177 |
| api | 1,972 | 8 | 247 |
| network | 1,804 | 12 | 150 |
| customWidgets | 999 | 6 | 167 |
| pdf | 810 | 8 | 101 |
| transition | 380 | 2 | 190 |
| globals | 80 | 1 | 80 |
| interfaces | 60 | 1 | 60 |

## Largest Files (Complexity Indicators)

| File | Lines | Concern |
|------|-------|---------|
| `adaptors/UBSvgSubsetAdaptor.cpp` | 4,245 | God file - all SVG serialization |
| `document/UBDocumentController.cpp` | 3,417 | Document management UI |
| `board/UBBoardController.cpp` | 3,024 | Board operations controller |
| `domain/UBGraphicsScene.cpp` | 2,589 | Scene management |
| `board/UBFeaturesController.cpp` | 1,926 | Features/library browser |
| `board/UBBoardView.cpp` | 1,926 | Board view event handling |
| `gui/UBTeacherGuideWidget.cpp` | 1,879 | Teacher guide UI |
| `gui/UBFeaturesWidget.cpp` | 1,801 | Features panel |
| `domain/UBGraphicsItemDelegate.cpp` | 1,562 | Item interaction delegate |
| `adaptors/UBCFFSubsetAdaptor.cpp` | 1,549 | CFF format parsing |

## Code Density

| Category | Count |
|----------|-------|
| Files > 2000 lines | 4 |
| Files > 1000 lines | 16 |
| Files > 500 lines | ~35 |
| Files < 100 lines | ~200 |

## UI Forms
- 10 .ui form files (mainWindow, preferences, documents, brushProperties, etc.)

## Translations
- 36 language translations supported
- Translation files: .ts source, .qm compiled

## Cross-References
- [Complexity Analysis](complexity-analysis.md)
- [Dependency Analysis](dependency-analysis.md)
- [Maintenance Burden](../technical-debt/maintenance-burden.md)
