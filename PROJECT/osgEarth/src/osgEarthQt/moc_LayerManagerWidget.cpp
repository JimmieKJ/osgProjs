/****************************************************************************
** Meta object code from reading C++ file 'LayerManagerWidget'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/osgEarthQt/LayerManagerWidget"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerManagerWidget' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase_t {
    QByteArrayData data[5];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase_t qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase = {
    {
QT_MOC_LITERAL(0, 0, 39), // "osgEarth::QtGui::LayerControl..."
QT_MOC_LITERAL(1, 40, 13), // "doubleClicked"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 15), // "onRemoveClicked"
QT_MOC_LITERAL(4, 71, 7) // "checked"

    },
    "osgEarth::QtGui::LayerControlWidgetBase\0"
    "doubleClicked\0\0onRemoveClicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__LayerControlWidgetBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void osgEarth::QtGui::LayerControlWidgetBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerControlWidgetBase *_t = static_cast<LayerControlWidgetBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        case 1: _t->onRemoveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerControlWidgetBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerControlWidgetBase::doubleClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject osgEarth::QtGui::LayerControlWidgetBase::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase.data,
      qt_meta_data_osgEarth__QtGui__LayerControlWidgetBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::LayerControlWidgetBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::LayerControlWidgetBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__LayerControlWidgetBase.stringdata0))
        return static_cast<void*>(const_cast< LayerControlWidgetBase*>(this));
    return QFrame::qt_metacast(_clname);
}

int osgEarth::QtGui::LayerControlWidgetBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void osgEarth::QtGui::LayerControlWidgetBase::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget_t {
    QByteArrayData data[6];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget_t qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 44), // "osgEarth::QtGui::ElevationLay..."
QT_MOC_LITERAL(1, 45, 26), // "onEnabledCheckStateChanged"
QT_MOC_LITERAL(2, 72, 0), // ""
QT_MOC_LITERAL(3, 73, 5), // "state"
QT_MOC_LITERAL(4, 79, 15), // "onRemoveClicked"
QT_MOC_LITERAL(5, 95, 7) // "checked"

    },
    "osgEarth::QtGui::ElevationLayerControlWidget\0"
    "onEnabledCheckStateChanged\0\0state\0"
    "onRemoveClicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__ElevationLayerControlWidget[] = {

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
       4,    1,   27,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void osgEarth::QtGui::ElevationLayerControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ElevationLayerControlWidget *_t = static_cast<ElevationLayerControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEnabledCheckStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onRemoveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osgEarth::QtGui::ElevationLayerControlWidget::staticMetaObject = {
    { &LayerControlWidgetBase::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget.data,
      qt_meta_data_osgEarth__QtGui__ElevationLayerControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::ElevationLayerControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::ElevationLayerControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__ElevationLayerControlWidget.stringdata0))
        return static_cast<void*>(const_cast< ElevationLayerControlWidget*>(this));
    return LayerControlWidgetBase::qt_metacast(_clname);
}

int osgEarth::QtGui::ElevationLayerControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LayerControlWidgetBase::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget_t {
    QByteArrayData data[8];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget_t qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 40), // "osgEarth::QtGui::ImageLayerCo..."
QT_MOC_LITERAL(1, 41, 19), // "onCheckStateChanged"
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 5), // "state"
QT_MOC_LITERAL(4, 68, 20), // "onSliderValueChanged"
QT_MOC_LITERAL(5, 89, 5), // "value"
QT_MOC_LITERAL(6, 95, 15), // "onRemoveClicked"
QT_MOC_LITERAL(7, 111, 7) // "checked"

    },
    "osgEarth::QtGui::ImageLayerControlWidget\0"
    "onCheckStateChanged\0\0state\0"
    "onSliderValueChanged\0value\0onRemoveClicked\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__ImageLayerControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    1,   35,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void osgEarth::QtGui::ImageLayerControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageLayerControlWidget *_t = static_cast<ImageLayerControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCheckStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onRemoveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osgEarth::QtGui::ImageLayerControlWidget::staticMetaObject = {
    { &LayerControlWidgetBase::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget.data,
      qt_meta_data_osgEarth__QtGui__ImageLayerControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::ImageLayerControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::ImageLayerControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__ImageLayerControlWidget.stringdata0))
        return static_cast<void*>(const_cast< ImageLayerControlWidget*>(this));
    return LayerControlWidgetBase::qt_metacast(_clname);
}

int osgEarth::QtGui::ImageLayerControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LayerControlWidgetBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget_t {
    QByteArrayData data[6];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget_t qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 40), // "osgEarth::QtGui::ModelLayerCo..."
QT_MOC_LITERAL(1, 41, 26), // "onEnabledCheckStateChanged"
QT_MOC_LITERAL(2, 68, 0), // ""
QT_MOC_LITERAL(3, 69, 5), // "state"
QT_MOC_LITERAL(4, 75, 15), // "onRemoveClicked"
QT_MOC_LITERAL(5, 91, 7) // "checked"

    },
    "osgEarth::QtGui::ModelLayerControlWidget\0"
    "onEnabledCheckStateChanged\0\0state\0"
    "onRemoveClicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__ModelLayerControlWidget[] = {

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
       4,    1,   27,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void osgEarth::QtGui::ModelLayerControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelLayerControlWidget *_t = static_cast<ModelLayerControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onEnabledCheckStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onRemoveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osgEarth::QtGui::ModelLayerControlWidget::staticMetaObject = {
    { &LayerControlWidgetBase::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget.data,
      qt_meta_data_osgEarth__QtGui__ModelLayerControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::ModelLayerControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::ModelLayerControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__ModelLayerControlWidget.stringdata0))
        return static_cast<void*>(const_cast< ModelLayerControlWidget*>(this));
    return LayerControlWidgetBase::qt_metacast(_clname);
}

int osgEarth::QtGui::ModelLayerControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = LayerControlWidgetBase::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData_t {
    QByteArrayData data[1];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData_t qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData = {
    {
QT_MOC_LITERAL(0, 0, 36) // "osgEarth::QtGui::LayerWidgetM..."

    },
    "osgEarth::QtGui::LayerWidgetMimeData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__LayerWidgetMimeData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void osgEarth::QtGui::LayerWidgetMimeData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject osgEarth::QtGui::LayerWidgetMimeData::staticMetaObject = {
    { &QMimeData::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData.data,
      qt_meta_data_osgEarth__QtGui__LayerWidgetMimeData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::LayerWidgetMimeData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::LayerWidgetMimeData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__LayerWidgetMimeData.stringdata0))
        return static_cast<void*>(const_cast< LayerWidgetMimeData*>(this));
    return QMimeData::qt_metacast(_clname);
}

int osgEarth::QtGui::LayerWidgetMimeData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMimeData::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget_t {
    QByteArrayData data[3];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget_t qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget = {
    {
QT_MOC_LITERAL(0, 0, 35), // "osgEarth::QtGui::LayerManager..."
QT_MOC_LITERAL(1, 36, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(2, 56, 0) // ""

    },
    "osgEarth::QtGui::LayerManagerWidget\0"
    "onItemDoubleClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__LayerManagerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void osgEarth::QtGui::LayerManagerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerManagerWidget *_t = static_cast<LayerManagerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onItemDoubleClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject osgEarth::QtGui::LayerManagerWidget::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget.data,
      qt_meta_data_osgEarth__QtGui__LayerManagerWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::LayerManagerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::LayerManagerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__LayerManagerWidget.stringdata0))
        return static_cast<void*>(const_cast< LayerManagerWidget*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int osgEarth::QtGui::LayerManagerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
