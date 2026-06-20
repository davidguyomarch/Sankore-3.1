# Technical Debt Report

## 🎯 AWS Transformation Recommendation

### **RECOMMENDED TRANSFORMATIONS: None**

This is a C++/Qt 4.x desktop application. None of the available AWS-managed transformations apply, as they target Java, Python, Node.js, Angular, and Vue.js ecosystems. The recommended next steps are to modernize the Qt framework from Qt 4 to Qt 6, replace removed modules (QtWebKit → QWebEngine, Phonon → Qt Multimedia), and update the build system from qmake to CMake.

---

## Executive Summary

Open-Sankoré 2.5.1 carries **critical technical debt** that renders it effectively unmaintainable and undeployable on modern systems. The project was last actively developed in 2013-2014 and relies on an End-of-Life framework (Qt 4.x), deprecated platform SDKs (macOS 10.5/10.6), and removed Qt modules (QtWebKit, Phonon, QtXmlPatterns). The application cannot be compiled with modern toolchains without significant intervention.

## Severity Summary

| Severity | Count | Category |
|----------|-------|----------|
| **High** | 6 | EOL/deprecated runtimes and frameworks |
| **Medium** | 4 | Outdated runtime dependencies |
| **Low** | 3 | Code quality and architectural issues |

## Critical Issues (Prioritized)

1. **Qt 4.x Framework (EOL since 2015)**
   - Qt 4 reached End-of-Life in 2015
   - No security patches or bug fixes available
   - Current Qt is version 6.x (Qt 5 also approaching EOL)
   - Impact: Cannot build on modern systems without legacy toolchains

2. **QtWebKit Module (Removed)**
   - Removed from Qt in version 5.6
   - Based on obsolete WebKit engine
   - Replacement: QWebEngine (Chromium-based) in Qt 5.4+
   - Impact: Web browser features completely non-functional on modern Qt

3. **Phonon Multimedia Framework (Removed)**
   - Removed from Qt in version 5.0
   - Replacement: Qt Multimedia module
   - Impact: All audio/video playback broken on modern Qt

4. **macOS 10.5/10.6 SDK (EOL)**
   - Targets deployment on macOS 10.5 (Leopard, 2007)
   - Uses MacOSX10.6 SDK (no longer available in modern Xcode)
   - 32-bit x86 only (macOS dropped 32-bit in 10.15 Catalina, 2019)
   - Carbon APIs used (deprecated, removed in 64-bit)
   - Impact: Cannot build on any macOS since Catalina

5. **Visual Studio 2008 (VC9) Build Target**
   - VS2008 is End-of-Life
   - Pre-C++11 compiler
   - Impact: Cannot build on modern Windows without retooling

6. **QtXmlPatterns Module (Removed in Qt 6)**
   - XQuery/XPath module removed in Qt 6
   - Impact: Requires replacement for Qt 6 migration

### Medium Severity — Outdated Dependencies

7. **QtScript Module (Deprecated)**
   - Deprecated since Qt 5.5, removed in Qt 6
   - Replacement: QJSEngine
   - Impact: Widget JavaScript integration needs rewrite

8. **QHttp/QFtp Classes (Removed)**
   - Used in `UBApplicationController` for update checking
   - Removed in Qt 5.0
   - Replacement: QNetworkAccessManager
   - Impact: Software update feature broken

9. **QPlastiqueStyle (Removed)**
   - Used as application style base class (`UBStyle : QPlastiqueStyle`)
   - Removed in Qt 5.0
   - Impact: Application styling broken on modern Qt

10. **QuaZIP Library (Version Unknown)**
    - External dependency with version unspecified
    - May require update for modern Qt/zlib compatibility

### Low Severity — Code Quality and Architecture

11. **God Class Anti-Pattern**
    - `UBBoardController` (~3025 lines, 200+ methods)
    - `UBGraphicsScene` (very large, many responsibilities)
    - Impact: Difficult maintenance, high coupling

12. **Global Static Access Pattern**
    - `UBApplication::boardController`, `UBApplication::mainWindow` etc.
    - Makes unit testing nearly impossible
    - Impact: No test isolation possible

13. **qmake Build System (Deprecated)**
    - Qt has deprecated qmake in favor of CMake
    - Modern Qt 6 primarily supports CMake
    - Impact: Build system migration needed for Qt upgrade

## Navigation

- [Detailed Technical Debt Summary](technical-debt/summary.md)
- [Outdated Components](technical-debt/outdated-components.md)
- [Maintenance Burden](technical-debt/maintenance-burden.md)
- [Remediation Plan](technical-debt/remediation-plan.md)

## Cross-References
- [Architecture Overview](architecture/system-overview.md)
- [Dependencies](architecture/dependencies.md)
- [Analysis: Tech Debt](analysis/tech-debt.md)
