/****************************************************************************
** Meta object code from reading C++ file 'DlgWbqd_LoadExcel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../DlgWbqd_LoadExcel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgWbqd_LoadExcel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDlgWbqd_LoadExcel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   20,   19,   19, 0x0a,
      78,   73,   19,   19, 0x0a,
     126,   19,   19,   19, 0x0a,
     154,   19,   19,   19, 0x0a,
     163,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDlgWbqd_LoadExcel[] = {
    "CDlgWbqd_LoadExcel\0\0curSel\0"
    "On_ComboBoxSheet_CurrentIndexChanged(QString)\0"
    "item\0On_tableViewContent_DataChanged(QStandardItem*)\0"
    "On_pushButtonSave_Clicked()\0accept()\0"
    "reject()\0"
};

void CDlgWbqd_LoadExcel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDlgWbqd_LoadExcel *_t = static_cast<CDlgWbqd_LoadExcel *>(_o);
        switch (_id) {
        case 0: _t->On_ComboBoxSheet_CurrentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->On_tableViewContent_DataChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 2: _t->On_pushButtonSave_Clicked(); break;
        case 3: _t->accept(); break;
        case 4: _t->reject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDlgWbqd_LoadExcel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDlgWbqd_LoadExcel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDlgWbqd_LoadExcel,
      qt_meta_data_CDlgWbqd_LoadExcel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDlgWbqd_LoadExcel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDlgWbqd_LoadExcel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDlgWbqd_LoadExcel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgWbqd_LoadExcel))
        return static_cast<void*>(const_cast< CDlgWbqd_LoadExcel*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDlgWbqd_LoadExcel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
