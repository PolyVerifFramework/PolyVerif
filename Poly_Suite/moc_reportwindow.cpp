/****************************************************************************
** Meta object code from reading C++ file 'reportwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rahul/QT_Project/PolySuite_Project/UI_Suit_15May/UI_Suit/reportwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reportwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_reportwindow_t {
    QByteArrayData data[16];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_reportwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_reportwindow_t qt_meta_stringdata_reportwindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "reportwindow"
QT_MOC_LITERAL(1, 13, 17), // "updateUI2TextSlot"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "text"
QT_MOC_LITERAL(4, 37, 10), // "seltabSlot"
QT_MOC_LITERAL(5, 48, 34), // "on_treeWidgetReportDir_itemCl..."
QT_MOC_LITERAL(6, 83, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 100, 4), // "item"
QT_MOC_LITERAL(8, 105, 6), // "column"
QT_MOC_LITERAL(9, 112, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 134, 28), // "on_b_generateReportC_clicked"
QT_MOC_LITERAL(11, 163, 12), // "executeShell"
QT_MOC_LITERAL(12, 176, 4), // "path"
QT_MOC_LITERAL(13, 181, 24), // "on_b_showReportC_clicked"
QT_MOC_LITERAL(14, 206, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(15, 230, 23) // "on_pushButton_3_clicked"

    },
    "reportwindow\0updateUI2TextSlot\0\0text\0"
    "seltabSlot\0on_treeWidgetReportDir_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_pushButton_clicked\0"
    "on_b_generateReportC_clicked\0executeShell\0"
    "path\0on_b_showReportC_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_reportwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    2,   65,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    1,   72,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void reportwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        reportwindow *_t = static_cast<reportwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateUI2TextSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->seltabSlot((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->on_treeWidgetReportDir_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_b_generateReportC_clicked(); break;
        case 5: _t->executeShell((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_b_showReportC_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject reportwindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_reportwindow.data,
      qt_meta_data_reportwindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *reportwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reportwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_reportwindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int reportwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
