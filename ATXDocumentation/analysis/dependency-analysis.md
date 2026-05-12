# Dependency Analysis

## External Dependencies

### Qt Framework Modules
| Module | Import Statement | Usage Area |
|--------|-----------------|------------|
| QtGui | `#include <QtGui>` | All UI components |
| QtWebKit | `#include <QtWebKit>` | Web browser, widget rendering |
| QtSvg | `QT += svg` | SVG rendering |
| QtNetwork | `QT += network` | HTTP, downloads |
| Phonon | `QT += phonon` | Media playback |
| QtXml | `QT += xml` | Document parsing |
| QtScript | `QT += script` | Widget JS engine |
| QtXmlPatterns | `QT += xmlpatterns` | XPath queries |
| QAxContainer | Windows only | ActiveX hosting |

### System Libraries
| Library | Platform | Usage |
|---------|----------|-------|
| libcrypto (OpenSSL) | All | UBCryptoUtils - symmetric encryption |
| libX11 | Linux | Window management |
| Foundation.framework | macOS | Platform utilities |
| Carbon.framework | macOS | Event handling (deprecated) |

### Third-Party Libraries
| Library | Path | Dependency Type |
|---------|------|----------------|
| QuaZIP | `../Sankore-ThirdParty/quazip/` | Compile-time, linked |
| QtSingleApplication | `../Sankore-ThirdParty/trolltech/singleapplication/` | Compile-time, linked |

## Internal Module Dependency Matrix

| Module → Depends On | core | board | domain | gui | adaptors | frameworks | network | web | document |
|---------------------|------|-------|--------|-----|----------|------------|---------|-----|----------|
| **core** | — | ○ | ○ | ○ | ○ | ● | ○ | ○ | ○ |
| **board** | ● | — | ● | ● | ● | ● | ● | ○ | ● |
| **domain** | ● | ○ | — | ○ | ○ | ● | ○ | ○ | ○ |
| **gui** | ● | ● | ● | — | ○ | ○ | ○ | ○ | ● |
| **adaptors** | ● | ○ | ● | ○ | — | ● | ○ | ○ | ● |
| **web** | ● | ○ | ○ | ● | ○ | ○ | ● | — | ○ |
| **network** | ● | ○ | ○ | ○ | ○ | ○ | — | ○ | ○ |
| **podcast** | ● | ● | ○ | ● | ○ | ○ | ○ | ○ | ○ |
| **tools** | ● | ○ | ○ | ○ | ○ | ● | ○ | ○ | ○ |
| **document** | ● | ○ | ● | ● | ● | ○ | ○ | ○ | — |
| **desktop** | ● | ● | ○ | ● | ○ | ○ | ○ | ○ | ○ |

● = Direct dependency, ○ = No dependency

## Dependency Criticality

### Critical Path Dependencies
1. **Qt Framework** → Everything depends on Qt; migration blocks all other work
2. **UBApplication (statics)** → Global access point; all modules depend on it
3. **UBGraphicsScene** → All board operations route through scene
4. **UBPersistenceManager** → All save/load operations
5. **UBSvgSubsetAdaptor** → Document format; all item types must be handled

### Fragile Dependencies
- `../Sankore-ThirdParty/` → External path, not version-controlled with project
- Platform SDK paths (hardcoded `/Developer/SDKs/MacOSX10.6.sdk`)
- Implicit Qt version requirements (no minimum version specified)

## Dependency Health Assessment

| Dependency | Health | Risk |
|-----------|--------|------|
| Qt 4.x | ❌ Dead | Cannot receive updates |
| QtWebKit | ❌ Dead | Completely removed |
| Phonon | ❌ Dead | Completely removed |
| QtScript | ❌ Dead | Removed in Qt 6 |
| QtXmlPatterns | ⚠️ Dying | Removed in Qt 6 |
| OpenSSL | ⚠️ Version-dependent | API breaks between versions |
| QuaZIP | ⚠️ Unknown version | May need update |
| QtSingleApplication | ❌ Abandoned | No maintenance |
| qmake | ⚠️ Deprecated | Still functional but not recommended |

## Cross-References
- [Code Metrics](code-metrics.md)
- [Architecture Dependencies](../architecture/dependencies.md)
- [Outdated Components](../technical-debt/outdated-components.md)
