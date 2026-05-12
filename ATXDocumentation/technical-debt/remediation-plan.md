# Remediation Plan

## Priority 1: Framework Modernization (High Severity)

### 1.1 Qt 4 → Qt 6 Migration
**Objective**: Migrate from Qt 4.x to Qt 6.x (latest LTS)

**Approach**: Incremental migration through Qt 5 as intermediate step

**Phase A: Qt 4 → Qt 5 (Critical Path)**
- Replace `Q_WS_MAC`/`Q_WS_WIN` → `Q_OS_MACOS`/`Q_OS_WIN`
- Replace `#include <QtGui>` monolithic → specific module includes
- Replace `QPlastiqueStyle` → `QProxyStyle` with Fusion base
- Remove `QHttp`/`QFtp` → use `QNetworkAccessManager` exclusively
- Replace `QApplication::setGraphicsSystem()` calls → remove (automatic in Qt 5)
- Update `QGraphicsScene::drawItems()` override → use item-level rendering

**Phase B: Module Replacements**
- Replace QtWebKit → Qt WebEngine (QWebEngineView, QWebEnginePage)
  - Note: API is significantly different; web/ module needs near-complete rewrite
- Replace Phonon → Qt Multimedia (QMediaPlayer, QVideoWidget)
  - Podcast module needs new encoder backends
- Replace QtScript → QJSEngine
  - Widget API bridge needs rewrite
- Replace QtXmlPatterns → custom or third-party XPath

**Phase C: Qt 5 → Qt 6**
- Remove QtXmlPatterns usage
- Adapt to QList/QVector unification
- Update signal/slot syntax to new style
- Address remaining deprecation warnings

### 1.2 Build System Modernization
**Objective**: Migrate from qmake to CMake

**Steps:**
1. Create `CMakeLists.txt` root project file
2. Create per-module `CMakeLists.txt` files
3. Configure `find_package(Qt6 COMPONENTS ...)` 
4. Vendor third-party dependencies or use package manager (vcpkg/conan)
5. Remove hardcoded SDK paths
6. Add CPack for packaging

### 1.3 Platform SDK Updates
**Objective**: Support modern platforms

**macOS:**
- Remove 32-bit constraint (`CONFIG += x86`)
- Target macOS 12+ (arm64 + x86_64)
- Replace Carbon APIs → Cocoa/AppKit
- Use modern Xcode SDK

**Windows:**
- Target MSVC 2022 / MinGW
- Enable C++17 standard minimum
- Remove VC9-specific flags

**Linux:**
- Modernize compiler requirements (GCC 12+ / Clang 15+)
- Use pkg-config for system dependencies

## Priority 2: Dependency Updates (Medium Severity)

### 2.1 QuaZIP Update
- Update to QuaZIP 1.x (Qt 6 compatible)
- Vendor as git submodule or use vcpkg

### 2.2 Single Application
- Replace Trolltech QtSingleApplication with modern alternative
- Options: Qt RunGuard, QSharedMemory-based lock, or KDE KDBusService

### 2.3 OpenSSL Compatibility
- Ensure compatibility with OpenSSL 3.x API
- Update UBCryptoUtils for new API (EVP-only, deprecation of low-level APIs)

## Priority 3: Architecture Improvements (Low Severity)

### 3.1 Decompose God Classes
- Split `UBBoardController` into:
  - `UBPageController` (page navigation)
  - `UBContentController` (content addition)
  - `UBViewportController` (zoom/scroll)
  - Keep `UBBoardController` as thin coordinator
- Split `UBGraphicsScene` into:
  - Scene (item container)
  - InputHandler (drawing input processing)
  - BackgroundManager (background rendering)

### 3.2 Remove Global Static Access
- Introduce dependency injection for controllers
- Use service locator pattern as intermediate step
- Enable unit testing with mock objects

### 3.3 Add Test Infrastructure
- Add Qt Test or Google Test framework
- Start with unit tests for `frameworks/` utilities (no dependencies)
- Add integration tests for document persistence
- Add widget API contract tests

### 3.4 Modernize C++
- Enable C++17 standard minimum
- Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) instead of raw `new`/`delete`
- Use range-based for loops, auto, structured bindings
- Replace manual memory management with RAII patterns

## Recommended Execution Order

1. **Build system** (CMake) - enables all subsequent work
2. **Qt 5 migration** - minimum viable modern build
3. **Platform SDK updates** - enables building on current systems
4. **Qt module replacements** (WebEngine, Multimedia, QJSEngine) - restores features
5. **Qt 6 migration** - reach current framework
6. **Dependency updates** - ensure all libraries compatible
7. **Architecture improvements** - long-term maintainability

## Cross-References
- [Technical Debt Report](../technical-debt-report.md)
- [Outdated Components](outdated-components.md)
- [Maintenance Burden](maintenance-burden.md)
- [Migration: Component Order](../migration/component-order.md)
