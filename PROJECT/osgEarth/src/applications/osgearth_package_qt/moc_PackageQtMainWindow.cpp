/****************************************************************************
** Meta object code from reading C++ file 'PackageQtMainWindow'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/applications/osgearth_package_qt/PackageQtMainWindow"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PackageQtMainWindow' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PackageQt__PackageQtMainWindow_t {
    QByteArrayData data[10];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PackageQt__PackageQtMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PackageQt__PackageQtMainWindow_t qt_meta_stringdata_PackageQt__PackageQtMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 30), // "PackageQt::PackageQtMainWindow"
QT_MOC_LITERAL(1, 31, 13), // "openEarthFile"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 13), // "addImageLayer"
QT_MOC_LITERAL(4, 60, 17), // "addElevationLayer"
QT_MOC_LITERAL(5, 78, 10), // "exportRepo"
QT_MOC_LITERAL(6, 89, 16), // "showExportResult"
QT_MOC_LITERAL(7, 106, 14), // "getBoundingBox"
QT_MOC_LITERAL(8, 121, 7), // "checked"
QT_MOC_LITERAL(9, 129, 16) // "clearBoundingBox"

    },
    "PackageQt::PackageQtMainWindow\0"
    "openEarthFile\0\0addImageLayer\0"
    "addElevationLayer\0exportRepo\0"
    "showExportResult\0getBoundingBox\0checked\0"
    "clearBoundingBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PackageQt__PackageQtMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void PackageQt::PackageQtMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PackageQtMainWindow *_t = static_cast<PackageQtMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openEarthFile(); break;
        case 1: _t->addImageLayer(); break;
        case 2: _t->addElevationLayer(); break;
        case 3: _t->exportRepo(); break;
        case 4: _t->showExportResult(); break;
        case 5: _t->getBoundingBox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->clearBoundingBox(); break;
        default: ;
        }
    }
}

const QMetaObject PackageQt::PackageQtMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PackageQt__PackageQtMainWindow.data,
      qt_meta_data_PackageQt__PackageQtMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PackageQt::PackageQtMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PackageQt::PackageQtMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PackageQt__PackageQtMainWindow.stringdata0))
        return static_cast<void*>(const_cast< PackageQtMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PackageQt::PackageQtMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
