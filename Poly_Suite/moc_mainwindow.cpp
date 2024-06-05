/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Downloads/VIP/Poly_Suit_Final/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[74];
    char stringdata0[1900];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "updateUI1Signal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "text"
QT_MOC_LITERAL(4, 33, 12), // "seltabSignal"
QT_MOC_LITERAL(5, 46, 19), // "on_pblaunch_clicked"
QT_MOC_LITERAL(6, 66, 20), // "on_b_StopAde_clicked"
QT_MOC_LITERAL(7, 87, 20), // "on_pblaunch_released"
QT_MOC_LITERAL(8, 108, 21), // "on_b_StopAde_released"
QT_MOC_LITERAL(9, 130, 21), // "on_checkBox_2_clicked"
QT_MOC_LITERAL(10, 152, 23), // "on_actionexit_triggered"
QT_MOC_LITERAL(11, 176, 25), // "on_b_sel_scenario_clicked"
QT_MOC_LITERAL(12, 202, 25), // "on_b_run_scenario_clicked"
QT_MOC_LITERAL(13, 228, 26), // "on_b_stop_scenario_clicked"
QT_MOC_LITERAL(14, 255, 25), // "on_treeWidget_itemClicked"
QT_MOC_LITERAL(15, 281, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 298, 4), // "item"
QT_MOC_LITERAL(17, 303, 6), // "column"
QT_MOC_LITERAL(18, 310, 21), // "on_checkBox_3_clicked"
QT_MOC_LITERAL(19, 332, 30), // "on_b_control_start_ade_clicked"
QT_MOC_LITERAL(20, 363, 33), // "on_b_control_sel_scenario_cli..."
QT_MOC_LITERAL(21, 397, 33), // "on_b_control_run_scenario_cli..."
QT_MOC_LITERAL(22, 431, 32), // "on_treeWidgetControl_itemClicked"
QT_MOC_LITERAL(23, 464, 31), // "on_b_control_showreport_clicked"
QT_MOC_LITERAL(24, 496, 28), // "on_b_control_stopAde_clicked"
QT_MOC_LITERAL(25, 525, 34), // "on_b_control_stop_scenario_cl..."
QT_MOC_LITERAL(26, 560, 36), // "on_listWidgetSceneSelect_item..."
QT_MOC_LITERAL(27, 597, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(28, 614, 39), // "on_listWidgetSceneSelectDSU_i..."
QT_MOC_LITERAL(29, 654, 11), // "fileChanged"
QT_MOC_LITERAL(30, 666, 4), // "path"
QT_MOC_LITERAL(31, 671, 10), // "fileModify"
QT_MOC_LITERAL(32, 682, 11), // "fileWatcher"
QT_MOC_LITERAL(33, 694, 20), // "createTempRecordPath"
QT_MOC_LITERAL(34, 715, 12), // "executeShell"
QT_MOC_LITERAL(35, 728, 26), // "on_scenic_activate_clicked"
QT_MOC_LITERAL(36, 755, 29), // "on_run_scenic_control_clicked"
QT_MOC_LITERAL(37, 785, 25), // "on_b_showreport_2_clicked"
QT_MOC_LITERAL(38, 811, 28), // "on_scenic_activate_2_clicked"
QT_MOC_LITERAL(39, 840, 21), // "on_avp_button_clicked"
QT_MOC_LITERAL(40, 862, 24), // "on_initial_pos_b_clicked"
QT_MOC_LITERAL(41, 887, 21), // "on_goal_pos_b_clicked"
QT_MOC_LITERAL(42, 909, 23), // "on_avp_button_2_clicked"
QT_MOC_LITERAL(43, 933, 28), // "on_scenic_activate_3_clicked"
QT_MOC_LITERAL(44, 962, 26), // "on_initial_pos_b_2_clicked"
QT_MOC_LITERAL(45, 989, 23), // "on_goal_pos_b_2_clicked"
QT_MOC_LITERAL(46, 1013, 29), // "on_ckbox_localization_clicked"
QT_MOC_LITERAL(47, 1043, 29), // "on_ckbox_PathPlanning_clicked"
QT_MOC_LITERAL(48, 1073, 42), // "on_treeWid_local_select_scrip..."
QT_MOC_LITERAL(49, 1116, 33), // "on_btn_local_sel_scenario_cli..."
QT_MOC_LITERAL(50, 1150, 29), // "on_btn_local_adeStart_clicked"
QT_MOC_LITERAL(51, 1180, 28), // "on_btn_local_StopAde_clicked"
QT_MOC_LITERAL(52, 1209, 41), // "on_listWid_local_scene_select..."
QT_MOC_LITERAL(53, 1251, 33), // "on_btn_local_scenic_count_cli..."
QT_MOC_LITERAL(54, 1285, 31), // "on_btn_local_scenic_run_clicked"
QT_MOC_LITERAL(55, 1317, 33), // "on_btn_local_run_scenario_cli..."
QT_MOC_LITERAL(56, 1351, 34), // "on_btn_local_stop_scenario_cl..."
QT_MOC_LITERAL(57, 1386, 31), // "on_btn_local_showreport_clicked"
QT_MOC_LITERAL(58, 1418, 24), // "on_btn_local_avp_clicked"
QT_MOC_LITERAL(59, 1443, 32), // "on_btn_local_initial_pos_clicked"
QT_MOC_LITERAL(60, 1476, 29), // "on_btn_local_goal_pos_clicked"
QT_MOC_LITERAL(61, 1506, 26), // "on_btn_pp_adeStart_clicked"
QT_MOC_LITERAL(62, 1533, 30), // "on_btn_pp_sel_scenario_clicked"
QT_MOC_LITERAL(63, 1564, 25), // "on_btn_pp_StopAde_clicked"
QT_MOC_LITERAL(64, 1590, 38), // "on_listWid_pp_scene_select_it..."
QT_MOC_LITERAL(65, 1629, 39), // "on_treeWid_pp_select_script_i..."
QT_MOC_LITERAL(66, 1669, 30), // "on_btn_pp_scenic_count_clicked"
QT_MOC_LITERAL(67, 1700, 28), // "on_btn_pp_scenic_run_clicked"
QT_MOC_LITERAL(68, 1729, 30), // "on_btn_pp_run_scenario_clicked"
QT_MOC_LITERAL(69, 1760, 31), // "on_btn_pp_stop_scenario_clicked"
QT_MOC_LITERAL(70, 1792, 28), // "on_btn_pp_showreport_clicked"
QT_MOC_LITERAL(71, 1821, 21), // "on_btn_pp_avp_clicked"
QT_MOC_LITERAL(72, 1843, 29), // "on_btn_pp_initial_pos_clicked"
QT_MOC_LITERAL(73, 1873, 26) // "on_btn_pp_goal_pos_clicked"

    },
    "MainWindow\0updateUI1Signal\0\0text\0"
    "seltabSignal\0on_pblaunch_clicked\0"
    "on_b_StopAde_clicked\0on_pblaunch_released\0"
    "on_b_StopAde_released\0on_checkBox_2_clicked\0"
    "on_actionexit_triggered\0"
    "on_b_sel_scenario_clicked\0"
    "on_b_run_scenario_clicked\0"
    "on_b_stop_scenario_clicked\0"
    "on_treeWidget_itemClicked\0QTreeWidgetItem*\0"
    "item\0column\0on_checkBox_3_clicked\0"
    "on_b_control_start_ade_clicked\0"
    "on_b_control_sel_scenario_clicked\0"
    "on_b_control_run_scenario_clicked\0"
    "on_treeWidgetControl_itemClicked\0"
    "on_b_control_showreport_clicked\0"
    "on_b_control_stopAde_clicked\0"
    "on_b_control_stop_scenario_clicked\0"
    "on_listWidgetSceneSelect_itemClicked\0"
    "QListWidgetItem*\0"
    "on_listWidgetSceneSelectDSU_itemClicked\0"
    "fileChanged\0path\0fileModify\0fileWatcher\0"
    "createTempRecordPath\0executeShell\0"
    "on_scenic_activate_clicked\0"
    "on_run_scenic_control_clicked\0"
    "on_b_showreport_2_clicked\0"
    "on_scenic_activate_2_clicked\0"
    "on_avp_button_clicked\0on_initial_pos_b_clicked\0"
    "on_goal_pos_b_clicked\0on_avp_button_2_clicked\0"
    "on_scenic_activate_3_clicked\0"
    "on_initial_pos_b_2_clicked\0"
    "on_goal_pos_b_2_clicked\0"
    "on_ckbox_localization_clicked\0"
    "on_ckbox_PathPlanning_clicked\0"
    "on_treeWid_local_select_script_itemClicked\0"
    "on_btn_local_sel_scenario_clicked\0"
    "on_btn_local_adeStart_clicked\0"
    "on_btn_local_StopAde_clicked\0"
    "on_listWid_local_scene_select_itemClicked\0"
    "on_btn_local_scenic_count_clicked\0"
    "on_btn_local_scenic_run_clicked\0"
    "on_btn_local_run_scenario_clicked\0"
    "on_btn_local_stop_scenario_clicked\0"
    "on_btn_local_showreport_clicked\0"
    "on_btn_local_avp_clicked\0"
    "on_btn_local_initial_pos_clicked\0"
    "on_btn_local_goal_pos_clicked\0"
    "on_btn_pp_adeStart_clicked\0"
    "on_btn_pp_sel_scenario_clicked\0"
    "on_btn_pp_StopAde_clicked\0"
    "on_listWid_pp_scene_select_itemClicked\0"
    "on_treeWid_pp_select_script_itemClicked\0"
    "on_btn_pp_scenic_count_clicked\0"
    "on_btn_pp_scenic_run_clicked\0"
    "on_btn_pp_run_scenario_clicked\0"
    "on_btn_pp_stop_scenario_clicked\0"
    "on_btn_pp_showreport_clicked\0"
    "on_btn_pp_avp_clicked\0"
    "on_btn_pp_initial_pos_clicked\0"
    "on_btn_pp_goal_pos_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  344,    2, 0x06 /* Public */,
       4,    1,  347,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  350,    2, 0x08 /* Private */,
       6,    0,  351,    2, 0x08 /* Private */,
       7,    0,  352,    2, 0x08 /* Private */,
       8,    0,  353,    2, 0x08 /* Private */,
       9,    0,  354,    2, 0x08 /* Private */,
      10,    0,  355,    2, 0x08 /* Private */,
      11,    0,  356,    2, 0x08 /* Private */,
      12,    0,  357,    2, 0x08 /* Private */,
      13,    0,  358,    2, 0x08 /* Private */,
      14,    2,  359,    2, 0x08 /* Private */,
      18,    0,  364,    2, 0x08 /* Private */,
      19,    0,  365,    2, 0x08 /* Private */,
      20,    0,  366,    2, 0x08 /* Private */,
      21,    0,  367,    2, 0x08 /* Private */,
      22,    2,  368,    2, 0x08 /* Private */,
      23,    0,  373,    2, 0x08 /* Private */,
      24,    0,  374,    2, 0x08 /* Private */,
      25,    0,  375,    2, 0x08 /* Private */,
      26,    1,  376,    2, 0x08 /* Private */,
      28,    1,  379,    2, 0x08 /* Private */,
      29,    1,  382,    2, 0x08 /* Private */,
      31,    0,  385,    2, 0x08 /* Private */,
      32,    0,  386,    2, 0x08 /* Private */,
      33,    0,  387,    2, 0x08 /* Private */,
      34,    1,  388,    2, 0x08 /* Private */,
      35,    0,  391,    2, 0x08 /* Private */,
      36,    0,  392,    2, 0x08 /* Private */,
      37,    0,  393,    2, 0x08 /* Private */,
      38,    0,  394,    2, 0x08 /* Private */,
      39,    0,  395,    2, 0x08 /* Private */,
      40,    0,  396,    2, 0x08 /* Private */,
      41,    0,  397,    2, 0x08 /* Private */,
      42,    0,  398,    2, 0x08 /* Private */,
      43,    0,  399,    2, 0x08 /* Private */,
      44,    0,  400,    2, 0x08 /* Private */,
      45,    0,  401,    2, 0x08 /* Private */,
      46,    0,  402,    2, 0x08 /* Private */,
      47,    0,  403,    2, 0x08 /* Private */,
      48,    2,  404,    2, 0x08 /* Private */,
      49,    0,  409,    2, 0x08 /* Private */,
      50,    0,  410,    2, 0x08 /* Private */,
      51,    0,  411,    2, 0x08 /* Private */,
      52,    1,  412,    2, 0x08 /* Private */,
      53,    0,  415,    2, 0x08 /* Private */,
      54,    0,  416,    2, 0x08 /* Private */,
      55,    0,  417,    2, 0x08 /* Private */,
      56,    0,  418,    2, 0x08 /* Private */,
      57,    0,  419,    2, 0x08 /* Private */,
      58,    0,  420,    2, 0x08 /* Private */,
      59,    0,  421,    2, 0x08 /* Private */,
      60,    0,  422,    2, 0x08 /* Private */,
      61,    0,  423,    2, 0x08 /* Private */,
      62,    0,  424,    2, 0x08 /* Private */,
      63,    0,  425,    2, 0x08 /* Private */,
      64,    1,  426,    2, 0x08 /* Private */,
      65,    2,  429,    2, 0x08 /* Private */,
      66,    0,  434,    2, 0x08 /* Private */,
      67,    0,  435,    2, 0x08 /* Private */,
      68,    0,  436,    2, 0x08 /* Private */,
      69,    0,  437,    2, 0x08 /* Private */,
      70,    0,  438,    2, 0x08 /* Private */,
      71,    0,  439,    2, 0x08 /* Private */,
      72,    0,  440,    2, 0x08 /* Private */,
      73,    0,  441,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    2,

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
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   16,
    QMetaType::Void, 0x80000000 | 27,   16,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
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
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   16,
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
    QMetaType::Void, 0x80000000 | 27,   16,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateUI1Signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->seltabSignal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->on_pblaunch_clicked(); break;
        case 3: _t->on_b_StopAde_clicked(); break;
        case 4: _t->on_pblaunch_released(); break;
        case 5: _t->on_b_StopAde_released(); break;
        case 6: _t->on_checkBox_2_clicked(); break;
        case 7: _t->on_actionexit_triggered(); break;
        case 8: _t->on_b_sel_scenario_clicked(); break;
        case 9: _t->on_b_run_scenario_clicked(); break;
        case 10: _t->on_b_stop_scenario_clicked(); break;
        case 11: _t->on_treeWidget_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->on_checkBox_3_clicked(); break;
        case 13: _t->on_b_control_start_ade_clicked(); break;
        case 14: _t->on_b_control_sel_scenario_clicked(); break;
        case 15: _t->on_b_control_run_scenario_clicked(); break;
        case 16: _t->on_treeWidgetControl_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_b_control_showreport_clicked(); break;
        case 18: _t->on_b_control_stopAde_clicked(); break;
        case 19: _t->on_b_control_stop_scenario_clicked(); break;
        case 20: _t->on_listWidgetSceneSelect_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 21: _t->on_listWidgetSceneSelectDSU_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 22: _t->fileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->fileModify(); break;
        case 24: _t->fileWatcher(); break;
        case 25: _t->createTempRecordPath(); break;
        case 26: _t->executeShell((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->on_scenic_activate_clicked(); break;
        case 28: _t->on_run_scenic_control_clicked(); break;
        case 29: _t->on_b_showreport_2_clicked(); break;
        case 30: _t->on_scenic_activate_2_clicked(); break;
        case 31: _t->on_avp_button_clicked(); break;
        case 32: _t->on_initial_pos_b_clicked(); break;
        case 33: _t->on_goal_pos_b_clicked(); break;
        case 34: _t->on_avp_button_2_clicked(); break;
        case 35: _t->on_scenic_activate_3_clicked(); break;
        case 36: _t->on_initial_pos_b_2_clicked(); break;
        case 37: _t->on_goal_pos_b_2_clicked(); break;
        case 38: _t->on_ckbox_localization_clicked(); break;
        case 39: _t->on_ckbox_PathPlanning_clicked(); break;
        case 40: _t->on_treeWid_local_select_script_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->on_btn_local_sel_scenario_clicked(); break;
        case 42: _t->on_btn_local_adeStart_clicked(); break;
        case 43: _t->on_btn_local_StopAde_clicked(); break;
        case 44: _t->on_listWid_local_scene_select_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 45: _t->on_btn_local_scenic_count_clicked(); break;
        case 46: _t->on_btn_local_scenic_run_clicked(); break;
        case 47: _t->on_btn_local_run_scenario_clicked(); break;
        case 48: _t->on_btn_local_stop_scenario_clicked(); break;
        case 49: _t->on_btn_local_showreport_clicked(); break;
        case 50: _t->on_btn_local_avp_clicked(); break;
        case 51: _t->on_btn_local_initial_pos_clicked(); break;
        case 52: _t->on_btn_local_goal_pos_clicked(); break;
        case 53: _t->on_btn_pp_adeStart_clicked(); break;
        case 54: _t->on_btn_pp_sel_scenario_clicked(); break;
        case 55: _t->on_btn_pp_StopAde_clicked(); break;
        case 56: _t->on_listWid_pp_scene_select_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 57: _t->on_treeWid_pp_select_script_itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 58: _t->on_btn_pp_scenic_count_clicked(); break;
        case 59: _t->on_btn_pp_scenic_run_clicked(); break;
        case 60: _t->on_btn_pp_run_scenario_clicked(); break;
        case 61: _t->on_btn_pp_stop_scenario_clicked(); break;
        case 62: { int _r = _t->on_btn_pp_showreport_clicked();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 63: _t->on_btn_pp_avp_clicked(); break;
        case 64: _t->on_btn_pp_initial_pos_clicked(); break;
        case 65: _t->on_btn_pp_goal_pos_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::updateUI1Signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::seltabSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 66;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::updateUI1Signal(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::seltabSignal(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
