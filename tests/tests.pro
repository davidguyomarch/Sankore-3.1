TARGET = OpenSankoreTests
TEMPLATE = app

CONFIG += testcase console c++11
CONFIG -= app_bundle

QT += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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

# Test headers
HEADERS += tst_UBStringUtils.h \
           tst_UBFileSystemUtils.h \
           tst_UBGeometryUtils.h

# Test sources
SOURCES += main.cpp \
           tst_UBStringUtils.cpp \
           tst_UBFileSystemUtils.cpp \
           tst_UBGeometryUtils.cpp

# Build output
DESTDIR = build
OBJECTS_DIR = build/objects
MOC_DIR = build/moc
