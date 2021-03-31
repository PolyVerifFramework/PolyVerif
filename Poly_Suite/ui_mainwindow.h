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
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
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
    QWidget *gridWidget;
    QWidget *horizontalWidget_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QStackedWidget *stackedWidget;
    QWidget *sensor_analog_suit;
    QWidget *digital_semantic_suit;
    QGroupBox *gbox_DST_Suit;
    QScrollArea *scrollScenarioList;
    QWidget *scrollAreaWidgetContents;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QListWidget *listWidgetSceneSelectDSU;
    QTableView *tableView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pblaunch;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *b_sel_scenario;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *b_StopAde;
    QSpacerItem *horizontalSpacer_10;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *b_run_scenario;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *b_stop_scenario;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *b_generatereport;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *b_showreport;
    QSpacerItem *horizontalSpacer_11;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *lbl_d_Auto;
    QLabel *lbl_d_LG;
    QLabel *lbl_d_Succes;
    QLabel *lbl_d_Failure;
    QLabel *lblSpinner;
    QWidget *control_test_suit;
    QGroupBox *gbox_DST_Control_Suit;
    QScrollArea *scrollControl_ScenarioList;
    QWidget *scrollAreaControlWidgetContents;
    QTreeWidget *treeWidgetControl;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QListWidget *listWidgetSceneSelect;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *b_control_start_ade;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *b_control_sel_scenario;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *b_control_stopAde;
    QSpacerItem *horizontalSpacer_15;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *b_control_run_scenario;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *b_control_stop_scenario;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *b_control_validation;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *b_control_showreport;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label;
    QTextBrowser *txtBrowser_control;
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
        MainWindow->resize(1276, 599);
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
        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setEnabled(true);
        gridWidget->setGeometry(QRect(0, 0, 1241, 481));
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        horizontalWidget_4 = new QWidget(gridWidget);
        horizontalWidget_4->setObjectName(QStringLiteral("horizontalWidget_4"));
        horizontalWidget_4->setEnabled(true);
        horizontalWidget_4->setGeometry(QRect(0, 0, 351, 431));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget_4->sizePolicy().hasHeightForWidth());
        horizontalWidget_4->setSizePolicy(sizePolicy1);
        horizontalWidget_4->setAutoFillBackground(true);
        checkBox_2 = new QCheckBox(horizontalWidget_4);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 100, 317, 29));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        checkBox_2->setFont(font1);
        checkBox_3 = new QCheckBox(horizontalWidget_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(0, 270, 218, 29));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox_3->setFont(font2);
        stackedWidget = new QStackedWidget(gridWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(350, 0, 861, 471));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        sensor_analog_suit = new QWidget();
        sensor_analog_suit->setObjectName(QStringLiteral("sensor_analog_suit"));
        sizePolicy.setHeightForWidth(sensor_analog_suit->sizePolicy().hasHeightForWidth());
        sensor_analog_suit->setSizePolicy(sizePolicy);
        stackedWidget->addWidget(sensor_analog_suit);
        digital_semantic_suit = new QWidget();
        digital_semantic_suit->setObjectName(QStringLiteral("digital_semantic_suit"));
        sizePolicy.setHeightForWidth(digital_semantic_suit->sizePolicy().hasHeightForWidth());
        digital_semantic_suit->setSizePolicy(sizePolicy);
        gbox_DST_Suit = new QGroupBox(digital_semantic_suit);
        gbox_DST_Suit->setObjectName(QStringLiteral("gbox_DST_Suit"));
        gbox_DST_Suit->setGeometry(QRect(0, 0, 851, 411));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_DST_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Suit->setSizePolicy(sizePolicy2);
        scrollScenarioList = new QScrollArea(gbox_DST_Suit);
        scrollScenarioList->setObjectName(QStringLiteral("scrollScenarioList"));
        scrollScenarioList->setGeometry(QRect(10, 70, 841, 121));
        scrollScenarioList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 839, 119));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(260, 0, 581, 121));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 258, 219));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        listWidgetSceneSelectDSU = new QListWidget(layoutWidget);
        listWidgetSceneSelectDSU->setObjectName(QStringLiteral("listWidgetSceneSelectDSU"));

        verticalLayout_3->addWidget(listWidgetSceneSelectDSU);

        scrollScenarioList->setWidget(scrollAreaWidgetContents);
        tableView = new QTableView(gbox_DST_Suit);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(430, 242, 421, 169));
        layoutWidget1 = new QWidget(gbox_DST_Suit);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(2, 30, 851, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pblaunch = new QPushButton(layoutWidget1);
        pblaunch->setObjectName(QStringLiteral("pblaunch"));

        horizontalLayout->addWidget(pblaunch);

        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        b_sel_scenario = new QPushButton(layoutWidget1);
        b_sel_scenario->setObjectName(QStringLiteral("b_sel_scenario"));

        horizontalLayout->addWidget(b_sel_scenario);

        horizontalSpacer_9 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        b_StopAde = new QPushButton(layoutWidget1);
        b_StopAde->setObjectName(QStringLiteral("b_StopAde"));

        horizontalLayout->addWidget(b_StopAde);

        horizontalSpacer_10 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        layoutWidget2 = new QWidget(gbox_DST_Suit);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1, 200, 851, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        b_run_scenario = new QPushButton(layoutWidget2);
        b_run_scenario->setObjectName(QStringLiteral("b_run_scenario"));

        horizontalLayout_2->addWidget(b_run_scenario);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        b_stop_scenario = new QPushButton(layoutWidget2);
        b_stop_scenario->setObjectName(QStringLiteral("b_stop_scenario"));

        horizontalLayout_2->addWidget(b_stop_scenario);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        b_generatereport = new QPushButton(layoutWidget2);
        b_generatereport->setObjectName(QStringLiteral("b_generatereport"));

        horizontalLayout_2->addWidget(b_generatereport);

        horizontalSpacer_7 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        b_showreport = new QPushButton(layoutWidget2);
        b_showreport->setObjectName(QStringLiteral("b_showreport"));

        horizontalLayout_2->addWidget(b_showreport);

        horizontalSpacer_11 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        b_showreport->raise();
        b_run_scenario->raise();
        b_stop_scenario->raise();
        b_generatereport->raise();
        layoutWidget3 = new QWidget(gbox_DST_Suit);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(12, 242, 411, 161));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setIndent(0);

        verticalLayout_2->addWidget(label_2);

        lbl_d_Auto = new QLabel(layoutWidget3);
        lbl_d_Auto->setObjectName(QStringLiteral("lbl_d_Auto"));

        verticalLayout_2->addWidget(lbl_d_Auto);

        lbl_d_LG = new QLabel(layoutWidget3);
        lbl_d_LG->setObjectName(QStringLiteral("lbl_d_LG"));

        verticalLayout_2->addWidget(lbl_d_LG);

        lbl_d_Succes = new QLabel(layoutWidget3);
        lbl_d_Succes->setObjectName(QStringLiteral("lbl_d_Succes"));

        verticalLayout_2->addWidget(lbl_d_Succes);

        lbl_d_Failure = new QLabel(layoutWidget3);
        lbl_d_Failure->setObjectName(QStringLiteral("lbl_d_Failure"));

        verticalLayout_2->addWidget(lbl_d_Failure);

        lblSpinner = new QLabel(gbox_DST_Suit);
        lblSpinner->setObjectName(QStringLiteral("lblSpinner"));
        lblSpinner->setGeometry(QRect(590, 280, 101, 81));
        stackedWidget->addWidget(digital_semantic_suit);
        control_test_suit = new QWidget();
        control_test_suit->setObjectName(QStringLiteral("control_test_suit"));
        sizePolicy.setHeightForWidth(control_test_suit->sizePolicy().hasHeightForWidth());
        control_test_suit->setSizePolicy(sizePolicy);
        gbox_DST_Control_Suit = new QGroupBox(control_test_suit);
        gbox_DST_Control_Suit->setObjectName(QStringLiteral("gbox_DST_Control_Suit"));
        gbox_DST_Control_Suit->setGeometry(QRect(0, 0, 871, 361));
        sizePolicy.setHeightForWidth(gbox_DST_Control_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Control_Suit->setSizePolicy(sizePolicy);
        scrollControl_ScenarioList = new QScrollArea(gbox_DST_Control_Suit);
        scrollControl_ScenarioList->setObjectName(QStringLiteral("scrollControl_ScenarioList"));
        scrollControl_ScenarioList->setGeometry(QRect(12, 65, 841, 221));
        scrollControl_ScenarioList->setWidgetResizable(true);
        scrollAreaControlWidgetContents = new QWidget();
        scrollAreaControlWidgetContents->setObjectName(QStringLiteral("scrollAreaControlWidgetContents"));
        scrollAreaControlWidgetContents->setGeometry(QRect(0, 0, 839, 219));
        treeWidgetControl = new QTreeWidget(scrollAreaControlWidgetContents);
        treeWidgetControl->setObjectName(QStringLiteral("treeWidgetControl"));
        treeWidgetControl->setGeometry(QRect(260, 0, 581, 221));
        layoutWidget4 = new QWidget(scrollAreaControlWidgetContents);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 0, 258, 219));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        listWidgetSceneSelect = new QListWidget(layoutWidget4);
        listWidgetSceneSelect->setObjectName(QStringLiteral("listWidgetSceneSelect"));

        verticalLayout_4->addWidget(listWidgetSceneSelect);

        scrollControl_ScenarioList->setWidget(scrollAreaControlWidgetContents);
        layoutWidget5 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 30, 841, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        b_control_start_ade = new QPushButton(layoutWidget5);
        b_control_start_ade->setObjectName(QStringLiteral("b_control_start_ade"));

        horizontalLayout_3->addWidget(b_control_start_ade);

        horizontalSpacer_13 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        b_control_sel_scenario = new QPushButton(layoutWidget5);
        b_control_sel_scenario->setObjectName(QStringLiteral("b_control_sel_scenario"));

        horizontalLayout_3->addWidget(b_control_sel_scenario);

        horizontalSpacer_14 = new QSpacerItem(87, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);

        b_control_stopAde = new QPushButton(layoutWidget5);
        b_control_stopAde->setObjectName(QStringLiteral("b_control_stopAde"));

        horizontalLayout_3->addWidget(b_control_stopAde);

        horizontalSpacer_15 = new QSpacerItem(61, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_15);

        layoutWidget6 = new QWidget(gbox_DST_Control_Suit);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 310, 841, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        b_control_run_scenario = new QPushButton(layoutWidget6);
        b_control_run_scenario->setObjectName(QStringLiteral("b_control_run_scenario"));

        horizontalLayout_4->addWidget(b_control_run_scenario);

        horizontalSpacer_17 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        b_control_stop_scenario = new QPushButton(layoutWidget6);
        b_control_stop_scenario->setObjectName(QStringLiteral("b_control_stop_scenario"));

        horizontalLayout_4->addWidget(b_control_stop_scenario);

        horizontalSpacer_18 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_18);

        b_control_validation = new QPushButton(layoutWidget6);
        b_control_validation->setObjectName(QStringLiteral("b_control_validation"));

        horizontalLayout_4->addWidget(b_control_validation);

        horizontalSpacer_19 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_19);

        b_control_showreport = new QPushButton(layoutWidget6);
        b_control_showreport->setObjectName(QStringLiteral("b_control_showreport"));

        horizontalLayout_4->addWidget(b_control_showreport);

        horizontalSpacer_20 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_20);

        label = new QLabel(control_test_suit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 420, 281, 31));
        txtBrowser_control = new QTextBrowser(control_test_suit);
        txtBrowser_control->setObjectName(QStringLiteral("txtBrowser_control"));
        txtBrowser_control->setGeometry(QRect(0, 360, 301, 101));
        stackedWidget->addWidget(control_test_suit);
        lbl_outputlog = new QLabel(tab);
        lbl_outputlog->setObjectName(QStringLiteral("lbl_outputlog"));
        lbl_outputlog->setGeometry(QRect(9, 472, 1221, 19));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1276, 24));
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
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "Digital Semantic Test Suite", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "Control Test Suite", Q_NULLPTR));
        gbox_DST_Suit->setTitle(QApplication::translate("MainWindow", "Digital Semantic Suit", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Select Scene", Q_NULLPTR));
        pblaunch->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        b_StopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        b_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_generatereport->setText(QApplication::translate("MainWindow", "Generate Report", Q_NULLPTR));
        b_showreport->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "     Report of Perception Validation", Q_NULLPTR));
        lbl_d_Auto->setText(QApplication::translate("MainWindow", "Detection range in Autoware (m)  :", Q_NULLPTR));
        lbl_d_LG->setText(QApplication::translate("MainWindow", "Detection range in LG (m)   :", Q_NULLPTR));
        lbl_d_Succes->setText(QApplication::translate("MainWindow", "Detection Success Rate (%)   :", Q_NULLPTR));
        lbl_d_Failure->setText(QApplication::translate("MainWindow", "Detection Failure Rate (%)   :", Q_NULLPTR));
        lblSpinner->setText(QString());
        gbox_DST_Control_Suit->setTitle(QApplication::translate("MainWindow", "Control Test Suite", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetControl->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Select Scene", Q_NULLPTR));
        b_control_start_ade->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_control_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        b_control_stopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        b_control_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_control_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_control_validation->setText(QApplication::translate("MainWindow", "Generate Report", Q_NULLPTR));
        b_control_showreport->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Report of the Control Validation", Q_NULLPTR));
        lbl_outputlog->setText(QApplication::translate("MainWindow", "Log Information :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Validation", Q_NULLPTR));
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
