/****************************************************************************
** Meta object code from reading C++ file 'winimagefuzzy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../helloworld/winimagefuzzy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winimagefuzzy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WinImageFuzzy_t {
    QByteArrayData data[10];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WinImageFuzzy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WinImageFuzzy_t qt_meta_stringdata_WinImageFuzzy = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WinImageFuzzy"
QT_MOC_LITERAL(1, 14, 10), // "WinDisplay"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "on_PbOpenFile_clicked"
QT_MOC_LITERAL(4, 48, 23), // "on_PbbackToMain_clicked"
QT_MOC_LITERAL(5, 72, 21), // "on_PbSaveFile_clicked"
QT_MOC_LITERAL(6, 94, 20), // "on_PbAverage_clicked"
QT_MOC_LITERAL(7, 115, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(8, 147, 8), // "position"
QT_MOC_LITERAL(9, 156, 21) // "on_PbGaussian_clicked"

    },
    "WinImageFuzzy\0WinDisplay\0\0"
    "on_PbOpenFile_clicked\0on_PbbackToMain_clicked\0"
    "on_PbSaveFile_clicked\0on_PbAverage_clicked\0"
    "on_horizontalSlider_sliderMoved\0"
    "position\0on_PbGaussian_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WinImageFuzzy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void WinImageFuzzy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WinImageFuzzy *_t = static_cast<WinImageFuzzy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->WinDisplay(); break;
        case 1: _t->on_PbOpenFile_clicked(); break;
        case 2: _t->on_PbbackToMain_clicked(); break;
        case 3: _t->on_PbSaveFile_clicked(); break;
        case 4: _t->on_PbAverage_clicked(); break;
        case 5: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_PbGaussian_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (WinImageFuzzy::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WinImageFuzzy::WinDisplay)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WinImageFuzzy::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WinImageFuzzy.data,
      qt_meta_data_WinImageFuzzy,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WinImageFuzzy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WinImageFuzzy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WinImageFuzzy.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WinImageFuzzy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void WinImageFuzzy::WinDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
