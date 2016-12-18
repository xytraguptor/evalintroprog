/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FileExplorer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_action_Search_triggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(4, 64, 30), // "on_actionShow_Treeview_toggled"
QT_MOC_LITERAL(5, 95, 4), // "arg1"
QT_MOC_LITERAL(6, 100, 23), // "on_actionLister_toggled"
QT_MOC_LITERAL(7, 124, 37), // "on_dockWidgetLister_visibilit..."
QT_MOC_LITERAL(8, 162, 7), // "visible"
QT_MOC_LITERAL(9, 170, 19), // "on_treeView_clicked"
QT_MOC_LITERAL(10, 190, 5), // "index"
QT_MOC_LITERAL(11, 196, 33), // "on_actionFileListViewMode_tog..."
QT_MOC_LITERAL(12, 230, 19), // "showFileContextMenu"
QT_MOC_LITERAL(13, 250, 21), // "contextMenuFileRename"
QT_MOC_LITERAL(14, 272, 21), // "contextMenuFileConcat"
QT_MOC_LITERAL(15, 294, 18), // "contextMenuFileCut"
QT_MOC_LITERAL(16, 313, 19), // "contextMenuFileCopy"
QT_MOC_LITERAL(17, 333, 20), // "contextMenuFilePaste"
QT_MOC_LITERAL(18, 354, 21), // "contextMenuFileDelete"
QT_MOC_LITERAL(19, 376, 25) // "contextMenuFileProperties"

    },
    "MainWindow\0on_action_Search_triggered\0"
    "\0on_actionAbout_triggered\0"
    "on_actionShow_Treeview_toggled\0arg1\0"
    "on_actionLister_toggled\0"
    "on_dockWidgetLister_visibilityChanged\0"
    "visible\0on_treeView_clicked\0index\0"
    "on_actionFileListViewMode_toggled\0"
    "showFileContextMenu\0contextMenuFileRename\0"
    "contextMenuFileConcat\0contextMenuFileCut\0"
    "contextMenuFileCopy\0contextMenuFilePaste\0"
    "contextMenuFileDelete\0contextMenuFileProperties"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       9,    1,  100,    2, 0x08 /* Private */,
      11,    1,  103,    2, 0x08 /* Private */,
      12,    1,  106,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QModelIndex,   10,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_Search_triggered(); break;
        case 1: _t->on_actionAbout_triggered(); break;
        case 2: _t->on_actionShow_Treeview_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actionLister_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_dockWidgetLister_visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_treeView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_actionFileListViewMode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->showFileContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 8: _t->contextMenuFileRename(); break;
        case 9: _t->contextMenuFileConcat(); break;
        case 10: _t->contextMenuFileCut(); break;
        case 11: _t->contextMenuFileCopy(); break;
        case 12: _t->contextMenuFilePaste(); break;
        case 13: _t->contextMenuFileDelete(); break;
        case 14: _t->contextMenuFileProperties(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
