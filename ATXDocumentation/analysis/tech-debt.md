# Technical Debt (Analysis)

## Comprehensive Assessment

This file consolidates technical debt findings from static code analysis of Open-Sankoré 2.5.1.

## Debt by Category

### Category 1: EOL Runtime & Framework (High)

| Component | Current | Required | Severity |
|-----------|---------|----------|----------|
| Qt Framework | 4.x (EOL 2015) | Qt 6.x | High |
| QtWebKit | Bundled Qt 4 | Qt WebEngine | High |
| Phonon | Qt 4 bundled | Qt Multimedia | High |
| macOS SDK | 10.6 SDK | macOS 14+ SDK | High |
| MSVC | 2008 (VC9) | 2022+ | High |
| QtXmlPatterns | Available | Removed Qt 6 | High |

### Category 2: Deprecated APIs (Medium)

| API | File(s) | Replacement |
|-----|---------|-------------|
| QHttp | UBApplicationController | QNetworkAccessManager |
| QFtp | UBApplicationController | QNetworkAccessManager |
| QPlastiqueStyle | UBApplication | Fusion/QProxyStyle |
| Q_WS_MAC/Q_WS_WIN | Multiple | Q_OS_MACOS/Q_OS_WIN |
| QtScript | api/ module | QJSEngine |
| drawItems() override | UBGraphicsScene | Per-item rendering |

### Category 3: Code Quality (Low)

| Issue | Location | Impact |
|-------|----------|--------|
| God class (3024 lines) | UBBoardController | High coupling, hard to maintain |
| God file (4245 lines) | UBSvgSubsetAdaptor | Format changes are risky |
| Global statics | UBApplication | No testability |
| No tests | Entire codebase | No safety net for changes |
| Pre-C++11 code | Entire codebase | Manual memory management |
| Scattered platform code | Multiple files | Maintenance multiplier |

## Quantitative Debt Indicators

| Metric | Value | Threshold | Status |
|--------|-------|-----------|--------|
| Files > 2000 LOC | 4 | 0 | ❌ Over |
| Files > 1000 LOC | 16 | 5 | ❌ Over |
| Removed Qt modules | 4 | 0 | ❌ Critical |
| Deprecated Qt APIs | 6+ | 0 | ⚠️ Warning |
| Test coverage | 0% | 60% | ❌ Critical |
| Framework version gap | ~10 years | <2 years | ❌ Critical |

## Debt Trend

The project has been accumulating debt since its last active development (2013-2014). No maintenance has addressed framework deprecations. The debt is now at a level where remediation requires a major rewrite effort rather than incremental fixes.

## Cross-References
- [Technical Debt Report](../technical-debt-report.md)
- [Outdated Components](../technical-debt/outdated-components.md)
- [Complexity Analysis](complexity-analysis.md)
- [Code Metrics](code-metrics.md)
