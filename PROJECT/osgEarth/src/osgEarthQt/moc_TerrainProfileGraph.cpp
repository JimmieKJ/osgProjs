/****************************************************************************
** Meta object code from reading C++ file 'TerrainProfileGraph'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/osgEarthQt/TerrainProfileGraph"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TerrainProfileGraph' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph_t {
    QByteArrayData data[5];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph_t qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph = {
    {
QT_MOC_LITERAL(0, 0, 36), // "osgEarth::QtGui::TerrainProfi..."
QT_MOC_LITERAL(1, 37, 27), // "onNotifyTerrainGraphChanged"
QT_MOC_LITERAL(2, 65, 0), // ""
QT_MOC_LITERAL(3, 66, 17), // "onCopyToClipboard"
QT_MOC_LITERAL(4, 84, 21) // "onTerrainGraphChanged"

    },
    "osgEarth::QtGui::TerrainProfileGraph\0"
    "onNotifyTerrainGraphChanged\0\0"
    "onCopyToClipboard\0onTerrainGraphChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__TerrainProfileGraph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void osgEarth::QtGui::TerrainProfileGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TerrainProfileGraph *_t = static_cast<TerrainProfileGraph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNotifyTerrainGraphChanged(); break;
        case 1: _t->onCopyToClipboard(); break;
        case 2: _t->onTerrainGraphChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TerrainProfileGraph::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TerrainProfileGraph::onNotifyTerrainGraphChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject osgEarth::QtGui::TerrainProfileGraph::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph.data,
      qt_meta_data_osgEarth__QtGui__TerrainProfileGraph,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::TerrainProfileGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::TerrainProfileGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__TerrainProfileGraph.stringdata0))
        return static_cast<void*>(const_cast< TerrainProfileGraph*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int osgEarth::QtGui::TerrainProfileGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void osgEarth::QtGui::TerrainProfileGraph::onNotifyTerrainGraphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
