/****************************************************************************
** Meta object code from reading C++ file 'cpuinforeader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cpuinforeader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpuinforeader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CPUinfoReader_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CPUinfoReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CPUinfoReader_t qt_meta_stringdata_CPUinfoReader = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CPUinfoReader"
QT_MOC_LITERAL(1, 14, 6), // "strLog"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "log"
QT_MOC_LITERAL(4, 26, 6), // "intLog"
QT_MOC_LITERAL(5, 33, 18), // "getNumberOfEntries"
QT_MOC_LITERAL(6, 52, 9), // "CPUnumber"
QT_MOC_LITERAL(7, 62, 15), // "getNumberOfCPUs"
QT_MOC_LITERAL(8, 78, 12), // "getLabelText"
QT_MOC_LITERAL(9, 91, 14), // "propertyNumber"
QT_MOC_LITERAL(10, 106, 15), // "processorNumber"
QT_MOC_LITERAL(11, 122, 14), // "getContentText"
QT_MOC_LITERAL(12, 137, 15), // "readCPUinfoFile"
QT_MOC_LITERAL(13, 153, 8) // "Filename"

    },
    "CPUinfoReader\0strLog\0\0log\0intLog\0"
    "getNumberOfEntries\0CPUnumber\0"
    "getNumberOfCPUs\0getLabelText\0"
    "propertyNumber\0processorNumber\0"
    "getContentText\0readCPUinfoFile\0Filename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CPUinfoReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x02 /* Public */,
       4,    1,   52,    2, 0x02 /* Public */,
       5,    1,   55,    2, 0x02 /* Public */,
       7,    0,   58,    2, 0x02 /* Public */,
       8,    2,   59,    2, 0x02 /* Public */,
      11,    2,   64,    2, 0x02 /* Public */,
      12,    1,   69,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int, QMetaType::Int,    6,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::QString, QMetaType::QString,   13,

       0        // eod
};

void CPUinfoReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CPUinfoReader *_t = static_cast<CPUinfoReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->strLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->intLog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->getNumberOfEntries((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getNumberOfCPUs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getLabelText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getContentText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->readCPUinfoFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject CPUinfoReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CPUinfoReader.data,
      qt_meta_data_CPUinfoReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CPUinfoReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CPUinfoReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CPUinfoReader.stringdata0))
        return static_cast<void*>(const_cast< CPUinfoReader*>(this));
    return QObject::qt_metacast(_clname);
}

int CPUinfoReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
