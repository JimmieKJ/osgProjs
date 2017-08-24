/****************************************************************************
** Meta object code from reading C++ file 'CollapsiblePairWidget'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/osgEarthQt/CollapsiblePairWidget"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CollapsiblePairWidget' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget_t {
    QByteArrayData data[5];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget_t qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget = {
    {
QT_MOC_LITERAL(0, 0, 38), // "osgEarth::QtGui::CollapsibleP..."
QT_MOC_LITERAL(1, 39, 20), // "onPrimaryHideClicked"
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 7), // "checked"
QT_MOC_LITERAL(4, 69, 22) // "onSecondaryHideClicked"

    },
    "osgEarth::QtGui::CollapsiblePairWidget\0"
    "onPrimaryHideClicked\0\0checked\0"
    "onSecondaryHideClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__CollapsiblePairWidget[] = {

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
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void osgEarth::QtGui::CollapsiblePairWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CollapsiblePairWidget *_t = static_cast<CollapsiblePairWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPrimaryHideClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onSecondaryHideClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osgEarth::QtGui::CollapsiblePairWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget.data,
      qt_meta_data_osgEarth__QtGui__CollapsiblePairWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::CollapsiblePairWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::CollapsiblePairWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__CollapsiblePairWidget.stringdata0))
        return static_cast<void*>(const_cast< CollapsiblePairWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int osgEarth::QtGui::CollapsiblePairWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
