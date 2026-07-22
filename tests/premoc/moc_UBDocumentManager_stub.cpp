/****************************************************************************
** Meta object code from reading C++ file 'UBDocumentManager_stub.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../stubs/UBDocumentManager_stub.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UBDocumentManager_stub.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UBDocumentManager_t {
    const uint offsetsAndSize[10];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_UBDocumentManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_UBDocumentManager_t qt_meta_stringdata_UBDocumentManager = {
    {
QT_MOC_LITERAL(0, 17), // "UBDocumentManager"
QT_MOC_LITERAL(18, 15), // "documentUpdated"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 16), // "UBDocumentProxy*"
QT_MOC_LITERAL(52, 5) // "proxy"

    },
    "UBDocumentManager\0documentUpdated\0\0"
    "UBDocumentProxy*\0proxy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UBDocumentManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void UBDocumentManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UBDocumentManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->documentUpdated((*reinterpret_cast< std::add_pointer_t<UBDocumentProxy*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UBDocumentManager::*)(UBDocumentProxy * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UBDocumentManager::documentUpdated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject UBDocumentManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UBDocumentManager.offsetsAndSize,
    qt_meta_data_UBDocumentManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_UBDocumentManager_t
, QtPrivate::TypeAndForceComplete<UBDocumentManager, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<UBDocumentProxy *, std::false_type>



>,
    nullptr
} };


const QMetaObject *UBDocumentManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UBDocumentManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UBDocumentManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UBDocumentManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void UBDocumentManager::documentUpdated(UBDocumentProxy * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
