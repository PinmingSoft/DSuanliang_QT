/****************************************************************************
** Meta object code from reading C++ file 'DlgQDDE.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../DlgQDDE.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgQDDE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDlgQDDE[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      36,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   62,    9,    9, 0x0a,
     104,   62,    9,    9, 0x0a,
     140,   62,    9,    9, 0x0a,
     182,   62,    9,    9, 0x0a,
     224,   62,    9,    9, 0x0a,
     266,    9,    9,    9, 0x0a,
     276,    9,    9,    9, 0x0a,
     286,    9,    9,    9, 0x0a,
     313,    9,    9,    9, 0x0a,
     340,    9,    9,    9, 0x0a,
     362,    9,    9,    9, 0x0a,
     383,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDlgQDDE[] = {
    "CDlgQDDE\0\0signal_AddQD(const WBQD*)\0"
    "signal_AddDE(const WBQD*)\0index\0"
    "On_ClickedTree_View_DE(QModelIndex)\0"
    "On_ClickedTree_View_QD(QModelIndex)\0"
    "On_DoubleClickedTree_View_QD(QModelIndex)\0"
    "On_DoubleClickedList_View_DE(QModelIndex)\0"
    "On_DoubleClickedList_View_QD(QModelIndex)\0"
    "OnBtnDe()\0OnBtnQd()\0On_ClickedRadioButton_DE()\0"
    "On_ClickedRadioButton_QD()\0"
    "On_ClickedTree_Node()\0On_ActiveComBox_QD()\0"
    "On_ActiveComBox_DE()\0"
};

void CDlgQDDE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDlgQDDE *_t = static_cast<CDlgQDDE *>(_o);
        switch (_id) {
        case 0: _t->signal_AddQD((*reinterpret_cast< const WBQD*(*)>(_a[1]))); break;
        case 1: _t->signal_AddDE((*reinterpret_cast< const WBQD*(*)>(_a[1]))); break;
        case 2: _t->On_ClickedTree_View_DE((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->On_ClickedTree_View_QD((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->On_DoubleClickedTree_View_QD((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->On_DoubleClickedList_View_DE((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->On_DoubleClickedList_View_QD((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->OnBtnDe(); break;
        case 8: _t->OnBtnQd(); break;
        case 9: _t->On_ClickedRadioButton_DE(); break;
        case 10: _t->On_ClickedRadioButton_QD(); break;
        case 11: _t->On_ClickedTree_Node(); break;
        case 12: _t->On_ActiveComBox_QD(); break;
        case 13: _t->On_ActiveComBox_DE(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDlgQDDE::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDlgQDDE::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDlgQDDE,
      qt_meta_data_CDlgQDDE, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDlgQDDE::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDlgQDDE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDlgQDDE::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgQDDE))
        return static_cast<void*>(const_cast< CDlgQDDE*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDlgQDDE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CDlgQDDE::signal_AddQD(const WBQD * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDlgQDDE::signal_AddDE(const WBQD * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
