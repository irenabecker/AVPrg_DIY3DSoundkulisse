/****************************************************************************
** Meta object code from reading C++ file 'dsoundknete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dsoundknete.h"
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
    QByteArrayData data[9];
    char stringdata0[183];
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
QT_MOC_LITERAL(6, 129, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(7, 151, 4), // "arg1"
QT_MOC_LITERAL(8, 156, 26) // "on_calibrateButton_clicked"

    },
    "DSoundKnete\0on_actionVideo_Top_triggered\0"
    "\0on_actionVideo_Front_triggered\0"
    "on_actionKamera_ffnen_triggered\0"
    "on_actionPlay_triggered\0on_comboBox_activated\0"
    "arg1\0on_calibrateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DSoundKnete[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

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
        case 4: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_calibrateButton_clicked(); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
