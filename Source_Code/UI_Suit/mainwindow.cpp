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
#include <QMovie>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    this->setWindowTitle("Poly-Validation Suite");
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
    ui->b_generatereport->setDisabled(true);


    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_sel_scenario->setDisabled(true);
    ui->b_control_start_ade->setDisabled(true);
    ui->b_control_stopAde->setDisabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_showreport->setDisabled(true);
    ui->treeWidgetControl->setDisabled(true);

    // createTempFile and file watcher can call at the application start
    // TODO
    // fileWatcher();
    // createTempRecordPath();
    //flagSimulation = false;

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
    // below variable can be assign at the start of the application TODO
    movie = new QMovie("spinner.gif");
    model = new QStandardItemModel;
    flagSimulation = false;
    fileWatcher();
    createTempRecordPath();

    ui->lbl_outputlog->setText("Log Information : ADE and other component initilize, it may take while to start..");
    ui->b_StopAde->setEnabled(true);
    ui->b_sel_scenario->setEnabled(true);
    QString path = QDir::currentPath() + "/q_ade_start.sh";
    executeShell(path);
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
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            this->textss.append(in.readLine());
            //std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
    if(!this->textss.isEmpty()){
        ui->lbl_outputlog->setText("Log Information : " + this->textss.first());
        if(this->textss.first() == "Report Generated"){
            ui->b_showreport->setEnabled(true);
            if(flagSimulation == true){
                flagSimulation = false;
                ui->lblSpinner->clear();
                ui->lblSpinner->hide();
                movie->stop();
                //delete movie;
                QMessageBox messageBox;
                messageBox.setText("Report Generated, Click on Show Report");
                messageBox.setFixedSize(500,200);
                messageBox.exec();
                qDebug() << "fReport Generated, Click on Show Report : ",this->textss.first();

                QString p_logInfo = QDir::currentPath() + "/logfiles/logInfo.txt";
                QFile fp(p_logInfo);
                fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
                fp.close();
            }

        }else if(true){
            // Handle the more feedback on the UI
        }

        this->textss.pop_front();
    }
}

// function to clear the logfile
void MainWindow::fileModify(){
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

void MainWindow::on_b_StopAde_clicked()
{
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);
    ui->b_sel_scenario->setDisabled(true);
    ui->treeWidget->clear();
    ui->treeWidget->setDisabled(true);
    ui->listWidgetSceneSelectDSU->setDisabled(true);
    ui->b_showreport->setDisabled(true);
    ui->b_generatereport->setDisabled(true);
    flagSimulation = false;
    ui->tableView->reset();
    ui->lbl_d_Auto->setText("Detection range in Autoware(m) : NA");
    ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
    ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA" );
    ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA" );
    QFile fp(QDir::currentPath() + "/test_runner.sh");
    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
    fp.close();
    ui->lbl_outputlog->setText("Log Information : ADE Stop");

    //Rahul
    delete watcher;
    delete model;
    //delete movie;


    //fileModify();
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
    ui->label_3->setEnabled(false);
    if(ui->checkBox_2->isChecked()){
        ui->gbox_DST_Suit->setVisible(true);
        ui->stackedWidget->setVisible(true);
        ui->pblaunch->setEnabled(true);
        ui->b_StopAde->setDisabled(true);
        ui->b_run_scenario->setDisabled(true);
        ui->b_generatereport->setDisabled(true);
        ui->b_sel_scenario->setDisabled(true);
        ui->b_showreport->setDisabled(true);

        ui->treeWidget->setDisabled(true);
        ui->label_2->setDisabled(true);//
        ui->lbl_d_Auto->setDisabled(true);
        ui->lbl_d_LG->setDisabled(true);
        ui->lbl_d_Failure->setDisabled(true);
        ui->lbl_d_Succes->setDisabled(true);
        ui->tableView->setDisabled(true);//
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
    sel_item_clr.clear();
    ui->treeWidget->clear();
    ui->label_3->setEnabled(true);
    ui->listWidgetSceneSelectDSU->setEnabled(true);
    static bool flag1 = true;
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    qDebug() << "new path : " + p_testCases;
    directory.setPath(p_testCases) ;
    bool flag = false;
    //sne
    if(flag1){
        QFile fp1(p_testCases+"/scene.txt");
        if (!fp1.open(QIODevice::ReadOnly))
        {
            qDebug() << "File not open";
            QMessageBox msgBox;
            msgBox.setText("Create scene.txt in Test_Cases Directory");
            msgBox.exec();
            return;
        }
        int m=1;

        while (!fp1.atEnd()) {
            QString str = fp1.readLine();
            str = str.remove('\n');
            ui->listWidgetSceneSelectDSU->insertItem(m++,str);
        }
        flag1 = false;
    }
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;
        if(flag == false)
        {
            root->setText(0,dir.dirName());
            qDebug() << "In main dir : " << root->text(0) ;
            ui->treeWidget->addTopLevelItem(root);
            // root->setCheckState(0,Qt::Unchecked); //optional  1
            flag = true;
        }//if_
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            //child->setCheckState(0,Qt::Unchecked);  2
            root->addChild(child);

            if(finfo.isDir())
            {
                qDebug() << "File name :"<<finfo.fileName();
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
    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->label_2->setDisabled(true);//
    ui->lbl_d_Auto->setDisabled(true);
    ui->lbl_d_LG->setDisabled(true);
    ui->lbl_d_Failure->setDisabled(true);
    ui->lbl_d_Succes->setDisabled(true);
    ui->tableView->setDisabled(true);//
    //
    ui->b_showreport->setDisabled(true);
    ui->treeWidget->setDisabled(true); //sne
    ui->b_sel_scenario->setDisabled(true);
    ui->b_generatereport->setDisabled(true);
    model->clear();
    ui->tableView->setModel(model);
    ui->lbl_d_Auto->setText("Detection range in Autoware(m): NA");
    ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
    ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA");
    ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");
    flagSimulation = true;
    qDebug() << "Selected items" <<selected;
    // TODO
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \nset -eu\n";

    QString testcasepath = par;  //sne
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos);
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    fp.close();
    selected.clear();
    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh";
        executeShell(c_path);
    }

    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setEnabled(true);
    ui->b_showreport->setDisabled(true);
}

void MainWindow::on_b_stop_scenario_clicked()
{
    ui->b_generatereport->setEnabled(true);
    ui->treeWidget->setEnabled(true);  //sne
    ui->b_sel_scenario->setEnabled(true);

    if(sel_item_clr.isEmpty() == false){
        qDebug() << "Clearing the list " << sel_item_clr ;
        foreach (QTreeWidgetItem * m, sel_item_clr) {
            m->setCheckState(0,Qt::Unchecked);
        }
    }

    //    QFile fp(QDir::currentPath() + "/test_runner.sh");
    //    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
    //    fp.close();
    //    qDebug() << "Stop Scenario : after clean test runner" ;

    ui->b_stop_scenario->setDisabled(true);
    ui->b_run_scenario->setEnabled(true);
    ui->b_generatereport->setEnabled(true);
    QString c_path = QDir::currentPath() + "/stop_scenario.sh" ;
    executeShell(c_path);
    qDebug() << "Stop Scenario : after calling the calling script shr" ;
}

void MainWindow::on_b_generatereport_clicked()
{

    qDebug() << " in script";
    ui->lblSpinner->setMovie(movie);
    ui->lblSpinner->show();
    movie->start();
    qDebug() << " afterin script";
    ui->label_2->setEnabled(true);//
    ui->lbl_d_Auto->setEnabled(true);
    ui->lbl_d_LG->setEnabled(true);
    ui->lbl_d_Failure->setEnabled(true);
    ui->lbl_d_Succes->setEnabled(true);

    ui->tableView->setEnabled(true);//
    ui->b_generatereport->setDisabled(true);
    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_perception_val_script.sh";
    executeShell(path);
}

void MainWindow::on_b_showreport_clicked()
{
    //ui->b_generatereport->setDisabled(true);
    ui->b_showreport->setDisabled(true);
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);

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
        ui->lbl_d_Auto->setText("Detection range in Autoware(m) : NA");
        ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
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

        for(int m=2;m<4;m++)
        {
            if(rData[m].contains(".")){
                int c=rData[m].indexOf('.');
                c=c+2;
                rData[m].truncate(c);
                qDebug() << rData[m] ;
            }
        }

        ui->lbl_d_Auto->setText("Detection range in Autoware(m) : " + rData[0]);
        ui->lbl_d_LG->setText("Detection range in LG(m) : " + rData[1]);
        ui->lbl_d_Succes->setText("Detection Success Rate(%) : " + rData[2]);
        ui->lbl_d_Failure->setText("Detection Failure Rate(%) : " + rData[3]);
    }
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString str,mainstring;
    if(item->text(column).contains("rain"))
    {
        qDebug() << "item clicked";
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        qDebug() << "First click  : " << parameters.Script;
        mainstring = parameters.Script + " "; //updated
        //
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
        qDebug() << "-------------tmp : " << tmp;
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

        qDebug() << "Mainstring  : " << mainstring;
        if(item->checkState(column) == p){
            selected.remove(mainstring);
            qDebug() << "item clicked 2";
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

void MainWindow::on_treeWidgetControl_itemClicked(QTreeWidgetItem *item, int column)
{
    //    if(check_flag == false)
    //    {
    //        //item->setCheckState(column,Qt::Checked);
    //        qDebug() << "selected :" << item->isSelected();

    //        QString str = item->text(column);
    //        //checked_item.insert(item);
    //        int pos = str.indexOf(":");
    //        str = str.left(pos) + ".py";
    //        //scenarioName = str.left(pos) + ".py";
    //        parameters.Script = str.left(pos) + ".py";

    //        qDebug() << "First click  : " << str;
    //        if(item->text(column).contains("rain"))
    //        {
    //            //    qDebug() << "Rain : " << item->text(column);
    //            QString tmp = item->text(column),val;
    //            foreach(QChar c, tmp){
    //                if(c == ',')
    //                    val.append(" ");

    //                if(c.isDigit() || c == '.')
    //                    val.append(c);
    //                //scenarioArgs.append(c);
    //            }
    //            check_list.insert("Rain",val);
    //        }
    //        //TO DO : for other parameters
    //        check_flag = true;
    //    }
    //    else
    //    {
    //        item->setCheckState(column,Qt::Unchecked);
    //        qDebug() << "Second Click";
    //        ui->b_control_run_scenario->setEnabled(true);
    //        check_flag = false;
    //    }

    QString str,mainstring;
    qDebug() << "item clicked !";
    //if(check_flag == false)
    if(item->text(column).contains("CV"))
    {
        sel_item_clr.clear();
        qDebug() << "item clicked";
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);

        par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        qDebug() << "First click  : " << parameters.Script;
        mainstring = parameters.Script + " "; //updated
        //
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
        qDebug() << "-------------tmp : " << tmp;
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

        qDebug() << "Mainstring  : " << mainstring;
        if(item->checkState(column) == p){
            selected.remove(mainstring);
            qDebug() << "item clicked 2";
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }
    }
    ui->b_control_run_scenario->setEnabled(true);
    check_flag = true;

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

    // belwo variables can add in the start of the application TODO
    movie = new QMovie("spinner.gif");
    model = new QStandardItemModel;
    flagSimulation = false;
    ui->lbl_outputlog->setText("Log Information : ADE and other component initilize, it may take while to start..");
    fileWatcher();
    createTempRecordPath();

    ui->b_control_stopAde->setEnabled(true);
    ui->b_control_sel_scenario->setEnabled(true);
    ui->b_control_start_ade->setDisabled(true);
    QString path = QDir::currentPath() + "/qc_ade_start.sh";
    executeShell(path);
}

// Select scenario from control validation tab
void MainWindow::on_b_control_sel_scenario_clicked()
{
    sel_item_clr.clear();
    ui->treeWidgetControl->clear();
    ui->label_5->setEnabled(true);
    ui->listWidgetSceneSelect->setEnabled(true);

    static bool flag1 = true;
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    qDebug() << "new path : " + p_testCases;
    directory.setPath(p_testCases) ;
    bool flag = false;

    if(flag1){
        QFile fp1(p_testCases+"/scene.txt");
        if (!fp1.open(QIODevice::ReadOnly))
        {
            qDebug() << "File not open";
            QMessageBox msgBox;
            msgBox.setText("Create scene.txt in Test_Cases Directory");
            msgBox.exec();
            return;
        }
        int m=1;

        while (!fp1.atEnd()) {
            QString str = fp1.readLine();
            str = str.remove('\n');
            ui->listWidgetSceneSelect->insertItem(m++,str);
        }
        flag1 = false;
    }

    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidgetControl);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;

        QDir dir(finfo.absoluteFilePath());
        if(finfo.isDir() == false)
            continue;

        if(flag == false)
        {
            root->setText(0,dir.dirName());
            qDebug() << "In main dir : " << root->text(0) ;
            ui->treeWidgetControl->addTopLevelItem(root);
            flag = true;
        }
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            root->addChild(child);
            if(finfo.isDir())
            {
                qDebug() << "File name :"<<finfo.fileName();
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
                            QString s = f.fileName();
                            str = str.remove('\n');
                            s.remove(".py");
                            s.append(":"+str);
                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
                            child_c->setText(0,s);
                            child_c->setCheckState(0,Qt::Unchecked);
                            child->addChild(child_c);
                        }
                        fp.flush();
                        fp.close();
                    }
                }
            }
        }
    }

}

// Rahul Rcontrol
void MainWindow::on_b_control_run_scenario_clicked()
{
    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_stop_scenario->setEnabled(true);
    ui->b_control_showreport->setDisabled(true);
    ui->b_control_validation->setDisabled(true); // generate report
    flagSimulation = true;
    qDebug() << "Selected items" <<selected;
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \nset -eu\n";

    QString testcasepath = par;  //sne
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos);
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    fp.close();
    selected.clear();

    // TODO :: run scenario for control validation
    if(parameters.Script != ""){
        //todo : need to add scenario
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh " ;
        qDebug()<<"c_path control :" << c_path ;
        executeShell(c_path);
    }
}

void MainWindow::on_b_control_showreport_clicked()
{
    //    // TODO : add show report for control validation
    //    // TODO path dynamic back one folder
    //    QString curr_path = QDir::currentPath();
    //    int pos = curr_path.lastIndexOf(QChar('/'));
    //    QString rc_filepath = curr_path.left(pos) + "/validation_report/report_control.txt";
    //    qDebug() << "new path : " + rc_filepath;

    //    bool filecheck = QDesktopServices::openUrl(QUrl::fromLocalFile(rc_filepath));
    //    if(filecheck){
    //        qDebug() << "File open successfully";
    //    }else{
    //        qDebug() << "File open successfully";
    //    }
    //    QString path = curr_path+ "/q_control_val_script.sh";
    //    executeShell(path);

    //    QFile file(rc_filepath);
    //    if(!file.open(QIODevice::ReadOnly)){
    //        QMessageBox::information(0,"info",file.errorString());

    //    }
    //    QTextStream in(&file);
    //    ui->txtBrowser_control->setText(in.readAll());

    //hide();
    reportwindow reportwin;
    reportwin.setModal(this);
    reportwin.exec();
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

void MainWindow::executeShell(QString path){
    QProcess *process = new QProcess();
    process->execute(path);
    process->waitForFinished(200);
    delete process;
}

