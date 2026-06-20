∏# Project Overview

## Open-Sankoré 2.5.1

**Open-Sankoré** is an open-source interactive whiteboard application designed for digital education. Originally developed as "Uniboard" and later released as open-source by GIP ENA (Groupement d'Intérêt Public pour l'Education Numérique en Afrique), it provides teachers with tools for creating interactive lessons on digital whiteboards.

## Key Features

- **Interactive Whiteboard**: Freehand drawing, shapes, text with pressure-sensitive stylus support
- **Multi-Media Support**: Images, videos, audio, PDF, SVG on the board
- **Web Integration**: Embedded browser for web content, W3C widget support
- **Document Management**: Multi-page documents with thumbnail navigation
- **Geometry Tools**: Ruler, compass, protractor, triangle for mathematics
- **Screen Recording**: Podcast/screencast recording with YouTube publishing
- **Desktop Annotation**: Annotate over any desktop content
- **Export Formats**: PDF, IWB/CFF, web format export
- **Multi-Language**: 36+ language translations
- **Multi-Screen**: Dual display (teacher control + audience presentation)

## Technology Summary

| Aspect | Technology |
|--------|-----------|
| Language | C++ (pre-C++11) |
| Framework | Qt 4.x (End-of-Life) |
| Build System | qmake |
| Platforms | macOS (32-bit x86), Windows (VC9), Linux |
| LOC | ~125,772 lines |
| Modules | 19 source modules + 1 plugin |

## Current Status

⚠️ **This project is no longer actively maintained.** The technology stack (Qt 4, macOS 10.5 SDK, Visual Studio 2008) is entirely End-of-Life and the application cannot be compiled on modern systems without significant modification. See the [Technical Debt Report](technical-debt-report.md) for detailed analysis.

## Documentation Structure

This documentation was generated through comprehensive static code analysis:

- **[Architecture](architecture/)** - System design, components, dependencies, patterns
- **[Behavior](behavior/)** - Business logic, workflows, decision trees
- **[Reference](reference/)** - Class hierarchies, APIs, modules
- **[Analysis](analysis/)** - Code metrics, complexity, security
- **[Technical Debt](technical-debt/)** - Outdated components, remediation plan
- **[Diagrams](diagrams/)** - Visual architecture and behavior diagrams
- **[Migration](migration/)** - Migration planning and validation
- **[Specialized](specialized/)** - UI patterns, document formats, tools

## Cross-References
- [Technical Debt Report](technical-debt-report.md)
- [System Overview](architecture/system-overview.md)
- [README](README.md)
