# Prompt AWS Transform — Génération de tests unitaires

## Contexte

Ce prompt est destiné à AWS Transform custom (`atx`) pour générer des tests unitaires
supplémentaires sur le projet Open-Sankoré afin d'augmenter le coverage.

## Prérequis

- Infrastructure de tests déjà en place dans `tests/`
- Framework : QTest (Qt Test)
- Fichier projet : `tests/tests.pro`
- Tests existants : UBStringUtils, UBFileSystemUtils, UBGeometryUtils

---

## Prompt à utiliser

```bash
atx
```

Puis :

```
I want to create a custom transformation to add comprehensive unit tests to a C++/Qt project.

## Project Context

This is "Open-Sankoré", a C++/Qt 4.8 interactive whiteboard application.
- Test framework: QTest (Qt Test)
- Test directory: tests/
- Test project file: tests/tests.pro
- Existing tests cover: UBStringUtils, UBFileSystemUtils, UBGeometryUtils

## Transformation Objective

Add unit tests to achieve maximum code coverage on testable classes. 
The project has heavy GUI dependencies, so focus on classes that can be tested in isolation.

## Classes to Test (priority order)

### 1. Already partially covered — extend coverage:
- src/frameworks/UBFileSystemUtils.h/cpp — add edge cases, error paths
- src/frameworks/UBStringUtils.h/cpp — add boundary tests
- src/frameworks/UBGeometryUtils.h/cpp — add more geometric scenarios

### 2. New test targets (no GUI dependency):
- src/document/UBDocumentProxy.h/cpp — metadata, page count, persistence path
- src/core/UBSettings.h/cpp — settings read/write, directory paths
- src/frameworks/UBCryptoUtils.h/cpp — encrypt/decrypt roundtrip
- src/document/UBDocumentTreeNode (in UBDocumentController.h) — tree operations
- src/core/UBSetting.h/cpp — individual setting get/set

### 3. Testable with mocking:
- src/network/UBHttpGet.h/cpp — signal emission, state management
- src/adaptors/UBExportAdaptor.h/cpp — file dialog helpers
- src/board/UBDrawingController.h/cpp — tool state machine

## Test Conventions

Follow these patterns (from existing tests):

```cpp
// Header: tst_ClassName.h
#ifndef TST_CLASSNAME_H
#define TST_CLASSNAME_H
#include <QtTest>
#include <QObject>

class TestClassName : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();    // optional setup
    void cleanupTestCase(); // optional teardown
    void testMethodName_scenario();
};
#endif

// Source: tst_ClassName.cpp
#include "tst_ClassName.h"
#include "path/to/ClassUnderTest.h"

void TestClassName::testMethodName_scenario()
{
    // Arrange
    // Act
    // Assert with QCOMPARE, QVERIFY, QVERIFY2
}
```

## Important Constraints

- CRITICAL: Each test must be self-contained (no dependency on application state)
- CRITICAL: Use QTemporaryDir for file system tests
- CRITICAL: Register each new test class in tests/main.cpp
- CRITICAL: Add new source files to tests/tests.pro
- Tests must compile standalone without the full application (no UBApplication dependency)
- For classes that depend on UBSettings singleton, create a test-specific initialization
- Use QSignalSpy for testing signal emissions
- Name test methods: test<MethodName>_<scenario>

## Build Command

qmake tests/tests.pro -o tests/Makefile && make -C tests -j8

## Target Coverage

Aim for 80%+ line coverage on the testable utility classes listed above.
Iterate until all tests pass (exit code 0).
```

---

## Exécution

```bash
atx custom def exec \
  -n add-unit-tests \
  -p . \
  -c "cd tests && qmake tests.pro && make -j8 && ./build/OpenSankoreTests"
```

---

## Notes

- L'agent va itérer : écrire des tests → compiler → corriger → recompiler
- Le flag `-c` avec l'exécution des tests permet à l'agent de vérifier que les tests passent
- Pour les classes avec dépendances lourdes (UBSettings, UBDocumentProxy), il faudra peut-être créer des stubs/mocks
- Commencer en mode interactif pour guider l'agent sur les premiers fichiers
