/****************************************************************************
** Meta object code from reading C++ file 'WbqdStandardItemModel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../WbqdStandardItemModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WbqdStandardItemModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CWbqd_LoadExcelItemModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CWbqd_LoadExcelItemModel[] = {
    "CWbqd_LoadExcelItemModel\0"
};

void CWbqd_LoadExcelItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CWbqd_LoadExcelItemModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CWbqd_LoadExcelItemModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_CWbqd_LoadExcelItemModel,
      qt_meta_data_CWbqd_LoadExcelItemModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWbqd_LoadExcelItemModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWbqd_LoadExcelItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWbqd_LoadExcelItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWbqd_LoadExcelItemModel))
        return static_cast<void*>(const_cast< CWbqd_LoadExcelItemModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int CWbqd_LoadExcelItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CWbqdStandardItemModel[] = {

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
      24,   23,   23,   23, 0x0a,
      45,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CWbqdStandardItemModel[] = {
    "CWbqdStandardItemModel\0\0OnAddQD(const WBQD*)\0"
    "OnAddDE(const WBQD*)\0"
};

void CWbqdStandardItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CWbqdStandardItemModel *_t = static_cast<CWbqdStandardItemModel *>(_o);
        switch (_id) {
        case 0: _t->OnAddQD((*reinterpret_cast< const WBQD*(*)>(_a[1]))); break;
        case 1: _t->OnAddDE((*reinterpret_cast< const WBQD*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CWbqdStandardItemModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CWbqdStandardItemModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_CWbqdStandardItemModel,
      qt_meta_data_CWbqdStandardItemModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CWbqdStandardItemModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CWbqdStandardItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CWbqdStandardItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CWbqdStandardItemModel))
        return static_cast<void*>(const_cast< CWbqdStandardItemModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int CWbqdStandardItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
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
