TARGET = OpenSankoreTests
TEMPLATE = app

CONFIG += testcase console c++17
CONFIG -= app_bundle

QT += core gui widgets testlib

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
HEADERS += stubs/UBCryptoUtils_stub.h
SOURCES += stubs/UBCryptoUtils_stub.cpp

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
           tst_UBCryptoUtils.h \
           tst_UBDocumentProxy.h \
           tst_UBSettings.h

# Test sources
SOURCES += main.cpp \
           tst_UBStringUtils.cpp \
           tst_UBFileSystemUtils.cpp \
           tst_UBGeometryUtils.cpp \
           tst_UBCryptoUtils.cpp \
           tst_UBDocumentProxy.cpp \
           tst_UBSettings.cpp

# Build output
DESTDIR = build
OBJECTS_DIR = build/objects
MOC_DIR = build/moc

# OpenSSL for UBCryptoUtils
win32-msvc* {
    # Static linking to avoid DLL loading issues on CI
    OPENSSL_STATIC_PATH = $$(VCPKG_ROOT)/installed/x64-windows-static
    !isEmpty(OPENSSL_STATIC_PATH):exists($$OPENSSL_STATIC_PATH/lib/libcrypto.lib) {
        INCLUDEPATH += $$OPENSSL_STATIC_PATH/include
        LIBS += -L$$OPENSSL_STATIC_PATH/lib -llibcrypto
        LIBS += -lws2_32 -lcrypt32 -ladvapi32 -luser32
    } else {
        # Fallback to dynamic
        VCPKG_ROOT_PATH = $$(VCPKG_ROOT)
        INCLUDEPATH += $$VCPKG_ROOT_PATH/installed/x64-windows/include
        LIBS += -L$$VCPKG_ROOT_PATH/installed/x64-windows/lib -llibcrypto
    }
} else {
    LIBS += -lcrypto
}

# Code coverage (GCC/Clang only — not available on MSVC)
!win32-msvc* {
    QMAKE_CXXFLAGS += --coverage
    QMAKE_LFLAGS += --coverage
}
