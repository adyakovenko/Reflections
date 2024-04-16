/****************************************************************************
** Meta object code from reading C++ file 'windowmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../windowmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WindowMain_t {
    QByteArrayData data[14];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WindowMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WindowMain_t qt_meta_stringdata_WindowMain = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WindowMain"
QT_MOC_LITERAL(1, 11, 29), // "on_pushButton_compute_clicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 30), // "on_checkBox_angle_stateChanged"
QT_MOC_LITERAL(4, 73, 4), // "arg1"
QT_MOC_LITERAL(5, 78, 26), // "on_checkBox_r_stateChanged"
QT_MOC_LITERAL(6, 105, 26), // "on_layer_parameter_changed"
QT_MOC_LITERAL(7, 132, 28), // "on_plot_range_angles_changed"
QT_MOC_LITERAL(8, 161, 23), // "on_plot_range_r_changed"
QT_MOC_LITERAL(9, 185, 29), // "on_checkBox_real_stateChanged"
QT_MOC_LITERAL(10, 215, 29), // "on_checkBox_imag_stateChanged"
QT_MOC_LITERAL(11, 245, 28), // "on_checkBox_abs_stateChanged"
QT_MOC_LITERAL(12, 274, 38), // "on_comboBox_approx_currentInd..."
QT_MOC_LITERAL(13, 313, 5) // "index"

    },
    "WindowMain\0on_pushButton_compute_clicked\0"
    "\0on_checkBox_angle_stateChanged\0arg1\0"
    "on_checkBox_r_stateChanged\0"
    "on_layer_parameter_changed\0"
    "on_plot_range_angles_changed\0"
    "on_plot_range_r_changed\0"
    "on_checkBox_real_stateChanged\0"
    "on_checkBox_imag_stateChanged\0"
    "on_checkBox_abs_stateChanged\0"
    "on_comboBox_approx_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WindowMain[] = {

 // content:
       8,       // revision
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
       3,    1,   65,    2, 0x08 /* Private */,
       5,    1,   68,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void WindowMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WindowMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_compute_clicked(); break;
        case 1: _t->on_checkBox_angle_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_checkBox_r_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_layer_parameter_changed(); break;
        case 4: _t->on_plot_range_angles_changed(); break;
        case 5: _t->on_plot_range_r_changed(); break;
        case 6: _t->on_checkBox_real_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_imag_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_checkBox_abs_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_comboBox_approx_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WindowMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_WindowMain.data,
    qt_meta_data_WindowMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WindowMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WindowMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WindowMain.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int WindowMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
