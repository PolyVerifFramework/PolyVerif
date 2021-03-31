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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reportwindow
{
public:
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *showReportLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QTreeWidget *treeWidgetReportDir;
    QTabWidget *tabReport;
    QWidget *controValidation;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *perceptionValidation;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_4;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_5;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_6;
    QTableView *tableView_3;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;

    void setupUi(QDialog *reportwindow)
    {
        if (reportwindow->objectName().isEmpty())
            reportwindow->setObjectName(QStringLiteral("reportwindow"));
        reportwindow->resize(1284, 595);
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
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidgetReportDir->setHeaderItem(__qtreewidgetitem);
        treeWidgetReportDir->setObjectName(QStringLiteral("treeWidgetReportDir"));

        verticalLayout_5->addWidget(treeWidgetReportDir);


        showReportLayout->addLayout(verticalLayout_5);

        tabReport = new QTabWidget(reportwindow);
        tabReport->setObjectName(QStringLiteral("tabReport"));
        tabReport->setGeometry(QRect(230, 30, 1041, 561));
        controValidation = new QWidget();
        controValidation->setObjectName(QStringLiteral("controValidation"));
        horizontalLayoutWidget_3 = new QWidget(controValidation);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(270, 80, 481, 371));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(horizontalLayoutWidget_3);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout->addWidget(tableView);

        verticalLayoutWidget = new QWidget(controValidation);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1031, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_4 = new QWidget(controValidation);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(750, 80, 281, 371));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(controValidation);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 450, 1031, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_5 = new QWidget(controValidation);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(0, 80, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        tabReport->addTab(controValidation, QString());
        perceptionValidation = new QWidget();
        perceptionValidation->setObjectName(QStringLiteral("perceptionValidation"));
        horizontalLayoutWidget_6 = new QWidget(perceptionValidation);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(0, 80, 271, 371));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_7 = new QWidget(perceptionValidation);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(750, 80, 281, 371));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(perceptionValidation);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 450, 1031, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(perceptionValidation);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 1031, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_8 = new QWidget(perceptionValidation);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(270, 80, 481, 371));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        tableView_3 = new QTableView(horizontalLayoutWidget_8);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));

        horizontalLayout_6->addWidget(tableView_3);

        tabReport->addTab(perceptionValidation, QString());
        verticalLayoutWidget_6 = new QWidget(reportwindow);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(630, 320, 1031, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);

        retranslateUi(reportwindow);

        tabReport->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(reportwindow);
    } // setupUi

    void retranslateUi(QDialog *reportwindow)
    {
        reportwindow->setWindowTitle(QApplication::translate("reportwindow", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("reportwindow", "Load Report", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(controValidation), QApplication::translate("reportwindow", "Control Validation", Q_NULLPTR));
        tabReport->setTabText(tabReport->indexOf(perceptionValidation), QApplication::translate("reportwindow", "Perception Validation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class reportwindow: public Ui_reportwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWINDOW_H
