/****************************************************************************
** Meta object code from reading C++ file 'mypreview.h'
**
** Created: Wed Apr 17 14:43:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mypreview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypreview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyPreview[] = {

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
      11,   10,   10,   10, 0x08,
      37,   10,   10,   10, 0x08,
      63,   10,   10,   10, 0x08,
      89,   10,   10,   10, 0x08,
     117,  113,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyPreview[] = {
    "MyPreview\0\0on_toolButton_3_pressed()\0"
    "on_toolButton_3_clicked()\0"
    "on_toolButton_2_clicked()\0"
    "on_toolButton_clicked()\0x,y\0"
    "ShowCrissCross(int,int)\0"
};

void MyPreview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyPreview *_t = static_cast<MyPreview *>(_o);
        switch (_id) {
        case 0: _t->on_toolButton_3_pressed(); break;
        case 1: _t->on_toolButton_3_clicked(); break;
        case 2: _t->on_toolButton_2_clicked(); break;
        case 3: _t->on_toolButton_clicked(); break;
        case 4: _t->ShowCrissCross((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyPreview::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyPreview::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyPreview,
      qt_meta_data_MyPreview, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyPreview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyPreview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyPreview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyPreview))
        return static_cast<void*>(const_cast< MyPreview*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyPreview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
