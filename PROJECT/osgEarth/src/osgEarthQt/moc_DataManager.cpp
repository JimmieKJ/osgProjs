/****************************************************************************
** Meta object code from reading C++ file 'DataManager'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/osgEarthQt/DataManager"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataManager' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgEarth__QtGui__DataManager_t {
    QByteArrayData data[8];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__DataManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__DataManager_t qt_meta_stringdata_osgEarth__QtGui__DataManager = {
    {
QT_MOC_LITERAL(0, 0, 28), // "osgEarth::QtGui::DataManager"
QT_MOC_LITERAL(1, 29, 10), // "mapChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "selectionChanged"
QT_MOC_LITERAL(4, 58, 15), // "annotationAdded"
QT_MOC_LITERAL(5, 74, 37), // "osgEarth::Annotation::Annotat..."
QT_MOC_LITERAL(6, 112, 10), // "annotation"
QT_MOC_LITERAL(7, 123, 17) // "annotationRemoved"

    },
    "osgEarth::QtGui::DataManager\0mapChanged\0"
    "\0selectionChanged\0annotationAdded\0"
    "osgEarth::Annotation::AnnotationNode*\0"
    "annotation\0annotationRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__DataManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       7,    1,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void osgEarth::QtGui::DataManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataManager *_t = static_cast<DataManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mapChanged(); break;
        case 1: _t->selectionChanged(); break;
        case 2: _t->annotationAdded((*reinterpret_cast< osgEarth::Annotation::AnnotationNode*(*)>(_a[1]))); break;
        case 3: _t->annotationRemoved((*reinterpret_cast< osgEarth::Annotation::AnnotationNode*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataManager::mapChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DataManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataManager::selectionChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DataManager::*_t)(osgEarth::Annotation::AnnotationNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataManager::annotationAdded)) {
                *result = 2;
            }
        }
        {
            typedef void (DataManager::*_t)(osgEarth::Annotation::AnnotationNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataManager::annotationRemoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject osgEarth::QtGui::DataManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__DataManager.data,
      qt_meta_data_osgEarth__QtGui__DataManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::DataManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::DataManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__DataManager.stringdata0))
        return static_cast<void*>(const_cast< DataManager*>(this));
    if (!strcmp(_clname, "osg::Referenced"))
        return static_cast< osg::Referenced*>(const_cast< DataManager*>(this));
    if (!strcmp(_clname, "ActionManager"))
        return static_cast< ActionManager*>(const_cast< DataManager*>(this));
    return QObject::qt_metacast(_clname);
}

int osgEarth::QtGui::DataManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void osgEarth::QtGui::DataManager::mapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void osgEarth::QtGui::DataManager::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void osgEarth::QtGui::DataManager::annotationAdded(osgEarth::Annotation::AnnotationNode * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void osgEarth::QtGui::DataManager::annotationRemoved(osgEarth::Annotation::AnnotationNode * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
