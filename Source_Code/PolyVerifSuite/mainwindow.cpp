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
#include <QWindow>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    this->setWindowTitle("PolyVerif Suite");
    //this->setFixedSize(1080,600);

    ui->gbox_DST_Suit->setVisible(false);

    ui->stackedWidget->setVisible(false);
    ui->pblaunch->setDisabled(true);
    ui->b_StopAde->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->b_sel_scenario->setDisabled(true);
    //->setDisabled(true);

    ui->scenic_activate->setDisabled(true);
    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_sel_scenario->setDisabled(true);
    ui->b_control_start_ade->setDisabled(true);
    ui->b_control_stopAde->setDisabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->label_5->setDisabled(true);


    ui->treeWidgetControl->setDisabled(true);


    ui->scenic_activate->setDisabled(true);
    ui->avp_button->setDisabled(true);



    // Localization widget
    ui->btn_local_adeStart->setEnabled(true);
    ui->btn_local_avp->setDisabled(true);
    ui->btn_local_goal_pos->setDisabled(true);
    ui->btn_local_initial_pos->setDisabled(true);
    ui->btn_local_run_scenario->setDisabled(true);
    ui->btn_local_scenic_count->setDisabled(true);
    ui->btn_local_scenic_run->setDisabled(true);
    ui->btn_local_sel_scenario->setDisabled(true);

    ui->btn_local_StopAde->setDisabled(true);
    ui->btn_local_stop_scenario->setDisabled(true);
    ui->treeWid_local_select_script->setDisabled(true);
    ui->listWid_local_scene_select->setDisabled(true);
    ui->lbl_sceneSelect->setDisabled(true);


    // Path Planning widget
    ui->btn_pp_adeStart->setEnabled(true);
    ui->btn_pp_avp->setDisabled(true);
    ui->btn_pp_goal_pos->setDisabled(true);
    ui->btn_pp_initial_pos->setDisabled(true);
    ui->btn_pp_run_scenario->setDisabled(true);
    ui->btn_pp_scenic_count->setDisabled(true);
    ui->btn_pp_scenic_run->setDisabled(true);
    ui->btn_pp_sel_scenario->setDisabled(true);

    ui->btn_pp_StopAde->setDisabled(true);
    ui->btn_pp_stop_scenario->setDisabled(true);
    ui->treeWid_pp_select_script->setDisabled(true);
    ui->listWid_pp_scene_select->setDisabled(true);
    ui->lbl_pp_sceneSelect->setDisabled(true);



    ui->btn_pp_showreport->setEnabled(true);
    ui->btn_local_showreport->setEnabled(true);
    ui->b_control_showreport->setEnabled(true);
    ui->b_showreport_2->setEnabled(true);
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
    count1 =1;
    ui->scenic_activate_2->setDisabled(true);
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

            QFile fp(QDir::currentPath() + "/logfiles/logInfo.txt");
            fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
            fp.setCurrentWriteChannel(0);
            QTextStream stream(&fp);
            stream << "Created Report for Analysis";
            fp.close();

            //  ui->b_showreport->setEnabled(true);
            //            if(flagSimulation == true){
            //                flagSimulation = false;
            //                ui->lblSpinner->clear();
            //                ui->lblSpinner->hide();
            //                movie->stop();
            //                //delete movie;
            //                QMessageBox messageBox;
            //                messageBox.setText("Report Generated, Click on Show Report");
            //                messageBox.setFixedSize(500,200);
            //                messageBox.exec();

            //            QString p_logInfo = QDir::currentPath() + "/logfiles/logInfo.txt";
            //            QFile fp(p_logInfo);
            //            fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
            //            fp.close();

            emit updateUI1Signal("Report Generated");
            //            }

        }
        else if(this->textss.first() == "Finish itr")
        {
            if(scenarioItr <= count1){
                QString curr_path = QDir::currentPath();
                int pos = curr_path.lastIndexOf(QChar('/'));
                QString path = curr_path.left(pos) + "/PolyReports/Validation_report/setup.sh";
                QFile fp(path);
                fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
                fp.setCurrentWriteChannel(0);
                QTextStream stream(&fp);
                QString tmp = tCase  + "_iteration_" + QString::number(scenarioItr);
                stream << "#!/bin/bash \n";
                stream << "echo \" Running iteration\" \n";
                stream << "mkdir -p " << "../" << reportPath+ tmp <<" && touch "<< "../" << reportPath+ tmp + "/"<<"\n";
                stream << "echo \""<< reportPath + tmp  <<" \" > ../PolyReports/Validation_report/config.txt \n";

                //stream << "echo \"after writing\n";
                fp.close();
                executeShell(path);
                //            QProcess *process = new QProcess();
                //            process->execute(path);
                //            qDebug() << "path in shell : "<<path;
                //            process->waitForFinished(200);
                //         delete process;

                QString p_logInfo = QDir::currentPath() + "/logfiles/logInfo.txt";
                QFile fplog(p_logInfo);
                fplog.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
                fplog.close();
            }
            scenarioItr++;


        }
        else if(true){
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
    flag1 = true;    //scene list
    ui->b_showreport_2->setDisabled(true);
    ui->scenic_activate->setDisabled(true);
    ui->scenic_activate_2->setDisabled(true);
//    ui->b_control_showreport->setDisabled(true);
    ui->avp_button->setDisabled(true);
    ui->goal_pos_b->setDisabled(true);
    ui->initial_pos_b->setDisabled(true);
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);
    ui->b_sel_scenario->setDisabled(true);
    ui->treeWidget->clear();
    ui->treeWidget->setDisabled(true);
    ui->listWidgetSceneSelectDSU->setDisabled(true);
    flagSimulation = false;

    QFile fp(QDir::currentPath() + "/test_runner.sh");
    fp.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate);
    fp.close();
    ui->lbl_outputlog->setText("Log Information : ADE Stop");
    ui->listWidgetSceneSelectDSU->clear();
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

    ui->scenic_activate_2->setDisabled(true);
    ui->stackedWidget->setCurrentIndex(2);

    ui->checkBox_3->setChecked(false);
    ui->ckbox_localization->setChecked(false);
    ui->ckbox_PathPlanning->setChecked(false);

    ui->label_3->setEnabled(false);
    if(ui->checkBox_2->isChecked()){
        ui->gbox_DST_Suit->setVisible(true);
        ui->avp_button->setDisabled(true);
        ui->initial_pos_b->setDisabled(true);
        ui->goal_pos_b->setDisabled(true);
        ui->stackedWidget->setVisible(true);
        ui->pblaunch->setEnabled(true);
        ui->b_StopAde->setDisabled(true);
        ui->b_run_scenario->setDisabled(true);
        ui->b_sel_scenario->setDisabled(true);
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

    sel_item_clr.clear();
    ui->treeWidget->clear();
    ui->label_3->setEnabled(true);
    ui->listWidgetSceneSelectDSU->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
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
    //    sel_item_clr.clear();
    //    ui->treeWidget->clear();
    //    ui->label_3->setEnabled(true);
    //    ui->listWidgetSceneSelectDSU->setEnabled(true);
    //    QDir directory ;
    //    QString curr_path = QDir::currentPath();
    //    int pos = curr_path.lastIndexOf(QChar('/'));
    //    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    //    directory.setPath(p_testCases) ;
    //    bool flag = false;
    //    //sne
    //    if(flag1){
    //        QFile fp1(p_testCases+"/scene.txt");
    //        if (!fp1.open(QIODevice::ReadOnly))
    //        {
    //            qDebug() << "File not open";
    //            QMessageBox msgBox;
    //            msgBox.setText("Create scene.txt in Test_Cases Directory");
    //            msgBox.exec();
    //            return;
    //        }
    //        int m=1;

    //        while (!fp1.atEnd()) {
    //            QString str = fp1.readLine();
    //            str = str.remove('\n');
    //            ui->listWidgetSceneSelectDSU->insertItem(m++,str);
    //        }
    //        flag1 = false;
    //    }

    //    // sneha1
    //    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    //    for(const QFileInfo &finfo : directory.entryInfoList()){
    //        if(finfo.fileName().contains(".."))
    //            continue;
    //        QDir dir(finfo.absoluteFilePath());

    //        if(finfo.isDir() == false)
    //            continue;
    //        if(flag == false)
    //        {
    //            root->setText(0,dir.dirName());
    //            ui->treeWidget->addTopLevelItem(root);
    //            // root->setCheckState(0,Qt::Unchecked); //optional  1
    //            flag = true;
    //        }//if_
    //        else
    //        {
    //            QTreeWidgetItem *child = new  QTreeWidgetItem();
    //            child->setText(0,dir.dirName());
    //            //child->setCheckState(0,Qt::Unchecked);  2
    //            root->addChild(child);

    //            if(finfo.isDir())
    //            {
    //                QDir dir(finfo.absoluteFilePath());
    //                if(finfo.fileName().contains("Scenic")){
    //                    qDebug() << finfo.fileName();
    //                    for(const QFileInfo &f : dir.entryInfoList()){
    //                        if(f.isDir())
    //                            continue;
    //                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                        child_c->setText(0,f.fileName());
    //                        child_c->setCheckState(0,Qt::Unchecked);
    //                        child->addChild(child_c);
    //                    }
    //                }
    //                if(dir.exists("config.txt")){
    //                    QDir d(finfo.absoluteFilePath());
    //                    path = finfo.absoluteFilePath();
    //                    QStringList flt;
    //                    flt << "*.py";

    //                    d.setNameFilters(flt);

    //                    for(const QFileInfo &f : d.entryInfoList()){
    //                        if(f.fileName() == "run.py")
    //                            continue;
    //                        QFile fp(dir.absolutePath()+"/config.txt");
    //                        if (!fp.open(QIODevice::ReadOnly))
    //                        {
    //                            qDebug() << "File not open";
    //                            return;
    //                        }
    //                        while (!fp.atEnd()) {
    //                            QString str = fp.readLine();
    //                            QString s = f.fileName();
    //                            str = str.remove('\n');
    //                            s.remove(".py");
    //                            s.append(":"+str);
    //                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                            child_c->setText(0,s);
    //                            child_c->setCheckState(0,Qt::Unchecked);
    //                            child->addChild(child_c);

    //                        }//while
    //                        fp.flush();
    //                        fp.close();
    //                    }
    //                }
    //            }
    //        }
    //    }
}

void MainWindow::on_b_stop_scenario_clicked()
{
    count1 = 1;
    ui->listWidgetSceneSelectDSU->clearSelection();
    ui->avp_button->setEnabled(false);
    ui->goal_pos_b->setDisabled(true);
    ui->initial_pos_b->setDisabled(true);
    ui->scenic_activate_2->setEnabled(false);
    ui->b_showreport_2->setEnabled(true);
    ui->b_run_scenario->setDisabled(true);
    ui->treeWidget->setEnabled(true);  //sne
    ui->b_sel_scenario->setEnabled(true);

    ui->scenic_activate->setEnabled(false);
    ui->scenic_activate_2->setDisabled(true);
    ui->b_run_scenario->setDisabled(true);

    scenarioItr = 1;
    if(sel_item_clr.isEmpty() == false){
        foreach (QTreeWidgetItem * m, sel_item_clr) {
            m->setCheckState(0,Qt::Unchecked);
        }
    }

    ui->b_stop_scenario->setDisabled(true);
    QString c_path = QDir::currentPath() + "/stop_scenario.sh" ;
    executeShell(c_path);
}

//void MainWindow::on_b_generatereport_clicked() //generate report button
//{
//button name ->    b_generatereport

//    qDebug() << " in script";
//    ui->lblSpinner->setMovie(movie);
//    ui->lblSpinner->show();
//    movie->start();
//    qDebug() << " afterin script";
//    ui->label_2->setEnabled(true);//
//    ui->lbl_d_Auto->setEnabled(true);
//    ui->lbl_d_LG->setEnabled(true);
//    ui->lbl_d_Failure->setEnabled(true);
//    ui->lbl_d_Succes->setEnabled(true);

//    //->setEnabled(true);//
//    //->setDisabled(true);
//    QString curr_path = QDir::currentPath();
//    QString path = curr_path + "/q_perception_val_script.sh";
//    executeShell(path);
//}

//void MainWindow::on_b_showreport_clicked()
//{
//    //b_show_report show report button
//    //ui->b_generatereport->setDisabled(true);
//    //->setDisabled(true);
//    QString curr_path = QDir::currentPath();
//    int pos = curr_path.lastIndexOf(QChar('/'));
//    QString rp_filepath = curr_path.left(pos);

//    QString rfile = rp_filepath + "/" + csv_ReportPath + "/rangeReport.csv";
//    qDebug() << "complete path of range report : ",rfile;
//    QFile file(rfile);
//    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
//        qDebug() << "File not exists";
//    } else {
//        QTextStream in(&file);
//        while (!in.atEnd())
//        {
//            QString line = in.readLine();
//            qDebug() << "line ",line;
//            QList<QStandardItem *> standardItemsList;
//            for (QString item : line.split(",")) {
//                standardItemsList.append(new QStandardItem(item));
//            }
//            model->insertRow(model->rowCount(), standardItemsList);
//        }
//        file.close();
//    }
//    //->setModel(model);


//    QString txtreport = rp_filepath + "/" + csv_ReportPath + "/report_1.txt";
//    qDebug() << "complete path of range report : ",txtreport;
//    QString rData[4];
//    QFile txtfile(txtreport);
//    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
//        qDebug() << "File not exists";
//        ui->lbl_d_Auto->setText("Detection range in Autoware(m) : NA");
//        ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
//        ui->lbl_d_Succes->setText("Detection Success Rate(%): NA");
//        ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");
//    } else {
//        QTextStream in(&txtfile);
//        int i=0;
//        while (!in.atEnd())
//        {
//            QString line = in.readLine();
//            rData[i++] =line;
//        }
//        txtfile.close();

//        for(int m=2;m<4;m++)
//        {
//            if(rData[m].contains(".")){
//                int c=rData[m].indexOf('.');
//                c=c+2;
//                rData[m].truncate(c);
//                qDebug() << rData[m] ;
//            }
//        }

//        ui->lbl_d_Auto->setText("Detection range in Autoware(m) : " + rData[0]);
//        ui->lbl_d_LG->setText("Detection range in LG(m) : " + rData[1]);
//        ui->lbl_d_Succes->setText("Detection Success Rate(%) : " + rData[2]);
//        ui->lbl_d_Failure->setText("Detection Failure Rate(%) : " + rData[3]);
//    }
//}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString str,mainstring;
    ui->avp_button->setEnabled(true);
    if(item->text(column).contains("scenic"))
    {
        count.clear();
        //ui->scenic_activate_2->setEnabled(true);
        str = item->text(column);
        parameters.Script = str;
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
//        par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        par= "/"+p1->text(column)+"/"+parameters.scene+"/"+p2->text(column)+"/";

        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        if(item->checkState(column) == p){
            selected.remove(str);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(str);
        }
        ui->b_run_scenario->setDisabled(true);
        ui->scenic_activate->setEnabled(true);
        ui->scenic_activate_2->setEnabled(true);
    }
    if(item->text(column).contains("rain"))
    {
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        // par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        par= "/"+p1->text(column)+ "/" + parameters.scene+"/"+p2->text(column)+"/"; //sne

        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        mainstring = parameters.Script + " "; //updated
        //
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
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

        if(item->checkState(column) == p){
            selected.remove(mainstring);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }
        ui->scenic_activate_2->setDisabled(true);
        ui->scenic_activate->setDisabled(true);
        ui->b_run_scenario->setEnabled(true);
    }
    //TO DO : for other parameters
    check_flag = true;
    //    ui->b_run_scenario->setEnabled(true);
    //    ui->scenic_activate->setEnabled(true);
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

    ui->avp_button_2->setEnabled(true);
    QString str,mainstring;
    if(item->text(column).contains("scenic"))
    {
        str = item->text(column);
        parameters.Script = str;
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        par= "/"+p1->text(column)+"/"+parameters.scene + "/" + p2->text(column)+"/"; //sne

        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        if(item->checkState(column) == p){
            selected.remove(str);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(str);
        }
        ui->b_control_run_scenario->setDisabled(true);
        ui->run_scenic_control->setEnabled(true);
        ui->scenic_activate_3->setEnabled(true);
    }
    if(item->text(column).contains("rain"))
    {
        sel_item_clr.clear();
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);

        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/"; //sne
        par= "/"+p1->text(column)+"/"+parameters.scene + "/" + p2->text(column)+"/"; //sne

        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        mainstring = parameters.Script + " "; //updated
        //
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
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
        if(item->checkState(column) == p){
            selected.remove(mainstring);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }
        ui->b_control_run_scenario->setEnabled(true);
        ui->run_scenic_control->setDisabled(true);
        ui->scenic_activate_3->setDisabled(true);
    }

    check_flag = true;
}

void MainWindow::on_checkBox_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->checkBox_2->setChecked(false);
    ui->ckbox_localization->setChecked(false);
    ui->ckbox_PathPlanning->setChecked(false);
    if(ui->checkBox_3->isChecked()){
        ui->run_scenic_control->setDisabled(true);
        ui->gbox_DST_Control_Suit->setVisible(true);
        ui->stackedWidget->setVisible(true);
        ui->b_control_start_ade->setEnabled(true);
        ui->b_StopAde->setDisabled(true);
        ui->treeWidget->setDisabled(true);
        ui->listWidgetSceneSelect->setDisabled(true);
        ui->avp_button_2->setDisabled(true);
        ui->initial_pos_b_2->setDisabled(true);
        ui->goal_pos_b_2->setDisabled(true);
        ui->scenic_activate_3->setDisabled(true);
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

void MainWindow::on_ckbox_localization_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    // ui->ckbox_localization->setChecked(false);

    ui->checkBox_3->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->ckbox_PathPlanning->setChecked(false);

    if(ui->ckbox_localization->isChecked()){
        ui->gbox_localization->setVisible(true);
        ui->stackedWidget->setVisible(true);
    }else{
        ui->gbox_localization->setVisible(false);
        ui->stackedWidget->setVisible(false);
    }
}

void MainWindow::on_ckbox_PathPlanning_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->checkBox_3->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->ckbox_localization->setChecked(false);

    if(ui->ckbox_PathPlanning->isChecked()){
        ui->gbox_path_planning->setVisible(true);
        ui->stackedWidget->setVisible(true);
    }else{
        ui->gbox_path_planning->setVisible(false);
        ui->stackedWidget->setVisible(false);
    }
}

void MainWindow::on_b_control_start_ade_clicked()
{
    this->startAde = true;
    count1 =1;
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
    ui->label_5->setEnabled(true);
    QString path = QDir::currentPath() + "/qc_ade_start.sh"; //sneha
    executeShell(path);
}

// Select scenario from control validation tab
void MainWindow::on_b_control_sel_scenario_clicked()
{
    ui->listWidgetSceneSelect->clear();
    sel_item_clr.clear();
    ui->treeWidgetControl->clear();
    ui->label_5->setEnabled(true);
    ui->listWidgetSceneSelect->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    directory.setPath(p_testCases) ;
    //sne
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
    //    sel_item_clr.clear();
    //    ui->treeWidgetControl->clear();
    //    ui->label_5->setEnabled(true);
    //    ui->listWidgetSceneSelect->setEnabled(true);
    //    QDir directory ;
    //    QString curr_path = QDir::currentPath();
    //    int pos = curr_path.lastIndexOf(QChar('/'));
    //    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    //    directory.setPath(p_testCases) ;
    //    bool flag = false;
    //    //sne
    //    if(flag2){
    //        QFile fp1(p_testCases+"/scene.txt");
    //        if (!fp1.open(QIODevice::ReadOnly))
    //        {
    //            qDebug() << "File not open";
    //            QMessageBox msgBox;
    //            msgBox.setText("Create scene.txt in Test_Cases Directory");
    //            msgBox.exec();
    //            return;
    //        }
    //        int m=1;

    //        while (!fp1.atEnd()) {
    //            QString str = fp1.readLine();
    //            str = str.remove('\n');
    //            ui->listWidgetSceneSelect->insertItem(m++,str);
    //        }
    //        flag2 = false;
    //    }
    //    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidgetControl);
    //    for(const QFileInfo &finfo : directory.entryInfoList()){
    //        if(finfo.fileName().contains(".."))
    //            continue;
    //        QDir dir(finfo.absoluteFilePath());

    //        if(finfo.isDir() == false)
    //            continue;
    //        if(flag == false)
    //        {
    //            root->setText(0,dir.dirName());
    //            ui->treeWidget->addTopLevelItem(root);
    //            // root->setCheckState(0,Qt::Unchecked); //optional  1
    //            flag = true;
    //        }//if_
    //        else
    //        {
    //            QTreeWidgetItem *child = new  QTreeWidgetItem();
    //            child->setText(0,dir.dirName());
    //            //child->setCheckState(0,Qt::Unchecked);  2
    //            root->addChild(child);

    //            if(finfo.isDir())
    //            {
    //                QDir dir(finfo.absoluteFilePath());
    //                if(finfo.fileName().contains("Scenic")){
    //                    for(const QFileInfo &f : dir.entryInfoList()){
    //                        if(f.isDir())
    //                            continue;
    //                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                        child_c->setText(0,f.fileName());
    //                        child_c->setCheckState(0,Qt::Unchecked);
    //                        child->addChild(child_c);
    //                    }
    //                }
    //                if(dir.exists("config.txt")){
    //                    QDir d(finfo.absoluteFilePath());
    //                    path = finfo.absoluteFilePath();
    //                    QStringList flt;
    //                    flt << "*.py";

    //                    d.setNameFilters(flt);

    //                    for(const QFileInfo &f : d.entryInfoList()){
    //                        if(f.fileName() == "run.py")
    //                            continue;
    //                        QFile fp(dir.absolutePath()+"/config.txt");
    //                        if (!fp.open(QIODevice::ReadOnly))
    //                        {
    //                            qDebug() << "File not open";
    //                            return;
    //                        }
    //                        while (!fp.atEnd()) {
    //                            QString str = fp.readLine();
    //                            QString s = f.fileName();
    //                            str = str.remove('\n');
    //                            s.remove(".py");
    //                            s.append(":"+str);
    //                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                            child_c->setText(0,s);
    //                            child_c->setCheckState(0,Qt::Unchecked);
    //                            child->addChild(child_c);

    //                        }//while
    //                        fp.flush();
    //                        fp.close();
    //                    }
    //                }
    //            }
    //        }
    //    }

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
    ui->avp_button_2->setEnabled(true);
    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_stop_scenario->setEnabled(true);
    ui->b_control_showreport->setDisabled(true);
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
    stream <<"./Poly_Suite/support_files/validate_c.sh & \n";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos) ;
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
        executeShell(c_path);
    }
}

void MainWindow::on_b_control_showreport_clicked()
{
    reportwindow *reportwin = new reportwindow;
    reportwin->setModal(this);
    connect( this, SIGNAL(updateUI1Signal(const QString)), reportwin, SLOT(updateUI2TextSlot(const QString) ) );
    connect( this, SIGNAL(seltabSignal(const int)),reportwin, SLOT(seltabSlot(const int) ) );
    emit seltabSignal(0);
    reportwin->exec();


}

void MainWindow::on_b_control_stopAde_clicked()
{
    flag2 = true; //scene
    ui->listWidgetSceneSelect->clear();
    ui->initial_pos_b->setDisabled(true);
    ui->goal_pos_b->setDisabled(true);
    ui->scenic_activate_3->setDisabled(true);
    ui->run_scenic_control->setDisabled(true);
    ui->avp_button_2->setDisabled(true);
    ui->b_control_start_ade->setEnabled(true);
    ui->b_control_stopAde->setDisabled(true);
    qDebug() << "ADE Stopped  ";
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);

    ui->b_control_sel_scenario->setDisabled(true);
    ui->treeWidgetControl->clear();
    ui->treeWidgetControl->setDisabled(true);
//    ui->b_control_showreport->setDisabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_run_scenario->setDisabled(true);
    ui->listWidgetSceneSelect->setDisabled(true);
    ui->lbl_outputlog->setText("Log Information : ADE Stop");
    fileModify();
}

void MainWindow::on_b_control_stop_scenario_clicked()
{
    scenarioItr = 1;
    count1 = 1;
    if(sel_item_clr.isEmpty() == false){
        foreach (QTreeWidgetItem * m, sel_item_clr) {
            m->setCheckState(0,Qt::Unchecked);
        }
    }
    ui->listWidgetSceneSelect->clearSelection();
    ui->initial_pos_b_2->setDisabled(true);
    ui->goal_pos_b_2->setDisabled(true);
    ui->avp_button_2->setDisabled(true);
    ui->run_scenic_control->setEnabled(true);
    ui->b_control_stop_scenario->setDisabled(true);
    ui->b_control_run_scenario->setEnabled(false);
    ui->run_scenic_control->setDisabled(true);
    ui->scenic_activate_3->setDisabled(true);
    ui->b_control_showreport->setEnabled(true);
    QString path = QDir::currentPath() + "/stop_scenario.sh";
    executeShell(path);
}

void MainWindow::on_listWidgetSceneSelect_itemClicked(QListWidgetItem *item)
{
    //    parameters.scene = item->text();
    //    ui->treeWidgetControl->setEnabled(true);
    //    qDebug() <<"senece selected in CVU : "<<  parameters.scene;

    ui->treeWidgetControl->clear();
    parameters.scene = item->text();
    ui->treeWidgetControl->setEnabled(true);
    qDebug() <<"senece selected in CVU : "<<  parameters.scene;
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos)  +"/Test_Cases/"+parameters.scene + "/";
    directory.setPath(p_testCases) ;
    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidgetControl);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;
        if(flag == false)
        {
            root->setText(0,"Test_Cases");
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
                QDir dir(finfo.absoluteFilePath());
                if(finfo.fileName().contains("Scenic")){
                    for(const QFileInfo &f : dir.entryInfoList()){
                        if(f.isDir())
                            continue;
                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
                        child_c->setText(0,f.fileName());
                        child_c->setCheckState(0,Qt::Unchecked);
                        child->addChild(child_c);
                    }
                }
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py";

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

                        }//while
                        fp.flush();
                        fp.close();
                    }
                }
            }
        }
    }

}

void MainWindow::on_listWidgetSceneSelectDSU_itemClicked(QListWidgetItem *item)
{
    //    parameters.scene = item->text();
    //    ui->treeWidget->setEnabled(true);
    //    qDebug() <<"senece selected in DSU: "<<  parameters.scene;
    ui->treeWidget->clear();
    parameters.scene = item->text();
    ui->treeWidget->setEnabled(true);
    qDebug() <<"senece selected in DSU: "<<  parameters.scene;
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/" + parameters.scene+ "/";
    qDebug() << "new path : " + p_testCases;
    directory.setPath(p_testCases) ;
    bool flag = false;
    ///////////////////
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;
        if(flag == false)
        {
            //root->setText(0,dir.dirName());
            root->setText(0,"Test_Cases");
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
                if(finfo.fileName().contains("Scenic")){
                    qDebug() << finfo.fileName();
                    for(const QFileInfo &f : dir.entryInfoList()){
                        if(f.isDir())
                            continue;
                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
                        child_c->setText(0,f.fileName());
                        child_c->setCheckState(0,Qt::Unchecked);
                        child->addChild(child_c);
                    }
                }
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py";

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

void MainWindow::on_b_control_validation_clicked()
{
    //TODO::Adding of callig script of control validation node start
    QString path = QDir::currentPath() + "/q_control_validate.sh";
    executeShell(path);
    //ui->b_per_validate->setDisabled(true);
    ui->b_control_showreport->setEnabled(true);
}

void MainWindow::executeShell(QString path){
    QProcess *process = new QProcess();
    process->execute(path);
    process->waitForFinished(200);
    delete process;
}


void MainWindow::on_scenic_activate_clicked()              //val
{
    //    QString path = QDir::currentPath() + "/q_scenic_Activate.sh";
    ////QProcess *process = new QProcess();
    //    executeShell(path);
    ui->scenic_activate_2->setDisabled(true);
    ui->avp_button->setEnabled(true);
    if(count.isEmpty())
        count = "1";

    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    //    ui->label_2->setDisabled(true);//
    //    ui->lbl_d_Auto->setDisabled(true);
    //    ui->lbl_d_LG->setDisabled(true);
    //    ui->lbl_d_Failure->setDisabled(true);
    //    ui->lbl_d_Succes->setDisabled(true);
    //->setDisabled(true);//
    //
    //->setDisabled(true);
    ui->treeWidget->setDisabled(true); //sne
    ui->b_sel_scenario->setDisabled(true);
    //->setDisabled(true);
    model->clear();
    //->setModel(model);
    //    ui->lbl_d_Auto->setText("Detection range in Autoware(m): NA");
    //    ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
    //    ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA");
    //    ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");
    flagSimulation = true;
    qDebug() << "Selected items from the scenic" <<selected;
    // TODO
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \n";

    QString testcasepath = par;  //sne
    par.remove(0,1);
    reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";
    stream <<"./Poly_Suite/support_files/validate_p.sh &"<<"\n";
    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        tCase = s.left(scenarioPos);
        QString tmp = tCase+ "_iteration_" + QString::number(scenarioItr) ;
        stream << "mkdir -p " <<  reportPath + tmp <<" && touch "<<  reportPath + tmp+"/"<<"\n";
        //stream << "echo \""<< reportPath + tmp<<" \" > PolyReports/Validation_report/config.txt; \n";
        ///stream << "mkdir -p " << "../" + reportPath + tCase <<" && touch "<<  "../" + reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tmp <<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;

        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        // stream << "ls \n";
        stream << "echo \"Running Scenic\" \n";
        stream << "scenic " + par + s + "   ";
        stream << " --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count " + count + "  " ;
        stream << "--param map " +par +"maps/" + parameters.scene +".xodr   ";
        stream << "--param lgsvl_map " + parameters.scene;

    }
    fp.close();
    selected.clear();
    //if(parameters.Script != ""){
    QString c_path = QDir::currentPath() + "/q_scenic_Activate.sh";
    executeShell(c_path);
    //    if( count1  == 1 )
    //        scenarioItr = 1;
    //    else
    scenarioItr = 2;

    //  }
    ui->b_run_scenario->setDisabled(true);
    ui->scenic_activate->setDisabled(true);
    ui->b_stop_scenario->setEnabled(true);
    //->setDisabled(true);
    //count.clear();
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
    ui->avp_button->setEnabled(true);


    //     ui->label_2->setDisabled(true);//
    //     ui->lbl_d_Auto->setDisabled(true);
    //     ui->lbl_d_LG->setDisabled(true);
    //     ui->lbl_d_Failure->setDisabled(true);
    //     ui->lbl_d_Succes->setDisabled(true);
    //->setDisabled(true);//
    //
    //->setDisabled(true);
    ui->treeWidget->setDisabled(true); //sne
    ui->b_sel_scenario->setDisabled(true);
    //->setDisabled(true);
    model->clear();
    //->setModel(model);
    //     ui->lbl_d_Auto->setText("Detection range in Autoware(m): NA");
    //     ui->lbl_d_LG->setText("Detection range in LG(m) : NA");
    //     ui->lbl_d_Succes->setText("Detection Success Rate(%) : NA");
    //     ui->lbl_d_Failure->setText("Detection Failure Rate(%) : NA");
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
    stream <<"./Poly_Suite/support_files/validate_p.sh &"<<"\n"<<"ls \n";
    //stream << "gnome-terminal --tab --title=\"Perception Node\" --command=\"bash -c 'ade enter sh ./Poly_Suite/support_files/validate_p.sh;'\" \n";
    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos);
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    stream << "\n \nsleep 20";
    fp.close();
    selected.clear();
    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh";
        executeShell(c_path);
    }

    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setEnabled(true);
    //->setDisabled(true);

}

void MainWindow::on_run_scenic_control_clicked()  //control
{
    ui->avp_button_2->setEnabled(true);
    if(count.isEmpty())
        count = "1";
    //    scenarioItr = 1;
    //    count1 = 1;
    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->scenic_activate_3->setDisabled(true);
    ui->avp_button_2->setEnabled(true);
    ui->b_control_run_scenario->setDisabled(true);
    ui->b_control_stop_scenario->setEnabled(true);
    ui->b_control_showreport->setDisabled(true);
    ui->run_scenic_control->setDisabled(true);
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
    stream << "#!/bin/sh \n";

    QString testcasepath = par;  //sne
    par.remove(0,1);

    reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";
    qDebug() << "reportPath : " <<reportPath;
    stream <<"./Poly_Suite/support_files/validate_c.sh &"<<"\n";
    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        tCase = s.left(scenarioPos);
        qDebug() << "tCase : " <<tCase;
        QString tmp = tCase+ "_iteration_" + QString::number(scenarioItr);
        stream << "mkdir -p " <<  reportPath + tmp <<" && touch "<<  reportPath + tmp+"/"<<"\n";
        stream << "echo \""<< reportPath + tmp <<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "echo \"Running Scenic\" \n";
        stream << "scenic " + par + s + "   ";
        stream << " --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count " + count + "  " ;
        stream << "--param map " +par +"maps/" + parameters.scene +".xodr   ";
        stream << "--param lgsvl_map " + parameters.scene;

    }

    fp.close();
    selected.clear();
    scenarioItr = 2;
    QString c_path = QDir::currentPath() + "/q_scenic_Activate.sh";
    executeShell(c_path);
    count.clear();
}

void MainWindow::on_b_showreport_2_clicked()
{
    reportwindow *reportwin = new reportwindow;
    reportwin->setModal(this);
    connect( this, SIGNAL(updateUI1Signal(const QString)), reportwin, SLOT(updateUI2TextSlot(const QString) ) );
    connect( this, SIGNAL(seltabSignal(const int)),reportwin, SLOT(seltabSlot(const int) ) );
    emit seltabSignal(1);
    reportwin->exec();

    ui->b_showreport_2->setDisabled(true);
}

void MainWindow::on_scenic_activate_2_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Count"),
                                         tr("Count:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()){
        count = text;
        count1 = text.toInt();
    }
    // scenarioItr = text.toInt();

    qDebug() << "scenariocount on set count  : " << count1;
}

void MainWindow::on_avp_button_clicked()
{
    ui->avp_button->setDisabled(true);
    ui->initial_pos_b->setEnabled(true);
    //ui->goal_pos_b->setEnabled(true);
    QString c_path = QDir::currentPath() + "/avp_launch.sh";
    executeShell(c_path);
}

void MainWindow::on_initial_pos_b_clicked()
{
    QString c_path = QDir::currentPath() + "/q_initialPos.sh";
    executeShell(c_path);
    ui->initial_pos_b->setDisabled(true);
    ui->goal_pos_b->setEnabled(true);
}

void MainWindow::on_goal_pos_b_clicked()
{
    QString c_path = QDir::currentPath() + "/q_goalPos.sh";
    executeShell(c_path);
    ui->goal_pos_b->setDisabled(true);
}

void MainWindow::on_avp_button_2_clicked()
{
    ui->initial_pos_b_2->setEnabled(true);

    ui->avp_button_2->setDisabled(true);
    QString c_path = QDir::currentPath() + "/avp_launch.sh";
    executeShell(c_path);
}

void MainWindow::on_scenic_activate_3_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Count"),
                                         tr("Count:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !text.isEmpty()){
        count = text;
        count1 = text.toInt();
    }
}


void MainWindow::on_initial_pos_b_2_clicked()
{
    QString c_path = QDir::currentPath() + "/q_initialPos.sh";
    executeShell(c_path);
    ui->initial_pos_b_2->setDisabled(true);
    ui->goal_pos_b_2->setEnabled(true);
}

void MainWindow::on_goal_pos_b_2_clicked()
{
    QString c_path = QDir::currentPath() + "/q_goalPos.sh";
    executeShell(c_path);
    ui->goal_pos_b_2->setEnabled(false);
}



void MainWindow::on_treeWid_local_select_script_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->btn_local_avp->setEnabled(true);

    QString str,mainstring;
    if(item->text(column).contains("scenic"))
    {
        count.clear();
        str = item->text(column);
        parameters.Script = str;
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/";
        par= "/"+p1->text(column)+"/"+parameters.scene+"/"+p2->text(column)+"/";

        Qt::CheckState p;
        p = Qt::Unchecked;
        if(item->checkState(column) == p){
            selected.remove(str);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(str);
        }
        ui->btn_local_run_scenario->setDisabled(true);
        ui->btn_local_scenic_count->setEnabled(true);
        ui->btn_local_scenic_run->setEnabled(true);
    }
    if(item->text(column).contains("rain"))
    {
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/";
        par= "/"+p1->text(column)+"/"+parameters.scene+"/"+p2->text(column)+"/";

        Qt::CheckState p; //updted
        p = Qt::Unchecked; //updated
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        mainstring = parameters.Script + " "; //updated
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
        foreach(QChar c, tmp){
            if(c == ',')
                val.append(" ");
            if(c.isDigit() || c == '.')
                val.append(c);
        }
        check_list.insert("Rain",val);
        mainstring.append(val + " "); //updtaed
        mainstring.append(parameters.scene); //updated

        if(item->checkState(column) == p){
            selected.remove(mainstring);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }
        ui->btn_local_scenic_count->setDisabled(true);
        ui->btn_local_scenic_run->setDisabled(true);
        ui->btn_local_run_scenario->setEnabled(true);
    }
    check_flag = true;
}

void MainWindow::on_btn_local_sel_scenario_clicked()
{
    sel_item_clr.clear();
    ui->listWid_local_scene_select->clear();
    ui->lbl_sceneSelect->setEnabled(true);
    ui->listWid_local_scene_select->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    directory.setPath(p_testCases) ;
    // bool flag = false;

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
        ui->listWid_local_scene_select->insertItem(m++,str);
    }

    //    sel_item_clr.clear();
    //    ui->treeWid_local_select_script->clear();
    //    ui->lbl_sceneSelect->setEnabled(true);
    //    ui->listWid_local_scene_select->setEnabled(true);
    //    QDir directory ;
    //    QString curr_path = QDir::currentPath();
    //    int pos = curr_path.lastIndexOf(QChar('/'));
    //    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    //    directory.setPath(p_testCases) ;
    //    bool flag = false;
    //    if(flag1){
    //        QFile fp1(p_testCases+"/scene.txt");
    //        if (!fp1.open(QIODevice::ReadOnly))
    //        {
    //            qDebug() << "File not open";
    //            QMessageBox msgBox;
    //            msgBox.setText("Create scene.txt in Test_Cases Directory");
    //            msgBox.exec();
    //            return;
    //        }
    //        int m=1;

    //        while (!fp1.atEnd()) {
    //            QString str = fp1.readLine();
    //            str = str.remove('\n');
    //            ui->listWid_local_scene_select->insertItem(m++,str);
    //        }
    //        flag1 = false;
    //    }

    //    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWid_local_select_script);
    //    for(const QFileInfo &finfo : directory.entryInfoList()){
    //        if(finfo.fileName().contains(".."))
    //            continue;
    //        QDir dir(finfo.absoluteFilePath());

    //        if(finfo.isDir() == false)
    //            continue;
    //        if(flag == false)
    //        {
    //            root->setText(0,dir.dirName());
    //            ui->treeWid_local_select_script->addTopLevelItem(root);
    //            flag = true;
    //        }
    //        else
    //        {
    //            QTreeWidgetItem *child = new  QTreeWidgetItem();
    //            child->setText(0,dir.dirName());
    //            root->addChild(child);

    //            if(finfo.isDir())
    //            {
    //                QDir dir(finfo.absoluteFilePath());
    //                if(finfo.fileName().contains("Scenic")){
    //                    qDebug() << finfo.fileName();
    //                    for(const QFileInfo &f : dir.entryInfoList()){
    //                        if(f.isDir())
    //                            continue;
    //                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                        child_c->setText(0,f.fileName());
    //                        child_c->setCheckState(0,Qt::Unchecked);
    //                        child->addChild(child_c);
    //                    }
    //                }
    //                if(dir.exists("config.txt")){
    //                    QDir d(finfo.absoluteFilePath());
    //                    path = finfo.absoluteFilePath();
    //                    QStringList flt;
    //                    flt << "*.py";

    //                    d.setNameFilters(flt);

    //                    for(const QFileInfo &f : d.entryInfoList()){
    //                        if(f.fileName() == "run.py")
    //                            continue;
    //                        QFile fp(dir.absolutePath()+"/config.txt");
    //                        if (!fp.open(QIODevice::ReadOnly))
    //                        {
    //                            qDebug() << "File not open";
    //                            return;
    //                        }
    //                        while (!fp.atEnd()) {
    //                            QString str = fp.readLine();
    //                            QString s = f.fileName();
    //                            str = str.remove('\n');
    //                            s.remove(".py");
    //                            s.append(":"+str);
    //                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                            child_c->setText(0,s);
    //                            child_c->setCheckState(0,Qt::Unchecked);
    //                            child->addChild(child_c);

    //                        }
    //                        fp.flush();
    //                        fp.close();
    //                    }
    //                }
    //            }
    //        }
    //    }
}

void MainWindow::on_btn_local_adeStart_clicked()
{
    count1 =1;
    this->startAde = true;
    // below variable can be assign at the start of the application TODO
    movie = new QMovie("spinner.gif");
    model = new QStandardItemModel;
    flagSimulation = false;
    fileWatcher();
    createTempRecordPath();

    ui->lbl_outputlog->setText("Log Information : ADE and other component initilize, it may take while to start..");
    ui->btn_local_StopAde->setEnabled(true);
    ui->btn_local_sel_scenario->setEnabled(true);
    ui->listWid_local_scene_select->setEnabled(true);
    ui->btn_local_adeStart->setDisabled(true);

    QString path = QDir::currentPath() + "/q_ade_start.sh";
    executeShell(path);
}

void MainWindow::on_btn_local_StopAde_clicked()
{

    flag1 = true;    //scene list
    ui->listWid_local_scene_select->clear();
    ui->btn_local_initial_pos->setDisabled(true);
    ui->btn_local_goal_pos->setDisabled(true);
    ui->btn_local_scenic_count->setDisabled(true);
    ui->btn_local_scenic_run->setDisabled(true);
    ui->btn_local_avp->setDisabled(true);
    ui->btn_local_adeStart->setEnabled(true);
    ui->btn_local_StopAde->setDisabled(true);

    ui->btn_local_sel_scenario->setDisabled(true);
    ui->treeWid_local_select_script->clear();
    ui->treeWid_local_select_script->setDisabled(true);
//    ui->btn_local_showreport->setDisabled(true);
    ui->btn_local_stop_scenario->setDisabled(true);
    ui->btn_local_run_scenario->setDisabled(true);
    ui->listWid_local_scene_select->setDisabled(true);
    ui->lbl_outputlog->setText("Log Information : ADE Stop");

    qDebug() << "ADE Stopped  ";
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);

    fileModify();
}

void MainWindow::on_listWid_local_scene_select_itemClicked(QListWidgetItem *item)
{
    //    parameters.scene = item->text();
    //    ui->treeWid_local_select_script->setEnabled(true);
    ui->treeWid_local_select_script->clear();
    parameters.scene = item->text();
    ui->treeWid_local_select_script->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/"+parameters.scene + "/";
    directory.setPath(p_testCases) ;

    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWid_local_select_script);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;
        if(flag == false)
        {
            root->setText(0,"Test_Cases");
            ui->treeWid_local_select_script->addTopLevelItem(root);
            flag = true;
        }
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            root->addChild(child);

            if(finfo.isDir())
            {
                QDir dir(finfo.absoluteFilePath());
                if(finfo.fileName().contains("Scenic")){
                    qDebug() << finfo.fileName();
                    for(const QFileInfo &f : dir.entryInfoList()){
                        if(f.isDir())
                            continue;
                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
                        child_c->setText(0,f.fileName());
                        child_c->setCheckState(0,Qt::Unchecked);
                        child->addChild(child_c);
                    }
                }
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py";

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

void MainWindow::on_btn_local_scenic_count_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Count"),tr("Count:"), QLineEdit::Normal,"", &ok);
    if (ok && !text.isEmpty()){
        count = text;
        count1 = text.toInt();
    }
}

void MainWindow::on_btn_local_scenic_run_clicked()
{
    if(count.isEmpty())
        count = "1";

    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->btn_local_scenic_run->setDisabled(true);
    ui->btn_local_scenic_count->setDisabled(true);
    ui->btn_local_sel_scenario->setDisabled(true);
    ui->btn_local_showreport->setDisabled(true);

    ui->btn_local_stop_scenario->setEnabled(true);
    ui->btn_local_avp->setEnabled(true);

    flagSimulation = true;
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \n";

    QString testcasepath = par;  //sne
    par.remove(0,1);

    reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";

    // local
    //stream <<"./Poly_Suite/support_files/validate_c.sh &"<<"\n";
    stream <<"./Poly_Suite/support_files/validate_local.sh &"<<"\n";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        tCase = s.left(scenarioPos);
        QString tmp = tCase+ "_iteration_" + QString::number(scenarioItr);
        stream << "mkdir -p " <<  reportPath + tmp <<" && touch "<<  reportPath + tmp+"/"<<"\n";
        stream << "echo \""<< reportPath + tmp <<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "echo \"Running Scenic\" \n";
        stream << "scenic " + par + s + "   ";
        stream << " --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count " + count + "  " ;
        stream << "--param map " +par +"maps/" + parameters.scene +".xodr   ";
        stream << "--param lgsvl_map " + parameters.scene;

    }

    fp.close();
    selected.clear();
    scenarioItr = 2;
    QString c_path = QDir::currentPath() + "/q_scenic_Activate.sh";
    executeShell(c_path);
    count.clear();
}

void MainWindow::on_btn_local_run_scenario_clicked()
{
    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->btn_local_avp->setEnabled(true);
    ui->btn_local_run_scenario->setDisabled(true);
    ui->btn_local_stop_scenario->setEnabled(true);
    ui->btn_local_showreport->setDisabled(true);
    flagSimulation = true;

    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \nset -eu\n";

    QString testcasepath = par;
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";
    //stream <<"./Poly_Suite/support_files/validate_c.sh & \n";

    stream <<"./Poly_Suite/support_files/validate_local.sh & \n";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos) ;
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    fp.close();
    selected.clear();

    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh " ;
        executeShell(c_path);
    }
}

void MainWindow::on_btn_local_stop_scenario_clicked()
{
    scenarioItr = 1;
    count1 = 1;
    if(sel_item_clr.isEmpty() == false){
        foreach (QTreeWidgetItem * m, sel_item_clr) {
            m->setCheckState(0,Qt::Unchecked);
        }
    }
    ui->listWid_local_scene_select->clearSelection();
    ui->btn_local_initial_pos->setDisabled(true);
    ui->btn_local_goal_pos->setDisabled(true);
    ui->btn_local_avp->setDisabled(true);
    ui->btn_local_run_scenario->setEnabled(true);
    ui->btn_local_stop_scenario->setDisabled(true);
    ui->btn_local_run_scenario->setEnabled(false);
    ui->btn_local_scenic_run->setDisabled(true);
    ui->btn_local_scenic_count->setDisabled(true);
    ui->btn_local_showreport->setEnabled(true);
    QString path = QDir::currentPath() + "/stop_scenario.sh";
    executeShell(path);
}

void MainWindow::on_btn_local_showreport_clicked()
{
    reportwindow *reportwin = new reportwindow;
    reportwin->setModal(this);
    connect( this, SIGNAL(updateUI1Signal(const QString)), reportwin, SLOT(updateUI2TextSlot(const QString) ) );
    connect( this, SIGNAL(seltabSignal(const int)),reportwin, SLOT(seltabSlot(const int) ) );
    emit seltabSignal(2);
    reportwin->exec();
}

void MainWindow::on_btn_local_avp_clicked()
{
    ui->btn_local_initial_pos->setEnabled(true);

    ui->btn_local_avp->setDisabled(true);
    QString c_path = QDir::currentPath() + "/avp_launch.sh";
    executeShell(c_path);
}

void MainWindow::on_btn_local_initial_pos_clicked()
{
    QString c_path = QDir::currentPath() + "/q_initialPos.sh";
    executeShell(c_path);
    ui->btn_local_initial_pos->setDisabled(true);
    ui->btn_local_goal_pos->setEnabled(true);
}

void MainWindow::on_btn_local_goal_pos_clicked()
{
    QString c_path = QDir::currentPath() + "/q_goalPos.sh";
    executeShell(c_path);
    ui->btn_local_goal_pos->setEnabled(false);
}

void MainWindow::on_btn_pp_adeStart_clicked()
{
    count1 =1;
    this->startAde = true;
    // below variable can be assign at the start of the application TODO
    movie = new QMovie("spinner.gif");
    model = new QStandardItemModel;
    flagSimulation = false;
    fileWatcher();
    createTempRecordPath();

    ui->lbl_outputlog->setText("Log Information : ADE and other component initilize, it may take while to start..");
    ui->btn_pp_StopAde->setEnabled(true);
    ui->btn_pp_sel_scenario->setEnabled(true);
    ui->btn_pp_adeStart->setDisabled(true);

    QString path = QDir::currentPath() + "/q_ade_start.sh";
    executeShell(path);
}

void MainWindow::on_btn_pp_sel_scenario_clicked()
{
    sel_item_clr.clear();
    ui->listWid_pp_scene_select->clear();
    ui->lbl_pp_sceneSelect->setEnabled(true);
    ui->listWid_pp_scene_select->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    directory.setPath(p_testCases) ;
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
        ui->listWid_pp_scene_select->insertItem(m++,str);
    }

    //    sel_item_clr.clear();
    //    ui->treeWid_pp_select_script->clear();
    //    ui->lbl_pp_sceneSelect->setEnabled(true);
    //    ui->listWid_pp_scene_select->setEnabled(true);
    //    QDir directory ;
    //    QString curr_path = QDir::currentPath();
    //    int pos = curr_path.lastIndexOf(QChar('/'));
    //    p_testCases = curr_path.left(pos) + "/Test_Cases/";
    //    directory.setPath(p_testCases) ;
    //    bool flag = false;

    //    if(flag1){
    //        QFile fp1(p_testCases+"/scene.txt");
    //        if (!fp1.open(QIODevice::ReadOnly))
    //        {
    //            qDebug() << "File not open";
    //            QMessageBox msgBox;
    //            msgBox.setText("Create scene.txt in Test_Cases Directory");
    //            msgBox.exec();
    //            return;
    //        }
    //        int m=1;

    //        while (!fp1.atEnd()) {
    //            QString str = fp1.readLine();
    //            str = str.remove('\n');
    //            ui->listWid_pp_scene_select->insertItem(m++,str);
    //        }
    //        flag1 = false;
    //    }

    //    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWid_pp_select_script);
    //    for(const QFileInfo &finfo : directory.entryInfoList()){
    //        if(finfo.fileName().contains(".."))
    //            continue;
    //        QDir dir(finfo.absoluteFilePath());

    //        if(finfo.isDir() == false)
    //            continue;
    //        if(flag == false)
    //        {
    //            root->setText(0,dir.dirName());
    //            ui->treeWid_pp_select_script->addTopLevelItem(root);
    //            flag = true;
    //        }
    //        else
    //        {
    //            QTreeWidgetItem *child = new  QTreeWidgetItem();
    //            child->setText(0,dir.dirName());
    //            root->addChild(child);

    //            if(finfo.isDir())
    //            {
    //                QDir dir(finfo.absoluteFilePath());
    //                if(finfo.fileName().contains("Scenic")){
    //                    qDebug() << finfo.fileName();
    //                    for(const QFileInfo &f : dir.entryInfoList()){
    //                        if(f.isDir())
    //                            continue;
    //                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                        child_c->setText(0,f.fileName());
    //                        child_c->setCheckState(0,Qt::Unchecked);
    //                        child->addChild(child_c);
    //                    }
    //                }
    //                if(dir.exists("config.txt")){
    //                    QDir d(finfo.absoluteFilePath());
    //                    path = finfo.absoluteFilePath();
    //                    QStringList flt;
    //                    flt << "*.py";

    //                    d.setNameFilters(flt);

    //                    for(const QFileInfo &f : d.entryInfoList()){
    //                        if(f.fileName() == "run.py")
    //                            continue;
    //                        QFile fp(dir.absolutePath()+"/config.txt");
    //                        if (!fp.open(QIODevice::ReadOnly))
    //                        {
    //                            qDebug() << "File not open";
    //                            return;
    //                        }
    //                        while (!fp.atEnd()) {
    //                            QString str = fp.readLine();
    //                            QString s = f.fileName();
    //                            str = str.remove('\n');
    //                            s.remove(".py");
    //                            s.append(":"+str);
    //                            QTreeWidgetItem *child_c = new QTreeWidgetItem();
    //                            child_c->setText(0,s);
    //                            child_c->setCheckState(0,Qt::Unchecked);
    //                            child->addChild(child_c);

    //                        }
    //                        fp.flush();
    //                        fp.close();
    //                    }
    //                }
    //            }
    //        }
    //    }
}

void MainWindow::on_btn_pp_StopAde_clicked()
{
    flag1 = true;    //scene list
    ui->listWid_pp_scene_select->clear();
    ui->btn_pp_initial_pos->setDisabled(true);
    ui->btn_pp_goal_pos->setDisabled(true);
    ui->btn_pp_scenic_count->setDisabled(true);
    ui->btn_pp_scenic_run->setDisabled(true);
    ui->btn_pp_avp->setDisabled(true);
    ui->btn_pp_adeStart->setEnabled(true);
    ui->btn_pp_StopAde->setDisabled(true);

    ui->btn_pp_sel_scenario->setDisabled(true);
    ui->treeWid_pp_select_script->clear();
    ui->treeWid_pp_select_script->setDisabled(true);
//    ui->btn_pp_showreport->setDisabled(true);
    ui->btn_pp_stop_scenario->setDisabled(true);
    ui->btn_pp_run_scenario->setDisabled(true);
    ui->listWid_pp_scene_select->setDisabled(true);
    ui->lbl_outputlog->setText("Log Information : ADE Stop");

    qDebug() << "ADE Stopped  ";
    QString path = QDir::currentPath() + "/q_stopt.sh";
    executeShell(path);

    fileModify();
}

void MainWindow::on_listWid_pp_scene_select_itemClicked(QListWidgetItem *item)
{
    //    parameters.scene = item->text();
    //    ui->treeWid_pp_select_script->setEnabled(true);

    parameters.scene = item->text();
    ui->treeWid_pp_select_script->clear();
    ui->treeWid_pp_select_script->setEnabled(true);
    QDir directory ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    p_testCases = curr_path.left(pos) + "/Test_Cases/" + parameters.scene + "/";
    directory.setPath(p_testCases) ;
    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWid_pp_select_script);
    for(const QFileInfo &finfo : directory.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;
        if(flag == false)
        {
            root->setText(0,"Test_Cases");
            ui->treeWid_pp_select_script->addTopLevelItem(root);
            flag = true;
        }
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            root->addChild(child);

            if(finfo.isDir())
            {
                QDir dir(finfo.absoluteFilePath());
                if(finfo.fileName().contains("Scenic")){
                    qDebug() << finfo.fileName();
                    for(const QFileInfo &f : dir.entryInfoList()){
                        if(f.isDir())
                            continue;
                        QTreeWidgetItem *child_c = new QTreeWidgetItem();
                        child_c->setText(0,f.fileName());
                        child_c->setCheckState(0,Qt::Unchecked);
                        child->addChild(child_c);
                    }
                }
                if(dir.exists("config.txt")){
                    QDir d(finfo.absoluteFilePath());
                    path = finfo.absoluteFilePath();
                    QStringList flt;
                    flt << "*.py";

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

void MainWindow::on_treeWid_pp_select_script_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->btn_pp_avp->setEnabled(true);

    QString str,mainstring;
    if(item->text(column).contains("scenic"))
    {
        count.clear();
        str = item->text(column);
        parameters.Script = str;
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/";
        par= "/"+p1->text(column)+"/"+parameters.scene+"/"+p2->text(column)+"/";

        Qt::CheckState p;
        p = Qt::Unchecked;
        if(item->checkState(column) == p){
            selected.remove(str);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(str);
        }
        ui->btn_pp_run_scenario->setDisabled(true);
        ui->btn_pp_scenic_count->setEnabled(true);
        ui->btn_pp_scenic_run->setEnabled(true);
    }
    if(item->text(column).contains("rain"))
    {
        QTreeWidgetItem *p2 = item->parent();
        QTreeWidgetItem *p1 = p2->parent();
        sel_item_clr.append(item);
        //        par= "/"+p1->text(column)+"/"+p2->text(column)+"/";
        par= "/"+p1->text(column)+"/"+parameters.scene+"/"+p2->text(column)+"/";

        Qt::CheckState p;
        p = Qt::Unchecked;
        str = item->text(column);
        int pos = str.indexOf(":");
        str = str.left(pos) + ".py";
        parameters.Script = str.left(pos) + ".py";
        mainstring = parameters.Script + " ";
        QString tmp = item->text(column),val;
        tmp = tmp.remove(0,pos);
        foreach(QChar c, tmp){
            if(c == ',')
                val.append(" ");
            if(c.isDigit() || c == '.')
                val.append(c);
        }
        check_list.insert("Rain",val);
        mainstring.append(val + " ");
        mainstring.append(parameters.scene);

        if(item->checkState(column) == p){
            selected.remove(mainstring);
            return;
        }
        Qt::CheckState t;
        t=Qt::Checked;
        if(item->checkState(column) == t){
            selected.insert(mainstring);
        }
        ui->btn_pp_scenic_count->setDisabled(true);
        ui->btn_pp_scenic_run->setDisabled(true);
        ui->btn_pp_run_scenario->setEnabled(true);
    }
    check_flag = true;
}

void MainWindow::on_btn_pp_scenic_count_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Count"),tr("Count:"), QLineEdit::Normal,"", &ok);
    if (ok && !text.isEmpty()){
        count = text;
        count1 = text.toInt();
    }
}

void MainWindow::on_btn_pp_scenic_run_clicked()
{
    if(count.isEmpty())
        count = "1";

    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->btn_pp_scenic_run->setDisabled(true);
    ui->btn_pp_scenic_count->setDisabled(true);
    ui->btn_pp_sel_scenario->setDisabled(true);
    ui->btn_pp_showreport->setDisabled(true);

    ui->btn_pp_stop_scenario->setEnabled(true);
    ui->btn_pp_avp->setEnabled(true);

    flagSimulation = true;
    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \n";

    QString testcasepath = par;  //sne
    par.remove(0,1);

    reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";

    // path_planning
    //stream <<"./Poly_Suite/support_files/validate_c.sh &"<<"\n";
    stream <<"./Poly_Suite/support_files/validate_pathplanning.sh &"<<"\n";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        tCase = s.left(scenarioPos);
        QString tmp = tCase+ "_iteration_" + QString::number(scenarioItr);
        stream << "mkdir -p " <<  reportPath + tmp <<" && touch "<<  reportPath + tmp+"/"<<"\n";
        stream << "echo \""<< reportPath + tmp <<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "echo \"Running Scenic\" \n";
        stream << "scenic " + par + s + "   ";
        stream << " --simulate   --model scenic.simulators.lgsvl.model   --time 200   --count " + count + "  " ;
        stream << "--param map " +par +"maps/" + parameters.scene +".xodr   ";
        stream << "--param lgsvl_map " + parameters.scene;

    }

    fp.close();
    selected.clear();
    scenarioItr = 2;
    QString c_path = QDir::currentPath() + "/q_scenic_Activate.sh";
    executeShell(c_path);
    count.clear();
}

void MainWindow::on_btn_pp_run_scenario_clicked()
{
    if(selected.isEmpty())
    {
        QMessageBox msg;
        msg.setText("Please select the scenario!");
        msg.exec();
        return;
    }
    ui->btn_pp_avp->setEnabled(true);
    ui->btn_pp_run_scenario->setDisabled(true);
    ui->btn_pp_stop_scenario->setEnabled(true);
    ui->btn_pp_showreport->setDisabled(true);
    flagSimulation = true;

    curr_DateTime = QDateTime::currentDateTime();
    QString dateTimeString = curr_DateTime.toString("dd_MM_yyyy__hh_mm_ss");
    QString curr_path = QDir::currentPath();
    QFile fp(curr_path + "/test_runner.sh");

    fp.open(QFile::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    fp.setCurrentWriteChannel(0);
    QTextStream stream(&fp);
    stream << "#!/bin/sh \nset -eu\n";

    QString testcasepath = par;
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/";
    //stream <<"./Poly_Suite/support_files/validate_c.sh & \n";

    // path_planning
    stream <<"./Poly_Suite/support_files/validate_pathplannerNode.sh & \n";

    foreach(QString s,selected){
        int scenarioPos = s.indexOf(".");
        QString tCase = s.left(scenarioPos) ;
        stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
        stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
        csv_ReportPath = reportPath + tCase;
        stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
        stream << "python3 ." + testcasepath + s+"\n";
    }
    fp.close();
    selected.clear();

    if(parameters.Script != ""){
        QString c_path = QDir::currentPath() + "/q_scenario_setup.sh " ;
        executeShell(c_path);
    }
}

void MainWindow::on_btn_pp_stop_scenario_clicked()
{
    scenarioItr = 1;
    count1 = 1;
    if(sel_item_clr.isEmpty() == false){
        foreach (QTreeWidgetItem * m, sel_item_clr) {
            m->setCheckState(0,Qt::Unchecked);
        }
    }
    ui->listWid_pp_scene_select->clearSelection();
    ui->btn_pp_initial_pos->setDisabled(true);
    ui->btn_pp_goal_pos->setDisabled(true);
    ui->btn_pp_avp->setDisabled(true);
    ui->btn_pp_run_scenario->setEnabled(true);
    ui->btn_pp_stop_scenario->setDisabled(true);
    ui->btn_pp_run_scenario->setEnabled(false);
    ui->btn_pp_scenic_run->setDisabled(true);
    ui->btn_pp_scenic_count->setDisabled(true);
    ui->btn_pp_showreport->setEnabled(true);
    QString path = QDir::currentPath() + "/stop_scenario.sh";
    executeShell(path);
}

void MainWindow::on_btn_pp_showreport_clicked()
{
    reportwindow *reportwin = new reportwindow;
    reportwin->setModal(this);
    connect( this, SIGNAL(updateUI1Signal(const QString)), reportwin, SLOT(updateUI2TextSlot(const QString) ) );
    connect( this, SIGNAL(seltabSignal(const int)),reportwin, SLOT(seltabSlot(const int) ) );
    emit seltabSignal(3);
    reportwin->exec();
}

void MainWindow::on_btn_pp_avp_clicked()
{
    ui->btn_pp_initial_pos->setEnabled(true);

    ui->btn_pp_avp->setDisabled(true);
    QString c_path = QDir::currentPath() + "/avp_launch.sh";
    executeShell(c_path);
}

void MainWindow::on_btn_pp_initial_pos_clicked()
{
    ui->btn_pp_initial_pos->setDisabled(true);
    ui->btn_pp_goal_pos->setEnabled(true);

    QString c_path = QDir::currentPath() + "/q_initialPos.sh";
    executeShell(c_path);
}

void MainWindow::on_btn_pp_goal_pos_clicked()
{
    ui->btn_pp_goal_pos->setEnabled(false);

    QString c_path = QDir::currentPath() + "/q_goalPos.sh";
    executeShell(c_path);
}
