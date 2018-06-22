/****************************************************************************
** Meta object code from reading C++ file 'threadfromqthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../helloworld/threadfromqthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadfromqthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreadFromQthread_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreadFromQthread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreadFromQthread_t qt_meta_stringdata_ThreadFromQthread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ThreadFromQthread"
QT_MOC_LITERAL(1, 18, 7), // "message"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "count"
QT_MOC_LITERAL(4, 33, 7), // "progess"
QT_MOC_LITERAL(5, 41, 7), // "present"
QT_MOC_LITERAL(6, 49, 16), // "sendCameraStatus"
QT_MOC_LITERAL(7, 66, 7), // "isPhoto"
QT_MOC_LITERAL(8, 74, 16), // "sendCrossEntropy"
QT_MOC_LITERAL(9, 91, 12), // "CrossEntropy"
QT_MOC_LITERAL(10, 104, 15) // "StopImmediately"

    },
    "ThreadFromQthread\0message\0\0count\0"
    "progess\0present\0sendCameraStatus\0"
    "isPhoto\0sendCrossEntropy\0CrossEntropy\0"
    "StopImmediately"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreadFromQthread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       8,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Float,    9,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ThreadFromQthread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreadFromQthread *_t = static_cast<ThreadFromQthread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->message((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->progess((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendCameraStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sendCrossEntropy((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->StopImmediately(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ThreadFromQthread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFromQthread::message)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ThreadFromQthread::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFromQthread::progess)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ThreadFromQthread::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFromQthread::sendCameraStatus)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ThreadFromQthread::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThreadFromQthread::sendCrossEntropy)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ThreadFromQthread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadFromQthread.data,
      qt_meta_data_ThreadFromQthread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThreadFromQthread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreadFromQthread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadFromQthread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ThreadFromQthread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ThreadFromQthread::message(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThreadFromQthread::progess(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThreadFromQthread::sendCameraStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ThreadFromQthread::sendCrossEntropy(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
