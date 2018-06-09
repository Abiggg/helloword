/****************************************************************************
** Meta object code from reading C++ file 'winaiphoto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../helloworld/winaiphoto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'winaiphoto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_winAiPhoto_t {
    QByteArrayData data[19];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_winAiPhoto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_winAiPhoto_t qt_meta_stringdata_winAiPhoto = {
    {
QT_MOC_LITERAL(0, 0, 10), // "winAiPhoto"
QT_MOC_LITERAL(1, 11, 10), // "WinDisplay"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "WinBeatifyDisplay"
QT_MOC_LITERAL(4, 41, 3), // "Mat"
QT_MOC_LITERAL(5, 45, 6), // "matCur"
QT_MOC_LITERAL(6, 52, 26), // "gotoAiPhoto_clicked_reshow"
QT_MOC_LITERAL(7, 79, 6), // "SrcMat"
QT_MOC_LITERAL(8, 86, 14), // "ReceiveMessage"
QT_MOC_LITERAL(9, 101, 5), // "count"
QT_MOC_LITERAL(10, 107, 23), // "on_PbBackToMain_clicked"
QT_MOC_LITERAL(11, 131, 23), // "on_PbWinBeatify_clicked"
QT_MOC_LITERAL(12, 155, 21), // "on_PbOpenFile_clicked"
QT_MOC_LITERAL(13, 177, 21), // "on_PbSaveFile_clicked"
QT_MOC_LITERAL(14, 199, 23), // "on_PbStratTrain_clicked"
QT_MOC_LITERAL(15, 223, 21), // "on_PbEndTrain_clicked"
QT_MOC_LITERAL(16, 245, 28), // "on_LwAiFun_currentRowChanged"
QT_MOC_LITERAL(17, 274, 10), // "currentRow"
QT_MOC_LITERAL(18, 285, 20) // "on_PbBpStart_clicked"

    },
    "winAiPhoto\0WinDisplay\0\0WinBeatifyDisplay\0"
    "Mat\0matCur\0gotoAiPhoto_clicked_reshow\0"
    "SrcMat\0ReceiveMessage\0count\0"
    "on_PbBackToMain_clicked\0on_PbWinBeatify_clicked\0"
    "on_PbOpenFile_clicked\0on_PbSaveFile_clicked\0"
    "on_PbStratTrain_clicked\0on_PbEndTrain_clicked\0"
    "on_LwAiFun_currentRowChanged\0currentRow\0"
    "on_PbBpStart_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_winAiPhoto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void winAiPhoto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        winAiPhoto *_t = static_cast<winAiPhoto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->WinDisplay(); break;
        case 1: _t->WinBeatifyDisplay((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 2: _t->gotoAiPhoto_clicked_reshow((*reinterpret_cast< Mat(*)>(_a[1]))); break;
        case 3: _t->ReceiveMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_PbBackToMain_clicked(); break;
        case 5: _t->on_PbWinBeatify_clicked(); break;
        case 6: _t->on_PbOpenFile_clicked(); break;
        case 7: _t->on_PbSaveFile_clicked(); break;
        case 8: _t->on_PbStratTrain_clicked(); break;
        case 9: _t->on_PbEndTrain_clicked(); break;
        case 10: _t->on_LwAiFun_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_PbBpStart_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (winAiPhoto::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&winAiPhoto::WinDisplay)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (winAiPhoto::*_t)(Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&winAiPhoto::WinBeatifyDisplay)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject winAiPhoto::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_winAiPhoto.data,
      qt_meta_data_winAiPhoto,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *winAiPhoto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *winAiPhoto::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_winAiPhoto.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int winAiPhoto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void winAiPhoto::WinDisplay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void winAiPhoto::WinBeatifyDisplay(Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
