/****************************************************************************
** Meta object code from reading C++ file 'dsoundknete.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dsoundknete.h"
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
    QByteArrayData data[14];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DSoundKnete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DSoundKnete_t qt_meta_stringdata_DSoundKnete = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DSoundKnete"
QT_MOC_LITERAL(1, 12, 11), // "on_dataSend"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 20), // "on_finishCalibrating"
QT_MOC_LITERAL(4, 46, 7), // "success"
QT_MOC_LITERAL(5, 54, 28), // "on_actionVideo_Top_triggered"
QT_MOC_LITERAL(6, 83, 30), // "on_actionVideo_Front_triggered"
QT_MOC_LITERAL(7, 114, 31), // "on_actionKamera_ffnen_triggered"
QT_MOC_LITERAL(8, 146, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(9, 170, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(10, 192, 4), // "arg1"
QT_MOC_LITERAL(11, 197, 26), // "on_calibrateButton_clicked"
QT_MOC_LITERAL(12, 224, 24), // "on_radioButton2D_clicked"
QT_MOC_LITERAL(13, 249, 24) // "on_radioButton3D_clicked"

    },
    "DSoundKnete\0on_dataSend\0\0on_finishCalibrating\0"
    "success\0on_actionVideo_Top_triggered\0"
    "on_actionVideo_Front_triggered\0"
    "on_actionKamera_ffnen_triggered\0"
    "on_actionPlay_triggered\0on_comboBox_activated\0"
    "arg1\0on_calibrateButton_clicked\0"
    "on_radioButton2D_clicked\0"
    "on_radioButton3D_clicked"
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
       1,    0,   64,    2, 0x0a /* Public */,
       3,    1,   65,    2, 0x0a /* Public */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    0,   69,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DSoundKnete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DSoundKnete *_t = static_cast<DSoundKnete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dataSend(); break;
        case 1: _t->on_finishCalibrating((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->on_actionVideo_Top_triggered(); break;
        case 3: _t->on_actionVideo_Front_triggered(); break;
        case 4: _t->on_actionKamera_ffnen_triggered(); break;
        case 5: _t->on_actionPlay_triggered(); break;
        case 6: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_calibrateButton_clicked(); break;
        case 8: _t->on_radioButton2D_clicked(); break;
        case 9: _t->on_radioButton3D_clicked(); break;
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
