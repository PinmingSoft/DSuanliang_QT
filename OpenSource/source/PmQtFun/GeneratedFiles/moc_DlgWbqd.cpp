/****************************************************************************
** Meta object code from reading C++ file 'DlgWbqd.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../DlgWbqd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DlgWbqd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDlgWbqd[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      32,    9,    9,    9, 0x0a,
      65,    9,    9,    9, 0x0a,
      94,    9,    9,    9, 0x0a,
     121,    9,    9,    9, 0x0a,
     157,  151,    9,    9, 0x0a,
     194,  151,    9,    9, 0x0a,
     242,  237,    9,    9, 0x0a,
     286,  237,    9,    9, 0x0a,
     331,  151,    9,    9, 0x0a,
     369,  151,    9,    9, 0x0a,
     407,  151,    9,    9, 0x0a,
     451,  151,    9,    9, 0x0a,
     491,  151,    9,    9, 0x0a,
     529,    9,    9,    9, 0x0a,
     564,    9,    9,    9, 0x0a,
     595,    9,    9,    9, 0x0a,
     625,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDlgWbqd[] = {
    "CDlgWbqd\0\0signal_clicked(WBQD*)\0"
    "On_pushButtonLoadExcel_Clicked()\0"
    "On_pushButtonUseQD_Clicked()\0"
    "On_pushButtonAdd_Clicked()\0"
    "On_pushButtonDelete_Clicked()\0index\0"
    "On_treeViewWbqd_Clicked(QModelIndex)\0"
    "On_treeViewWbqd_DoubleClicked(QModelIndex)\0"
    "item\0On_treeViewWbqd_ItemChanged(QStandardItem*)\0"
    "On_tableViewXMTZ_ItemChanged(QStandardItem*)\0"
    "On_tableViewXMTZ_pressed(QModelIndex)\0"
    "On_tableViewXMTZ_clicked(QModelIndex)\0"
    "On_tableViewXMTZ_doubleClicked(QModelIndex)\0"
    "On_tableViewXMTZ_activated(QModelIndex)\0"
    "On_tableViewXMTZ_entered(QModelIndex)\0"
    "On_tableViewXMTZ_viewportEntered()\0"
    "On_pushButtonRetract_Clicked()\0"
    "On_pushButtonExpend_Clicked()\0"
    "On_pushButtonMoveUp_Clicked()\0"
};

void CDlgWbqd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDlgWbqd *_t = static_cast<CDlgWbqd *>(_o);
        switch (_id) {
        case 0: _t->signal_clicked((*reinterpret_cast< WBQD*(*)>(_a[1]))); break;
        case 1: _t->On_pushButtonLoadExcel_Clicked(); break;
        case 2: _t->On_pushButtonUseQD_Clicked(); break;
        case 3: _t->On_pushButtonAdd_Clicked(); break;
        case 4: _t->On_pushButtonDelete_Clicked(); break;
        case 5: _t->On_treeViewWbqd_Clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->On_treeViewWbqd_DoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->On_treeViewWbqd_ItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 8: _t->On_tableViewXMTZ_ItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 9: _t->On_tableViewXMTZ_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->On_tableViewXMTZ_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 11: _t->On_tableViewXMTZ_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->On_tableViewXMTZ_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->On_tableViewXMTZ_entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->On_tableViewXMTZ_viewportEntered(); break;
        case 15: _t->On_pushButtonRetract_Clicked(); break;
        case 16: _t->On_pushButtonExpend_Clicked(); break;
        case 17: _t->On_pushButtonMoveUp_Clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDlgWbqd::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDlgWbqd::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDlgWbqd,
      qt_meta_data_CDlgWbqd, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDlgWbqd::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDlgWbqd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDlgWbqd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgWbqd))
        return static_cast<void*>(const_cast< CDlgWbqd*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDlgWbqd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void CDlgWbqd::signal_clicked(WBQD * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
