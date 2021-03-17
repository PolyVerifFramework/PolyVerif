#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QMap>
#include <QSet>
#include <Q_PID>
#include <QPlainTextEdit>
#include <QThread>
#include <QFileSystemWatcher>
#include <QDateTime>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct para_data{
    QString Script;
    QString scene;
}ST;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QMap<QString, QString> check_list;
    ST parameters;
    QString path;
    QString scenarioName;
    QSet<QString> selected;
    QString parent;
    QProcess *q_proc;
    QStringList textss;
    QString p_testCases;
    QDateTime curr_DateTime;
    QString csv_ReportPath;
    QString par;
    QList<QTreeWidgetItem *> sel_item_clr;
    int counter;
    QMovie *movie;
    ~MainWindow();

private slots:

    void on_pblaunch_clicked();

    void on_b_StopAde_clicked();

    void on_pblaunch_released();

    void on_b_StopAde_released();

    void on_checkBox_2_clicked();

    void on_actionexit_triggered();

    void on_b_sel_scenario_clicked();

    void on_b_run_scenario_clicked();

    void on_b_stop_scenario_clicked();

    void on_b_showreport_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_checkBox_3_clicked();

    void on_b_control_start_ade_clicked();

    void on_b_control_sel_scenario_clicked();

    void on_b_control_run_scenario_clicked();

    void on_treeWidgetControl_itemClicked(QTreeWidgetItem *item, int column);

    void on_b_control_showreport_clicked();

    void on_b_control_stopAde_clicked();

    void on_b_control_stop_scenario_clicked();

    void on_listWidgetSceneSelect_itemClicked(QListWidgetItem *item);

    void on_listWidgetSceneSelectDSU_itemClicked(QListWidgetItem *item);


    void on_b_control_validation_clicked();
    void fileChanged(const QString & path);
    void fileModify();
    void fileWatcher();
    void createTempRecordPath();
    void executeShell(QString path);



    void on_b_generatereport_clicked();

private:
    Ui::MainWindow *ui;
    bool startAde = false;
    bool dataRecord = false;
    bool check_flag = false;
    bool click = false;

    QString scenarioFile = "";
    QFileSystemWatcher * watcher;
    QStandardItemModel *model;

private:
    QSize sizeHint()const;

};
#endif // MAINWINDOW_H
