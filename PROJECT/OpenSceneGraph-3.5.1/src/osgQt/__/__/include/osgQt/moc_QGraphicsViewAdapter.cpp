/****************************************************************************
** Meta object code from reading C++ file 'QGraphicsViewAdapter'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "osgQt/QGraphicsViewAdapter"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGraphicsViewAdapter' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgQt__QGraphicsViewAdapter_t {
    QByteArrayData data[6];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgQt__QGraphicsViewAdapter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgQt__QGraphicsViewAdapter_t qt_meta_stringdata_osgQt__QGraphicsViewAdapter = {
    {
QT_MOC_LITERAL(0, 0, 27), // "osgQt::QGraphicsViewAdapter"
QT_MOC_LITERAL(1, 28, 20), // "repaintRequestedSlot"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 13), // "QList<QRectF>"
QT_MOC_LITERAL(4, 64, 7), // "regions"
QT_MOC_LITERAL(5, 72, 6) // "region"

    },
    "osgQt::QGraphicsViewAdapter\0"
    "repaintRequestedSlot\0\0QList<QRectF>\0"
    "regions\0region"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgQt__QGraphicsViewAdapter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       1,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QRectF,    5,

       0        // eod
};

void osgQt::QGraphicsViewAdapter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGraphicsViewAdapter *_t = static_cast<QGraphicsViewAdapter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->repaintRequestedSlot((*reinterpret_cast< const QList<QRectF>(*)>(_a[1]))); break;
        case 1: _t->repaintRequestedSlot((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QRectF> >(); break;
            }
            break;
        }
    }
}

const QMetaObject osgQt::QGraphicsViewAdapter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_osgQt__QGraphicsViewAdapter.data,
      qt_meta_data_osgQt__QGraphicsViewAdapter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgQt::QGraphicsViewAdapter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgQt::QGraphicsViewAdapter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgQt__QGraphicsViewAdapter.stringdata0))
        return static_cast<void*>(const_cast< QGraphicsViewAdapter*>(this));
    return QObject::qt_metacast(_clname);
}

int osgQt::QGraphicsViewAdapter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
