/****************************************************************************
** Meta object code from reading C++ file 'tst_UBFileSystemUtils.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tst_UBFileSystemUtils.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_UBFileSystemUtils.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestUBFileSystemUtils_t {
    const uint offsetsAndSize[104];
    char stringdata0[1329];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestUBFileSystemUtils_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestUBFileSystemUtils_t qt_meta_stringdata_TestUBFileSystemUtils = {
    {
QT_MOC_LITERAL(0, 21), // "TestUBFileSystemUtils"
QT_MOC_LITERAL(22, 12), // "initTestCase"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 15), // "cleanupTestCase"
QT_MOC_LITERAL(52, 30), // "testRemoveLocalFilePrefix_unix"
QT_MOC_LITERAL(83, 34), // "testRemoveLocalFilePrefix_noP..."
QT_MOC_LITERAL(118, 31), // "testRemoveLocalFilePrefix_empty"
QT_MOC_LITERAL(150, 26), // "testCleanName_removesSlash"
QT_MOC_LITERAL(177, 26), // "testCleanName_removesColon"
QT_MOC_LITERAL(204, 34), // "testCleanName_removesMultiple..."
QT_MOC_LITERAL(239, 29), // "testCleanName_preservesNormal"
QT_MOC_LITERAL(269, 33), // "testNormalizeFilePath_backsla..."
QT_MOC_LITERAL(303, 39), // "testNormalizeFilePath_already..."
QT_MOC_LITERAL(343, 20), // "testExtension_simple"
QT_MOC_LITERAL(364, 27), // "testExtension_multiple_dots"
QT_MOC_LITERAL(392, 25), // "testExtension_noExtension"
QT_MOC_LITERAL(418, 27), // "testExtension_trailingSlash"
QT_MOC_LITERAL(446, 26), // "testLastPathComponent_file"
QT_MOC_LITERAL(473, 25), // "testLastPathComponent_dir"
QT_MOC_LITERAL(499, 35), // "testLastPathComponent_trailin..."
QT_MOC_LITERAL(535, 28), // "testMimeTypeFromFileName_png"
QT_MOC_LITERAL(564, 28), // "testMimeTypeFromFileName_pdf"
QT_MOC_LITERAL(593, 28), // "testMimeTypeFromFileName_svg"
QT_MOC_LITERAL(622, 28), // "testMimeTypeFromFileName_mp4"
QT_MOC_LITERAL(651, 32), // "testMimeTypeFromFileName_unknown"
QT_MOC_LITERAL(684, 35), // "testFileExtensionFromMimeType..."
QT_MOC_LITERAL(720, 35), // "testFileExtensionFromMimeType..."
QT_MOC_LITERAL(756, 37), // "testFileExtensionFromMimeType..."
QT_MOC_LITERAL(794, 34), // "testMimeTypeFromString_raster..."
QT_MOC_LITERAL(829, 34), // "testMimeTypeFromString_vector..."
QT_MOC_LITERAL(864, 28), // "testMimeTypeFromString_video"
QT_MOC_LITERAL(893, 28), // "testMimeTypeFromString_audio"
QT_MOC_LITERAL(922, 26), // "testMimeTypeFromString_pdf"
QT_MOC_LITERAL(949, 30), // "testMimeTypeFromString_unknown"
QT_MOC_LITERAL(980, 21), // "testIsPathMatch_exact"
QT_MOC_LITERAL(1002, 23), // "testIsPathMatch_subpath"
QT_MOC_LITERAL(1026, 23), // "testIsPathMatch_noMatch"
QT_MOC_LITERAL(1050, 29), // "testIsPathMatch_similarPrefix"
QT_MOC_LITERAL(1080, 12), // "testCopyFile"
QT_MOC_LITERAL(1093, 24), // "testCopyFile_nonExistent"
QT_MOC_LITERAL(1118, 14), // "testDeleteFile"
QT_MOC_LITERAL(1133, 13), // "testDeleteDir"
QT_MOC_LITERAL(1147, 11), // "testCopyDir"
QT_MOC_LITERAL(1159, 11), // "testMoveDir"
QT_MOC_LITERAL(1171, 12), // "testAllFiles"
QT_MOC_LITERAL(1184, 25), // "testNextAvailableFileName"
QT_MOC_LITERAL(1210, 24), // "testNextAvailableDirName"
QT_MOC_LITERAL(1235, 16), // "testReadTextFile"
QT_MOC_LITERAL(1252, 17), // "testThumbnailPath"
QT_MOC_LITERAL(1270, 19), // "testDeletePath_file"
QT_MOC_LITERAL(1290, 18), // "testDeletePath_dir"
QT_MOC_LITERAL(1309, 19) // "testMimeTypeFromUrl"

    },
    "TestUBFileSystemUtils\0initTestCase\0\0"
    "cleanupTestCase\0testRemoveLocalFilePrefix_unix\0"
    "testRemoveLocalFilePrefix_noPrefix\0"
    "testRemoveLocalFilePrefix_empty\0"
    "testCleanName_removesSlash\0"
    "testCleanName_removesColon\0"
    "testCleanName_removesMultipleChars\0"
    "testCleanName_preservesNormal\0"
    "testNormalizeFilePath_backslashes\0"
    "testNormalizeFilePath_alreadyNormalized\0"
    "testExtension_simple\0testExtension_multiple_dots\0"
    "testExtension_noExtension\0"
    "testExtension_trailingSlash\0"
    "testLastPathComponent_file\0"
    "testLastPathComponent_dir\0"
    "testLastPathComponent_trailingSlash\0"
    "testMimeTypeFromFileName_png\0"
    "testMimeTypeFromFileName_pdf\0"
    "testMimeTypeFromFileName_svg\0"
    "testMimeTypeFromFileName_mp4\0"
    "testMimeTypeFromFileName_unknown\0"
    "testFileExtensionFromMimeType_image\0"
    "testFileExtensionFromMimeType_video\0"
    "testFileExtensionFromMimeType_unknown\0"
    "testMimeTypeFromString_rasterImage\0"
    "testMimeTypeFromString_vectorImage\0"
    "testMimeTypeFromString_video\0"
    "testMimeTypeFromString_audio\0"
    "testMimeTypeFromString_pdf\0"
    "testMimeTypeFromString_unknown\0"
    "testIsPathMatch_exact\0testIsPathMatch_subpath\0"
    "testIsPathMatch_noMatch\0"
    "testIsPathMatch_similarPrefix\0"
    "testCopyFile\0testCopyFile_nonExistent\0"
    "testDeleteFile\0testDeleteDir\0testCopyDir\0"
    "testMoveDir\0testAllFiles\0"
    "testNextAvailableFileName\0"
    "testNextAvailableDirName\0testReadTextFile\0"
    "testThumbnailPath\0testDeletePath_file\0"
    "testDeletePath_dir\0testMimeTypeFromUrl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestUBFileSystemUtils[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  314,    2, 0x08,    1 /* Private */,
       3,    0,  315,    2, 0x08,    2 /* Private */,
       4,    0,  316,    2, 0x08,    3 /* Private */,
       5,    0,  317,    2, 0x08,    4 /* Private */,
       6,    0,  318,    2, 0x08,    5 /* Private */,
       7,    0,  319,    2, 0x08,    6 /* Private */,
       8,    0,  320,    2, 0x08,    7 /* Private */,
       9,    0,  321,    2, 0x08,    8 /* Private */,
      10,    0,  322,    2, 0x08,    9 /* Private */,
      11,    0,  323,    2, 0x08,   10 /* Private */,
      12,    0,  324,    2, 0x08,   11 /* Private */,
      13,    0,  325,    2, 0x08,   12 /* Private */,
      14,    0,  326,    2, 0x08,   13 /* Private */,
      15,    0,  327,    2, 0x08,   14 /* Private */,
      16,    0,  328,    2, 0x08,   15 /* Private */,
      17,    0,  329,    2, 0x08,   16 /* Private */,
      18,    0,  330,    2, 0x08,   17 /* Private */,
      19,    0,  331,    2, 0x08,   18 /* Private */,
      20,    0,  332,    2, 0x08,   19 /* Private */,
      21,    0,  333,    2, 0x08,   20 /* Private */,
      22,    0,  334,    2, 0x08,   21 /* Private */,
      23,    0,  335,    2, 0x08,   22 /* Private */,
      24,    0,  336,    2, 0x08,   23 /* Private */,
      25,    0,  337,    2, 0x08,   24 /* Private */,
      26,    0,  338,    2, 0x08,   25 /* Private */,
      27,    0,  339,    2, 0x08,   26 /* Private */,
      28,    0,  340,    2, 0x08,   27 /* Private */,
      29,    0,  341,    2, 0x08,   28 /* Private */,
      30,    0,  342,    2, 0x08,   29 /* Private */,
      31,    0,  343,    2, 0x08,   30 /* Private */,
      32,    0,  344,    2, 0x08,   31 /* Private */,
      33,    0,  345,    2, 0x08,   32 /* Private */,
      34,    0,  346,    2, 0x08,   33 /* Private */,
      35,    0,  347,    2, 0x08,   34 /* Private */,
      36,    0,  348,    2, 0x08,   35 /* Private */,
      37,    0,  349,    2, 0x08,   36 /* Private */,
      38,    0,  350,    2, 0x08,   37 /* Private */,
      39,    0,  351,    2, 0x08,   38 /* Private */,
      40,    0,  352,    2, 0x08,   39 /* Private */,
      41,    0,  353,    2, 0x08,   40 /* Private */,
      42,    0,  354,    2, 0x08,   41 /* Private */,
      43,    0,  355,    2, 0x08,   42 /* Private */,
      44,    0,  356,    2, 0x08,   43 /* Private */,
      45,    0,  357,    2, 0x08,   44 /* Private */,
      46,    0,  358,    2, 0x08,   45 /* Private */,
      47,    0,  359,    2, 0x08,   46 /* Private */,
      48,    0,  360,    2, 0x08,   47 /* Private */,
      49,    0,  361,    2, 0x08,   48 /* Private */,
      50,    0,  362,    2, 0x08,   49 /* Private */,
      51,    0,  363,    2, 0x08,   50 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestUBFileSystemUtils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestUBFileSystemUtils *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->testRemoveLocalFilePrefix_unix(); break;
        case 3: _t->testRemoveLocalFilePrefix_noPrefix(); break;
        case 4: _t->testRemoveLocalFilePrefix_empty(); break;
        case 5: _t->testCleanName_removesSlash(); break;
        case 6: _t->testCleanName_removesColon(); break;
        case 7: _t->testCleanName_removesMultipleChars(); break;
        case 8: _t->testCleanName_preservesNormal(); break;
        case 9: _t->testNormalizeFilePath_backslashes(); break;
        case 10: _t->testNormalizeFilePath_alreadyNormalized(); break;
        case 11: _t->testExtension_simple(); break;
        case 12: _t->testExtension_multiple_dots(); break;
        case 13: _t->testExtension_noExtension(); break;
        case 14: _t->testExtension_trailingSlash(); break;
        case 15: _t->testLastPathComponent_file(); break;
        case 16: _t->testLastPathComponent_dir(); break;
        case 17: _t->testLastPathComponent_trailingSlash(); break;
        case 18: _t->testMimeTypeFromFileName_png(); break;
        case 19: _t->testMimeTypeFromFileName_pdf(); break;
        case 20: _t->testMimeTypeFromFileName_svg(); break;
        case 21: _t->testMimeTypeFromFileName_mp4(); break;
        case 22: _t->testMimeTypeFromFileName_unknown(); break;
        case 23: _t->testFileExtensionFromMimeType_image(); break;
        case 24: _t->testFileExtensionFromMimeType_video(); break;
        case 25: _t->testFileExtensionFromMimeType_unknown(); break;
        case 26: _t->testMimeTypeFromString_rasterImage(); break;
        case 27: _t->testMimeTypeFromString_vectorImage(); break;
        case 28: _t->testMimeTypeFromString_video(); break;
        case 29: _t->testMimeTypeFromString_audio(); break;
        case 30: _t->testMimeTypeFromString_pdf(); break;
        case 31: _t->testMimeTypeFromString_unknown(); break;
        case 32: _t->testIsPathMatch_exact(); break;
        case 33: _t->testIsPathMatch_subpath(); break;
        case 34: _t->testIsPathMatch_noMatch(); break;
        case 35: _t->testIsPathMatch_similarPrefix(); break;
        case 36: _t->testCopyFile(); break;
        case 37: _t->testCopyFile_nonExistent(); break;
        case 38: _t->testDeleteFile(); break;
        case 39: _t->testDeleteDir(); break;
        case 40: _t->testCopyDir(); break;
        case 41: _t->testMoveDir(); break;
        case 42: _t->testAllFiles(); break;
        case 43: _t->testNextAvailableFileName(); break;
        case 44: _t->testNextAvailableDirName(); break;
        case 45: _t->testReadTextFile(); break;
        case 46: _t->testThumbnailPath(); break;
        case 47: _t->testDeletePath_file(); break;
        case 48: _t->testDeletePath_dir(); break;
        case 49: _t->testMimeTypeFromUrl(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestUBFileSystemUtils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestUBFileSystemUtils.offsetsAndSize,
    qt_meta_data_TestUBFileSystemUtils,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestUBFileSystemUtils_t
, QtPrivate::TypeAndForceComplete<TestUBFileSystemUtils, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestUBFileSystemUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestUBFileSystemUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestUBFileSystemUtils.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestUBFileSystemUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
