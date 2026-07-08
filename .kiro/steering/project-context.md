# Open-Sankoré 3.1 — Project Context

## Overview

Open-Sankoré is a C++/Qt interactive whiteboard application originally built with Qt 4.8.
It is being migrated to Qt 6 and compiled for Windows (x64) and Linux (x64/arm64).

## Architecture

- **Build system**: qmake (`.pro` / `.pri` files)
- **Language**: C++17
- **Framework**: Qt 6.8.3
- **Target platforms**: Windows x64 (MSVC 2022), Linux x64/arm64 (GCC)
- **CI**: GitHub Actions (`build-windows.yml`)
- **Docker dev**: `sankore-qt6` image (Ubuntu 24.04, Qt 6, aarch64)

## Key Directories

```
src/                  # Main application source
  adaptors/           # Import/export (PDF, SVG, CFF, documents)
  board/              # Whiteboard controller and view
  core/               # Application lifecycle, settings
  document/           # Document model
  domain/             # Graphics scene and items
  frameworks/         # Stub headers for missing dependencies
  gui/                # UI windows and widgets
  network/            # HTTP and network features
  pdf/                # PDF rendering
  pdf-merger/         # PDF merge library (built-in, uses zlib)
  web/                # Embedded browser (stubbed)
  tools/              # Drawing tools
plugins/              # CFF adaptor plugin
tests/                # QTest unit tests
resources/            # UI forms, icons, translations
.github/workflows/    # CI pipelines
```

## Build Dependencies

| Dependency | Windows | Linux | Status |
|------------|---------|-------|--------|
| Qt 6.8.3 | aqtinstall | apt | ✅ |
| QuaZip | vcpkg (quazip) | apt (libquazip1-qt6-dev) | ✅ |
| zlib | vcpkg | apt (zlib1g-dev) | ✅ |
| QtWebEngine | Stubbed | Stubbed | ⚠️ Not functional |
| OpenSSL | Not yet | apt (libssl-dev) | ⚠️ Windows pending |
| pdf-merger | Built-in sources | Built-in sources | ✅ Reactivated |

## Stubs (Compilation Shims)

These files in `src/frameworks/` provide empty implementations to compile without real deps:

- `QGraphicsWebView.h` — Replaces QtWebKit QGraphicsWebView
- `QWebEngineView` — Stub QWebEngineView widget
- `QWebEnginePage` — Stub page with WebAction/NavigationType enums
- `QWebEngineSettings` — Stub settings with WebAttribute enum
- `QWebEngineProfile` — Stub profile
- `qtsingleapplication.h` — Single-instance via QLockFile (functional)
- `quazip.h`, `quazipfile.h`, `quazipfileinfo.h` — Only used if vcpkg QuaZip not found

## What Works vs What's Stubbed

| Feature | Status | Notes |
|---------|--------|-------|
| Core whiteboard | ✅ | Drawing, pages, tools |
| Document open/save (.ubz) | ✅ | Via QuaZip (real lib linked) |
| PDF export | ✅ | pdf-merger reactivated |
| Web widgets | ⚠️ Stub | Shows "Web view disabled" |
| Embedded browser | ⚠️ Stub | No navigation/rendering |
| Flash capture | ❌ Removed | Obsolete (Flash dead) |
| Single-instance | ✅ | QLockFile-based (no IPC message) |

## Build Commands

### Windows (CI)
```
qmake Sankore_3.1.pro
nmake release
```

### Linux (Docker)
```
docker run --rm -v $(pwd):/src -w /src sankore-qt6 bash -c 'qmake6 Sankore_3.1.pro && make -j4'
```

## Git Workflow

- Main branch: `master`
- CI triggers on push to `master` and `atx-result-*` branches
- Repo: `git@github.com:davidguyomarch/Sankore-3.1.git`
