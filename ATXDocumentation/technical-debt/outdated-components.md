# Outdated Components

## End-of-Life Frameworks (High Severity)

### Qt 4.x Framework
- **Current**: Qt 4.x (exact version not specified, likely 4.7 or 4.8)
- **EOL Date**: December 2015
- **Latest Available**: Qt 6.7+ (2024)
- **Gap**: ~10 years behind current
- **Impact**: No security patches, cannot build with modern compilers
- **Evidence**: Uses `QPlastiqueStyle`, `#include <QtGui>` as monolithic include, `Q_WS_MAC`/`Q_WS_WIN` macros (removed in Qt 5)

### QtWebKit
- **Current**: QtWebKit (bundled with Qt 4)
- **Removed**: Qt 5.6 (2016)
- **Replacement**: Qt WebEngine (Chromium-based)
- **Impact**: Entire web browser feature set non-functional
- **Evidence**: `QT += webkit`, `#include <QtWebKit>`, `QWebSettings`, `QWebPage`

### Phonon Multimedia
- **Current**: Phonon (Qt 4 multimedia backend)
- **Removed**: Qt 5.0 (2012)
- **Replacement**: Qt Multimedia (QMediaPlayer, QAudioOutput)
- **Impact**: All audio/video playback broken
- **Evidence**: `QT += phonon`

### QtXmlPatterns
- **Current**: QtXmlPatterns (XQuery/XPath)
- **Removed**: Qt 6.0 (2020)
- **Replacement**: Custom XPath or third-party library
- **Evidence**: `QT += xmlpatterns`

### QtScript
- **Current**: QtScript (JavaScript engine)
- **Deprecated**: Qt 5.5 (2015)
- **Removed**: Qt 6.0 (2020)
- **Replacement**: QJSEngine (Qt QML module)
- **Evidence**: `QT += script`

## End-of-Life Platform SDKs (High Severity)

### macOS SDK
- **Current**: MacOSX 10.6 SDK, deployment target 10.5
- **EOL**: macOS 10.6 support ended 2014
- **32-bit Dropped**: macOS 10.15 Catalina (2019)
- **Carbon APIs**: Deprecated/removed in 64-bit mode
- **Impact**: Cannot build on any Mac since Catalina
- **Evidence**: `QMAKE_MAC_SDK = "/Developer/SDKs/MacOSX10.6.sdk"`, `CONFIG += x86` (32-bit only)

### Windows Toolchain
- **Current**: Visual Studio 2008 (VC9)
- **EOL**: VS2008 extended support ended 2018
- **Impact**: Pre-C++11, no modern language features
- **Evidence**: `release.win7.vc9.bat`, MSVC-specific flags

## Deprecated Qt APIs in Use (Medium Severity)

| API | Status | Replacement |
|-----|--------|-------------|
| `QHttp` | Removed Qt 5.0 | QNetworkAccessManager |
| `QFtp` | Removed Qt 5.0 | QNetworkAccessManager |
| `QPlastiqueStyle` | Removed Qt 5.0 | QProxyStyle / Fusion |
| `Q_WS_MAC` / `Q_WS_WIN` | Removed Qt 5.0 | Q_OS_MAC / Q_OS_WIN |
| `QApplication::setGraphicsSystem()` | Removed Qt 5.0 | Automatic |
| `QGraphicsScene::drawItems()` | Deprecated Qt 4.6 | Individual item paint |
| `QPixmapCache::setCacheLimit()` | Still available | Still available |

## Third-Party Libraries (Medium Severity)

### QuaZIP
- **Version**: Unknown (external, version not specified in project)
- **Location**: `../Sankore-ThirdParty/quazip/`
- **Risk**: May not compile with modern Qt/zlib
- **Note**: Modern QuaZIP versions available (1.x) but API may differ

### QtSingleApplication
- **Source**: Trolltech (pre-Nokia acquisition)
- **Status**: Abandoned upstream
- **Replacement**: Qt Solutions / custom implementation
- **Location**: `../Sankore-ThirdParty/trolltech/singleapplication/`

### OpenSSL (libcrypto)
- **Version**: Unknown (system-provided)
- **Risk**: System OpenSSL versions vary; API changes between 1.x and 3.x
- **Usage**: UBCryptoUtils for document encryption/hashing

## Build System (Low Severity)

### qmake
- **Status**: Deprecated by Qt in favor of CMake
- **Impact**: Qt 6 primarily supports CMake; qmake has limited Qt 6 support
- **Migration**: Full CMakeLists.txt needed for modern Qt

## Cross-References
- [Technical Debt Report](../technical-debt-report.md)
- [Summary](summary.md)
- [Remediation Plan](remediation-plan.md)
