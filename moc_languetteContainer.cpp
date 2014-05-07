/****************************************************************************
** Meta object code from reading C++ file 'languetteContainer.h'
**
** Created: Thu May 1 17:32:04 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "languetteContainer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'languetteContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LanguetteContainer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      33,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LanguetteContainer[] = {
    "LanguetteContainer\0\0tableClick()\0"
    "ticketClick()\0"
};

void LanguetteContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LanguetteContainer *_t = static_cast<LanguetteContainer *>(_o);
        switch (_id) {
        case 0: _t->tableClick(); break;
        case 1: _t->ticketClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LanguetteContainer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LanguetteContainer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LanguetteContainer,
      qt_meta_data_LanguetteContainer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LanguetteContainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LanguetteContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LanguetteContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LanguetteContainer))
        return static_cast<void*>(const_cast< LanguetteContainer*>(this));
    return QWidget::qt_metacast(_clname);
}

int LanguetteContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
