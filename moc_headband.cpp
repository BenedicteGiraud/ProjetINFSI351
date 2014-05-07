/****************************************************************************
** Meta object code from reading C++ file 'headband.h'
**
** Created: Thu May 1 18:25:37 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headband.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headband.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Headband[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      33,    9,    9,    9, 0x05,
      60,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   86,    9,    9, 0x0a,
     106,    9,    9,    9, 0x0a,
     121,  119,    9,    9, 0x0a,
     152,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Headband[] = {
    "Headband\0\0addHeadband(Headband*)\0"
    "itemSelect(Headband_Item*)\0"
    "closeRequested(Headband*)\0dx\0"
    "applyScroll(int)\0normalMode()\0w\0"
    "extensibleMode(Headband_Item*)\0"
    "plusOrMinusClicked()\0"
};

void Headband::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Headband *_t = static_cast<Headband *>(_o);
        switch (_id) {
        case 0: _t->addHeadband((*reinterpret_cast< Headband*(*)>(_a[1]))); break;
        case 1: _t->itemSelect((*reinterpret_cast< Headband_Item*(*)>(_a[1]))); break;
        case 2: _t->closeRequested((*reinterpret_cast< Headband*(*)>(_a[1]))); break;
        case 3: _t->applyScroll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->normalMode(); break;
        case 5: _t->extensibleMode((*reinterpret_cast< Headband_Item*(*)>(_a[1]))); break;
        case 6: _t->plusOrMinusClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Headband::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Headband::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Headband,
      qt_meta_data_Headband, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Headband::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Headband::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Headband::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Headband))
        return static_cast<void*>(const_cast< Headband*>(this));
    return QWidget::qt_metacast(_clname);
}

int Headband::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Headband::addHeadband(Headband * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Headband::itemSelect(Headband_Item * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Headband::closeRequested(Headband * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
