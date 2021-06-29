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
#include "reportwindow.h"
#include <QInputDialog>
#include <QLineEdit>

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
    QString  count;
    bool flag1 = true,flag2 = true;
    QString path;
    QString reportPath;
    QString tCase;
    QString scenarioName;
    QSet<QString> selected;
    QString parent;
    QProcess *q_proc;
    int count1 =1;
    int scenarioItr = 1;
    QStringList textss;
    QString p_testCases;
    QDateTime curr_DateTime;
    QString csv_ReportPath;
    QString par;
    QList<QTreeWidgetItem *> sel_item_clr;
    bool flagSimulation = false;
    QMovie *movie;
    ~MainWindow();

signals:
    void updateUI1Signal(const QString text);
    void seltabSignal(const int);

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

    void on_scenic_activate_clicked();

    void on_run_scenic_control_clicked();

    void on_b_showreport_2_clicked();

    void on_scenic_activate_2_clicked();

    void on_avp_button_clicked();

    void on_initial_pos_b_clicked();

    void on_goal_pos_b_clicked();

    void on_avp_button_2_clicked();

    void on_scenic_activate_3_clicked();

    void on_initial_pos_b_2_clicked();

    void on_goal_pos_b_2_clicked();

    void on_ckbox_localization_clicked();

    void on_ckbox_PathPlanning_clicked();

    void on_treeWid_local_select_script_itemClicked(QTreeWidgetItem *item, int column);

    void on_btn_local_sel_scenario_clicked();

    void on_btn_local_adeStart_clicked();

    void on_btn_local_StopAde_clicked();

    void on_listWid_local_scene_select_itemClicked(QListWidgetItem *item);

    void on_btn_local_scenic_count_clicked();

    void on_btn_local_scenic_run_clicked();

    void on_btn_local_run_scenario_clicked();

    void on_btn_local_stop_scenario_clicked();

    void on_btn_local_showreport_clicked();

    void on_btn_local_avp_clicked();

    void on_btn_local_initial_pos_clicked();

    void on_btn_local_goal_pos_clicked();

    void on_btn_pp_adeStart_clicked();

    void on_btn_pp_sel_scenario_clicked();

    void on_btn_pp_StopAde_clicked();

    void on_listWid_pp_scene_select_itemClicked(QListWidgetItem *item);

    void on_treeWid_pp_select_script_itemClicked(QTreeWidgetItem *item, int column);

    void on_btn_pp_scenic_count_clicked();

    void on_btn_pp_scenic_run_clicked();

    void on_btn_pp_run_scenario_clicked();

    void on_btn_pp_stop_scenario_clicked();

    void on_btn_pp_showreport_clicked();

    void on_btn_pp_avp_clicked();

    void on_btn_pp_initial_pos_clicked();

    void on_btn_pp_goal_pos_clicked();


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
