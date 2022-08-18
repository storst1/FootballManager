/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/main/mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[30];
    char stringdata0[415];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 31), // "on_StartingSceneNewGame_clicked"
QT_MOC_LITERAL(43, 0), // ""
QT_MOC_LITERAL(44, 50), // "on_NewGameSceneLeaguesComboBo..."
QT_MOC_LITERAL(95, 5), // "index"
QT_MOC_LITERAL(101, 37), // "on_NewGameScenePrevClubButton..."
QT_MOC_LITERAL(139, 37), // "on_NewGameSceneNextClubButton..."
QT_MOC_LITERAL(177, 34), // "on_NewGameSceneStartButton_cl..."
QT_MOC_LITERAL(212, 29), // "on_HomeSceneSSANation_clicked"
QT_MOC_LITERAL(242, 27), // "on_HomeSceneSSAName_clicked"
QT_MOC_LITERAL(270, 26), // "on_HomeSceneSSAPos_clicked"
QT_MOC_LITERAL(297, 26), // "on_HomeSceneSSAAge_clicked"
QT_MOC_LITERAL(324, 29), // "on_HomeSceneSSARating_clicked"
QT_MOC_LITERAL(354, 28), // "on_HomeSceneSSAValue_clicked"
QT_MOC_LITERAL(383, 31) // "on_HomeSceneNLTransfers_clicked"

    },
    "MainWindow\0on_StartingSceneNewGame_clicked\0"
    "\0on_NewGameSceneLeaguesComboBox_currentIndexChanged\0"
    "index\0on_NewGameScenePrevClubButton_clicked\0"
    "on_NewGameSceneNextClubButton_clicked\0"
    "on_NewGameSceneStartButton_clicked\0"
    "on_HomeSceneSSANation_clicked\0"
    "on_HomeSceneSSAName_clicked\0"
    "on_HomeSceneSSAPos_clicked\0"
    "on_HomeSceneSSAAge_clicked\0"
    "on_HomeSceneSSARating_clicked\0"
    "on_HomeSceneSSAValue_clicked\0"
    "on_HomeSceneNLTransfers_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    1,   87,    2, 0x08,    2 /* Private */,
       5,    0,   90,    2, 0x08,    4 /* Private */,
       6,    0,   91,    2, 0x08,    5 /* Private */,
       7,    0,   92,    2, 0x08,    6 /* Private */,
       8,    0,   93,    2, 0x08,    7 /* Private */,
       9,    0,   94,    2, 0x08,    8 /* Private */,
      10,    0,   95,    2, 0x08,    9 /* Private */,
      11,    0,   96,    2, 0x08,   10 /* Private */,
      12,    0,   97,    2, 0x08,   11 /* Private */,
      13,    0,   98,    2, 0x08,   12 /* Private */,
      14,    0,   99,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_StartingSceneNewGame_clicked(); break;
        case 1: _t->on_NewGameSceneLeaguesComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_NewGameScenePrevClubButton_clicked(); break;
        case 3: _t->on_NewGameSceneNextClubButton_clicked(); break;
        case 4: _t->on_NewGameSceneStartButton_clicked(); break;
        case 5: _t->on_HomeSceneSSANation_clicked(); break;
        case 6: _t->on_HomeSceneSSAName_clicked(); break;
        case 7: _t->on_HomeSceneSSAPos_clicked(); break;
        case 8: _t->on_HomeSceneSSAAge_clicked(); break;
        case 9: _t->on_HomeSceneSSARating_clicked(); break;
        case 10: _t->on_HomeSceneSSAValue_clicked(); break;
        case 11: _t->on_HomeSceneNLTransfers_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
