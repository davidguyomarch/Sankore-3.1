# Technical Debt Summary

## Overview

Open-Sankoré 2.5.1 is an interactive whiteboard application built on Qt 4.x (circa 2010-2013). The entire technology stack is End-of-Life, making the application impossible to build or maintain on modern platforms without significant modernization effort.

## Debt Categories

### 1. Framework & Runtime Debt (High)
The entire Qt 4.x framework is EOL. Critical modules (QtWebKit, Phonon) have been removed with no backward-compatible replacement path. This represents the single largest barrier to any continued development.

### 2. Platform SDK Debt (High)
- macOS: Targets 10.5/10.6 with 32-bit x86 only. Modern macOS (10.15+) has dropped 32-bit support entirely.
- Windows: Targets Visual Studio 2008. Modern Windows development requires VS2019+.
- Compiler: Code is pre-C++11, not leveraging modern C++ features.

### 3. Dependency Debt (Medium)
- Multiple Qt modules used are deprecated or removed
- Third-party library versions unknown/outdated
- External dependency (`../Sankore-ThirdParty`) may not be available

### 4. Architectural Debt (Low)
- God classes with too many responsibilities
- Tight coupling via global statics
- No unit test infrastructure
- Platform-specific code scattered (not fully abstracted)

## Impact Assessment

| Area | Impact |
|------|--------|
| Buildability | Cannot build on any modern platform without significant changes |
| Security | No security patches for Qt 4.x vulnerabilities |
| Features | Web integration (QtWebKit) completely non-functional |
| Multimedia | Audio/video (Phonon) broken on modern Qt |
| Maintenance | High coupling makes changes risky |
| Recruitment | Developers familiar with Qt 4 increasingly rare |

## Cross-References
- [Technical Debt Report](../technical-debt-report.md)
- [Outdated Components](outdated-components.md)
- [Maintenance Burden](maintenance-burden.md)
- [Remediation Plan](remediation-plan.md)
