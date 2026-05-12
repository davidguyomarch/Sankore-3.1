# Test Specifications

## Unit Test Specifications

### frameworks/ Module Tests

#### UBFileSystemUtils
- Test `readTextFile()` with valid/invalid paths
- Test `deleteAllTempDirCreatedDuringSession()` cleanup
- Test path generation utilities

#### UBGeometryUtils
- Test geometric calculations (line intersection, distance)
- Test polygon operations
- Test angle calculations

#### UBCryptoUtils
- Test `symetricEncrypt()` / `symetricDecrypt()` roundtrip
- Test with empty strings, special characters, Unicode
- Verify encrypted output is different from input

#### UBVersion
- Test version parsing ("2.5.1", "2.5.a.1")
- Test version comparison operators
- Test invalid version strings

#### UBBase32
- Test encode/decode roundtrip
- Test with empty data, boundary sizes

### core/ Module Tests

#### UBSettings
- Test setting read/write persistence
- Test default value fallbacks
- Test setting change signals

#### UBPersistenceManager
- Test document creation (directory structure created)
- Test scene count retrieval
- Test document deletion (files removed)
- Test unique path generation

#### UBSceneCache
- Test cache hit/miss behavior
- Test eviction when cache full
- Test dirty scene persistence on eviction

### domain/ Module Tests

#### UBGraphicsScene
- Test item add/remove
- Test Z-layer ordering
- Test background setting
- Test nominal size changes
- Test clear operations (items, annotations, all)

#### UBZLayerController
- Test Z-value generation within layer bounds
- Test changeZLevelTo (up, down, top, bottom)
- Test layer type assignment

#### UBShapeFactory
- Test shape creation for each type
- Test shape type identification

#### Undo Commands
- Test UBGraphicsItemUndoCommand undo/redo
- Test UBGraphicsItemTransformUndoCommand
- Test UBPageSizeUndoCommand

### adaptors/ Module Tests

#### UBSvgSubsetAdaptor
- Test persistScene() / loadScene() roundtrip
- Test each item type serialization
- Test with empty scene
- Test with complex scene (multiple item types)
- Test backward compatibility with older SVG versions

#### UBMetadataDcSubsetAdaptor
- Test metadata read/write roundtrip
- Test with minimal metadata
- Test with full metadata

### network/ Module Tests

#### UBHttpGet (Integration)
- Test successful download
- Test failed download (404)
- Test timeout behavior

#### UBCookieJar
- Test cookie storage and retrieval
- Test cookie expiration

## Integration Test Specifications

### Document Lifecycle
1. Create document → verify directory structure
2. Add page → verify scene count increases
3. Add items to page → persist → reload → verify items present
4. Delete page → verify scene count decreases
5. Delete document → verify directory removed

### Import/Export Roundtrip
1. Export document as .ubz
2. Import .ubz → verify document equivalent
3. Export as PDF → verify PDF valid
4. Import PDF → verify pages created

### Board Operations
1. Create stroke → verify polygon items in scene
2. Undo stroke → verify items removed
3. Redo stroke → verify items restored
4. Add image → verify pixmap item
5. Group items → verify container
6. Ungroup → verify individual items

## Acceptance Test Specifications

### Core Workflows
- Application starts without error
- Board mode displays empty scene
- Drawing with pen creates visible strokes
- Page navigation works (add, next, previous)
- Document save and reload preserves all content
- Import PDF creates viewable document
- Export to PDF generates valid file

### Platform-Specific
- macOS: Application launches in .app bundle
- Windows: Application launches from installer
- Linux: Application launches from package

## Cross-References
- [Validation Criteria](validation-criteria.md)
- [Component Order](component-order.md)
