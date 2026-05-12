# ATXDocumentation - Open-Sankoré 2.5.1

## Navigation

### Quick Links
- 📋 [Project Overview](project-overview.md)
- ⚠️ [Technical Debt Report](technical-debt-report.md) *(Start here for actionable findings)*

---

### 🏗️ Architecture
- [System Overview](architecture/system-overview.md) - Technology stack, high-level architecture
- [Components](architecture/components.md) - Major components and their roles
- [Dependencies](architecture/dependencies.md) - Internal and external dependency mapping
- [Patterns](architecture/patterns.md) - Design patterns and anti-patterns

### 🔄 Behavior
- [Business Logic](behavior/business-logic.md) - Core business rules and processes
- [Workflows](behavior/workflows.md) - Application workflows and user journeys
- [Decision Logic](behavior/decision-logic.md) - Decision trees and branching logic
- [Error Handling](behavior/error-handling.md) - Exception patterns and recovery

### 📖 Reference
- [Program Structure](reference/program-structure.md) - Complete class hierarchies
- [Interfaces](reference/interfaces.md) - Interface definitions and contracts
- [Data Models](reference/data-models.md) - Type definitions and relationships
- [API Reference](reference/api-reference.md) - Public APIs (C++ and JavaScript)
- [Modules](reference/modules.md) - Module organization and responsibilities

### 📊 Analysis
- [Code Metrics](analysis/code-metrics.md) - Size and complexity measurements
- [Complexity Analysis](analysis/complexity-analysis.md) - Hotspots and coupling
- [Dependency Analysis](analysis/dependency-analysis.md) - Dependency health and mapping
- [Security Patterns](analysis/security-patterns.md) - Security implementations
- [Tech Debt](analysis/tech-debt.md) - Technical debt assessment

### 🔧 Technical Debt
- [Summary](technical-debt/summary.md) - Overview of all debt findings
- [Outdated Components](technical-debt/outdated-components.md) - EOL and deprecated items
- [Maintenance Burden](technical-debt/maintenance-burden.md) - High-cost maintenance areas
- [Remediation Plan](technical-debt/remediation-plan.md) - Prioritized fix plan

### 📐 Diagrams
- [Structural](diagrams/structural/README.md) - Component and class diagrams
- [Behavioral](diagrams/behavioral/README.md) - Sequence and activity diagrams
- [Architecture](diagrams/architecture/README.md) - System context and deployment

### 🚀 Migration
- [Component Order](migration/component-order.md) - Migration sequence
- [Test Specifications](migration/test-specifications.md) - Test cases for validation
- [Validation Criteria](migration/validation-criteria.md) - Success criteria

### 🔬 Specialized
- [Specialized Topics](specialized/README.md) - UI patterns, document formats, tools

---

## About This Documentation

Generated via comprehensive static code analysis of the Open-Sankoré 2.5.1 codebase (~125K LOC C++/Qt). All analysis performed without building or executing the code.

**Key Finding**: This project relies on End-of-Life technology (Qt 4.x, macOS 10.5 SDK) and cannot be built on modern systems. No AWS-managed transformations apply to this C++/Qt codebase. See the [Technical Debt Report](technical-debt-report.md) for detailed remediation guidance.
