/****************************************************************************
** Meta object code from reading C++ file 'tst_UBDocumentProxy.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tst_UBDocumentProxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_UBDocumentProxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestUBDocumentProxy_t {
    const uint offsetsAndSize[32];
    char stringdata0[340];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestUBDocumentProxy_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestUBDocumentProxy_t qt_meta_stringdata_TestUBDocumentProxy = {
    {
QT_MOC_LITERAL(0, 19), // "TestUBDocumentProxy"
QT_MOC_LITERAL(20, 12), // "initTestCase"
QT_MOC_LITERAL(33, 0), // ""
QT_MOC_LITERAL(34, 15), // "cleanupTestCase"
QT_MOC_LITERAL(50, 18), // "testMetadataGetSet"
QT_MOC_LITERAL(69, 23), // "testPageCountOperations"
QT_MOC_LITERAL(93, 31), // "testPersistencePathConstruction"
QT_MOC_LITERAL(125, 28), // "testUuidGenerationUniqueness"
QT_MOC_LITERAL(154, 19), // "testCopyConstructor"
QT_MOC_LITERAL(174, 23), // "testDefaultDocumentSize"
QT_MOC_LITERAL(198, 16), // "testDocumentName"
QT_MOC_LITERAL(215, 19), // "testTheSameDocument"
QT_MOC_LITERAL(235, 29), // "testDocumentDateAndLastUpdate"
QT_MOC_LITERAL(265, 26), // "testDefaultImageBackground"
QT_MOC_LITERAL(292, 17), // "testExternalFiles"
QT_MOC_LITERAL(310, 29) // "testExternalFilesClear_noLeak"

    },
    "TestUBDocumentProxy\0initTestCase\0\0"
    "cleanupTestCase\0testMetadataGetSet\0"
    "testPageCountOperations\0"
    "testPersistencePathConstruction\0"
    "testUuidGenerationUniqueness\0"
    "testCopyConstructor\0testDefaultDocumentSize\0"
    "testDocumentName\0testTheSameDocument\0"
    "testDocumentDateAndLastUpdate\0"
    "testDefaultImageBackground\0testExternalFiles\0"
    "testExternalFilesClear_noLeak"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestUBDocumentProxy[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    0,  110,    2, 0x08,   13 /* Private */,
      15,    0,  111,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestUBDocumentProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestUBDocumentProxy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->testMetadataGetSet(); break;
        case 3: _t->testPageCountOperations(); break;
        case 4: _t->testPersistencePathConstruction(); break;
        case 5: _t->testUuidGenerationUniqueness(); break;
        case 6: _t->testCopyConstructor(); break;
        case 7: _t->testDefaultDocumentSize(); break;
        case 8: _t->testDocumentName(); break;
        case 9: _t->testTheSameDocument(); break;
        case 10: _t->testDocumentDateAndLastUpdate(); break;
        case 11: _t->testDefaultImageBackground(); break;
        case 12: _t->testExternalFiles(); break;
        case 13: _t->testExternalFilesClear_noLeak(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestUBDocumentProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestUBDocumentProxy.offsetsAndSize,
    qt_meta_data_TestUBDocumentProxy,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestUBDocumentProxy_t
, QtPrivate::TypeAndForceComplete<TestUBDocumentProxy, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestUBDocumentProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestUBDocumentProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestUBDocumentProxy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestUBDocumentProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
