/****************************************************************************
** Meta object code from reading C++ file 'tst_UBOEmbedParser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tst_UBOEmbedParser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_UBOEmbedParser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestUBOEmbedParser_t {
    const uint offsetsAndSize[20];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestUBOEmbedParser_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestUBOEmbedParser_t qt_meta_stringdata_TestUBOEmbedParser = {
    {
QT_MOC_LITERAL(0, 18), // "TestUBOEmbedParser"
QT_MOC_LITERAL(19, 22), // "testGetJSONInfos_video"
QT_MOC_LITERAL(42, 0), // ""
QT_MOC_LITERAL(43, 22), // "testGetJSONInfos_photo"
QT_MOC_LITERAL(66, 26), // "testGetJSONInfos_emptyJson"
QT_MOC_LITERAL(93, 21), // "testGetXMLInfos_video"
QT_MOC_LITERAL(115, 21), // "testGetXMLInfos_photo"
QT_MOC_LITERAL(137, 24), // "testGetXMLInfos_emptyXml"
QT_MOC_LITERAL(162, 28), // "testGetJSONInfos_partialData"
QT_MOC_LITERAL(191, 25) // "testGetXMLInfos_allFields"

    },
    "TestUBOEmbedParser\0testGetJSONInfos_video\0"
    "\0testGetJSONInfos_photo\0"
    "testGetJSONInfos_emptyJson\0"
    "testGetXMLInfos_video\0testGetXMLInfos_photo\0"
    "testGetXMLInfos_emptyXml\0"
    "testGetJSONInfos_partialData\0"
    "testGetXMLInfos_allFields"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestUBOEmbedParser[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

void TestUBOEmbedParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestUBOEmbedParser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testGetJSONInfos_video(); break;
        case 1: _t->testGetJSONInfos_photo(); break;
        case 2: _t->testGetJSONInfos_emptyJson(); break;
        case 3: _t->testGetXMLInfos_video(); break;
        case 4: _t->testGetXMLInfos_photo(); break;
        case 5: _t->testGetXMLInfos_emptyXml(); break;
        case 6: _t->testGetJSONInfos_partialData(); break;
        case 7: _t->testGetXMLInfos_allFields(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestUBOEmbedParser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestUBOEmbedParser.offsetsAndSize,
    qt_meta_data_TestUBOEmbedParser,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestUBOEmbedParser_t
, QtPrivate::TypeAndForceComplete<TestUBOEmbedParser, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestUBOEmbedParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestUBOEmbedParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestUBOEmbedParser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestUBOEmbedParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
