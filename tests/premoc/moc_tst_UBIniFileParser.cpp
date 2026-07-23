/****************************************************************************
** Meta object code from reading C++ file 'tst_UBIniFileParser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tst_UBIniFileParser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_UBIniFileParser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestUBIniFileParser_t {
    const uint offsetsAndSize[18];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestUBIniFileParser_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestUBIniFileParser_t qt_meta_stringdata_TestUBIniFileParser = {
    {
QT_MOC_LITERAL(0, 19), // "TestUBIniFileParser"
QT_MOC_LITERAL(20, 18), // "testParseSimpleIni"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 35), // "testParseMissingSectionReturnsEmpty"
QT_MOC_LITERAL(76, 31), // "testParseMissingKeyReturnsEmpty"
QT_MOC_LITERAL(108, 25), // "testParseMultipleSections"
QT_MOC_LITERAL(134, 24), // "testParseNonExistentFile"
QT_MOC_LITERAL(159, 18), // "testParseEmptyFile"
QT_MOC_LITERAL(178, 25) // "testParseValuesWithEquals"

    },
    "TestUBIniFileParser\0testParseSimpleIni\0"
    "\0testParseMissingSectionReturnsEmpty\0"
    "testParseMissingKeyReturnsEmpty\0"
    "testParseMultipleSections\0"
    "testParseNonExistentFile\0testParseEmptyFile\0"
    "testParseValuesWithEquals"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestUBIniFileParser[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestUBIniFileParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestUBIniFileParser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testParseSimpleIni(); break;
        case 1: _t->testParseMissingSectionReturnsEmpty(); break;
        case 2: _t->testParseMissingKeyReturnsEmpty(); break;
        case 3: _t->testParseMultipleSections(); break;
        case 4: _t->testParseNonExistentFile(); break;
        case 5: _t->testParseEmptyFile(); break;
        case 6: _t->testParseValuesWithEquals(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestUBIniFileParser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestUBIniFileParser.offsetsAndSize,
    qt_meta_data_TestUBIniFileParser,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestUBIniFileParser_t
, QtPrivate::TypeAndForceComplete<TestUBIniFileParser, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestUBIniFileParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestUBIniFileParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestUBIniFileParser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestUBIniFileParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
