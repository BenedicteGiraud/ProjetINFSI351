/****************************************************************************
** Meta object code from reading C++ file 'headband_item.h'
**
** Created: Thu May 1 17:32:02 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headband_item.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headband_item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Headband_Item[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   15,   14,   14, 0x05,
      33,   14,   14,   14, 0x05,
      51,   49,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Headband_Item[] = {
    "Headband_Item\0\0dx\0scrolling(int)\0"
    "setNormalMode()\0w\0setExtensibleMode(Headband_Item*)\0"
};

void Headband_Item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Headband_Item *_t = static_cast<Headband_Item *>(_o);
        switch (_id) {
        case 0: _t->scrolling((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setNormalMode(); break;
        case 2: _t->setExtensibleMode((*reinterpret_cast< Headband_Item*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Headband_Item::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Headband_Item::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Headband_Item,
      qt_meta_data_Headband_Item, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Headband_Item::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Headband_Item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Headband_Item::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Headband_Item))
        return static_cast<void*>(const_cast< Headband_Item*>(this));
    return QWidget::qt_metacast(_clname);
}

int Headband_Item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Headband_Item::scrolling(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Headband_Item::setNormalMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Headband_Item::setExtensibleMode(Headband_Item * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
