/****************************************************************************
** Meta object code from reading C++ file 'sequencewindow.h'
**
** Created: Tue Apr 30 21:56:17 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sequencewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sequencewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SequenceWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      49,   47,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SequenceWindow[] = {
    "SequenceWindow\0\0endSequence(std::vector<Data>)\0"
    ",\0changeLabMW(int,int)\0changePosBtn()\0"
};

void SequenceWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SequenceWindow *_t = static_cast<SequenceWindow *>(_o);
        switch (_id) {
        case 0: _t->endSequence((*reinterpret_cast< std::vector<Data>(*)>(_a[1]))); break;
        case 1: _t->changeLabMW((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->changePosBtn(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SequenceWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequenceWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SequenceWindow,
      qt_meta_data_SequenceWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequenceWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequenceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequenceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequenceWindow))
        return static_cast<void*>(const_cast< SequenceWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int SequenceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SequenceWindow::endSequence(std::vector<Data> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SequenceWindow::changeLabMW(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
