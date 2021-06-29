/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reportwindow
{
public:
    QTabWidget *tabReport;
    QWidget *controValidation;
    QLabel *lblRSpinner;
    QTableView *tableViewControl;
    QLabel *label_9;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *b_generateReportC;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *b_showReportC;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_9;
    QLabel *label_6;
    QLabel *lblGT;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_8;
    QLabel *lblPer;
    QSpacerItem *verticalSpacer_4;
    QLabel *lblBrake;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *lblDelayPer;
    QSpacerItem *verticalSpacer_7;
    QWidget *detectionValidation;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_441;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_439;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_440;
    QLabel *lblRSpinnerPerception;
    QTableView *tableView;
    QLabel *label_10;
    QWidget *layoutWidget3;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QLabel *lbl_d_Succes;
    QSpacerItem *verticalSpacer_10;
    QLabel *lbl_d_LG;
    QSpacerItem *verticalSpacer_11;
    QLabel *lbl_d_Auto;
    QSpacerItem *verticalSpacer_12;
    QLabel *lblSucceRate;
    QLabel *lblRangeLGSVL;
    QLabel *lblRangeAutoware;
    QWidget *localizationValidation;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_btn_top;
    QSpacerItem *horizontalSpacer_442;
    QPushButton *btn_local_Gen_Report;
    QSpacerItem *horizontalSpacer_443;
    QPushButton *btn_local_show_report;
    QSpacerItem *horizontalSpacer_444;
    QLabel *lbl_local_heading;
    QTableView *tblV_local_DataReport;
    QLabel *lbl_SpinnerLocalization;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_2;
    QLabel *lbl_local_meanDev;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblD_local_meanDev;
    QLabel *lbl_local_maxDev;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lblD_local_maxDev;
    QLabel *lbl_local_minDev;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lblD_local_minDev;
    QWidget *missionplanningValidation;
    QLabel *lbl_pp_spinnerPathPlanning;
    QTableView *tblV_pp_DataReport;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_btn_top_2;
    QSpacerItem *horizontalSpacer_445;
    QPushButton *btn_pp_Gen_Report;
    QSpacerItem *horizontalSpacer_446;
    QPushButton *btn_pp_show_report;
    QSpacerItem *horizontalSpacer_447;
    QLabel *lbl_pp_heading;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_3;
    QLabel *lblD_pp_goalPosAchieved;
    QLabel *lblD_pp_collisionCount;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lbl_pp_collisionCount;
    QLabel *lbl_pp_goalPosDeviation;
    QLabel *lblD_pp_goalPosDeviation;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lbl_pp_goalPosAchieved;
    QSpacerItem *horizontalSpacer_9;
    QLabel *lblD_pp_drivableAreaFollowed;
    QLabel *lbl_pp_drivableAreaFollowed;
    QWidget *summary;
    QTableWidget *tableWidSummary;
    QLabel *lbl_summry_lbl2;
    QLabel *lbl_summry_lbl1;
    QLabel *lblD_summry_lbl1;
    QLabel *lblD_summry_lbl2;
    QLabel *lbl_analysis;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *showReportLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QTreeWidget *treeWidgetReportDir;

    void setupUi(QDialog *reportwindow)
    {
        if (reportwindow->objectName().isEmpty())
            reportwindow->setObjectName(QStringLiteral("reportwindow"));
        reportwindow->resize(1268, 615);
        tabReport = new QTabWidget(reportwindow);
        tabReport->setObjectName(QStringLiteral("tabReport"));
        tabReport->setGeometry(QRect(220, 30, 1051, 591));
        controValidation = new QWidget();
        controValidation->setObjectName(QStringLiteral("controValidation"));
        lblRSpinner = new QLabel(controValidation);
        lblRSpinner->setObjectName(QStringLiteral("lblRSpinner"));
        lblRSpinner->setGeometry(QRect(550, 250, 121, 91));
        tableViewControl = new QTableView(controValidation);
        tableViewControl->setObjectName(QStringLiteral("tableViewControl"));
        tableViewControl->setGeometry(QRect(600, 130, 431, 401));
        label_9 = new QLabel(controValidation);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(11, 71, 581, 51));
        label_9->setFrameShape(QFrame::Panel);
        label_9->setAlignment(Qt::AlignCenter);
        label_9->setIndent(0);
        layoutWidget = new QWidget(controValidation);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(2, 2, 991, 61));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        b_generateReportC = new QPushButton(layoutWidget);
        b_generateReportC->setObjectName(QStringLiteral("b_generateReportC"));

        horizontalLayout_3->addWidget(b_generateReportC);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        b_showReportC = new QPushButton(layoutWidget);
        b_showReportC->setObjectName(QStringLiteral("b_showReportC"));

        horizontalLayout_3->addWidget(b_showReportC);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        layoutWidget1 = new QWidget(controValidation);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 130, 581, 401));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 7, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        lblGT = new QLabel(layoutWidget1);
        lblGT->setObjectName(QStringLiteral("lblGT"));

        gridLayout->addWidget(lblGT, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_8, 4, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 6, 0, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 0, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        lblPer = new QLabel(layoutWidget1);
        lblPer->setObjectName(QStringLiteral("lblPer"));

        gridLayout->addWidget(lblPer, 3, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 0, 1, 1);

        lblBrake = new QLabel(layoutWidget1);
        lblBrake->setObjectName(QStringLiteral("lblBrake"));

        gridLayout->addWidget(lblBrake, 8, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lblDelayPer = new QLabel(layoutWidget1);
        lblDelayPer->setObjectName(QStringLiteral("lblDelayPer"));

        gridLayout->addWidget(lblDelayPer, 5, 1, 2, 1);

        verticalSpacer_7 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 2, 1, 1, 1);

        tabReport->addTab(controValidation, QString());
        detectionValidation = new QWidget();
        detectionValidation->setObjectName(QStringLiteral("detectionValidation"));
        layoutWidget2 = new QWidget(detectionValidation);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(9, 9, 991, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_441 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_441);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_439 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_439);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_440 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_440);

        lblRSpinnerPerception = new QLabel(detectionValidation);
        lblRSpinnerPerception->setObjectName(QStringLiteral("lblRSpinnerPerception"));
        lblRSpinnerPerception->setGeometry(QRect(540, 220, 131, 101));
        tableView = new QTableView(detectionValidation);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(620, 110, 421, 421));
        label_10 = new QLabel(detectionValidation);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 59, 601, 51));
        label_10->setFrameShape(QFrame::Panel);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setIndent(0);
        layoutWidget3 = new QWidget(detectionValidation);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 110, 601, 421));
        formLayout = new QFormLayout(layoutWidget3);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::LabelRole, verticalSpacer);

        lbl_d_Succes = new QLabel(layoutWidget3);
        lbl_d_Succes->setObjectName(QStringLiteral("lbl_d_Succes"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_d_Succes);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer_10);

        lbl_d_LG = new QLabel(layoutWidget3);
        lbl_d_LG->setObjectName(QStringLiteral("lbl_d_LG"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lbl_d_LG);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer_11);

        lbl_d_Auto = new QLabel(layoutWidget3);
        lbl_d_Auto->setObjectName(QStringLiteral("lbl_d_Auto"));

        formLayout->setWidget(5, QFormLayout::LabelRole, lbl_d_Auto);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::LabelRole, verticalSpacer_12);

        lblSucceRate = new QLabel(layoutWidget3);
        lblSucceRate->setObjectName(QStringLiteral("lblSucceRate"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblSucceRate);

        lblRangeLGSVL = new QLabel(layoutWidget3);
        lblRangeLGSVL->setObjectName(QStringLiteral("lblRangeLGSVL"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblRangeLGSVL);

        lblRangeAutoware = new QLabel(layoutWidget3);
        lblRangeAutoware->setObjectName(QStringLiteral("lblRangeAutoware"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lblRangeAutoware);

        tabReport->addTab(detectionValidation, QString());
        localizationValidation = new QWidget();
        localizationValidation->setObjectName(QStringLiteral("localizationValidation"));
        layoutWidget_2 = new QWidget(localizationValidation);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(-1, 9, 991, 27));
        horizontalLayout_btn_top = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_btn_top->setObjectName(QStringLiteral("horizontalLayout_btn_top"));
        horizontalLayout_btn_top->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_442 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top->addItem(horizontalSpacer_442);

        btn_local_Gen_Report = new QPushButton(layoutWidget_2);
        btn_local_Gen_Report->setObjectName(QStringLiteral("btn_local_Gen_Report"));

        horizontalLayout_btn_top->addWidget(btn_local_Gen_Report);

        horizontalSpacer_443 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top->addItem(horizontalSpacer_443);

        btn_local_show_report = new QPushButton(layoutWidget_2);
        btn_local_show_report->setObjectName(QStringLiteral("btn_local_show_report"));

        horizontalLayout_btn_top->addWidget(btn_local_show_report);

        horizontalSpacer_444 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top->addItem(horizontalSpacer_444);

        lbl_local_heading = new QLabel(localizationValidation);
        lbl_local_heading->setObjectName(QStringLiteral("lbl_local_heading"));
        lbl_local_heading->setGeometry(QRect(0, 59, 601, 51));
        lbl_local_heading->setFrameShape(QFrame::Panel);
        lbl_local_heading->setAlignment(Qt::AlignCenter);
        lbl_local_heading->setIndent(0);
        tblV_local_DataReport = new QTableView(localizationValidation);
        tblV_local_DataReport->setObjectName(QStringLiteral("tblV_local_DataReport"));
        tblV_local_DataReport->setGeometry(QRect(610, 120, 421, 411));
        lbl_SpinnerLocalization = new QLabel(localizationValidation);
        lbl_SpinnerLocalization->setObjectName(QStringLiteral("lbl_SpinnerLocalization"));
        lbl_SpinnerLocalization->setGeometry(QRect(530, 220, 131, 101));
        layoutWidget4 = new QWidget(localizationValidation);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 140, 381, 261));
        gridLayout_2 = new QGridLayout(layoutWidget4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_local_meanDev = new QLabel(layoutWidget4);
        lbl_local_meanDev->setObjectName(QStringLiteral("lbl_local_meanDev"));

        gridLayout_2->addWidget(lbl_local_meanDev, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        lblD_local_meanDev = new QLabel(layoutWidget4);
        lblD_local_meanDev->setObjectName(QStringLiteral("lblD_local_meanDev"));

        gridLayout_2->addWidget(lblD_local_meanDev, 0, 2, 1, 1);

        lbl_local_maxDev = new QLabel(layoutWidget4);
        lbl_local_maxDev->setObjectName(QStringLiteral("lbl_local_maxDev"));

        gridLayout_2->addWidget(lbl_local_maxDev, 1, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 1, 1, 1);

        lblD_local_maxDev = new QLabel(layoutWidget4);
        lblD_local_maxDev->setObjectName(QStringLiteral("lblD_local_maxDev"));

        gridLayout_2->addWidget(lblD_local_maxDev, 1, 2, 1, 1);

        lbl_local_minDev = new QLabel(layoutWidget4);
        lbl_local_minDev->setObjectName(QStringLiteral("lbl_local_minDev"));

        gridLayout_2->addWidget(lbl_local_minDev, 2, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 1, 1, 1);

        lblD_local_minDev = new QLabel(layoutWidget4);
        lblD_local_minDev->setObjectName(QStringLiteral("lblD_local_minDev"));

        gridLayout_2->addWidget(lblD_local_minDev, 2, 2, 1, 1);

        tabReport->addTab(localizationValidation, QString());
        missionplanningValidation = new QWidget();
        missionplanningValidation->setObjectName(QStringLiteral("missionplanningValidation"));
        lbl_pp_spinnerPathPlanning = new QLabel(missionplanningValidation);
        lbl_pp_spinnerPathPlanning->setObjectName(QStringLiteral("lbl_pp_spinnerPathPlanning"));
        lbl_pp_spinnerPathPlanning->setGeometry(QRect(530, 211, 131, 101));
        tblV_pp_DataReport = new QTableView(missionplanningValidation);
        tblV_pp_DataReport->setObjectName(QStringLiteral("tblV_pp_DataReport"));
        tblV_pp_DataReport->setGeometry(QRect(610, 121, 421, 401));
        layoutWidget_4 = new QWidget(missionplanningValidation);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 10, 991, 27));
        horizontalLayout_btn_top_2 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_btn_top_2->setObjectName(QStringLiteral("horizontalLayout_btn_top_2"));
        horizontalLayout_btn_top_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_445 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top_2->addItem(horizontalSpacer_445);

        btn_pp_Gen_Report = new QPushButton(layoutWidget_4);
        btn_pp_Gen_Report->setObjectName(QStringLiteral("btn_pp_Gen_Report"));

        horizontalLayout_btn_top_2->addWidget(btn_pp_Gen_Report);

        horizontalSpacer_446 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top_2->addItem(horizontalSpacer_446);

        btn_pp_show_report = new QPushButton(layoutWidget_4);
        btn_pp_show_report->setObjectName(QStringLiteral("btn_pp_show_report"));

        horizontalLayout_btn_top_2->addWidget(btn_pp_show_report);

        horizontalSpacer_447 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_btn_top_2->addItem(horizontalSpacer_447);

        lbl_pp_heading = new QLabel(missionplanningValidation);
        lbl_pp_heading->setObjectName(QStringLiteral("lbl_pp_heading"));
        lbl_pp_heading->setGeometry(QRect(0, 60, 601, 51));
        lbl_pp_heading->setFrameShape(QFrame::Panel);
        lbl_pp_heading->setAlignment(Qt::AlignCenter);
        lbl_pp_heading->setIndent(0);
        layoutWidget5 = new QWidget(missionplanningValidation);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 132, 511, 281));
        gridLayout_3 = new QGridLayout(layoutWidget5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lblD_pp_goalPosAchieved = new QLabel(layoutWidget5);
        lblD_pp_goalPosAchieved->setObjectName(QStringLiteral("lblD_pp_goalPosAchieved"));

        gridLayout_3->addWidget(lblD_pp_goalPosAchieved, 0, 2, 1, 1);

        lblD_pp_collisionCount = new QLabel(layoutWidget5);
        lblD_pp_collisionCount->setObjectName(QStringLiteral("lblD_pp_collisionCount"));

        gridLayout_3->addWidget(lblD_pp_collisionCount, 2, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 1, 1, 1, 1);

        lbl_pp_collisionCount = new QLabel(layoutWidget5);
        lbl_pp_collisionCount->setObjectName(QStringLiteral("lbl_pp_collisionCount"));

        gridLayout_3->addWidget(lbl_pp_collisionCount, 2, 0, 1, 1);

        lbl_pp_goalPosDeviation = new QLabel(layoutWidget5);
        lbl_pp_goalPosDeviation->setObjectName(QStringLiteral("lbl_pp_goalPosDeviation"));

        gridLayout_3->addWidget(lbl_pp_goalPosDeviation, 1, 0, 1, 1);

        lblD_pp_goalPosDeviation = new QLabel(layoutWidget5);
        lblD_pp_goalPosDeviation->setObjectName(QStringLiteral("lblD_pp_goalPosDeviation"));

        gridLayout_3->addWidget(lblD_pp_goalPosDeviation, 1, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 3, 1, 1, 1);

        lbl_pp_goalPosAchieved = new QLabel(layoutWidget5);
        lbl_pp_goalPosAchieved->setObjectName(QStringLiteral("lbl_pp_goalPosAchieved"));

        gridLayout_3->addWidget(lbl_pp_goalPosAchieved, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 2, 1, 1, 1);

        lblD_pp_drivableAreaFollowed = new QLabel(layoutWidget5);
        lblD_pp_drivableAreaFollowed->setObjectName(QStringLiteral("lblD_pp_drivableAreaFollowed"));

        gridLayout_3->addWidget(lblD_pp_drivableAreaFollowed, 3, 2, 1, 1);

        lbl_pp_drivableAreaFollowed = new QLabel(layoutWidget5);
        lbl_pp_drivableAreaFollowed->setObjectName(QStringLiteral("lbl_pp_drivableAreaFollowed"));

        gridLayout_3->addWidget(lbl_pp_drivableAreaFollowed, 3, 0, 1, 1);

        tabReport->addTab(missionplanningValidation, QString());
        summary = new QWidget();
        summary->setObjectName(QStringLiteral("summary"));
        tableWidSummary = new QTableWidget(summary);
        tableWidSummary->setObjectName(QStringLiteral("tableWidSummary"));
        tableWidSummary->setGeometry(QRect(20, 40, 641, 421));
        lbl_summry_lbl2 = new QLabel(summary);
        lbl_summry_lbl2->setObjectName(QStringLiteral("lbl_summry_lbl2"));
        lbl_summry_lbl2->setGeometry(QRect(670, 150, 205, 65));
        lbl_summry_lbl1 = new QLabel(summary);
        lbl_summry_lbl1->setObjectName(QStringLiteral("lbl_summry_lbl1"));
        lbl_summry_lbl1->setGeometry(QRect(670, 90, 205, 65));
        lblD_summry_lbl1 = new QLabel(summary);
        lblD_summry_lbl1->setObjectName(QStringLiteral("lblD_summry_lbl1"));
        lblD_summry_lbl1->setGeometry(QRect(910, 87, 81, 65));
        lblD_summry_lbl2 = new QLabel(summary);
        lblD_summry_lbl2->setObjectName(QStringLiteral("lblD_summry_lbl2"));
        lblD_summry_lbl2->setGeometry(QRect(910, 150, 101, 65));
        lbl_analysis = new QLabel(summary);
        lbl_analysis->setObjectName(QStringLiteral("lbl_analysis"));
        lbl_analysis->setGeometry(QRect(790, 30, 205, 65));
        tabReport->addTab(summary, QString());
        horizontalLayoutWidget_2 = new QWidget(reportwindow);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 211, 561));
        showReportLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        showReportLayout->setObjectName(QStringLiteral("showReportLayout"));
        showReportLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_5->addWidget(pushButton);

        treeWidgetReportDir = new QTreeWidget(horizontalLayoutWidget_2);
        treeWidgetReportDir->setObjectName(QStringLiteral("treeWidgetReportDir"));

        verticalLayout_5->addWidget(treeWidgetReportDir);


        showReportLayout->addLayout(verticalLayout_5);


        retranslateUi(reportwindow);

        tabReport->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(reportwindow);
    } // setupUi

    void retranslateUi(QDialog *reportwindow)
    {
        reportwindow->setWindowTitle(QApplication::translate("reportwindow", "Dialog", Q_NULLPTR));
        lblRSpinner->setText(QString());
        label_9->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Control Validation Report</span></p></body></html>", Q_NULLPTR));
        b_generateReportC->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        b_showReportC->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        label_6->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Response Time of Ego in Autoware (sec) :</span></p></body></html>", Q_NULLPTR));
        lblGT->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Brake Applied from Ego :</span></p></body></html>", Q_NULLPTR));
        lblPer->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblBrake->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Delay in Response Time of Ego in Autoware (sec) :</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Response Time of Ego in LGSVL (sec) :</span></p></body></html>", Q_NULLPTR));
        lblDelayPer->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(controValidation), QApplication::translate("reportwindow", "Control Validation", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        lblRSpinnerPerception->setText(QString());
        label_10->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection Validation Report</span></p></body></html>", Q_NULLPTR));
        lbl_d_Succes->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection Success Rate (%) of Autoware                  :</span></p></body></html>", Q_NULLPTR));
        lbl_d_LG->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection range of LGSVL (meters)                      :</span></p></body></html>", Q_NULLPTR));
        lbl_d_Auto->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection range of Autoware (meters)                   :</span></p></body></html>", Q_NULLPTR));
        lblSucceRate->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblRangeLGSVL->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblRangeAutoware->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(detectionValidation), QApplication::translate("reportwindow", "Detection Validation", Q_NULLPTR));
        btn_local_Gen_Report->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        btn_local_show_report->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        lbl_local_heading->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Localization Validation Report</span></p></body></html>", Q_NULLPTR));
        lbl_SpinnerLocalization->setText(QString());
        lbl_local_meanDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Mean Deviation(meters)</span></p></body></html>", Q_NULLPTR));
        lblD_local_meanDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lbl_local_maxDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Max Deviation(meters)</span></p></body></html>", Q_NULLPTR));
        lblD_local_maxDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lbl_local_minDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Min Deviation(meters)</span></p></body></html>", Q_NULLPTR));
        lblD_local_minDev->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(localizationValidation), QApplication::translate("reportwindow", "Localization Validation", Q_NULLPTR));
        lbl_pp_spinnerPathPlanning->setText(QString());
        btn_pp_Gen_Report->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        btn_pp_show_report->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        lbl_pp_heading->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Mission Planning Validation Report</span></p></body></html>", Q_NULLPTR));
        lblD_pp_goalPosAchieved->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblD_pp_collisionCount->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lbl_pp_collisionCount->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Number of Collisions</span></p></body></html>", Q_NULLPTR));
        lbl_pp_goalPosDeviation->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Goal Position Deviation(meters)</span></p></body></html>", Q_NULLPTR));
        lblD_pp_goalPosDeviation->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lbl_pp_goalPosAchieved->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Goal Position Achieved</span></p></body></html>", Q_NULLPTR));
        lblD_pp_drivableAreaFollowed->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lbl_pp_drivableAreaFollowed->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Driveable Area Followed</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(missionplanningValidation), QApplication::translate("reportwindow", "Mission Planning Validation", Q_NULLPTR));
        lbl_summry_lbl2->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Collision </span></p></body></html>", Q_NULLPTR));
        lbl_summry_lbl1->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Destination Reached</span></p></body></html>", Q_NULLPTR));
        lblD_summry_lbl1->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#4e9a06;\">Succeed</span></p></body></html>", Q_NULLPTR));
        lblD_summry_lbl2->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; color:#4e9a06;\">No Collision</span></p></body></html>", Q_NULLPTR));
        lbl_analysis->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Analysis</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(summary), QApplication::translate("reportwindow", "Summary ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("reportwindow", "Load Report", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetReportDir->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("reportwindow", "Select Simulation Report", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reportwindow: public Ui_reportwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
