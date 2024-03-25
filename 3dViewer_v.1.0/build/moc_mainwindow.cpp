/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../front/mainwindow.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_fileBtn_clicked",
    "",
    "on_scaleMinus_clicked",
    "on_scalePlus_clicked",
    "on_rotateXplus_clicked",
    "on_rotateXminus_clicked",
    "on_rotateYplus_clicked",
    "on_rotateYminus_clicked",
    "on_rotateZminus_clicked",
    "on_rotateZplus_clicked",
    "on_moveXleft_clicked",
    "on_moveXright_clicked",
    "on_moveYdown_clicked",
    "on_moveYup_clicked",
    "on_moveZfar_clicked",
    "on_moveZnear_clicked",
    "on_PB_Normalize_clicked",
    "on_actionBackground_color_triggered",
    "on_actionParallel_triggered",
    "on_actionCentral_triggered",
    "on_actionSize_Edge_triggered",
    "on_actionColor_Edge_triggered",
    "on_actionSolidLine_Edge_triggered",
    "on_actionLineDots_Edge_triggered",
    "on_actionSize_Vertex_triggered",
    "on_actionColor_Vertex_triggered",
    "on_actionNone_triggered",
    "on_actionCircle_triggered",
    "on_actionSquere_triggered",
    "on_actionOnly_edge_triggered",
    "on_actionOnly_vertex_triggered",
    "on_actionMix_triggered",
    "on_actionSave_settings_triggered",
    "on_actionImage_triggered",
    "on_actionGIF_triggered",
    "on_stopBtn_clicked",
    "setInfo",
    "fileName"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[78];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[21];
    char stringdata5[23];
    char stringdata6[24];
    char stringdata7[23];
    char stringdata8[24];
    char stringdata9[24];
    char stringdata10[23];
    char stringdata11[21];
    char stringdata12[22];
    char stringdata13[21];
    char stringdata14[19];
    char stringdata15[20];
    char stringdata16[21];
    char stringdata17[24];
    char stringdata18[36];
    char stringdata19[28];
    char stringdata20[27];
    char stringdata21[29];
    char stringdata22[30];
    char stringdata23[34];
    char stringdata24[33];
    char stringdata25[31];
    char stringdata26[32];
    char stringdata27[24];
    char stringdata28[26];
    char stringdata29[26];
    char stringdata30[29];
    char stringdata31[31];
    char stringdata32[23];
    char stringdata33[33];
    char stringdata34[25];
    char stringdata35[23];
    char stringdata36[19];
    char stringdata37[8];
    char stringdata38[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 18),  // "on_fileBtn_clicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 21),  // "on_scaleMinus_clicked"
        QT_MOC_LITERAL(53, 20),  // "on_scalePlus_clicked"
        QT_MOC_LITERAL(74, 22),  // "on_rotateXplus_clicked"
        QT_MOC_LITERAL(97, 23),  // "on_rotateXminus_clicked"
        QT_MOC_LITERAL(121, 22),  // "on_rotateYplus_clicked"
        QT_MOC_LITERAL(144, 23),  // "on_rotateYminus_clicked"
        QT_MOC_LITERAL(168, 23),  // "on_rotateZminus_clicked"
        QT_MOC_LITERAL(192, 22),  // "on_rotateZplus_clicked"
        QT_MOC_LITERAL(215, 20),  // "on_moveXleft_clicked"
        QT_MOC_LITERAL(236, 21),  // "on_moveXright_clicked"
        QT_MOC_LITERAL(258, 20),  // "on_moveYdown_clicked"
        QT_MOC_LITERAL(279, 18),  // "on_moveYup_clicked"
        QT_MOC_LITERAL(298, 19),  // "on_moveZfar_clicked"
        QT_MOC_LITERAL(318, 20),  // "on_moveZnear_clicked"
        QT_MOC_LITERAL(339, 23),  // "on_PB_Normalize_clicked"
        QT_MOC_LITERAL(363, 35),  // "on_actionBackground_color_tri..."
        QT_MOC_LITERAL(399, 27),  // "on_actionParallel_triggered"
        QT_MOC_LITERAL(427, 26),  // "on_actionCentral_triggered"
        QT_MOC_LITERAL(454, 28),  // "on_actionSize_Edge_triggered"
        QT_MOC_LITERAL(483, 29),  // "on_actionColor_Edge_triggered"
        QT_MOC_LITERAL(513, 33),  // "on_actionSolidLine_Edge_trigg..."
        QT_MOC_LITERAL(547, 32),  // "on_actionLineDots_Edge_triggered"
        QT_MOC_LITERAL(580, 30),  // "on_actionSize_Vertex_triggered"
        QT_MOC_LITERAL(611, 31),  // "on_actionColor_Vertex_triggered"
        QT_MOC_LITERAL(643, 23),  // "on_actionNone_triggered"
        QT_MOC_LITERAL(667, 25),  // "on_actionCircle_triggered"
        QT_MOC_LITERAL(693, 25),  // "on_actionSquere_triggered"
        QT_MOC_LITERAL(719, 28),  // "on_actionOnly_edge_triggered"
        QT_MOC_LITERAL(748, 30),  // "on_actionOnly_vertex_triggered"
        QT_MOC_LITERAL(779, 22),  // "on_actionMix_triggered"
        QT_MOC_LITERAL(802, 32),  // "on_actionSave_settings_triggered"
        QT_MOC_LITERAL(835, 24),  // "on_actionImage_triggered"
        QT_MOC_LITERAL(860, 22),  // "on_actionGIF_triggered"
        QT_MOC_LITERAL(883, 18),  // "on_stopBtn_clicked"
        QT_MOC_LITERAL(902, 7),  // "setInfo"
        QT_MOC_LITERAL(910, 8)   // "fileName"
    },
    "MainWindow",
    "on_fileBtn_clicked",
    "",
    "on_scaleMinus_clicked",
    "on_scalePlus_clicked",
    "on_rotateXplus_clicked",
    "on_rotateXminus_clicked",
    "on_rotateYplus_clicked",
    "on_rotateYminus_clicked",
    "on_rotateZminus_clicked",
    "on_rotateZplus_clicked",
    "on_moveXleft_clicked",
    "on_moveXright_clicked",
    "on_moveYdown_clicked",
    "on_moveYup_clicked",
    "on_moveZfar_clicked",
    "on_moveZnear_clicked",
    "on_PB_Normalize_clicked",
    "on_actionBackground_color_triggered",
    "on_actionParallel_triggered",
    "on_actionCentral_triggered",
    "on_actionSize_Edge_triggered",
    "on_actionColor_Edge_triggered",
    "on_actionSolidLine_Edge_triggered",
    "on_actionLineDots_Edge_triggered",
    "on_actionSize_Vertex_triggered",
    "on_actionColor_Vertex_triggered",
    "on_actionNone_triggered",
    "on_actionCircle_triggered",
    "on_actionSquere_triggered",
    "on_actionOnly_edge_triggered",
    "on_actionOnly_vertex_triggered",
    "on_actionMix_triggered",
    "on_actionSave_settings_triggered",
    "on_actionImage_triggered",
    "on_actionGIF_triggered",
    "on_stopBtn_clicked",
    "setInfo",
    "fileName"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  230,    2, 0x08,    1 /* Private */,
       3,    0,  231,    2, 0x08,    2 /* Private */,
       4,    0,  232,    2, 0x08,    3 /* Private */,
       5,    0,  233,    2, 0x08,    4 /* Private */,
       6,    0,  234,    2, 0x08,    5 /* Private */,
       7,    0,  235,    2, 0x08,    6 /* Private */,
       8,    0,  236,    2, 0x08,    7 /* Private */,
       9,    0,  237,    2, 0x08,    8 /* Private */,
      10,    0,  238,    2, 0x08,    9 /* Private */,
      11,    0,  239,    2, 0x08,   10 /* Private */,
      12,    0,  240,    2, 0x08,   11 /* Private */,
      13,    0,  241,    2, 0x08,   12 /* Private */,
      14,    0,  242,    2, 0x08,   13 /* Private */,
      15,    0,  243,    2, 0x08,   14 /* Private */,
      16,    0,  244,    2, 0x08,   15 /* Private */,
      17,    0,  245,    2, 0x08,   16 /* Private */,
      18,    0,  246,    2, 0x08,   17 /* Private */,
      19,    0,  247,    2, 0x08,   18 /* Private */,
      20,    0,  248,    2, 0x08,   19 /* Private */,
      21,    0,  249,    2, 0x08,   20 /* Private */,
      22,    0,  250,    2, 0x08,   21 /* Private */,
      23,    0,  251,    2, 0x08,   22 /* Private */,
      24,    0,  252,    2, 0x08,   23 /* Private */,
      25,    0,  253,    2, 0x08,   24 /* Private */,
      26,    0,  254,    2, 0x08,   25 /* Private */,
      27,    0,  255,    2, 0x08,   26 /* Private */,
      28,    0,  256,    2, 0x08,   27 /* Private */,
      29,    0,  257,    2, 0x08,   28 /* Private */,
      30,    0,  258,    2, 0x08,   29 /* Private */,
      31,    0,  259,    2, 0x08,   30 /* Private */,
      32,    0,  260,    2, 0x08,   31 /* Private */,
      33,    0,  261,    2, 0x08,   32 /* Private */,
      34,    0,  262,    2, 0x08,   33 /* Private */,
      35,    0,  263,    2, 0x08,   34 /* Private */,
      36,    0,  264,    2, 0x08,   35 /* Private */,
      37,    1,  265,    2, 0x08,   36 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   38,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_fileBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scaleMinus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scalePlus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateXplus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateXminus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateYplus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateYminus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateZminus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotateZplus_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveXleft_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveXright_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveYdown_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveYup_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveZfar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moveZnear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_PB_Normalize_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionBackground_color_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionParallel_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCentral_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSize_Edge_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionColor_Edge_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSolidLine_Edge_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionLineDots_Edge_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSize_Vertex_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionColor_Vertex_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionNone_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionCircle_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSquere_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOnly_edge_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionOnly_vertex_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionMix_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSave_settings_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionImage_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionGIF_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_fileBtn_clicked(); break;
        case 1: _t->on_scaleMinus_clicked(); break;
        case 2: _t->on_scalePlus_clicked(); break;
        case 3: _t->on_rotateXplus_clicked(); break;
        case 4: _t->on_rotateXminus_clicked(); break;
        case 5: _t->on_rotateYplus_clicked(); break;
        case 6: _t->on_rotateYminus_clicked(); break;
        case 7: _t->on_rotateZminus_clicked(); break;
        case 8: _t->on_rotateZplus_clicked(); break;
        case 9: _t->on_moveXleft_clicked(); break;
        case 10: _t->on_moveXright_clicked(); break;
        case 11: _t->on_moveYdown_clicked(); break;
        case 12: _t->on_moveYup_clicked(); break;
        case 13: _t->on_moveZfar_clicked(); break;
        case 14: _t->on_moveZnear_clicked(); break;
        case 15: _t->on_PB_Normalize_clicked(); break;
        case 16: _t->on_actionBackground_color_triggered(); break;
        case 17: _t->on_actionParallel_triggered(); break;
        case 18: _t->on_actionCentral_triggered(); break;
        case 19: _t->on_actionSize_Edge_triggered(); break;
        case 20: _t->on_actionColor_Edge_triggered(); break;
        case 21: _t->on_actionSolidLine_Edge_triggered(); break;
        case 22: _t->on_actionLineDots_Edge_triggered(); break;
        case 23: _t->on_actionSize_Vertex_triggered(); break;
        case 24: _t->on_actionColor_Vertex_triggered(); break;
        case 25: _t->on_actionNone_triggered(); break;
        case 26: _t->on_actionCircle_triggered(); break;
        case 27: _t->on_actionSquere_triggered(); break;
        case 28: _t->on_actionOnly_edge_triggered(); break;
        case 29: _t->on_actionOnly_vertex_triggered(); break;
        case 30: _t->on_actionMix_triggered(); break;
        case 31: _t->on_actionSave_settings_triggered(); break;
        case 32: _t->on_actionImage_triggered(); break;
        case 33: _t->on_actionGIF_triggered(); break;
        case 34: _t->on_stopBtn_clicked(); break;
        case 35: _t->setInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 36;
    }
    return _id;
}
QT_WARNING_POP
