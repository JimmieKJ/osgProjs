/****************************************************************************
** Meta object code from reading C++ file 'LOSControlWidget'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "D:/PROJECT/osgEarth/src/osgEarthQt/LOSControlWidget"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LOSControlWidget' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget_t {
    QByteArrayData data[18];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget_t qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget = {
    {
QT_MOC_LITERAL(0, 0, 33), // "osgEarth::QtGui::LOSControlWi..."
QT_MOC_LITERAL(1, 34, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 72, 4), // "item"
QT_MOC_LITERAL(5, 77, 13), // "onItemChanged"
QT_MOC_LITERAL(6, 91, 22), // "onItemSelectionChanged"
QT_MOC_LITERAL(7, 114, 17), // "onDepthBoxChanged"
QT_MOC_LITERAL(8, 132, 5), // "state"
QT_MOC_LITERAL(9, 138, 20), // "onRadiusValueChanged"
QT_MOC_LITERAL(10, 159, 5), // "value"
QT_MOC_LITERAL(11, 165, 20), // "onSpokesValueChanged"
QT_MOC_LITERAL(12, 186, 8), // "onAddLOS"
QT_MOC_LITERAL(13, 195, 19), // "onRemoveSelectedLOS"
QT_MOC_LITERAL(14, 215, 17), // "onEditSelectedLOS"
QT_MOC_LITERAL(15, 233, 16), // "onCreateFinished"
QT_MOC_LITERAL(16, 250, 6), // "result"
QT_MOC_LITERAL(17, 257, 14) // "onEditFinished"

    },
    "osgEarth::QtGui::LOSControlWidget\0"
    "onItemDoubleClicked\0\0QListWidgetItem*\0"
    "item\0onItemChanged\0onItemSelectionChanged\0"
    "onDepthBoxChanged\0state\0onRadiusValueChanged\0"
    "value\0onSpokesValueChanged\0onAddLOS\0"
    "onRemoveSelectedLOS\0onEditSelectedLOS\0"
    "onCreateFinished\0result\0onEditFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_osgEarth__QtGui__LOSControlWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       9,    1,   79,    2, 0x08 /* Private */,
      11,    1,   82,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    1,   88,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void osgEarth::QtGui::LOSControlWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LOSControlWidget *_t = static_cast<LOSControlWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->onItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->onItemSelectionChanged(); break;
        case 3: _t->onDepthBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onRadiusValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->onSpokesValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onAddLOS(); break;
        case 7: _t->onRemoveSelectedLOS(); break;
        case 8: _t->onEditSelectedLOS(); break;
        case 9: _t->onCreateFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onEditFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject osgEarth::QtGui::LOSControlWidget::staticMetaObject = {
    { &CollapsiblePairWidget::staticMetaObject, qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget.data,
      qt_meta_data_osgEarth__QtGui__LOSControlWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *osgEarth::QtGui::LOSControlWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *osgEarth::QtGui::LOSControlWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_osgEarth__QtGui__LOSControlWidget.stringdata0))
        return static_cast<void*>(const_cast< LOSControlWidget*>(this));
    return CollapsiblePairWidget::qt_metacast(_clname);
}

int osgEarth::QtGui::LOSControlWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CollapsiblePairWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
