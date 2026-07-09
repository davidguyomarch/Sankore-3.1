# Open-Sankoré 3.1 — Project Context

## Overview

Open-Sankoré is a C++/Qt interactive whiteboard application originally built with Qt 4.8.
It has been migrated to Qt 6 and compiles successfully for Windows x64.
Linux builds (x64/arm64) are next.

## Current Status

- **Windows x64 build**: ✅ DONE — Open-Sankore.exe produced via GitHub Actions CI
- **windeployqt**: ✅ Added — artifact is self-contained with Qt DLLs
- **Linux builds**: 🔜 Pending (issues #3, #4)
- **Functional testing**: 🔜 Pending (issue #1)

## Architecture

- **Build system**: qmake (`.pro` / `.pri` files)
- **Language**: C++17
- **Framework**: Qt 6.8.3
- **Target platforms**: Windows x64 (MSVC 2022), Linux x64/arm64 (GCC)
- **CI**: GitHub Actions (`build-windows.yml`)
- **Docker dev**: `sankore-qt6` image (Ubuntu 24.04, Qt 6, aarch64)
- **Issue tracking**: GitHub Issues (https://github.com/davidguyomarch/Sankore-3.1/issues)

## Key Directories

```
src/                  # Main application source
  adaptors/           # Import/export (PDF, SVG, CFF, documents)
  board/              # Whiteboard controller and view
  core/               # Application lifecycle, settings
  document/           # Document model
  domain/             # Graphics scene and items
  frameworks/         # Stub headers + moc wrappers for WebEngine
  gui/                # UI windows and widgets
  network/            # HTTP and network features
  pdf/                # PDF rendering (GraphicsPDFItem, PDFRenderer)
  pdf-merger/         # PDF merge library (built-in, uses zlib)
  web/                # Web controller (stubbed) + OEmbed parser
  podcast/            # Recording (Windows Media disabled, needs Qt Multimedia)
  tools/              # Drawing tools (ruler, compass, etc.)
  desktop/            # Desktop annotation mode
  transition/         # Uniboard→Sankoré migration
plugins/              # CFF adaptor plugin
tests/                # QTest unit tests (6 test classes)
resources/            # UI forms, icons, translations
.github/workflows/    # CI pipelines
notes/                # Local-only notes (gitignored)
```

## Build Dependencies (Windows CI)

| Dependency | Source | Status |
|------------|--------|--------|
| Qt 6.8.3 (+ core5compat, multimedia) | aqtinstall | ✅ |
| QuaZip 1.4 (static) | Built from source (CMake) | ✅ |
| zlib 1.3.1 (static) | Built from source (CMake) | ✅ |
| OpenSSL 3.x | vcpkg (openssl:x64-windows) | ✅ |
| QtWebEngine | Stubbed | ⚠️ Not functional (issue #8) |
| pdf-merger | Built-in sources | ✅ |

## Stubs (Compilation Shims)

Files in `src/frameworks/` providing empty implementations:

- `QWebEngineView_stub.h` / `.cpp` — Stub QWebEngineView with Q_OBJECT (moc'd)
- `QWebEnginePage_stub.h` / `.cpp` — Stub page with WebAction/NavigationType
- `QWebEngineProfile_stub.h` / `.cpp` — Stub profile with settings()
- `QWebEngineSettings` — Stub settings with WebAttribute enum
- `QGraphicsWebView.h` / `.cpp` — Stub QGraphicsWebView (renders "Web view disabled")
- `qtsingleapplication.h` / `.cpp` — Single-instance via QLockFile (functional)

## What Works vs What's Stubbed

| Feature | Status | Notes |
|---------|--------|-------|
| Core whiteboard | ✅ | Drawing, pages, tools |
| Document open/save (.ubz) | ✅ | Via real QuaZip library |
| PDF export | ✅ | pdf-merger reactivated |
| Geometric instruments | ✅ | Ruler, compass, protractor, triangle, aristo |
| Desktop annotation mode | ✅ | Window capture, overlay |
| Web widgets | ⚠️ Stub | Shows "Web view disabled" (issue #8) |
| Embedded browser | ⚠️ Stub | Delegates to system browser |
| Podcast recording | ⚠️ Disabled | Windows Media SDK removed (issue #9) |
| Flash capture | ❌ Removed | Obsolete (Flash dead) |
| Single-instance | ✅ | QLockFile-based (no IPC message passing) |

## Build Commands

### Windows (CI — GitHub Actions)
```
qmake Sankore_3.1.pro
nmake release
windeployqt --release build\win32\release\product\Open-Sankore.exe
```

### Linux (Docker)
```
docker run --rm -v $(pwd):/src -w /src sankore-qt6 bash -c 'qmake6 Sankore_3.1.pro && make -j4'
```

## Git Workflow

- Main branch: `master`
- CI triggers on push to `master` and `atx-result-*` branches
- Repo: `git@github.com:davidguyomarch/Sankore-3.1.git`
- Issues: https://github.com/davidguyomarch/Sankore-3.1/issues

## GitHub Issues (Backlog)

| # | Title | Priority |
|---|-------|----------|
| 1 | Test fonctionnel Windows | Immédiat |
| 2 | Tests unitaires dans le CI Windows | Court terme |
| 3 | Build Linux x64 dans le CI | Court terme |
| 4 | Build Linux ARM64 dans le CI | Moyen terme |
| 5 | Packaging .deb (Debian/Ubuntu) x64+arm64 | Moyen terme |
| 6 | Packaging .rpm (Fedora/RedHat) x64+arm64 | Moyen terme |
| 7 | CI matrix build (5 artefacts en parallèle) | Après #3-6 |
| 8 | Réactiver QtWebEngine (widgets HTML5) | Long terme |
| 9 | Réécrire podcast avec Qt Multimedia | Long terme |

## Distribution Targets

| Platform | Architecture | Format | Status |
|----------|-------------|--------|--------|
| Windows | x64 | .zip (windeployqt) | ✅ Done |
| Linux | x64 | .deb + .rpm | 🔜 Issues #5, #6 |
| Linux | ARM64 | .deb + .rpm | 🔜 Issues #5, #6 |

## Important Notes for Development

- **Do NOT compile locally** — use GitHub Actions CI only (no Windows machine available)
- **Push to master** triggers CI automatically
- **Web module is stubbed** — UBWebController.cpp is a minimal stub, browser/ excluded from build
- **QuaZip stubs deleted** — real QuaZip headers come from C:/quazip via INCLUDEPATH prepend
- **Warnings are non-blocking**: D9025 (/O2 vs /Od) and LNK4217 (UBCFFAdaptor dllimport)
