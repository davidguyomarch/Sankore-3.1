TARGET = OpenSankoreTests
TEMPLATE = app

CONFIG += testcase console c++17
CONFIG -= app_bundle

QT += core gui testlib

# Skip crypto tests on MSVC (OpenSSL DLL loading issues on CI)
win32-msvc*: DEFINES += SKIP_CRYPTO_TESTS

# Paths
INCLUDEPATH += ../src
INCLUDEPATH += .

# We only compile the utility sources under test (no app dependencies)
# This avoids pulling in UBApplication, UBPersistenceManager, etc.

# Headers under test
HEADERS += ../src/frameworks/UBStringUtils.h \
           ../src/frameworks/UBGeometryUtils.h \
           ../src/core/UB.h

# Sources under test (only self-contained utilities)
SOURCES += ../src/frameworks/UBStringUtils.cpp \
           ../src/frameworks/UBGeometryUtils.cpp

# For UBFileSystemUtils we need a minimal version without OpenSSL/QuaZip deps
# We provide a test stub instead
HEADERS += stubs/UBFileSystemUtils_stub.h
SOURCES += stubs/UBFileSystemUtils_stub.cpp

# UBCryptoUtils stub (bypasses UBApplication singleton)
!win32-msvc* {
    HEADERS += stubs/UBCryptoUtils_stub.h
    SOURCES += stubs/UBCryptoUtils_stub.cpp
}

# UBDocumentProxy stubs (UBSettings, UBFeature, UBDocumentManager, UBDocumentProxy)
HEADERS += stubs/UBSettings_stub.h \
           stubs/UBFeature_stub.h \
           stubs/UBDocumentManager_stub.h \
           stubs/UBDocumentProxy_stub.h
SOURCES += stubs/UBSettings_stub.cpp \
           stubs/UBDocumentManager_stub.cpp \
           stubs/UBDocumentProxy_stub.cpp

# UBPlatformUtils stub
HEADERS += stubs/UBPlatformUtils_stub.h
SOURCES += stubs/UBPlatformUtils_stub.cpp

# Test headers
HEADERS += tst_UBStringUtils.h \
           tst_UBFileSystemUtils.h \
           tst_UBGeometryUtils.h \
           tst_UBDocumentProxy.h \
           tst_UBSettings.h

!win32-msvc* {
    HEADERS += tst_UBCryptoUtils.h
}

# Test sources
SOURCES += main.cpp \
           tst_UBStringUtils.cpp \
           tst_UBFileSystemUtils.cpp \
           tst_UBGeometryUtils.cpp \
           tst_UBDocumentProxy.cpp \
           tst_UBSettings.cpp

!win32-msvc* {
    SOURCES += tst_UBCryptoUtils.cpp
}

# Build output
DESTDIR = build
OBJECTS_DIR = build/objects
MOC_DIR = build/moc

# OpenSSL for UBCryptoUtils (Linux/Mac only — skipped on Windows CI)
!win32-msvc* {
    LIBS += -lcrypto
}

# Code coverage (GCC/Clang only — not available on MSVC)
!win32-msvc* {
    QMAKE_CXXFLAGS += --coverage
    QMAKE_LFLAGS += --coverage
}
