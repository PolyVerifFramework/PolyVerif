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
    QWidget *perceptionValidation;
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
    QWidget *pathplanningValidation;
    QWidget *consolidatedReport;
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
        perceptionValidation = new QWidget();
        perceptionValidation->setObjectName(QStringLiteral("perceptionValidation"));
        layoutWidget2 = new QWidget(perceptionValidation);
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

        lblRSpinnerPerception = new QLabel(perceptionValidation);
        lblRSpinnerPerception->setObjectName(QStringLiteral("lblRSpinnerPerception"));
        lblRSpinnerPerception->setGeometry(QRect(540, 220, 131, 101));
        tableView = new QTableView(perceptionValidation);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(620, 110, 421, 421));
        label_10 = new QLabel(perceptionValidation);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 59, 601, 51));
        label_10->setFrameShape(QFrame::Panel);
        label_10->setAlignment(Qt::AlignCenter);
        label_10->setIndent(0);
        layoutWidget3 = new QWidget(perceptionValidation);
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

        tabReport->addTab(perceptionValidation, QString());
        localizationValidation = new QWidget();
        localizationValidation->setObjectName(QStringLiteral("localizationValidation"));
        tabReport->addTab(localizationValidation, QString());
        pathplanningValidation = new QWidget();
        pathplanningValidation->setObjectName(QStringLiteral("pathplanningValidation"));
        tabReport->addTab(pathplanningValidation, QString());
        consolidatedReport = new QWidget();
        consolidatedReport->setObjectName(QStringLiteral("consolidatedReport"));
        tabReport->addTab(consolidatedReport, QString());
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

        tabReport->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(reportwindow);
    } // setupUi

    void retranslateUi(QDialog *reportwindow)
    {
        reportwindow->setWindowTitle(QApplication::translate("reportwindow", "Dialog", Q_NULLPTR));
        lblRSpinner->setText(QString());
        label_9->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Report of Autoware Control Validation</span></p></body></html>", Q_NULLPTR));
        b_generateReportC->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        b_showReportC->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        label_6->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Reaction Time of Ego in Autoware (sec) :</span></p></body></html>", Q_NULLPTR));
        lblGT->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Brake Applied from Ego :</span></p></body></html>", Q_NULLPTR));
        lblPer->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblBrake->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Delay in Reaction Time of Ego in Autoware (sec) :</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Reaction Time of Ego in LGSVL (sec) :</span></p></body></html>", Q_NULLPTR));
        lblDelayPer->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(controValidation), QApplication::translate("reportwindow", "Control Validation", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("reportwindow", "Generate Report", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("reportwindow", "Show Report", Q_NULLPTR));
        lblRSpinnerPerception->setText(QString());
        label_10->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Report of Autoware Perception Validation</span></p></body></html>", Q_NULLPTR));
        lbl_d_Succes->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection Success Rate (%) of Autoware                  :</span></p></body></html>", Q_NULLPTR));
        lbl_d_LG->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection range of LGSVL (meters)                      :</span></p></body></html>", Q_NULLPTR));
        lbl_d_Auto->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Detection range of Autoware (meters)                   :</span></p></body></html>", Q_NULLPTR));
        lblSucceRate->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblRangeLGSVL->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        lblRangeAutoware->setText(QApplication::translate("reportwindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">NA</span></p></body></html>", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(perceptionValidation), QApplication::translate("reportwindow", "Perception Validation", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(localizationValidation), QApplication::translate("reportwindow", "Localization Validation", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(pathplanningValidation), QApplication::translate("reportwindow", "Path Planning Validation", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(consolidatedReport), QApplication::translate("reportwindow", "Consolidated Report", Q_NULLPTR));
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
