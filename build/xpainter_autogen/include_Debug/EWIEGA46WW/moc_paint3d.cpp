/****************************************************************************
** Meta object code from reading C++ file 'paint3d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../paint3d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paint3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Paint3D_t {
    QByteArrayData data[17];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Paint3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Paint3D_t qt_meta_stringdata_Paint3D = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Paint3D"
QT_MOC_LITERAL(1, 8, 4), // "open"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 4), // "save"
QT_MOC_LITERAL(4, 19, 8), // "penColor"
QT_MOC_LITERAL(5, 28, 8), // "penWidth"
QT_MOC_LITERAL(6, 37, 5), // "about"
QT_MOC_LITERAL(7, 43, 3), // "pen"
QT_MOC_LITERAL(8, 47, 6), // "marker"
QT_MOC_LITERAL(9, 54, 6), // "eraser"
QT_MOC_LITERAL(10, 61, 8), // "oilBrush"
QT_MOC_LITERAL(11, 70, 15), // "waterColorBrush"
QT_MOC_LITERAL(12, 86, 4), // "undo"
QT_MOC_LITERAL(13, 91, 4), // "redo"
QT_MOC_LITERAL(14, 96, 8), // "addShape"
QT_MOC_LITERAL(15, 105, 11), // "std::string"
QT_MOC_LITERAL(16, 117, 5) // "shape"

    },
    "Paint3D\0open\0\0save\0penColor\0penWidth\0"
    "about\0pen\0marker\0eraser\0oilBrush\0"
    "waterColorBrush\0undo\0redo\0addShape\0"
    "std::string\0shape"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paint3D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void Paint3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Paint3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->save(); break;
        case 2: _t->penColor(); break;
        case 3: _t->penWidth(); break;
        case 4: _t->about(); break;
        case 5: _t->pen(); break;
        case 6: _t->marker(); break;
        case 7: _t->eraser(); break;
        case 8: _t->oilBrush(); break;
        case 9: _t->waterColorBrush(); break;
        case 10: _t->undo(); break;
        case 11: _t->redo(); break;
        case 12: _t->addShape((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Paint3D::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Paint3D.data,
    qt_meta_data_Paint3D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Paint3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paint3D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Paint3D.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Paint3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
