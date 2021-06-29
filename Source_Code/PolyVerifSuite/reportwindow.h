#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QMovie>
#include <QLayout>

namespace Ui {
class reportwindow;
}

class reportwindow : public QDialog
{
    Q_OBJECT

public:
    explicit reportwindow(QWidget *parent = 0);
    ~reportwindow();

    QString simReport = "";
    QMovie *movie;
    bool flag = true;
    QString statsData[4];

public slots:
    void updateUI2TextSlot( const QString text );
    void seltabSlot(const int);
    void TableWidgetDisplay();
    bool ControlStatsFileRead(QString file_name);
    bool PerceptionStatsFileRead(QString file_name);
    bool LocalizationStatsFileRead(QString file_name);
    bool PlannerStatsFileRead(QString file_name);


private slots:

    void on_treeWidgetReportDir_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();

    void on_b_generateReportC_clicked();

    void executeShell(QString path);

    void on_b_showReportC_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_btn_local_Gen_Report_clicked();

    void on_btn_local_show_report_clicked();

    void on_btn_pp_Gen_Report_clicked();

    void on_btn_pp_show_report_clicked();

    void on_tableWidSummary_clicked(const QModelIndex &index);

private:
    Ui::reportwindow *ui;
    QString p_testCases = "";

};

#endif // REPORTWINDOW_H
