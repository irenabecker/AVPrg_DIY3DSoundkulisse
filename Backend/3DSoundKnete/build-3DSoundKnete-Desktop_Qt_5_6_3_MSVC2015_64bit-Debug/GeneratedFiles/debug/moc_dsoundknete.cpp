/****************************************************************************
** Meta object code from reading C++ file 'dsoundknete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../3DSoundKnete/dsoundknete.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dsoundknete.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DSoundKnete_t {
    QByteArrayData data[13];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DSoundKnete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DSoundKnete_t qt_meta_stringdata_DSoundKnete = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DSoundKnete"
QT_MOC_LITERAL(1, 12, 28), // "on_actionVideo_Top_triggered"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 30), // "on_actionVideo_Front_triggered"
QT_MOC_LITERAL(4, 73, 31), // "on_actionKamera_ffnen_triggered"
QT_MOC_LITERAL(5, 105, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(6, 129, 18), // "onHmaxValueChanged"
QT_MOC_LITERAL(7, 148, 5), // "value"
QT_MOC_LITERAL(8, 154, 20), // "on_vmax_valueChanged"
QT_MOC_LITERAL(9, 175, 20), // "on_smin_valueChanged"
QT_MOC_LITERAL(10, 196, 20), // "on_smax_valueChanged"
QT_MOC_LITERAL(11, 217, 20), // "on_vmin_valueChanged"
QT_MOC_LITERAL(12, 238, 20) // "on_hmin_valueChanged"

    },
    "DSoundKnete\0on_actionVideo_Top_triggered\0"
    "\0on_actionVideo_Front_triggered\0"
    "on_actionKamera_ffnen_triggered\0"
    "on_actionPlay_triggered\0onHmaxValueChanged\0"
    "value\0on_vmax_valueChanged\0"
    "on_smin_valueChanged\0on_smax_valueChanged\0"
    "on_vmin_valueChanged\0on_hmin_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DSoundKnete[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    1,   71,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void DSoundKnete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DSoundKnete *_t = static_cast<DSoundKnete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionVideo_Top_triggered(); break;
        case 1: _t->on_actionVideo_Front_triggered(); break;
        case 2: _t->on_actionKamera_ffnen_triggered(); break;
        case 3: _t->on_actionPlay_triggered(); break;
        case 4: _t->onHmaxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_vmax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_smin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_smax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_vmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_hmin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DSoundKnete::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DSoundKnete.data,
      qt_meta_data_DSoundKnete,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DSoundKnete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DSoundKnete::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DSoundKnete.stringdata0))
        return static_cast<void*>(const_cast< DSoundKnete*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DSoundKnete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
