/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionexit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *lbl_outputlog;
    QWidget *gridWidget;
    QWidget *horizontalWidget_4;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_5;
    QCheckBox *checkBox_2;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox_3;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *ckbox_localization;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *ckbox_PathPlanning;
    QSpacerItem *verticalSpacer;
    QCheckBox *ckbox_perception;
    QStackedWidget *stackedWidget;
    QWidget *localization_test_suite;
    QGroupBox *gbox_localization;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_btnTop;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_local_adeStart;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btn_local_sel_scenario;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *btn_local_StopAde;
    QSpacerItem *horizontalSpacer_22;
    QScrollArea *scrollScenarioList_2;
    QWidget *scrollAreaWidgetContents_2;
    QTreeWidget *treeWid_local_select_script;
    QLabel *lbl_sceneSelect;
    QListWidget *listWid_local_scene_select;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_btn_bottom;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *btn_local_avp;
    QSpacerItem *horizontalSpacer_30;
    QPushButton *btn_local_initial_pos;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *btn_local_goal_pos;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_btnMiddle;
    QSpacerItem *horizontalSpacer_32;
    QPushButton *btn_local_scenic_count;
    QSpacerItem *horizontalSpacer_33;
    QPushButton *btn_local_scenic_run;
    QSpacerItem *horizontalSpacer_34;
    QPushButton *btn_local_run_scenario;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *btn_local_stop_scenario;
    QSpacerItem *horizontalSpacer_36;
    QPushButton *btn_local_showreport;
    QWidget *path_planning_test_suite;
    QGroupBox *gbox_path_planning;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_btnMiddle_2;
    QSpacerItem *horizontalSpacer_37;
    QPushButton *btn_pp_scenic_count;
    QSpacerItem *horizontalSpacer_38;
    QPushButton *btn_pp_scenic_run;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *btn_pp_run_scenario;
    QSpacerItem *horizontalSpacer_40;
    QPushButton *btn_pp_stop_scenario;
    QSpacerItem *horizontalSpacer_41;
    QPushButton *btn_pp_showreport;
    QScrollArea *scrollScenarioList_3;
    QWidget *scrollAreaWidgetContents_3;
    QTreeWidget *treeWid_pp_select_script;
    QLabel *lbl_pp_sceneSelect;
    QListWidget *listWid_pp_scene_select;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_btnTop_2;
    QSpacerItem *horizontalSpacer_42;
    QPushButton *btn_pp_adeStart;
    QSpacerItem *horizontalSpacer_43;
    QPushButton *btn_pp_sel_scenario;
    QSpacerItem *horizontalSpacer_44;
    QPushButton *btn_pp_StopAde;
    QSpacerItem *horizontalSpacer_45;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_btn_bottom_2;
    QSpacerItem *horizontalSpacer_46;
    QPushButton *btn_pp_avp;
    QSpacerItem *horizontalSpacer_47;
    QPushButton *btn_pp_initial_pos;
    QSpacerItem *horizontalSpacer_48;
    QPushButton *btn_pp_goal_pos;
    QWidget *digital_semantic_suit;
    QGroupBox *gbox_DST_Suit;
    QScrollArea *scrollScenarioList;
    QWidget *scrollAreaWidgetContents;
    QTreeWidget *treeWidget;
    QLabel *label_3;
    QListWidget *listWidgetSceneSelectDSU;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pblaunch;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *b_sel_scenario;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *b_StopAde;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lblSpinner;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *scenic_activate_2;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *scenic_activate;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *b_run_scenario;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *b_stop_scenario;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *b_showreport_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *avp_button;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *initial_pos_b;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *goal_pos_b;
    QWidget *control_test_suit;
    QGroupBox *gbox_DST_Control_Suit;
    QScrollArea *scrollControl_ScenarioList;
    QWidget *scrollAreaControlWidgetContents;
    QTreeWidget *treeWidgetControl;
    QLabel *label_5;
    QListWidget *listWidgetSceneSelect;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *b_control_start_ade;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *b_control_sel_scenario;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *b_control_stopAde;
    QSpacerItem *horizontalSpacer_15;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *scenic_activate_3;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *run_scenic_control;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *b_control_run_scenario;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *b_control_stop_scenario;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *b_control_showreport;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *avp_button_2;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *initial_pos_b_2;
    QSpacerItem *horizontalSpacer_28;
    QPushButton *goal_pos_b_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1284, 619);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_outputlog = new QLabel(tab);
        lbl_outputlog->setObjectName(QString::fromUtf8("lbl_outputlog"));

        gridLayout->addWidget(lbl_outputlog, 1, 0, 1, 1);

        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        horizontalWidget_4 = new QWidget(gridWidget);
        horizontalWidget_4->setObjectName(QString::fromUtf8("horizontalWidget_4"));
        horizontalWidget_4->setEnabled(true);
        horizontalWidget_4->setGeometry(QRect(0, 0, 351, 441));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget_4->sizePolicy().hasHeightForWidth());
        horizontalWidget_4->setSizePolicy(sizePolicy1);
        horizontalWidget_4->setAutoFillBackground(true);
        layoutWidget = new QWidget(horizontalWidget_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 341, 431));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(14);
        font1.setBold(true);
        checkBox_2->setFont(font1);

        gridLayout_2->addWidget(checkBox_2, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(layoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setFont(font1);

        gridLayout_2->addWidget(checkBox_3, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 0, 1, 1);

        ckbox_localization = new QCheckBox(layoutWidget);
        ckbox_localization->setObjectName(QString::fromUtf8("ckbox_localization"));
        sizePolicy.setHeightForWidth(ckbox_localization->sizePolicy().hasHeightForWidth());
        ckbox_localization->setSizePolicy(sizePolicy);
        ckbox_localization->setFont(font1);

        gridLayout_2->addWidget(ckbox_localization, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 0, 1, 1);

        ckbox_PathPlanning = new QCheckBox(layoutWidget);
        ckbox_PathPlanning->setObjectName(QString::fromUtf8("ckbox_PathPlanning"));
        sizePolicy.setHeightForWidth(ckbox_PathPlanning->sizePolicy().hasHeightForWidth());
        ckbox_PathPlanning->setSizePolicy(sizePolicy);
        ckbox_PathPlanning->setFont(font1);

        gridLayout_2->addWidget(ckbox_PathPlanning, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 8, 0, 1, 1);

        ckbox_perception = new QCheckBox(layoutWidget);
        ckbox_perception->setObjectName(QString::fromUtf8("ckbox_perception"));
        sizePolicy.setHeightForWidth(ckbox_perception->sizePolicy().hasHeightForWidth());
        ckbox_perception->setSizePolicy(sizePolicy);
        ckbox_perception->setFont(font1);

        gridLayout_2->addWidget(ckbox_perception, 9, 0, 1, 1);

        stackedWidget = new QStackedWidget(gridWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(360, 0, 881, 441));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        localization_test_suite = new QWidget();
        localization_test_suite->setObjectName(QString::fromUtf8("localization_test_suite"));
        sizePolicy.setHeightForWidth(localization_test_suite->sizePolicy().hasHeightForWidth());
        localization_test_suite->setSizePolicy(sizePolicy);
        gbox_localization = new QGroupBox(localization_test_suite);
        gbox_localization->setObjectName(QString::fromUtf8("gbox_localization"));
        gbox_localization->setGeometry(QRect(10, 0, 871, 431));
        layoutWidget_2 = new QWidget(gbox_localization);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(2, 30, 851, 29));
        horizontalLayout_btnTop = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_btnTop->setObjectName(QString::fromUtf8("horizontalLayout_btnTop"));
        horizontalLayout_btnTop->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop->addItem(horizontalSpacer_7);

        btn_local_adeStart = new QPushButton(layoutWidget_2);
        btn_local_adeStart->setObjectName(QString::fromUtf8("btn_local_adeStart"));

        horizontalLayout_btnTop->addWidget(btn_local_adeStart);

        horizontalSpacer_12 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop->addItem(horizontalSpacer_12);

        btn_local_sel_scenario = new QPushButton(layoutWidget_2);
        btn_local_sel_scenario->setObjectName(QString::fromUtf8("btn_local_sel_scenario"));

        horizontalLayout_btnTop->addWidget(btn_local_sel_scenario);

        horizontalSpacer_20 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop->addItem(horizontalSpacer_20);

        btn_local_StopAde = new QPushButton(layoutWidget_2);
        btn_local_StopAde->setObjectName(QString::fromUtf8("btn_local_StopAde"));

        horizontalLayout_btnTop->addWidget(btn_local_StopAde);

        horizontalSpacer_22 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop->addItem(horizontalSpacer_22);

        scrollScenarioList_2 = new QScrollArea(gbox_localization);
        scrollScenarioList_2->setObjectName(QString::fromUtf8("scrollScenarioList_2"));
        scrollScenarioList_2->setGeometry(QRect(0, 60, 861, 281));
        scrollScenarioList_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 859, 279));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy);
        treeWid_local_select_script = new QTreeWidget(scrollAreaWidgetContents_2);
        treeWid_local_select_script->setObjectName(QString::fromUtf8("treeWid_local_select_script"));
        treeWid_local_select_script->setGeometry(QRect(260, 0, 601, 281));
        lbl_sceneSelect = new QLabel(scrollAreaWidgetContents_2);
        lbl_sceneSelect->setObjectName(QString::fromUtf8("lbl_sceneSelect"));
        lbl_sceneSelect->setGeometry(QRect(1, 1, 105, 19));
        listWid_local_scene_select = new QListWidget(scrollAreaWidgetContents_2);
        listWid_local_scene_select->setObjectName(QString::fromUtf8("listWid_local_scene_select"));
        listWid_local_scene_select->setGeometry(QRect(0, 20, 261, 261));
        scrollScenarioList_2->setWidget(scrollAreaWidgetContents_2);
        layoutWidget_3 = new QWidget(gbox_localization);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(11, 400, 461, 31));
        horizontalLayout_btn_bottom = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_btn_bottom->setObjectName(QString::fromUtf8("horizontalLayout_btn_bottom"));
        horizontalLayout_btn_bottom->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_29 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom->addItem(horizontalSpacer_29);

        btn_local_avp = new QPushButton(layoutWidget_3);
        btn_local_avp->setObjectName(QString::fromUtf8("btn_local_avp"));

        horizontalLayout_btn_bottom->addWidget(btn_local_avp);

        horizontalSpacer_30 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom->addItem(horizontalSpacer_30);

        btn_local_initial_pos = new QPushButton(layoutWidget_3);
        btn_local_initial_pos->setObjectName(QString::fromUtf8("btn_local_initial_pos"));

        horizontalLayout_btn_bottom->addWidget(btn_local_initial_pos);

        horizontalSpacer_31 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom->addItem(horizontalSpacer_31);

        btn_local_goal_pos = new QPushButton(layoutWidget_3);
        btn_local_goal_pos->setObjectName(QString::fromUtf8("btn_local_goal_pos"));

        horizontalLayout_btn_bottom->addWidget(btn_local_goal_pos);

        layoutWidget_4 = new QWidget(gbox_localization);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 360, 851, 29));
        horizontalLayout_btnMiddle = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_btnMiddle->setObjectName(QString::fromUtf8("horizontalLayout_btnMiddle"));
        horizontalLayout_btnMiddle->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_32 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle->addItem(horizontalSpacer_32);

        btn_local_scenic_count = new QPushButton(layoutWidget_4);
        btn_local_scenic_count->setObjectName(QString::fromUtf8("btn_local_scenic_count"));

        horizontalLayout_btnMiddle->addWidget(btn_local_scenic_count);

        horizontalSpacer_33 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle->addItem(horizontalSpacer_33);

        btn_local_scenic_run = new QPushButton(layoutWidget_4);
        btn_local_scenic_run->setObjectName(QString::fromUtf8("btn_local_scenic_run"));

        horizontalLayout_btnMiddle->addWidget(btn_local_scenic_run);

        horizontalSpacer_34 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle->addItem(horizontalSpacer_34);

        btn_local_run_scenario = new QPushButton(layoutWidget_4);
        btn_local_run_scenario->setObjectName(QString::fromUtf8("btn_local_run_scenario"));

        horizontalLayout_btnMiddle->addWidget(btn_local_run_scenario);

        horizontalSpacer_35 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle->addItem(horizontalSpacer_35);

        btn_local_stop_scenario = new QPushButton(layoutWidget_4);
        btn_local_stop_scenario->setObjectName(QString::fromUtf8("btn_local_stop_scenario"));

        horizontalLayout_btnMiddle->addWidget(btn_local_stop_scenario);

        horizontalSpacer_36 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle->addItem(horizontalSpacer_36);

        btn_local_showreport = new QPushButton(layoutWidget_4);
        btn_local_showreport->setObjectName(QString::fromUtf8("btn_local_showreport"));

        horizontalLayout_btnMiddle->addWidget(btn_local_showreport);

        stackedWidget->addWidget(localization_test_suite);
        path_planning_test_suite = new QWidget();
        path_planning_test_suite->setObjectName(QString::fromUtf8("path_planning_test_suite"));
        gbox_path_planning = new QGroupBox(path_planning_test_suite);
        gbox_path_planning->setObjectName(QString::fromUtf8("gbox_path_planning"));
        gbox_path_planning->setGeometry(QRect(0, 0, 881, 441));
        layoutWidget_5 = new QWidget(gbox_path_planning);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 370, 861, 29));
        horizontalLayout_btnMiddle_2 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_btnMiddle_2->setObjectName(QString::fromUtf8("horizontalLayout_btnMiddle_2"));
        horizontalLayout_btnMiddle_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_37 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle_2->addItem(horizontalSpacer_37);

        btn_pp_scenic_count = new QPushButton(layoutWidget_5);
        btn_pp_scenic_count->setObjectName(QString::fromUtf8("btn_pp_scenic_count"));

        horizontalLayout_btnMiddle_2->addWidget(btn_pp_scenic_count);

        horizontalSpacer_38 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle_2->addItem(horizontalSpacer_38);

        btn_pp_scenic_run = new QPushButton(layoutWidget_5);
        btn_pp_scenic_run->setObjectName(QString::fromUtf8("btn_pp_scenic_run"));

        horizontalLayout_btnMiddle_2->addWidget(btn_pp_scenic_run);

        horizontalSpacer_39 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle_2->addItem(horizontalSpacer_39);

        btn_pp_run_scenario = new QPushButton(layoutWidget_5);
        btn_pp_run_scenario->setObjectName(QString::fromUtf8("btn_pp_run_scenario"));

        horizontalLayout_btnMiddle_2->addWidget(btn_pp_run_scenario);

        horizontalSpacer_40 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle_2->addItem(horizontalSpacer_40);

        btn_pp_stop_scenario = new QPushButton(layoutWidget_5);
        btn_pp_stop_scenario->setObjectName(QString::fromUtf8("btn_pp_stop_scenario"));

        horizontalLayout_btnMiddle_2->addWidget(btn_pp_stop_scenario);

        horizontalSpacer_41 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnMiddle_2->addItem(horizontalSpacer_41);

        btn_pp_showreport = new QPushButton(layoutWidget_5);
        btn_pp_showreport->setObjectName(QString::fromUtf8("btn_pp_showreport"));

        horizontalLayout_btnMiddle_2->addWidget(btn_pp_showreport);

        scrollScenarioList_3 = new QScrollArea(gbox_path_planning);
        scrollScenarioList_3->setObjectName(QString::fromUtf8("scrollScenarioList_3"));
        scrollScenarioList_3->setGeometry(QRect(0, 70, 871, 281));
        scrollScenarioList_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 869, 279));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        treeWid_pp_select_script = new QTreeWidget(scrollAreaWidgetContents_3);
        treeWid_pp_select_script->setObjectName(QString::fromUtf8("treeWid_pp_select_script"));
        treeWid_pp_select_script->setGeometry(QRect(260, 0, 611, 281));
        lbl_pp_sceneSelect = new QLabel(scrollAreaWidgetContents_3);
        lbl_pp_sceneSelect->setObjectName(QString::fromUtf8("lbl_pp_sceneSelect"));
        lbl_pp_sceneSelect->setGeometry(QRect(1, 1, 105, 19));
        listWid_pp_scene_select = new QListWidget(scrollAreaWidgetContents_3);
        listWid_pp_scene_select->setObjectName(QString::fromUtf8("listWid_pp_scene_select"));
        listWid_pp_scene_select->setGeometry(QRect(0, 20, 261, 261));
        scrollScenarioList_3->setWidget(scrollAreaWidgetContents_3);
        layoutWidget_6 = new QWidget(gbox_path_planning);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(2, 30, 871, 29));
        horizontalLayout_btnTop_2 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_btnTop_2->setObjectName(QString::fromUtf8("horizontalLayout_btnTop_2"));
        horizontalLayout_btnTop_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_42 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop_2->addItem(horizontalSpacer_42);

        btn_pp_adeStart = new QPushButton(layoutWidget_6);
        btn_pp_adeStart->setObjectName(QString::fromUtf8("btn_pp_adeStart"));

        horizontalLayout_btnTop_2->addWidget(btn_pp_adeStart);

        horizontalSpacer_43 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop_2->addItem(horizontalSpacer_43);

        btn_pp_sel_scenario = new QPushButton(layoutWidget_6);
        btn_pp_sel_scenario->setObjectName(QString::fromUtf8("btn_pp_sel_scenario"));

        horizontalLayout_btnTop_2->addWidget(btn_pp_sel_scenario);

        horizontalSpacer_44 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop_2->addItem(horizontalSpacer_44);

        btn_pp_StopAde = new QPushButton(layoutWidget_6);
        btn_pp_StopAde->setObjectName(QString::fromUtf8("btn_pp_StopAde"));

        horizontalLayout_btnTop_2->addWidget(btn_pp_StopAde);

        horizontalSpacer_45 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btnTop_2->addItem(horizontalSpacer_45);

        layoutWidget_7 = new QWidget(gbox_path_planning);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(11, 410, 461, 31));
        horizontalLayout_btn_bottom_2 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_btn_bottom_2->setObjectName(QString::fromUtf8("horizontalLayout_btn_bottom_2"));
        horizontalLayout_btn_bottom_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_46 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom_2->addItem(horizontalSpacer_46);

        btn_pp_avp = new QPushButton(layoutWidget_7);
        btn_pp_avp->setObjectName(QString::fromUtf8("btn_pp_avp"));

        horizontalLayout_btn_bottom_2->addWidget(btn_pp_avp);

        horizontalSpacer_47 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom_2->addItem(horizontalSpacer_47);

        btn_pp_initial_pos = new QPushButton(layoutWidget_7);
        btn_pp_initial_pos->setObjectName(QString::fromUtf8("btn_pp_initial_pos"));

        horizontalLayout_btn_bottom_2->addWidget(btn_pp_initial_pos);

        horizontalSpacer_48 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_bottom_2->addItem(horizontalSpacer_48);

        btn_pp_goal_pos = new QPushButton(layoutWidget_7);
        btn_pp_goal_pos->setObjectName(QString::fromUtf8("btn_pp_goal_pos"));

        horizontalLayout_btn_bottom_2->addWidget(btn_pp_goal_pos);

        stackedWidget->addWidget(path_planning_test_suite);
        digital_semantic_suit = new QWidget();
        digital_semantic_suit->setObjectName(QString::fromUtf8("digital_semantic_suit"));
        sizePolicy.setHeightForWidth(digital_semantic_suit->sizePolicy().hasHeightForWidth());
        digital_semantic_suit->setSizePolicy(sizePolicy);
        gbox_DST_Suit = new QGroupBox(digital_semantic_suit);
        gbox_DST_Suit->setObjectName(QString::fromUtf8("gbox_DST_Suit"));
        gbox_DST_Suit->setGeometry(QRect(0, 0, 881, 441));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_DST_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Suit->setSizePolicy(sizePolicy2);
        scrollScenarioList = new QScrollArea(gbox_DST_Suit);
        scrollScenarioList->setObjectName(QString::fromUtf8("scrollScenarioList"));
        scrollScenarioList->setGeometry(QRect(0, 70, 871, 281));
        scrollScenarioList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 869, 279));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(260, 0, 601, 281));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1, 1, 105, 19));
        listWidgetSceneSelectDSU = new QListWidget(scrollAreaWidgetContents);
        listWidgetSceneSelectDSU->setObjectName(QString::fromUtf8("listWidgetSceneSelectDSU"));
        listWidgetSceneSelectDSU->setGeometry(QRect(0, 20, 261, 261));
        scrollScenarioList->setWidget(scrollAreaWidgetContents);
        label_3->raise();
        listWidgetSceneSelectDSU->raise();
        treeWidget->raise();
        layoutWidget1 = new QWidget(gbox_DST_Suit);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(2, 30, 871, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pblaunch = new QPushButton(layoutWidget1);
        pblaunch->setObjectName(QString::fromUtf8("pblaunch"));

        horizontalLayout->addWidget(pblaunch);

        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        b_sel_scenario = new QPushButton(layoutWidget1);
        b_sel_scenario->setObjectName(QString::fromUtf8("b_sel_scenario"));

        horizontalLayout->addWidget(b_sel_scenario);

        horizontalSpacer_9 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        b_StopAde = new QPushButton(layoutWidget1);
        b_StopAde->setObjectName(QString::fromUtf8("b_StopAde"));

        horizontalLayout->addWidget(b_StopAde);

        horizontalSpacer_10 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        lblSpinner = new QLabel(gbox_DST_Suit);
        lblSpinner->setObjectName(QString::fromUtf8("lblSpinner"));
        lblSpinner->setGeometry(QRect(590, 280, 101, 81));
        layoutWidget2 = new QWidget(gbox_DST_Suit);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 370, 861, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        scenic_activate_2 = new QPushButton(layoutWidget2);
        scenic_activate_2->setObjectName(QString::fromUtf8("scenic_activate_2"));

        horizontalLayout_2->addWidget(scenic_activate_2);

        horizontalSpacer_21 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_21);

        scenic_activate = new QPushButton(layoutWidget2);
        scenic_activate->setObjectName(QString::fromUtf8("scenic_activate"));

        horizontalLayout_2->addWidget(scenic_activate);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        b_run_scenario = new QPushButton(layoutWidget2);
        b_run_scenario->setObjectName(QString::fromUtf8("b_run_scenario"));

        horizontalLayout_2->addWidget(b_run_scenario);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        b_stop_scenario = new QPushButton(layoutWidget2);
        b_stop_scenario->setObjectName(QString::fromUtf8("b_stop_scenario"));

        horizontalLayout_2->addWidget(b_stop_scenario);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        b_showreport_2 = new QPushButton(layoutWidget2);
        b_showreport_2->setObjectName(QString::fromUtf8("b_showreport_2"));

        horizontalLayout_2->addWidget(b_showreport_2);

        layoutWidget3 = new QWidget(gbox_DST_Suit);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 410, 461, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_25 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_25);

        avp_button = new QPushButton(layoutWidget3);
        avp_button->setObjectName(QString::fromUtf8("avp_button"));

        horizontalLayout_5->addWidget(avp_button);

        horizontalSpacer_23 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_23);

        initial_pos_b = new QPushButton(layoutWidget3);
        initial_pos_b->setObjectName(QString::fromUtf8("initial_pos_b"));

        horizontalLayout_5->addWidget(initial_pos_b);

        horizontalSpacer_24 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_24);

        goal_pos_b = new QPushButton(layoutWidget3);
        goal_pos_b->setObjectName(QString::fromUtf8("goal_pos_b"));

        horizontalLayout_5->addWidget(goal_pos_b);

        stackedWidget->addWidget(digital_semantic_suit);
        control_test_suit = new QWidget();
        control_test_suit->setObjectName(QString::fromUtf8("control_test_suit"));
        sizePolicy.setHeightForWidth(control_test_suit->sizePolicy().hasHeightForWidth());
        control_test_suit->setSizePolicy(sizePolicy);
        gbox_DST_Control_Suit = new QGroupBox(control_test_suit);
        gbox_DST_Control_Suit->setObjectName(QString::fromUtf8("gbox_DST_Control_Suit"));
        gbox_DST_Control_Suit->setGeometry(QRect(0, 10, 871, 431));
        sizePolicy.setHeightForWidth(gbox_DST_Control_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Control_Suit->setSizePolicy(sizePolicy);
        scrollControl_ScenarioList = new QScrollArea(gbox_DST_Control_Suit);
        scrollControl_ScenarioList->setObjectName(QString::fromUtf8("scrollControl_ScenarioList"));
        scrollControl_ScenarioList->setGeometry(QRect(2, 65, 861, 271));
        scrollControl_ScenarioList->setWidgetResizable(true);
        scrollAreaControlWidgetContents = new QWidget();
        scrollAreaControlWidgetContents->setObjectName(QString::fromUtf8("scrollAreaControlWidgetContents"));
        scrollAreaControlWidgetContents->setGeometry(QRect(0, 0, 859, 269));
        treeWidgetControl = new QTreeWidget(scrollAreaControlWidgetContents);
        treeWidgetControl->setObjectName(QString::fromUtf8("treeWidgetControl"));
        treeWidgetControl->setGeometry(QRect(260, 0, 601, 271));
        label_5 = new QLabel(scrollAreaControlWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1, 1, 105, 19));
        listWidgetSceneSelect = new QListWidget(scrollAreaControlWidgetContents);
        listWidgetSceneSelect->setObjectName(QString::fromUtf8("listWidgetSceneSelect"));
        listWidgetSceneSelect->setGeometry(QRect(0, 20, 261, 251));
        scrollControl_ScenarioList->setWidget(scrollAreaControlWidgetContents);
        layoutWidget4 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 30, 851, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        b_control_start_ade = new QPushButton(layoutWidget4);
        b_control_start_ade->setObjectName(QString::fromUtf8("b_control_start_ade"));

        horizontalLayout_3->addWidget(b_control_start_ade);

        horizontalSpacer_13 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        b_control_sel_scenario = new QPushButton(layoutWidget4);
        b_control_sel_scenario->setObjectName(QString::fromUtf8("b_control_sel_scenario"));

        horizontalLayout_3->addWidget(b_control_sel_scenario);

        horizontalSpacer_14 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);

        b_control_stopAde = new QPushButton(layoutWidget4);
        b_control_stopAde->setObjectName(QString::fromUtf8("b_control_stopAde"));

        horizontalLayout_3->addWidget(b_control_stopAde);

        horizontalSpacer_15 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);

        layoutWidget5 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(-1, 348, 861, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scenic_activate_3 = new QPushButton(layoutWidget5);
        scenic_activate_3->setObjectName(QString::fromUtf8("scenic_activate_3"));

        horizontalLayout_4->addWidget(scenic_activate_3);

        horizontalSpacer_26 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_26);

        run_scenic_control = new QPushButton(layoutWidget5);
        run_scenic_control->setObjectName(QString::fromUtf8("run_scenic_control"));

        horizontalLayout_4->addWidget(run_scenic_control);

        horizontalSpacer_17 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        b_control_run_scenario = new QPushButton(layoutWidget5);
        b_control_run_scenario->setObjectName(QString::fromUtf8("b_control_run_scenario"));

        horizontalLayout_4->addWidget(b_control_run_scenario);

        horizontalSpacer_18 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_18);

        b_control_stop_scenario = new QPushButton(layoutWidget5);
        b_control_stop_scenario->setObjectName(QString::fromUtf8("b_control_stop_scenario"));

        horizontalLayout_4->addWidget(b_control_stop_scenario);

        horizontalSpacer_19 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_19);

        b_control_showreport = new QPushButton(layoutWidget5);
        b_control_showreport->setObjectName(QString::fromUtf8("b_control_showreport"));

        horizontalLayout_4->addWidget(b_control_showreport);

        layoutWidget6 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(0, 390, 431, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        avp_button_2 = new QPushButton(layoutWidget6);
        avp_button_2->setObjectName(QString::fromUtf8("avp_button_2"));

        horizontalLayout_6->addWidget(avp_button_2);

        horizontalSpacer_27 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_27);

        initial_pos_b_2 = new QPushButton(layoutWidget6);
        initial_pos_b_2->setObjectName(QString::fromUtf8("initial_pos_b_2"));

        horizontalLayout_6->addWidget(initial_pos_b_2);

        horizontalSpacer_28 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_28);

        goal_pos_b_2 = new QPushButton(layoutWidget6);
        goal_pos_b_2->setObjectName(QString::fromUtf8("goal_pos_b_2"));

        horizontalLayout_6->addWidget(goal_pos_b_2);

        stackedWidget->addWidget(control_test_suit);

        gridLayout->addWidget(gridWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1284, 24));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        lbl_outputlog->setText(QCoreApplication::translate("MainWindow", "Log Information :", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Detection Validation", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Control Validation", nullptr));
        ckbox_localization->setText(QCoreApplication::translate("MainWindow", "Localization Validation", nullptr));
        ckbox_PathPlanning->setText(QCoreApplication::translate("MainWindow", "Mission Planning Validation", nullptr));
        ckbox_perception->setText(QCoreApplication::translate("MainWindow", "                 TBD", nullptr));
        gbox_localization->setTitle(QCoreApplication::translate("MainWindow", "Localization Validation", nullptr));
        btn_local_adeStart->setText(QCoreApplication::translate("MainWindow", "Start ADE", nullptr));
        btn_local_sel_scenario->setText(QCoreApplication::translate("MainWindow", "Select Scenario", nullptr));
        btn_local_StopAde->setText(QCoreApplication::translate("MainWindow", "Stop ADE", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWid_local_select_script->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", " Select Scripts", nullptr));
        lbl_sceneSelect->setText(QCoreApplication::translate("MainWindow", "Select Scene", nullptr));
        btn_local_avp->setText(QCoreApplication::translate("MainWindow", "AVP", nullptr));
        btn_local_initial_pos->setText(QCoreApplication::translate("MainWindow", "Initial_pos", nullptr));
        btn_local_goal_pos->setText(QCoreApplication::translate("MainWindow", "Goal_pos", nullptr));
        btn_local_scenic_count->setText(QCoreApplication::translate("MainWindow", "Set Count", nullptr));
        btn_local_scenic_run->setText(QCoreApplication::translate("MainWindow", "Run_Scenic", nullptr));
        btn_local_run_scenario->setText(QCoreApplication::translate("MainWindow", "Run Scenario", nullptr));
        btn_local_stop_scenario->setText(QCoreApplication::translate("MainWindow", "Stop Scenario", nullptr));
        btn_local_showreport->setText(QCoreApplication::translate("MainWindow", "Show Report", nullptr));
        gbox_path_planning->setTitle(QCoreApplication::translate("MainWindow", "Mission Planning Validation", nullptr));
        btn_pp_scenic_count->setText(QCoreApplication::translate("MainWindow", "Run Node", nullptr));
        btn_pp_scenic_run->setText(QCoreApplication::translate("MainWindow", "Run_Scenic", nullptr));
        btn_pp_run_scenario->setText(QCoreApplication::translate("MainWindow", "Run Scenario", nullptr));
        btn_pp_stop_scenario->setText(QCoreApplication::translate("MainWindow", "Stop Scenario", nullptr));
        btn_pp_showreport->setText(QCoreApplication::translate("MainWindow", "Show Report", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWid_pp_select_script->headerItem();
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", " Select Scripts", nullptr));
        lbl_pp_sceneSelect->setText(QCoreApplication::translate("MainWindow", "Select Scene", nullptr));
        btn_pp_adeStart->setText(QCoreApplication::translate("MainWindow", "Start ADE", nullptr));
        btn_pp_sel_scenario->setText(QCoreApplication::translate("MainWindow", "Select Scenario", nullptr));
        btn_pp_StopAde->setText(QCoreApplication::translate("MainWindow", "Stop ADE", nullptr));
        btn_pp_avp->setText(QCoreApplication::translate("MainWindow", "AVP", nullptr));
        btn_pp_initial_pos->setText(QCoreApplication::translate("MainWindow", "Initial_pos", nullptr));
        btn_pp_goal_pos->setText(QCoreApplication::translate("MainWindow", "Goal_pos", nullptr));
        gbox_DST_Suit->setTitle(QCoreApplication::translate("MainWindow", "Detection Validation", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->headerItem();
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", " Select Scripts", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Select Scene", nullptr));
        pblaunch->setText(QCoreApplication::translate("MainWindow", "Start ADE", nullptr));
        b_sel_scenario->setText(QCoreApplication::translate("MainWindow", "Select Scenario", nullptr));
        b_StopAde->setText(QCoreApplication::translate("MainWindow", "Stop ADE", nullptr));
        lblSpinner->setText(QString());
        scenic_activate_2->setText(QCoreApplication::translate("MainWindow", "Set Count", nullptr));
        scenic_activate->setText(QCoreApplication::translate("MainWindow", "Run_Scenic", nullptr));
        b_run_scenario->setText(QCoreApplication::translate("MainWindow", "Run Scenario", nullptr));
        b_stop_scenario->setText(QCoreApplication::translate("MainWindow", "Stop Scenario", nullptr));
        b_showreport_2->setText(QCoreApplication::translate("MainWindow", "Show Report", nullptr));
        avp_button->setText(QCoreApplication::translate("MainWindow", "AVP", nullptr));
        initial_pos_b->setText(QCoreApplication::translate("MainWindow", "Initial_pos", nullptr));
        goal_pos_b->setText(QCoreApplication::translate("MainWindow", "Goal_pos", nullptr));
        gbox_DST_Control_Suit->setTitle(QCoreApplication::translate("MainWindow", "Control Validation", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidgetControl->headerItem();
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", " Select Scripts", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Select Scene", nullptr));
        b_control_start_ade->setText(QCoreApplication::translate("MainWindow", "Start ADE", nullptr));
        b_control_sel_scenario->setText(QCoreApplication::translate("MainWindow", "Select Scenario", nullptr));
        b_control_stopAde->setText(QCoreApplication::translate("MainWindow", "Stop ADE", nullptr));
        scenic_activate_3->setText(QCoreApplication::translate("MainWindow", "Run Node", nullptr));
        run_scenic_control->setText(QCoreApplication::translate("MainWindow", "Run_Scenic", nullptr));
        b_control_run_scenario->setText(QCoreApplication::translate("MainWindow", "Run Scenario", nullptr));
        b_control_stop_scenario->setText(QCoreApplication::translate("MainWindow", "Stop Scenario", nullptr));
        b_control_showreport->setText(QCoreApplication::translate("MainWindow", "Show Report", nullptr));
        avp_button_2->setText(QCoreApplication::translate("MainWindow", "AVP", nullptr));
        initial_pos_b_2->setText(QCoreApplication::translate("MainWindow", "Initial_pos", nullptr));
        goal_pos_b_2->setText(QCoreApplication::translate("MainWindow", "Goal_pos", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Validation Suite", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
