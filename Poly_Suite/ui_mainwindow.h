/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QWidget *gridWidget;
    QWidget *horizontalWidget_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QCheckBox *checkBox_2;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox_3;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *ckbox_localization;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *ckbox_PathPlanning;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *localization_test_suite;
    QGroupBox *gbox_localization;
    QWidget *path_planning_test_suite;
    QGroupBox *gbox_path_planning;
    QWidget *digital_semantic_suit;
    QGroupBox *gbox_DST_Suit;
    QScrollArea *scrollScenarioList;
    QWidget *scrollAreaWidgetContents;
    QTreeWidget *treeWidget;
    QLabel *label_3;
    QListWidget *listWidgetSceneSelectDSU;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pblaunch;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *b_sel_scenario;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *b_StopAde;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lblSpinner;
    QWidget *layoutWidget1;
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
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *avp_button;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *initial_pos_b;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *goal_pos_b;
    QWidget *control_test_suit;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *gbox_DST_Control_Suit;
    QScrollArea *scrollControl_ScenarioList;
    QWidget *scrollAreaControlWidgetContents;
    QTreeWidget *treeWidgetControl;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
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
    QLabel *lbl_outputlog;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuHelp_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1284, 619);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        horizontalWidget_4 = new QWidget(gridWidget);
        horizontalWidget_4->setObjectName(QStringLiteral("horizontalWidget_4"));
        horizontalWidget_4->setEnabled(true);
        horizontalWidget_4->setGeometry(QRect(0, 0, 351, 441));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget_4->sizePolicy().hasHeightForWidth());
        horizontalWidget_4->setSizePolicy(sizePolicy1);
        horizontalWidget_4->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(horizontalWidget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        checkBox_2 = new QCheckBox(horizontalWidget_4);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        checkBox_2->setFont(font1);

        verticalLayout_2->addWidget(checkBox_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        checkBox_3 = new QCheckBox(horizontalWidget_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setFont(font1);

        verticalLayout_2->addWidget(checkBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        ckbox_localization = new QCheckBox(horizontalWidget_4);
        ckbox_localization->setObjectName(QStringLiteral("ckbox_localization"));
        sizePolicy.setHeightForWidth(ckbox_localization->sizePolicy().hasHeightForWidth());
        ckbox_localization->setSizePolicy(sizePolicy);
        ckbox_localization->setFont(font1);

        verticalLayout_2->addWidget(ckbox_localization);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        ckbox_PathPlanning = new QCheckBox(horizontalWidget_4);
        ckbox_PathPlanning->setObjectName(QStringLiteral("ckbox_PathPlanning"));
        sizePolicy.setHeightForWidth(ckbox_PathPlanning->sizePolicy().hasHeightForWidth());
        ckbox_PathPlanning->setSizePolicy(sizePolicy);
        ckbox_PathPlanning->setFont(font1);

        verticalLayout_2->addWidget(ckbox_PathPlanning);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        stackedWidget = new QStackedWidget(gridWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(350, 0, 881, 451));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        localization_test_suite = new QWidget();
        localization_test_suite->setObjectName(QStringLiteral("localization_test_suite"));
        sizePolicy.setHeightForWidth(localization_test_suite->sizePolicy().hasHeightForWidth());
        localization_test_suite->setSizePolicy(sizePolicy);
        gbox_localization = new QGroupBox(localization_test_suite);
        gbox_localization->setObjectName(QStringLiteral("gbox_localization"));
        gbox_localization->setGeometry(QRect(0, 0, 591, 411));
        stackedWidget->addWidget(localization_test_suite);
        path_planning_test_suite = new QWidget();
        path_planning_test_suite->setObjectName(QStringLiteral("path_planning_test_suite"));
        gbox_path_planning = new QGroupBox(path_planning_test_suite);
        gbox_path_planning->setObjectName(QStringLiteral("gbox_path_planning"));
        gbox_path_planning->setGeometry(QRect(0, 0, 651, 371));
        stackedWidget->addWidget(path_planning_test_suite);
        digital_semantic_suit = new QWidget();
        digital_semantic_suit->setObjectName(QStringLiteral("digital_semantic_suit"));
        sizePolicy.setHeightForWidth(digital_semantic_suit->sizePolicy().hasHeightForWidth());
        digital_semantic_suit->setSizePolicy(sizePolicy);
        gbox_DST_Suit = new QGroupBox(digital_semantic_suit);
        gbox_DST_Suit->setObjectName(QStringLiteral("gbox_DST_Suit"));
        gbox_DST_Suit->setGeometry(QRect(0, 0, 901, 451));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_DST_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Suit->setSizePolicy(sizePolicy2);
        scrollScenarioList = new QScrollArea(gbox_DST_Suit);
        scrollScenarioList->setObjectName(QStringLiteral("scrollScenarioList"));
        scrollScenarioList->setGeometry(QRect(10, 70, 841, 281));
        scrollScenarioList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 839, 279));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(260, 0, 581, 281));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1, 1, 105, 19));
        listWidgetSceneSelectDSU = new QListWidget(scrollAreaWidgetContents);
        listWidgetSceneSelectDSU->setObjectName(QStringLiteral("listWidgetSceneSelectDSU"));
        listWidgetSceneSelectDSU->setGeometry(QRect(0, 30, 271, 261));
        scrollScenarioList->setWidget(scrollAreaWidgetContents);
        label_3->raise();
        listWidgetSceneSelectDSU->raise();
        treeWidget->raise();
        layoutWidget = new QWidget(gbox_DST_Suit);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 30, 851, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pblaunch = new QPushButton(layoutWidget);
        pblaunch->setObjectName(QStringLiteral("pblaunch"));

        horizontalLayout->addWidget(pblaunch);

        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        b_sel_scenario = new QPushButton(layoutWidget);
        b_sel_scenario->setObjectName(QStringLiteral("b_sel_scenario"));

        horizontalLayout->addWidget(b_sel_scenario);

        horizontalSpacer_9 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        b_StopAde = new QPushButton(layoutWidget);
        b_StopAde->setObjectName(QStringLiteral("b_StopAde"));

        horizontalLayout->addWidget(b_StopAde);

        horizontalSpacer_10 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        lblSpinner = new QLabel(gbox_DST_Suit);
        lblSpinner->setObjectName(QStringLiteral("lblSpinner"));
        lblSpinner->setGeometry(QRect(590, 280, 101, 81));
        layoutWidget1 = new QWidget(gbox_DST_Suit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 370, 861, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        scenic_activate_2 = new QPushButton(layoutWidget1);
        scenic_activate_2->setObjectName(QStringLiteral("scenic_activate_2"));

        horizontalLayout_2->addWidget(scenic_activate_2);

        horizontalSpacer_21 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_21);

        scenic_activate = new QPushButton(layoutWidget1);
        scenic_activate->setObjectName(QStringLiteral("scenic_activate"));

        horizontalLayout_2->addWidget(scenic_activate);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        b_run_scenario = new QPushButton(layoutWidget1);
        b_run_scenario->setObjectName(QStringLiteral("b_run_scenario"));

        horizontalLayout_2->addWidget(b_run_scenario);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        b_stop_scenario = new QPushButton(layoutWidget1);
        b_stop_scenario->setObjectName(QStringLiteral("b_stop_scenario"));

        horizontalLayout_2->addWidget(b_stop_scenario);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        b_showreport_2 = new QPushButton(layoutWidget1);
        b_showreport_2->setObjectName(QStringLiteral("b_showreport_2"));

        horizontalLayout_2->addWidget(b_showreport_2);

        layoutWidget2 = new QWidget(gbox_DST_Suit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 410, 461, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_25 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_25);

        avp_button = new QPushButton(layoutWidget2);
        avp_button->setObjectName(QStringLiteral("avp_button"));

        horizontalLayout_5->addWidget(avp_button);

        horizontalSpacer_23 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_23);

        initial_pos_b = new QPushButton(layoutWidget2);
        initial_pos_b->setObjectName(QStringLiteral("initial_pos_b"));

        horizontalLayout_5->addWidget(initial_pos_b);

        horizontalSpacer_24 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_24);

        goal_pos_b = new QPushButton(layoutWidget2);
        goal_pos_b->setObjectName(QStringLiteral("goal_pos_b"));

        horizontalLayout_5->addWidget(goal_pos_b);

        stackedWidget->addWidget(digital_semantic_suit);
        control_test_suit = new QWidget();
        control_test_suit->setObjectName(QStringLiteral("control_test_suit"));
        sizePolicy.setHeightForWidth(control_test_suit->sizePolicy().hasHeightForWidth());
        control_test_suit->setSizePolicy(sizePolicy);
        horizontalLayout_7 = new QHBoxLayout(control_test_suit);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        gbox_DST_Control_Suit = new QGroupBox(control_test_suit);
        gbox_DST_Control_Suit->setObjectName(QStringLiteral("gbox_DST_Control_Suit"));
        sizePolicy.setHeightForWidth(gbox_DST_Control_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Control_Suit->setSizePolicy(sizePolicy);
        scrollControl_ScenarioList = new QScrollArea(gbox_DST_Control_Suit);
        scrollControl_ScenarioList->setObjectName(QStringLiteral("scrollControl_ScenarioList"));
        scrollControl_ScenarioList->setGeometry(QRect(12, 65, 841, 271));
        scrollControl_ScenarioList->setWidgetResizable(true);
        scrollAreaControlWidgetContents = new QWidget();
        scrollAreaControlWidgetContents->setObjectName(QStringLiteral("scrollAreaControlWidgetContents"));
        scrollAreaControlWidgetContents->setGeometry(QRect(0, 0, 839, 269));
        treeWidgetControl = new QTreeWidget(scrollAreaControlWidgetContents);
        treeWidgetControl->setObjectName(QStringLiteral("treeWidgetControl"));
        treeWidgetControl->setGeometry(QRect(260, 0, 581, 271));
        layoutWidget3 = new QWidget(scrollAreaControlWidgetContents);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 258, 271));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        listWidgetSceneSelect = new QListWidget(layoutWidget3);
        listWidgetSceneSelect->setObjectName(QStringLiteral("listWidgetSceneSelect"));

        verticalLayout_4->addWidget(listWidgetSceneSelect);

        scrollControl_ScenarioList->setWidget(scrollAreaControlWidgetContents);
        layoutWidget4 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 30, 841, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        b_control_start_ade = new QPushButton(layoutWidget4);
        b_control_start_ade->setObjectName(QStringLiteral("b_control_start_ade"));

        horizontalLayout_3->addWidget(b_control_start_ade);

        horizontalSpacer_13 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        b_control_sel_scenario = new QPushButton(layoutWidget4);
        b_control_sel_scenario->setObjectName(QStringLiteral("b_control_sel_scenario"));

        horizontalLayout_3->addWidget(b_control_sel_scenario);

        horizontalSpacer_14 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);

        b_control_stopAde = new QPushButton(layoutWidget4);
        b_control_stopAde->setObjectName(QStringLiteral("b_control_stopAde"));

        horizontalLayout_3->addWidget(b_control_stopAde);

        horizontalSpacer_15 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);

        layoutWidget5 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(9, 348, 841, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scenic_activate_3 = new QPushButton(layoutWidget5);
        scenic_activate_3->setObjectName(QStringLiteral("scenic_activate_3"));

        horizontalLayout_4->addWidget(scenic_activate_3);

        horizontalSpacer_26 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_26);

        run_scenic_control = new QPushButton(layoutWidget5);
        run_scenic_control->setObjectName(QStringLiteral("run_scenic_control"));

        horizontalLayout_4->addWidget(run_scenic_control);

        horizontalSpacer_17 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        b_control_run_scenario = new QPushButton(layoutWidget5);
        b_control_run_scenario->setObjectName(QStringLiteral("b_control_run_scenario"));

        horizontalLayout_4->addWidget(b_control_run_scenario);

        horizontalSpacer_18 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_18);

        b_control_stop_scenario = new QPushButton(layoutWidget5);
        b_control_stop_scenario->setObjectName(QStringLiteral("b_control_stop_scenario"));

        horizontalLayout_4->addWidget(b_control_stop_scenario);

        horizontalSpacer_19 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_19);

        b_control_showreport = new QPushButton(layoutWidget5);
        b_control_showreport->setObjectName(QStringLiteral("b_control_showreport"));

        horizontalLayout_4->addWidget(b_control_showreport);

        layoutWidget6 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 390, 431, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        avp_button_2 = new QPushButton(layoutWidget6);
        avp_button_2->setObjectName(QStringLiteral("avp_button_2"));

        horizontalLayout_6->addWidget(avp_button_2);

        horizontalSpacer_27 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_27);

        initial_pos_b_2 = new QPushButton(layoutWidget6);
        initial_pos_b_2->setObjectName(QStringLiteral("initial_pos_b_2"));

        horizontalLayout_6->addWidget(initial_pos_b_2);

        horizontalSpacer_28 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_28);

        goal_pos_b_2 = new QPushButton(layoutWidget6);
        goal_pos_b_2->setObjectName(QStringLiteral("goal_pos_b_2"));

        horizontalLayout_6->addWidget(goal_pos_b_2);


        horizontalLayout_7->addWidget(gbox_DST_Control_Suit);

        stackedWidget->addWidget(control_test_suit);

        gridLayout->addWidget(gridWidget, 0, 0, 1, 1);

        lbl_outputlog = new QLabel(tab);
        lbl_outputlog->setObjectName(QStringLiteral("lbl_outputlog"));

        gridLayout->addWidget(lbl_outputlog, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1284, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp_2 = new QMenu(menubar);
        menuHelp_2->setObjectName(QStringLiteral("menuHelp_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuHelp_2->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionexit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Digital Semantic Test Suite", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "Control Test Suite", Q_NULLPTR));
        ckbox_localization->setText(QApplication::translate("MainWindow", "Localization Test Suite", Q_NULLPTR));
        ckbox_PathPlanning->setText(QApplication::translate("MainWindow", "Path Planning Test Suite", Q_NULLPTR));
        gbox_localization->setTitle(QApplication::translate("MainWindow", "Localization Test Suite", Q_NULLPTR));
        gbox_path_planning->setTitle(QApplication::translate("MainWindow", "Path Planning Test Suite", Q_NULLPTR));
        gbox_DST_Suit->setTitle(QApplication::translate("MainWindow", "Digital Semantic Suite", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Select Scene", Q_NULLPTR));
        pblaunch->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        b_StopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        lblSpinner->setText(QString());
        scenic_activate_2->setText(QApplication::translate("MainWindow", "Set Count", Q_NULLPTR));
        scenic_activate->setText(QApplication::translate("MainWindow", "Run_Scenic", Q_NULLPTR));
        b_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_showreport_2->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        avp_button->setText(QApplication::translate("MainWindow", "AVP", Q_NULLPTR));
        initial_pos_b->setText(QApplication::translate("MainWindow", "Initial_pos", Q_NULLPTR));
        goal_pos_b->setText(QApplication::translate("MainWindow", "Goal_pos", Q_NULLPTR));
        gbox_DST_Control_Suit->setTitle(QApplication::translate("MainWindow", "Control Test Suite", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetControl->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Select Scene", Q_NULLPTR));
        b_control_start_ade->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_control_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        b_control_stopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        scenic_activate_3->setText(QApplication::translate("MainWindow", "Set Count", Q_NULLPTR));
        run_scenic_control->setText(QApplication::translate("MainWindow", "Run_Scenic", Q_NULLPTR));
        b_control_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_control_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_control_showreport->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        avp_button_2->setText(QApplication::translate("MainWindow", "AVP", Q_NULLPTR));
        initial_pos_b_2->setText(QApplication::translate("MainWindow", "Initial_pos", Q_NULLPTR));
        goal_pos_b_2->setText(QApplication::translate("MainWindow", "Goal_pos", Q_NULLPTR));
        lbl_outputlog->setText(QApplication::translate("MainWindow", "Log Information :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Validation Suite", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Test Suit", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuHelp_2->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
