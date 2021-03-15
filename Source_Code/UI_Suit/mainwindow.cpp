#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringList>
#include <QProcess>
#include <QDir>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFile>
#include <iostream>
#include <thread>
#include <QStandardItemModel>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    this->setWindowTitle("Poly-Validation Suit");
    //this->setFixedSize(1080,600);
    ui->gbox_DST_Suit->setVisible(false);

    ui->stackedWidget->setVisible(false);
    ui->pblaunch->setDisabled(true);
    ui->b_StopAde->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->b_showreport->setDisabled(true);
    ui->b_sel_scenario->setDisabled(true);


    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_sel_scenario->setDisabled(true);
    ui->b_control_start_ade->setDisabled(true);
    ui->b_control_stopAde->setDisabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_showreport->setDisabled(true);
    ui->treeWidgetControl->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(1200,800);
}

void MainWindow::on_pblaunch_clicked()
{
    this->startAde = true;
    qDebug() << "Ade start ";
    ui->lbl_outputlog->setText("Log Information : ADE and other component initilize, it may take while to start..");
    ui->b_StopAde->setEnabled(true);
    ui->b_sel_scenario->setEnabled(true);
    model = new QStandardItemModel;

    QString path = QDir::currentPath() + "/q_ade_start.sh";
    executeShell(path);

    fileWatcher();

    createTempRecordPath();
}
void MainWindow::createTempRecordPath(){
    //stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"+tCase + ".txt" <<"\n";

    QString curr_path = QDir::currentPath();

    int pos = curr_path.lastIndexOf(QChar('/'));
    QString polyReportPath = curr_path.left(pos) + "/PolyReports/Validation_report/";
    QFile fp(polyReportPath + "/config.txt");
    fp.open(QIODevice::WriteOnly);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "PolyReports/Temp_Files \n";
    fp.close();
}

// TODO path
// Check the logInfo file if any change happened or not
void MainWindow::fileWatcher(){
    //QString curr_path = QDir::currentPath();
    //int pos = curr_path.lastIndexOf(QChar('/'));
    //QString p_logInfo = curr_path.left(pos) + "/logfiles/logInfo.txt";

    QString curr_path = QDir::currentPath();
    QString p_logInfo = curr_path + "/logfiles/logInfo.txt";
    qDebug() << "new path : " + p_logInfo;
    watcher = new QFileSystemWatcher(this);
    connect(watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(fileChanged(const QString &)));
    if (QFile::exists(p_logInfo)) {
        watcher->addPath(p_logInfo);

    }
}

// If any change happened in logInfo file it will update in the UI
void MainWindow::fileChanged(const QString & path){

    qDebug() << path;
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            this->textss.append(in.readLine());
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
    }
    if(!this->textss.isEmpty()){
        qDebug() <<"Hello";
        ui->lbl_outputlog->setText("Log Information : " + this->textss.first());
        this->textss.pop_front();
    }
}

void MainWindow::on_b_StopAde_clicked()
{
    qDebug() << "ADE Stopped  ";
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);
    ui->b_sel_scenario->setDisabled(true);
    ui->treeWidget->clear();
    ui->treeWidget->setDisabled(true);
    ui->listWidgetSceneSelectDSU->setDisabled(true);
    ui->b_showreport->setDisabled(true);

    model->clear();
    ui->tableView->setModel(model);
    ui->lbl_d_Auto->setText("Detection range in Autoware(m/s) : NA");
    ui->lbl_d_LG->setText("Detection range in LG(m/s) : NA");
    ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA" );
    ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA" );
    QFile fp(QDir::currentPath() + "/test_runner.sh");
    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);

    ui->lbl_outputlog->setText("Log Information : ADE Stop");

    //Rahul
    delete watcher;
    delete model;

    fileModify();
}

void MainWindow::fileModify(){
    //QString curr_path = QDir::currentPath();
    //int pos = curr_path.lastIndexOf(QChar('/'));
    //QString p_logInfo = curr_path.left(pos) + "/logfiles/logInfo.txt";

    QString curr_path = QDir::currentPath();
    QString p_logInfo = curr_path + "/logfiles/logInfo.txt";
    qDebug() << "new path : " + p_logInfo;
    QFile fileModify(p_logInfo);
    if (!fileModify.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate))
    {
        qDebug()<<" file emptying failed";
    }
    fileModify.close();
}



void MainWindow::on_pblaunch_released()
{
    ui->pblaunch->setDisabled(true);
}

void MainWindow::on_b_StopAde_released()
{
    ui->pblaunch->setEnabled(true);
    ui->b_StopAde->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setDisabled(true);
}

void MainWindow::on_checkBox_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->checkBox_3->setChecked(false);
    if(ui->checkBox_2->isChecked()){
        ui->gbox_DST_Suit->setVisible(true);
        ui->stackedWidget->setVisible(true);
        ui->pblaunch->setEnabled(true);
        ui->b_StopAde->setDisabled(true);
        ui->treeWidget->setDisabled(true);
        ui->listWidgetSceneSelectDSU->setDisabled(true);

    }else{
        ui->gbox_DST_Suit->setVisible(false);
        ui->stackedWidget->setVisible(false);
        ui->pblaunch->setDisabled(true);
        ui->b_StopAde->setDisabled(true);
        if( this->startAde == true){
            QString path = QDir::currentPath() + "/q_stopt.sh";
            executeShell(path);
            if(this->dataRecord == true){
                QString path = QDir::currentPath() + "/q_data_stop.sh";
                executeShell(path);
            }
        }
    }
}

void MainWindow::on_actionexit_triggered()
{
    this->close();
}

void MainWindow::on_b_sel_scenario_clicked()
{
    ui->treeWidget->clear();
    //ui->b_run_scenario->setEnabled(true);
    ui->listWidgetSceneSelectDSU->setEnabled(true);

    // TODO path dynamic back one folder
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    qDebug() << "new path : " + p_testCases;
    directory.setPath(p_testCases) ;
    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(flag == false)
        {
            QDir dir(finfo.absoluteFilePath());
            root->setText(0,dir.dirName());
            qDebug() << "In main dir : " << root->text(0) ;
            ui->treeWidget->addTopLevelItem(root);
            root->setCheckState(0,Qt::Unchecked); //optional
            flag = true;
        }//if_
        else
        {
            QDir dir(finfo.absoluteFilePath());
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            child->setCheckState(0,Qt::Unchecked);
            root->addChild(child);
            if(finfo.isDir())
            {
                QDir dir(finfo.absoluteFilePath());
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py" ;
                    d.setNameFilters(flt);
                    for(const QFileInfo &f : d.entryInfoList()){
                        if(f.fileName() == "run.py")
                            continue;
                        QFile fp(dir.absolutePath()+"/config.txt");
                        if (!fp.open(QIODevice::ReadOnly))
                        {
                            qDebug() << "File not open";
                            return;
                        }
                        while (!fp.atEnd()) {
                            QString str = fp.readLine();
                            // qDebug() <<str;
                            QString s = f.fileName();
                            str = str.remove('\n');
                            s.remove(".py");
                            s.append(":"+str);
                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
                            child_c->setText(0,s);
                            child_c->setCheckState(0,Qt::Unchecked);
                            child->addChild(child_c);

                        }//while
                        fp.flush();
                        fp.close();
                    }
                }
            }
        }
    }
}

void MainWindow::on_b_run_scenario_clicked()
{
    model->clear();
    ui->tableView->setModel(model);
    ui->lbl_d_Auto->setText("Detection range in Autoware(m/s): NA");
    ui->lbl_d_LG->setText("Detection range in LG(m/s) : NA");
    ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA");
    ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");


    // TODO
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");
    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \nset -eu\n";

    // TODO WeaterControl sitng need to be dynamic
    // Added the directory path for report
    //QString testcasepath = p_testCases + "/Weather_Control/";
    QString testcasepath =  "/Test_Cases/Weather_Control/";
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";

    //sh ./support_files/validate_perception.sh &
    //mpid=$!
    //echo $mpid

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos);
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"+tCase + ".txt" <<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        //stream << "sh ./support_files/validate_perception.sh & \n";
        //stream << "perception_pid=$! \n";
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    fp.close();
    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh";
        executeShell(c_path);
    }

    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setEnabled(true);
    ui->b_showreport->setDisabled(true);
}

void MainWindow::executeShell(QString path){
    QProcess *process = new QProcess();
    process->execute(path);
    //process->waitForFinished(300);
    delete process;
}

void MainWindow::on_b_stop_scenario_clicked()
{

    QFile fp(QDir::currentPath() + "/test_runner.sh");
    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
    fp.close();
    ui->b_stop_scenario->setDisabled(true);
    ui->b_run_scenario->setEnabled(true);
    ui->b_showreport->setEnabled(true);
    QString c_path = QDir::currentPath() + "/stop_scenario.sh" ;
    executeShell(c_path);
    qDebug() << "Stoping scenario.." ;
}

void MainWindow::on_b_showreport_clicked()
{
    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_perception_val_script.sh";
    executeShell(path);

    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);

    // int pos1 = rp_filepath.lastIndexOf(QChar('/'));
    // QString rp1 = rp_filepath.left(pos1);


    QThread::sleep(1);
    //csv_ReportPath = "PolyReports/Validation_report/" + dateTimeString + "/" + "TC_1";
    //model = new QStandardItemModel;
    QString rfile = rp_filepath + "/" + csv_ReportPath + "/rangeReport.csv";
    qDebug() << "complete path of range report : ",rfile;
    QFile file(rfile);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            qDebug() << "line ",line;
            QList<QStandardItem *> standardItemsList;
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            model->insertRow(model->rowCount(), standardItemsList);
        }
        file.close();
    }
    ui->tableView->setModel(model);


    QString txtreport = rp_filepath + "/" + csv_ReportPath + "/report_1.txt";
    qDebug() << "complete path of range report : ",txtreport;
    QString rData[4];
    QFile txtfile(txtreport);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        ui->lbl_d_Auto->setText("Detection range in Autoware(m/s) : NA");
        ui->lbl_d_LG->setText("Detection range in LG(m/s) : NA");
        ui->lbl_d_Succes->setText("Detection Success Rate(%): NA");
        ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");
    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] =line;
        }
        txtfile.close();
        ui->lbl_d_Auto->setText("Detection range in Autoware(m/s) : " + rData[0]);
        ui->lbl_d_LG->setText("Detection range in LG(m/s) : " + rData[1]);
        ui->lbl_d_Succes->setText("Detection Success Rate(%) : " + rData[2]);
        ui->lbl_d_Failure->setText("Detection Failure Rate(%) : " + rData[3]);
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Qt::CheckState p; //updted
    p = Qt::Unchecked; //updated
    QString str = item->text(column),mainstring;
    int pos = str.indexOf(":");
    str = str.left(pos) + ".py";
    parameters.Script = str.left(pos) + ".py";
    qDebug() << "First click  : " << parameters.Script;
    mainstring = parameters.Script + " "; //updated
    if(item->text(column).contains("rain"))
    {
        QString tmp = item->text(column),val;
        foreach(QChar c, tmp){
            if(c == ',')
                val.append(" ");
            if(c.isDigit() || c == '.')
                val.append(c);
        }
        check_list.insert("Rain",val);
        //rain.insert(val);
        mainstring.append(val + " "); //updtaed
        mainstring.append(parameters.scene); //updated
        parameters.rain = val;
        qDebug() << "Mainstring  : " << mainstring;
        if(item->checkState(column) == p){
            selected.remove(mainstring);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }

    }
    //TO DO : for other parameters
    check_flag = true;
    ui->b_run_scenario->setEnabled(true);
}


void MainWindow::on_checkBox_3_clicked()
{
    qDebug()<< "in checkbox3";
    ui->stackedWidget->setCurrentIndex(2);
    ui->checkBox_2->setChecked(false);
    if(ui->checkBox_3->isChecked()){
        ui->gbox_DST_Control_Suit->setVisible(true);
        ui->stackedWidget->setVisible(true);
        ui->b_control_start_ade->setEnabled(true);
        ui->b_StopAde->setDisabled(true);
        ui->treeWidget->setDisabled(true);
        ui->listWidgetSceneSelect->setDisabled(true);
        ui->b_control_validation->setDisabled(true);

    }else{
        ui->gbox_DST_Control_Suit->setVisible(false);
        ui->stackedWidget->setVisible(false);
        ui->b_control_start_ade->setDisabled(true);
        ui->b_StopAde->setDisabled(true);
        if( this->startAde == true){
            QString path = QDir::currentPath() + "/q_stopt.sh";
            executeShell(path);
            if(this->dataRecord == true){
                QString path = QDir::currentPath() + "/q_data_stop.sh";
                executeShell(path);
            }
        }
    }
}


void MainWindow::on_b_control_start_ade_clicked()
{
    this->startAde = true;
    ui->b_control_stopAde->setEnabled(true);
    ui->b_control_sel_scenario->setEnabled(true);
    ui->b_control_start_ade->setDisabled(true);
    QString path = QDir::currentPath() + "/q_ade_start.sh";
    executeShell(path);
    fileWatcher();
}
// Select scenario from control validation tab
void MainWindow::on_b_control_sel_scenario_clicked()
{
    ui->treeWidgetControl->clear();
    ui->listWidgetSceneSelect->setEnabled(true);

    // TODO path dynamic back one folder
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString p_testCases = curr_path.left(pos) + "/Test_Cases/";
    qDebug() << "new path : " + p_testCases;
    directory.setPath(p_testCases) ;
    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidgetControl);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        QDir dir(finfo.absoluteFilePath());
        if(flag == false)
        {
            root->setText(0,dir.dirName());
            qDebug() << "In main dir : " << root->text(0) ;
            ui->treeWidgetControl->addTopLevelItem(root);
            root->setCheckState(0,Qt::Unchecked); //optional
            flag = true;
        }
        else
        {
            //QDir dir(finfo.absoluteFilePath());
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            child->setCheckState(0,Qt::Unchecked);
            root->addChild(child);
            //child->setWhatsThis(0,"directory");
            if(finfo.isDir())
            {
                QDir dir(finfo.absoluteFilePath());
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py" ;
                    d.setNameFilters(flt);
                    for(const QFileInfo &f : d.entryInfoList()){
                        if(f.fileName() == "run.py")
                            continue;
                        QFile fp(dir.absolutePath()+"/config.txt");
                        if (!fp.open(QIODevice::ReadOnly))
                        {
                            qDebug() << "File not open";
                            return;
                        }
                        while (!fp.atEnd()) {
                            QString str = fp.readLine();
                            // qDebug() <<str;
                            QString s = f.fileName();
                            str = str.remove('\n');
                            s.remove(".py");
                            s.append(":"+str);
                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
                            child_c->setText(0,s);
                            child_c->setCheckState(0,Qt::Unchecked);
                            child->addChild(child_c);
                        }//while
                        fp.flush();
                        fp.close();
                    }//for_py
                }
            }
        }//else_
    } //for_loop
}

// Rahul Rcontrol
void MainWindow::on_b_control_run_scenario_clicked()
{
    // TODO :: run scenario for control validation
    QSet<QString>::iterator m;
    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh " +  parameters.Script + " " + parameters.rain + " " +parameters.fog + " "
                + parameters.wetness + " " + parameters.damage +" " + parameters.scene;
        qDebug()<<"Path :" << c_path ;
        executeShell(c_path);
        ui->b_control_run_scenario->setDisabled(true);
        ui->b_control_stop_scenario->setEnabled(true);
        ui->b_control_showreport->setDisabled(true);
        ui->b_control_validation->setEnabled(true);
    }
}

void MainWindow::on_treeWidgetControl_itemClicked(QTreeWidgetItem *item, int column)
{
    if(check_flag == false)
    {
        //item->setCheckState(column,Qt::Checked);
        qDebug() << "selected :" << item->isSelected();

        QString str = item->text(column);
        //checked_item.insert(item);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        //scenarioName = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";

        qDebug() << "First click  : " << str;
        if(item->text(column).contains("rain"))
        {
            //    qDebug() << "Rain : " << item->text(column);
            QString tmp = item->text(column),val;
            foreach(QChar c, tmp){
                if(c == ',')
                    val.append(" ");

                if(c.isDigit() || c == '.')
                    val.append(c);
                //scenarioArgs.append(c);
            }
            check_list.insert("Rain",val);
            parameters.rain = val;
            qDebug() << "parameter  : " << parameters.rain << " ";

        }
        //TO DO : for other parameters
        check_flag = true;
    }
    else
    {
        item->setCheckState(column,Qt::Unchecked);
        qDebug() << "Second Click";
        ui->b_control_run_scenario->setEnabled(true);
        check_flag = false;
    }
}

void MainWindow::on_b_control_showreport_clicked()
{
    // TODO : add show report for control validation
    // TODO path dynamic back one folder
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rc_filepath = curr_path.left(pos) + "/validation_report/report_control.txt";
    qDebug() << "new path : " + rc_filepath;

    bool filecheck = QDesktopServices::openUrl(QUrl::fromLocalFile(rc_filepath));
    if(filecheck){
        qDebug() << "File open successfully";
    }else{
        qDebug() << "File open successfully";
    }
    QString path = curr_path+ "/q_control_val_script.sh";
    executeShell(path);

    QFile file(rc_filepath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0,"info",file.errorString());

    }
    QTextStream in(&file);
    ui->txtBrowser_control->setText(in.readAll());
}

void MainWindow::on_b_control_stopAde_clicked()
{
    ui->b_control_start_ade->setEnabled(true);
    ui->b_control_stopAde->setDisabled(true);
    qDebug() << "ADE Stopped  ";
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);

    ui->b_control_sel_scenario->setDisabled(true);
    ui->treeWidgetControl->clear();
    ui->treeWidgetControl->setDisabled(true);
    ui->b_control_showreport->setDisabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_run_scenario->setDisabled(true);
    ui->listWidgetSceneSelect->setDisabled(true);
    ui->lbl_outputlog->setText("Log Information : ADE Stop");
    fileModify();
}

void MainWindow::on_b_control_stop_scenario_clicked()
{
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_run_scenario->setEnabled(true);
    ui->b_control_showreport->setEnabled(true);
    QString path = QDir::currentPath() + "/stop_scenario.sh";
    executeShell(path);

    qDebug() << path ;
}

void MainWindow::on_listWidgetSceneSelect_itemClicked(QListWidgetItem *item)
{
    parameters.scene = item->text();
    ui->treeWidgetControl->setEnabled(true);
    qDebug() <<"senece selected in CVU : "<<  parameters.scene;
}

void MainWindow::on_listWidgetSceneSelectDSU_itemClicked(QListWidgetItem *item)
{
    parameters.scene = item->text();
    ui->treeWidget->setEnabled(true);
    qDebug() <<"senece selected in DSU: "<<  parameters.scene;

}

void MainWindow::on_b_control_validation_clicked()
{
    //TODO::Adding of callig script of control validation node start
    QString path = QDir::currentPath() + "/q_control_validate.sh";
    executeShell(path);
    //ui->b_per_validate->setDisabled(true);
    ui->b_control_validation->setDisabled(true);
    ui->b_control_showreport->setEnabled(true);
}


