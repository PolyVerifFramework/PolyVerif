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
    QVBoxLayout *verticalLayout_3;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QWidget *horizontalWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *sensor_analog_suit;
    QWidget *digital_semantic_suit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_digital_suit;
    QGroupBox *gbox_DST_Suit;
    QPushButton *pblaunch;
    QPushButton *b_StopAde;
    QPushButton *b_showreport;
    QPushButton *b_sel_scenario;
    QScrollArea *scrollScenarioList;
    QWidget *scrollAreaWidgetContents;
    QTreeWidget *treeWidget;
    QListWidget *listWidgetSceneSelectDSU;
    QLabel *label_3;
    QPushButton *b_run_scenario;
    QPushButton *b_stop_scenario;
    QPushButton *b_generatereport;
    QLabel *label_2;
    QLabel *lbl_d_Auto;
    QLabel *lbl_d_LG;
    QLabel *lbl_d_Succes;
    QLabel *lbl_d_Failure;
    QTableView *tableView;
    QWidget *control_test_suit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *layout_control_suit;
    QGroupBox *gbox_DST_Control_Suit;
    QPushButton *b_control_start_ade;
    QPushButton *b_control_stopAde;
    QPushButton *b_control_showreport;
    QPushButton *b_control_sel_scenario;
    QScrollArea *scrollControl_ScenarioList;
    QWidget *scrollAreaControlWidgetContents;
    QTreeWidget *treeWidgetControl;
    QListWidget *listWidgetSceneSelect;
    QPushButton *b_control_run_scenario;
    QPushButton *b_control_stop_scenario;
    QPushButton *b_control_validation;
    QTextBrowser *txtBrowser_control;
    QLabel *label;
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
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridWidget = new QWidget(tab);
        gridWidget->setObjectName(QStringLiteral("gridWidget"));
        gridWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(gridWidget->sizePolicy().hasHeightForWidth());
        gridWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalWidget_4 = new QWidget(gridWidget);
        horizontalWidget_4->setObjectName(QStringLiteral("horizontalWidget_4"));
        horizontalWidget_4->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalWidget_4->sizePolicy().hasHeightForWidth());
        horizontalWidget_4->setSizePolicy(sizePolicy1);
        horizontalWidget_4->setAutoFillBackground(true);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox_2 = new QCheckBox(horizontalWidget_4);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        checkBox_2->setFont(font1);

        verticalLayout_2->addWidget(checkBox_2, 0, Qt::AlignLeft);

        checkBox_3 = new QCheckBox(horizontalWidget_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox_3->setFont(font2);

        verticalLayout_2->addWidget(checkBox_3, 0, Qt::AlignLeft);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addWidget(horizontalWidget_4, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        stackedWidget = new QStackedWidget(gridWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
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
        horizontalLayoutWidget = new QWidget(digital_semantic_suit);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 531, 381));
        layout_digital_suit = new QHBoxLayout(horizontalLayoutWidget);
        layout_digital_suit->setObjectName(QStringLiteral("layout_digital_suit"));
        layout_digital_suit->setContentsMargins(0, 0, 0, 0);
        gbox_DST_Suit = new QGroupBox(horizontalLayoutWidget);
        gbox_DST_Suit->setObjectName(QStringLiteral("gbox_DST_Suit"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbox_DST_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Suit->setSizePolicy(sizePolicy2);
        pblaunch = new QPushButton(gbox_DST_Suit);
        pblaunch->setObjectName(QStringLiteral("pblaunch"));
        pblaunch->setGeometry(QRect(10, 40, 120, 31));
        b_StopAde = new QPushButton(gbox_DST_Suit);
        b_StopAde->setObjectName(QStringLiteral("b_StopAde"));
        b_StopAde->setGeometry(QRect(380, 40, 121, 27));
        b_showreport = new QPushButton(gbox_DST_Suit);
        b_showreport->setObjectName(QStringLiteral("b_showreport"));
        b_showreport->setGeometry(QRect(310, 260, 131, 27));
        b_sel_scenario = new QPushButton(gbox_DST_Suit);
        b_sel_scenario->setObjectName(QStringLiteral("b_sel_scenario"));
        b_sel_scenario->setGeometry(QRect(200, 40, 131, 31));
        scrollScenarioList = new QScrollArea(gbox_DST_Suit);
        scrollScenarioList->setObjectName(QStringLiteral("scrollScenarioList"));
        scrollScenarioList->setGeometry(QRect(10, 80, 501, 121));
        scrollScenarioList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 499, 119));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(170, 0, 331, 121));
        listWidgetSceneSelectDSU = new QListWidget(scrollAreaWidgetContents);
        listWidgetSceneSelectDSU->setObjectName(QStringLiteral("listWidgetSceneSelectDSU"));
        listWidgetSceneSelectDSU->setGeometry(QRect(0, 20, 171, 101));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 161, 21));
        scrollScenarioList->setWidget(scrollAreaWidgetContents);
        b_run_scenario = new QPushButton(gbox_DST_Suit);
        b_run_scenario->setObjectName(QStringLiteral("b_run_scenario"));
        b_run_scenario->setGeometry(QRect(110, 210, 141, 27));
        b_stop_scenario = new QPushButton(gbox_DST_Suit);
        b_stop_scenario->setObjectName(QStringLiteral("b_stop_scenario"));
        b_stop_scenario->setGeometry(QRect(310, 210, 131, 27));
        b_generatereport = new QPushButton(gbox_DST_Suit);
        b_generatereport->setObjectName(QStringLiteral("b_generatereport"));
        b_generatereport->setGeometry(QRect(110, 260, 141, 27));

        layout_digital_suit->addWidget(gbox_DST_Suit);

        label_2 = new QLabel(digital_semantic_suit);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 10, 281, 31));
        lbl_d_Auto = new QLabel(digital_semantic_suit);
        lbl_d_Auto->setObjectName(QStringLiteral("lbl_d_Auto"));
        lbl_d_Auto->setGeometry(QRect(550, 40, 341, 31));
        lbl_d_LG = new QLabel(digital_semantic_suit);
        lbl_d_LG->setObjectName(QStringLiteral("lbl_d_LG"));
        lbl_d_LG->setGeometry(QRect(550, 70, 341, 31));
        lbl_d_Succes = new QLabel(digital_semantic_suit);
        lbl_d_Succes->setObjectName(QStringLiteral("lbl_d_Succes"));
        lbl_d_Succes->setGeometry(QRect(550, 100, 341, 31));
        lbl_d_Failure = new QLabel(digital_semantic_suit);
        lbl_d_Failure->setObjectName(QStringLiteral("lbl_d_Failure"));
        lbl_d_Failure->setGeometry(QRect(550, 130, 341, 31));
        tableView = new QTableView(digital_semantic_suit);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(550, 160, 321, 241));
        stackedWidget->addWidget(digital_semantic_suit);
        control_test_suit = new QWidget();
        control_test_suit->setObjectName(QStringLiteral("control_test_suit"));
        sizePolicy.setHeightForWidth(control_test_suit->sizePolicy().hasHeightForWidth());
        control_test_suit->setSizePolicy(sizePolicy);
        horizontalLayoutWidget_3 = new QWidget(control_test_suit);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(9, 9, 531, 381));
        layout_control_suit = new QHBoxLayout(horizontalLayoutWidget_3);
        layout_control_suit->setObjectName(QStringLiteral("layout_control_suit"));
        layout_control_suit->setContentsMargins(0, 0, 0, 0);
        gbox_DST_Control_Suit = new QGroupBox(horizontalLayoutWidget_3);
        gbox_DST_Control_Suit->setObjectName(QStringLiteral("gbox_DST_Control_Suit"));
        sizePolicy.setHeightForWidth(gbox_DST_Control_Suit->sizePolicy().hasHeightForWidth());
        gbox_DST_Control_Suit->setSizePolicy(sizePolicy);
        b_control_start_ade = new QPushButton(gbox_DST_Control_Suit);
        b_control_start_ade->setObjectName(QStringLiteral("b_control_start_ade"));
        b_control_start_ade->setGeometry(QRect(10, 40, 120, 31));
        b_control_stopAde = new QPushButton(gbox_DST_Control_Suit);
        b_control_stopAde->setObjectName(QStringLiteral("b_control_stopAde"));
        b_control_stopAde->setGeometry(QRect(400, 40, 121, 27));
        b_control_showreport = new QPushButton(gbox_DST_Control_Suit);
        b_control_showreport->setObjectName(QStringLiteral("b_control_showreport"));
        b_control_showreport->setGeometry(QRect(200, 280, 131, 27));
        b_control_sel_scenario = new QPushButton(gbox_DST_Control_Suit);
        b_control_sel_scenario->setObjectName(QStringLiteral("b_control_sel_scenario"));
        b_control_sel_scenario->setGeometry(QRect(190, 40, 131, 31));
        scrollControl_ScenarioList = new QScrollArea(gbox_DST_Control_Suit);
        scrollControl_ScenarioList->setObjectName(QStringLiteral("scrollControl_ScenarioList"));
        scrollControl_ScenarioList->setGeometry(QRect(10, 80, 511, 121));
        scrollControl_ScenarioList->setWidgetResizable(true);
        scrollAreaControlWidgetContents = new QWidget();
        scrollAreaControlWidgetContents->setObjectName(QStringLiteral("scrollAreaControlWidgetContents"));
        scrollAreaControlWidgetContents->setGeometry(QRect(0, 0, 509, 119));
        treeWidgetControl = new QTreeWidget(scrollAreaControlWidgetContents);
        treeWidgetControl->setObjectName(QStringLiteral("treeWidgetControl"));
        treeWidgetControl->setGeometry(QRect(170, 0, 341, 121));
        listWidgetSceneSelect = new QListWidget(scrollAreaControlWidgetContents);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidgetSceneSelect);
        __qlistwidgetitem->setFont(font3);
        new QListWidgetItem(listWidgetSceneSelect);
        new QListWidgetItem(listWidgetSceneSelect);
        new QListWidgetItem(listWidgetSceneSelect);
        new QListWidgetItem(listWidgetSceneSelect);
        new QListWidgetItem(listWidgetSceneSelect);
        listWidgetSceneSelect->setObjectName(QStringLiteral("listWidgetSceneSelect"));
        listWidgetSceneSelect->setGeometry(QRect(0, 0, 171, 121));
        scrollControl_ScenarioList->setWidget(scrollAreaControlWidgetContents);
        b_control_run_scenario = new QPushButton(gbox_DST_Control_Suit);
        b_control_run_scenario->setObjectName(QStringLiteral("b_control_run_scenario"));
        b_control_run_scenario->setGeometry(QRect(10, 210, 131, 27));
        b_control_stop_scenario = new QPushButton(gbox_DST_Control_Suit);
        b_control_stop_scenario->setObjectName(QStringLiteral("b_control_stop_scenario"));
        b_control_stop_scenario->setGeometry(QRect(390, 210, 131, 27));
        b_control_validation = new QPushButton(gbox_DST_Control_Suit);
        b_control_validation->setObjectName(QStringLiteral("b_control_validation"));
        b_control_validation->setGeometry(QRect(200, 210, 131, 27));

        layout_control_suit->addWidget(gbox_DST_Control_Suit);

        txtBrowser_control = new QTextBrowser(control_test_suit);
        txtBrowser_control->setObjectName(QStringLiteral("txtBrowser_control"));
        txtBrowser_control->setGeometry(QRect(560, 40, 301, 351));
        label = new QLabel(control_test_suit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 10, 281, 31));
        stackedWidget->addWidget(control_test_suit);

        horizontalLayout_4->addWidget(stackedWidget);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);


        verticalLayout_3->addWidget(gridWidget);

        lbl_outputlog = new QLabel(tab);
        lbl_outputlog->setObjectName(QStringLiteral("lbl_outputlog"));

        verticalLayout_3->addWidget(lbl_outputlog);

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
        pblaunch->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_StopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        b_showreport->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        b_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Select Scene", Q_NULLPTR));
        b_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_generatereport->setText(QApplication::translate("MainWindow", "Generate Report", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "     Report of Perception Validation", Q_NULLPTR));
        lbl_d_Auto->setText(QApplication::translate("MainWindow", "Detection range in Autoware (m/s)  :", Q_NULLPTR));
        lbl_d_LG->setText(QApplication::translate("MainWindow", "Detection range in LG (m/s)   :", Q_NULLPTR));
        lbl_d_Succes->setText(QApplication::translate("MainWindow", "Detection Success Rate (%)   :", Q_NULLPTR));
        lbl_d_Failure->setText(QApplication::translate("MainWindow", "Detection Failure Rate (%)   :", Q_NULLPTR));
        gbox_DST_Control_Suit->setTitle(QApplication::translate("MainWindow", "Control Test Suite", Q_NULLPTR));
        b_control_start_ade->setText(QApplication::translate("MainWindow", "Start ADE", Q_NULLPTR));
        b_control_stopAde->setText(QApplication::translate("MainWindow", "Stop ADE", Q_NULLPTR));
        b_control_showreport->setText(QApplication::translate("MainWindow", "Show Report", Q_NULLPTR));
        b_control_sel_scenario->setText(QApplication::translate("MainWindow", "Select Scenario", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetControl->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", " Select Scripts", Q_NULLPTR));

        const bool __sortingEnabled = listWidgetSceneSelect->isSortingEnabled();
        listWidgetSceneSelect->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetSceneSelect->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Select Scene       ", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidgetSceneSelect->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "BorregasAve", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidgetSceneSelect->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "SanFrancisco", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = listWidgetSceneSelect->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "SingleLaneRoad", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = listWidgetSceneSelect->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "CubeTown", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = listWidgetSceneSelect->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Jacksonville", Q_NULLPTR));
        listWidgetSceneSelect->setSortingEnabled(__sortingEnabled);

        b_control_run_scenario->setText(QApplication::translate("MainWindow", "Run Scenario", Q_NULLPTR));
        b_control_stop_scenario->setText(QApplication::translate("MainWindow", "Stop Scenario", Q_NULLPTR));
        b_control_validation->setText(QApplication::translate("MainWindow", "Validation", Q_NULLPTR));
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
