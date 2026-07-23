/****************************************************************************
** Meta object code from reading C++ file 'tst_UBVersion.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tst_UBVersion.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_UBVersion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestUBVersion_t {
    const uint offsetsAndSize[34];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestUBVersion_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestUBVersion_t qt_meta_stringdata_TestUBVersion = {
    {
QT_MOC_LITERAL(0, 13), // "TestUBVersion"
QT_MOC_LITERAL(14, 22), // "testDefaultConstructor"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 24), // "testValidVersionTwoParts"
QT_MOC_LITERAL(63, 26), // "testValidVersionThreeParts"
QT_MOC_LITERAL(90, 21), // "testValidVersionAlpha"
QT_MOC_LITERAL(112, 20), // "testValidVersionBeta"
QT_MOC_LITERAL(133, 18), // "testValidVersionRC"
QT_MOC_LITERAL(152, 18), // "testInvalidVersion"
QT_MOC_LITERAL(171, 22), // "testComparisonLessThan"
QT_MOC_LITERAL(194, 25), // "testComparisonGreaterThan"
QT_MOC_LITERAL(220, 19), // "testComparisonEqual"
QT_MOC_LITERAL(240, 31), // "testComparisonDifferentPlatform"
QT_MOC_LITERAL(272, 28), // "testComparisonDifferentMajor"
QT_MOC_LITERAL(301, 28), // "testComparisonDifferentStage"
QT_MOC_LITERAL(330, 12), // "testToString"
QT_MOC_LITERAL(343, 19) // "testToStringInvalid"

    },
    "TestUBVersion\0testDefaultConstructor\0"
    "\0testValidVersionTwoParts\0"
    "testValidVersionThreeParts\0"
    "testValidVersionAlpha\0testValidVersionBeta\0"
    "testValidVersionRC\0testInvalidVersion\0"
    "testComparisonLessThan\0"
    "testComparisonGreaterThan\0"
    "testComparisonEqual\0"
    "testComparisonDifferentPlatform\0"
    "testComparisonDifferentMajor\0"
    "testComparisonDifferentStage\0"
    "testToString\0testToStringInvalid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestUBVersion[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    0,  110,    2, 0x08,    7 /* Private */,
       9,    0,  111,    2, 0x08,    8 /* Private */,
      10,    0,  112,    2, 0x08,    9 /* Private */,
      11,    0,  113,    2, 0x08,   10 /* Private */,
      12,    0,  114,    2, 0x08,   11 /* Private */,
      13,    0,  115,    2, 0x08,   12 /* Private */,
      14,    0,  116,    2, 0x08,   13 /* Private */,
      15,    0,  117,    2, 0x08,   14 /* Private */,
      16,    0,  118,    2, 0x08,   15 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void TestUBVersion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestUBVersion *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testDefaultConstructor(); break;
        case 1: _t->testValidVersionTwoParts(); break;
        case 2: _t->testValidVersionThreeParts(); break;
        case 3: _t->testValidVersionAlpha(); break;
        case 4: _t->testValidVersionBeta(); break;
        case 5: _t->testValidVersionRC(); break;
        case 6: _t->testInvalidVersion(); break;
        case 7: _t->testComparisonLessThan(); break;
        case 8: _t->testComparisonGreaterThan(); break;
        case 9: _t->testComparisonEqual(); break;
        case 10: _t->testComparisonDifferentPlatform(); break;
        case 11: _t->testComparisonDifferentMajor(); break;
        case 12: _t->testComparisonDifferentStage(); break;
        case 13: _t->testToString(); break;
        case 14: _t->testToStringInvalid(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestUBVersion::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestUBVersion.offsetsAndSize,
    qt_meta_data_TestUBVersion,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestUBVersion_t
, QtPrivate::TypeAndForceComplete<TestUBVersion, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestUBVersion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestUBVersion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestUBVersion.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestUBVersion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
