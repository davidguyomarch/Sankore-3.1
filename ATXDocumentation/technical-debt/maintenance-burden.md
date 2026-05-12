# Maintenance Burden

## High-Burden Areas

### 1. UBBoardController (src/board/UBBoardController.cpp)
- **Size**: ~3025 lines, 200+ methods
- **Burden**: God class handling page management, content addition, clipboard, zoom, background, tool coordination
- **Impact**: Any change risks unintended side effects across many features
- **Coupling**: Depends on core, domain, gui, adaptors, network, podcast modules

### 2. UBGraphicsScene (src/domain/UBGraphicsScene.h/.cpp)
- **Size**: Very large (header alone ~350 lines of declarations)
- **Burden**: Combines canvas rendering, input handling, item management, magnifier, undo integration
- **Impact**: Central to all board operations; bugs here affect everything

### 3. UBSvgSubsetAdaptor (src/adaptors/UBSvgSubsetAdaptor.cpp)
- **Burden**: Handles serialization of ALL item types to/from SVG
- **Impact**: Any new item type requires changes here; format versioning critical
- **Risk**: SVG subset is custom, not standard SVG

### 4. Platform-Specific Code
- **Files**: `UBPlatformUtils_mac.mm`, `UBPlatformUtils_win.cpp`, `UBPlatformUtils_linux.cpp`
- **GUI Keyboard**: `UBKeyboardPalette_*.cpp` (separate per platform)
- **Podcast**: `quicktime/`, `windowsmedia/` (entirely separate implementations)
- **Burden**: Every feature must be verified on all platforms; platform APIs evolve independently

### 5. Qt Module Migration Surface
- **QtWebKit usages**: Spread across web/, board/, core/ modules
- **Phonon usages**: Podcast module, domain (media items)
- **QtScript usages**: Widget API, embedded widget execution
- **Burden**: Replacing these modules touches nearly every part of the application

## Complexity Hotspots

### Files Likely > 1000 Lines
- `UBBoardController.cpp` (~3025 lines)
- `UBGraphicsScene.cpp` (estimated 2000+ lines)
- `UBSvgSubsetAdaptor.cpp` (estimated 2000+ lines)
- `UBSettings.cpp` (estimated 1000+ lines)
- `UBApplicationController.cpp` (estimated 1000+ lines)
- `UBDocumentController.cpp` (estimated 1000+ lines)

### Circular/Tight Dependencies
- `board` ↔ `domain`: Bidirectional dependency
- `core` ↔ `board`: Application knows about board, board knows about application
- `gui` ↔ `board`: Palette manager in board module, palettes in gui module

## Testing Debt

### No Test Infrastructure
- No unit tests found in the repository
- No test framework configured (no Google Test, Catch2, Qt Test references)
- Global statics make mocking impossible without major refactoring
- No CI/CD pipeline definitions found

### Validation Gaps
- Document format compatibility untested
- Cross-platform behavior untested
- Widget API contract untested

## Documentation Debt

### In-Code Documentation
- Sparse inline comments (mostly copyright headers)
- Some TODO comments scattered (`// TODO UB 4.x should be pure virtual`)
- Qt documentation style (Q_PROPERTY descriptions in API)
- No Doxygen or similar documentation system configured

### Architecture Documentation
- No architecture decision records found
- No component interaction diagrams in repository
- Release notes exist but are PDF (not version-controlled text)

## Build System Burden

### External Dependency Path
- `THIRD_PARTY_PATH=../Sankore-ThirdParty` - relative path outside repository
- Not vendored or included as git submodule
- Availability of this directory is uncertain

### Complex Platform Conditionals
- `.pro` file has extensive `macx {}`, `win32 {}`, `linux-* {}` blocks
- Translation bundling logic is complex and repetitive
- SDK path hardcoded (`/Developer/SDKs/MacOSX10.6.sdk`)

## Cross-References
- [Technical Debt Report](../technical-debt-report.md)
- [Outdated Components](outdated-components.md)
- [Remediation Plan](remediation-plan.md)
- [Complexity Analysis](../analysis/complexity-analysis.md)
