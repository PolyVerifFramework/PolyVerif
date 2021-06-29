#include "reportwindow.h"
#include "ui_reportwindow.h"
#include<QScreen>
#include <QDir>
#include <QDebug>
#include <QProcess>
#include <QStandardItem>
#include <QMessageBox>
#include <mainwindow.h>

reportwindow::reportwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportwindow)
{
    ui->setupUi(this);

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    this->setWindowTitle("Simulation Reports");
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->lbl_d_Auto->setDisabled(true);
    ui->lbl_d_LG->setDisabled(true);
    ui->lbl_d_Succes->setDisabled(true);
    ui->b_showReportC->setDisabled(true);
    ui->b_generateReportC->setDisabled(true);
    ui->label_9->setDisabled(true);
    ui->label_8->setDisabled(true);
    ui->label_7->setDisabled(true);
    ui->label_6->setDisabled(true);
    ui->label_5->setDisabled(true);
    ui->lblBrake->setDisabled(true);
    ui->lblDelayPer->setDisabled(true);
    ui->lblPer->setDisabled(true);
    ui->lblGT->setDisabled(true);

    ui->label_10->setDisabled(true);
    ui->lblSucceRate->setDisabled(true);
    ui->lblRangeAutoware->setDisabled(true);
    ui->lblRangeLGSVL->setDisabled(true);

    movie = new QMovie("spinner.gif");
    ui->tableViewControl->setDisabled(true);

    // Localization
    ui->btn_local_show_report->setDisabled(true);
    ui->btn_local_Gen_Report->setDisabled(true);
    ui->lblD_local_maxDev->setDisabled(true);
    ui->lblD_local_meanDev->setDisabled(true);
    ui->lblD_local_minDev->setDisabled(true);
    ui->lbl_local_heading->setDisabled(true);
    ui->lbl_local_maxDev->setDisabled(true);
    ui->lbl_local_meanDev->setDisabled(true);
    ui->lbl_local_minDev->setDisabled(true);
    ui->tblV_local_DataReport->setDisabled(true);

    // Path Planning
    ui->btn_pp_show_report->setDisabled(true);
    ui->btn_pp_Gen_Report->setDisabled(true);
    ui->lblD_pp_goalPosAchieved->setDisabled(true);
    ui->lblD_pp_collisionCount->setDisabled(true);
    ui->lblD_pp_goalPosDeviation->setDisabled(true);
    ui->lblD_pp_drivableAreaFollowed->setDisabled(true);

    ui->lbl_pp_heading->setDisabled(true);
    ui->lbl_pp_collisionCount->setDisabled(true);
    ui->lbl_pp_goalPosAchieved->setDisabled(true);
    ui->lbl_pp_goalPosDeviation->setDisabled(true);
    ui->lbl_pp_drivableAreaFollowed->setDisabled(true);
    ui->tblV_pp_DataReport->setDisabled(true);

    ui->tabReport->setTabEnabled(0,false);
    ui->tabReport->setTabEnabled(1,false);
    ui->tabReport->setTabEnabled(2,false);
    ui->tabReport->setTabEnabled(3,false);
    ui->tabReport->setTabEnabled(4,false);

    ui->lbl_summry_lbl1->hide();
    ui->lbl_summry_lbl2->hide();
    ui->lblD_summry_lbl1->hide();
    ui->lblD_summry_lbl2->hide();

    TableWidgetDisplay();
}


reportwindow::~reportwindow()
{
    delete movie;
    delete ui;
}

void reportwindow::on_treeWidgetReportDir_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->isExpanded())
    {
        return;
    }

    QTreeWidgetItem *item_ = item->child(column);
    if(item_ != NULL)
    {
        return;
    }

    flag = true;

    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString testCasesDir = curr_path.left(pos) + "/PolyReports";

    simReport = item->text(column);

    QTreeWidgetItem *p2 = item->parent(); // TODO need to andle these pointers it is crashing
    QTreeWidgetItem *p1 = p2->parent();
    QString par= "/"+p1->text(column)+"/"+p2->text(column)+"/";
    p_testCases = "PolyReports" + par + simReport;

    int repPos = curr_path.lastIndexOf(QChar('/'));
    QString reportDir = curr_path.left(repPos);
    QString p = reportDir + "/" + p_testCases;

    QString perceptionParams( p + "/perception_stats.txt");
    QString controlParams( p + "/control_stats.txt");
    QString localizationParams( p + "/localize_stats.txt");
    QString pathplanningParams( p + "/planner_stats.txt");

    if(QFileInfo::exists(perceptionParams) || QFileInfo::exists(controlParams) || QFileInfo::exists(localizationParams) || QFileInfo::exists(pathplanningParams))
    {
        ui->b_generateReportC->setDisabled(true);
        ui->pushButton_2->setDisabled(true);

        ui->b_showReportC->setEnabled(true);
        ui->pushButton_3->setEnabled(true);

        ui->btn_local_Gen_Report->setDisabled(true);
        ui->btn_local_show_report->setEnabled(true);

        ui->btn_pp_Gen_Report->setDisabled(true);
        ui->btn_pp_show_report->setEnabled(true);

    }else{
        QFile file(testCasesDir + "/Validation_report/config1.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {

            QTextStream stream(&file);
            stream << p_testCases;
            file.close();
        }
        ui->pushButton_2->setEnabled(true);
        ui->b_generateReportC->setEnabled(true);

        ui->b_showReportC->setDisabled(true);
        ui->pushButton_3->setDisabled(true);

        ui->btn_local_Gen_Report->setEnabled(true);
        ui->btn_local_show_report->setDisabled(true);

        ui->btn_pp_Gen_Report->setEnabled(true);
        ui->btn_pp_show_report->setDisabled(true);

    }

}

void reportwindow::on_pushButton_clicked()
{
    ui->treeWidgetReportDir->clear();
    QDir reportDir ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString testCasesDir = curr_path.left(pos) + "/PolyReports/Validation_report/";

    reportDir.setPath(testCasesDir);
    bool flag = false;
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidgetReportDir);
    for(const QFileInfo &finfo : reportDir.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;

        if(flag == false)
        {
            root->setText(0,dir.dirName());
            ui->treeWidgetReportDir->addTopLevelItem(root);
            flag = true;

        }
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            root->addChild(child);
            if(finfo.isDir())
            {
                QDir d(finfo.absoluteFilePath());
                for(const QFileInfo &f : d.entryInfoList()){
                    if(f.baseName().isEmpty())
                        continue;
                    QTreeWidgetItem *child2 = new  QTreeWidgetItem();
                    child2->setText(0,f.baseName());
                    child->addChild(child2);
                }

            }
        }
    }
}

void reportwindow::on_b_generateReportC_clicked()
{
    ui->b_generateReportC->setDisabled(true);
    ui->lblRSpinner->setMovie(movie);
    ui->lblRSpinner->show();
    movie->start();

    ui->b_showReportC->setEnabled(true);
    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_control_val_script.sh";
    executeShell(path);
}

void reportwindow::executeShell(QString path){
    QProcess *process = new QProcess();
    process->execute(path);
    process->waitForFinished(200);
    delete process;
}


void reportwindow::on_b_showReportC_clicked()
{
    TableWidgetDisplay();
    ui->b_showReportC->setDisabled(true);
    ui->label_9->setDisabled(false);
    ui->label_8->setDisabled(false);
    ui->label_7->setDisabled(false);
    ui->label_6->setDisabled(false);
    ui->label_5->setDisabled(false);
    ui->lblBrake->setDisabled(false);
    ui->lblDelayPer->setDisabled(false);
    ui->lblPer->setDisabled(false);
    ui->lblGT->setDisabled(false);
    ui->tableViewControl->setEnabled(false);
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);


    QString txtreport = rp_filepath + "/" + p_testCases + "/control_stats.txt";
    QString rData[4];
    QFile txtfile(txtreport);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        ui->lblGT->setText("0");
        ui->lblPer->setText("0");
        ui->lblDelayPer->setText("0");
        ui->lblBrake->setText("0");
    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] =line;
        }
        txtfile.close();
        ui->lblGT->setText(rData[0]);
        ui->lblPer->setText(rData[1]);
        ui->lblDelayPer->setText(rData[2]);
        ui->lblBrake->setText(rData[3]);
    }
}

void reportwindow::updateUI2TextSlot( const QString text )
{
    movie->stop();
    ui->lblRSpinner->clear();
    ui->lblRSpinnerPerception->clear();

    if(flag == true){
        flag = false;
        QMessageBox messageBox;
        messageBox.setText("Report Generated, Click on Show Report");
        messageBox.setFixedSize(500,200);
        messageBox.exec();

    }

}

void reportwindow::seltabSlot( const int tab ){

    ui->tabReport->setTabEnabled(4,true);
    if(tab == 0)
    {
        ui->tabReport->setTabEnabled(1,false);
        ui->tabReport->setTabEnabled(2,false);
        ui->tabReport->setTabEnabled(3,false);
        ui->tabReport->setTabEnabled(0,true);
    }

    if(tab == 1){
        ui->tabReport->setTabEnabled(0,false);
        ui->tabReport->setTabEnabled(2,false);
        ui->tabReport->setTabEnabled(3,false);
        ui->tabReport->setTabEnabled(1,true);

    }

    if(tab == 2){
        ui->tabReport->setTabEnabled(0,false);
        ui->tabReport->setTabEnabled(1,false);
        ui->tabReport->setTabEnabled(3,false);
        ui->tabReport->setTabEnabled(2,true);

    }

    if(tab == 3){
        ui->tabReport->setTabEnabled(0,false);
        ui->tabReport->setTabEnabled(1,false);
        ui->tabReport->setTabEnabled(2,false);
        ui->tabReport->setTabEnabled(3,true);

    }
}

void reportwindow::on_pushButton_2_clicked()
{
    ui->lblRSpinnerPerception->setMovie(movie);
    ui->lblRSpinnerPerception->show();
    movie->start();

    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_perception_val_script.sh";
    executeShell(path);
    ui->pushButton_3->setEnabled(true);
    ui->b_showReportC->setEnabled(true);
    ui->pushButton_2->setDisabled(true);
}

void reportwindow::on_pushButton_3_clicked()   //perception
{
    TableWidgetDisplay();
    ui->label_10->setEnabled(true);
    ui->lblSucceRate->setEnabled(true);
    ui->lblRangeAutoware->setEnabled(true);
    ui->lblRangeLGSVL->setEnabled(true);

    ui->pushButton_3->setDisabled(true);

    ui->lbl_d_Auto->setDisabled(false);
    ui->lbl_d_LG->setDisabled(false);
    ui->lbl_d_Succes->setDisabled(false);
    ui->tableView->setEnabled(true);

    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);
    QStandardItemModel *model;
    model = new QStandardItemModel;
    QString rfile = rp_filepath + "/" + p_testCases + "/rangeReport.csv";
    QFile file(rfile);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QList<QStandardItem *> standardItemsList;
            for (QString item : line.split(",")) {
                standardItemsList.append(new QStandardItem(item));
            }
            model->insertRow(model->rowCount(), standardItemsList);
        }
        file.close();
    }

    ui->tableView->setModel(model);

    QString txtreport = rp_filepath + "/" + p_testCases + "/perception_stats.txt";
    QString rData[4];
    QFile txtfile(txtreport);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        ui->lblSucceRate->setText("NA");
        ui->lblRangeLGSVL->setText("NA");
        ui->lblRangeAutoware->setText("NA");
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
            }
        }
        ui->lblSucceRate->setText(rData[2]);
        ui->lblRangeLGSVL->setText(rData[1]);
        ui->lblRangeAutoware->setText(rData[0]);
    }
}

void reportwindow::on_btn_local_Gen_Report_clicked()
{
    ui->btn_local_Gen_Report->setDisabled(true);
    ui->lbl_SpinnerLocalization->setMovie(movie);
    ui->lbl_SpinnerLocalization->show();
    movie->start();

    ui->btn_local_show_report->setEnabled(true);
    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_localization_validation.sh";
    executeShell(path);
}

void reportwindow::on_btn_local_show_report_clicked()
{
    TableWidgetDisplay();
    ui->btn_local_show_report->setDisabled(true);
    ui->lblD_local_maxDev->setDisabled(false);
    ui->lblD_local_meanDev->setDisabled(false);
    ui->lblD_local_minDev->setDisabled(false);
    ui->lbl_local_heading->setDisabled(false);
    ui->lbl_local_maxDev->setDisabled(false);
    ui->lbl_local_meanDev->setDisabled(false);
    ui->lbl_local_minDev->setDisabled(false);
    ui->tblV_local_DataReport->setEnabled(false);
    ui->lbl_SpinnerLocalization->setDisabled(true);
    ui->lbl_SpinnerLocalization->hide();

    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);

    QString txtreport = rp_filepath + "/" + p_testCases + "/localize_stats.txt";
    QString rData[4];
    QFile txtfile(txtreport);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        ui->lblD_local_maxDev->setText("NA");
        ui->lblD_local_minDev->setText("NA");
        ui->lblD_local_minDev->setText("NA");
    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] =line;
        }
        txtfile.close();
        ui->lblD_local_maxDev->setText(rData[0]);
        ui->lblD_local_minDev->setText(rData[1]);
        ui->lblD_local_meanDev->setText(rData[2]);
    }
}

void reportwindow::on_btn_pp_Gen_Report_clicked()
{
    ui->btn_pp_Gen_Report->setDisabled(true);
    ui->lbl_pp_spinnerPathPlanning->setMovie(movie);
    ui->lbl_pp_spinnerPathPlanning->show();
    movie->start();

    ui->btn_pp_show_report->setEnabled(true);
    QString curr_path = QDir::currentPath();
    QString path = curr_path + "/q_path_planning_validation.sh";
    executeShell(path);
}

void reportwindow::on_btn_pp_show_report_clicked()
{
    TableWidgetDisplay();
    ui->btn_pp_show_report->setDisabled(true);
    ui->lblD_pp_collisionCount->setDisabled(false);
    ui->lblD_pp_goalPosAchieved->setDisabled(false);
    ui->lblD_pp_goalPosDeviation->setDisabled(false);
    ui->lblD_pp_drivableAreaFollowed->setDisabled(false);

    ui->lbl_pp_heading->setDisabled(false);
    ui->lbl_pp_collisionCount->setDisabled(false);
    ui->lbl_pp_goalPosAchieved->setDisabled(false);
    ui->lbl_pp_goalPosDeviation->setDisabled(false);
    ui->lbl_pp_drivableAreaFollowed->setDisabled(false);

    ui->tblV_pp_DataReport->setEnabled(false);
    ui->lbl_pp_spinnerPathPlanning->setDisabled(true);
    ui->lbl_pp_spinnerPathPlanning->hide();

    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString rp_filepath = curr_path.left(pos);

    // path_planning
    QString txtreport = rp_filepath + "/" + p_testCases + "/planner_stats.txt";
    QString collisionCount = rp_filepath + "/" + "PolyReports/Validation_report/collisionCount.txt";
    QString rData[4];
    QFile txtfile(txtreport);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        ui->lblD_pp_collisionCount->setText("NA");
        ui->lblD_pp_goalPosAchieved->setText("NA");
        ui->lblD_pp_goalPosDeviation->setText("NA");
        ui->lblD_pp_drivableAreaFollowed->setText("NA");

    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] =line;
        }
        txtfile.close();
        ui->lblD_pp_goalPosAchieved->setText(rData[1]);
        ui->lblD_pp_goalPosDeviation->setText(rData[0]);

        QString cData[2];
        cData[0] = "0";
        QFile txtfileCollision(collisionCount);
        if (txtfileCollision.open(QFile::ReadOnly | QFile::Text) ){
            QTextStream inn(&txtfileCollision);
            while (!inn.atEnd())
            {
                QString line = inn.readLine();
                cData[0] = line;
            }
            txtfile.close();
        }

        ui->lblD_pp_collisionCount->setText(cData[0]);
       // ui->lblD_pp_collisionCount->setText("0");  //Hard coded
        ui->lblD_pp_drivableAreaFollowed->setText(rData[3]);

    }
}


void reportwindow::TableWidgetDisplay(){

    QString testCasesDir1 = QDir::currentPath().left(QDir::currentPath().lastIndexOf(QChar('/'))) + "/PolyReports/Validation_report/";

    int count = QDir(testCasesDir1).entryList(QDir::AllDirs | QDir::NoDotAndDotDot).count();

    ui->tableWidSummary->clear();

    ui->tableWidSummary->setRowCount(count);
    ui->tableWidSummary->setColumnCount(4);

    QStringList hLables;

    hLables << "Date-Time" << "Name" << "Validation Type" << "Status";
    ui->tableWidSummary->setHorizontalHeaderLabels(hLables);
    ui->tableWidSummary->setAlternatingRowColors(true);
    ui->tableWidSummary->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidSummary->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidSummary->setTextElideMode(Qt::ElideRight);

    ui->tableWidSummary->setShowGrid(true);
    ui->tableWidSummary->setGridStyle(Qt::DotLine);

    ui->tableWidSummary->horizontalHeader()->setVisible(true);
    ui->tableWidSummary->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableWidSummary->horizontalHeader()->setStretchLastSection(true);
    /////////////////////////////

    QDir reportDir ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString testCasesDir = curr_path.left(pos) + "/PolyReports/Validation_report/";

    reportDir.setPath(testCasesDir);

    bool flag = false;
    QTableWidgetItem *item;// = new QTableWidgetItem(ui->tableWidSummary);

    int i = 0;
    for(const QFileInfo &finfo : reportDir.entryInfoList()){
        if(finfo.fileName().contains(".."))
            continue;
        QDir dir(finfo.absoluteFilePath());

        if(finfo.isDir() == false)
            continue;

        if(flag == false)
        {
            flag = true;
        }
        else
        {
            if(finfo.isDir())
            {
                QDir d(finfo.absoluteFilePath());
                for(const QFileInfo &f : d.entryInfoList()){
                    if(f.baseName().isEmpty())
                        continue;

                    bool simStatus = false;
                    for(int j=0; j<4; j++){
                        item = new QTableWidgetItem;
                        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
                        if(j == 0)
                            item->setText(dir.dirName());
                        if(j == 1)
                            item->setText(f.baseName());
                        if(j == 2){
                            QString p_testCases = testCasesDir + dir.dirName()+ "/" + f.baseName();
                            QString perceptionParams( p_testCases + "/perception_stats.txt");
                            QString controlParams( p_testCases + "/control_stats.txt");
                            QString localizationParams( p_testCases + "/localize_stats.txt");
                            QString pathplanningParams( p_testCases + "/planner_stats.txt");

                            if(QFileInfo::exists(pathplanningParams)){
                                simStatus = PlannerStatsFileRead(pathplanningParams);
                                item->setText("Planner");

                            }else if(QFileInfo::exists(localizationParams)){
                                simStatus = LocalizationStatsFileRead(localizationParams);
                                item->setText("Localization");

                            }else if(QFileInfo::exists(perceptionParams)){
                                simStatus = PerceptionStatsFileRead(perceptionParams);
                                item->setText("Detection");

                            }else if(QFileInfo::exists(controlParams)){
                                simStatus = ControlStatsFileRead(controlParams);
                                item->setText("Control");


                            }else{
                                simStatus = false;
                                item->setText("Stats Not Availabe");
                            }
                        }
                        if(j == 3){
                            if(simStatus){
                                item->setText("Success");
                            }else{
                                item->setText("Failed");
                            }

                        }
                        ui->tableWidSummary->setItem(i,j,item);
                    }

                    if(simStatus){
                        ui->tableWidSummary->item(i, 3)->setBackground(Qt::green);
                    }else{
                        ui->tableWidSummary->item(i, 3)->setBackground(Qt::red);
                    }

                }

            }
            i++;
        }
    }
}

void reportwindow::on_tableWidSummary_clicked(const QModelIndex &index)
{
    statsData[0] = "0";
    statsData[1] = "1";
    statsData[2] = "2";
    statsData[3] = "3";

    QString valType = "";

    QTableWidgetItem *cellItem = ui->tableWidSummary->item(index.row(), 2);
    if (cellItem == 0)
        return;

    QString statsFile = "";
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString testCasesDir = curr_path.left(pos) + "/PolyReports/Validation_report/";

    valType = ui->tableWidSummary->item(index.row(), 2)->text();
    ui->lbl_summry_lbl1->show();
    ui->lbl_summry_lbl2->show();
    ui->lblD_summry_lbl1->show();
    ui->lblD_summry_lbl2->show();

    if(valType == "Detection"){
        statsFile = testCasesDir + "/" + ui->tableWidSummary->item(index.row(), 0)->text() + "/" + ui->tableWidSummary->item(index.row(), 1)->text();
        QString perceptionParams( statsFile + "/perception_stats.txt");
        PerceptionStatsFileRead(perceptionParams);

        ui->lbl_analysis->setText("Detection Validation");
        ui->lbl_analysis->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl1->setText("Success Rate(%)");
        ui->lbl_summry_lbl1->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl2->setText("Detection Range(meters)");
        ui->lbl_summry_lbl2->setStyleSheet("font-weight: bold; color: black");

        ui->lblD_summry_lbl1->setText(statsData[2]);
        ui->lblD_summry_lbl2->setText(statsData[0]);



    }else if(valType == "Control"){
        statsFile = testCasesDir + "/" + ui->tableWidSummary->item(index.row(), 0)->text() + "/" + ui->tableWidSummary->item(index.row(), 1)->text();
        QString controlParams( statsFile + "/control_stats.txt");
        ControlStatsFileRead(controlParams);

        ui->lbl_analysis->setStyleSheet("font-weight: bold; color: black");
        ui->lbl_analysis->setText("Control Validation");

        ui->lbl_summry_lbl1->setText("Delay in Response Time(sec)");
        ui->lbl_summry_lbl1->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl2->setText("Brake Applied");
        ui->lbl_summry_lbl2->setStyleSheet("font-weight: bold; color: black");

        ui->lblD_summry_lbl1->setText(statsData[2]);
        ui->lblD_summry_lbl2->setText(statsData[3]);


    }else if(valType == "Localization"){
        statsFile = testCasesDir + "/" + ui->tableWidSummary->item(index.row(), 0)->text() + "/" + ui->tableWidSummary->item(index.row(), 1)->text();
        QString localizationParams( statsFile + "/localize_stats.txt");
        LocalizationStatsFileRead(localizationParams);

        ui->lbl_analysis->setStyleSheet("font-weight: bold; color: black");
        ui->lbl_analysis->setText("Localization Validation");

        ui->lbl_summry_lbl1->setText("Mininum Deviation(meters)");
        ui->lbl_summry_lbl1->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl2->setText("Mean Deviation(meters)");
        ui->lbl_summry_lbl2->setStyleSheet("font-weight: bold; color: black");


        ui->lblD_summry_lbl1->setText(statsData[1]);
        ui->lblD_summry_lbl2->setText(statsData[2]);


    }else if(valType == "Planner"){
        statsFile = testCasesDir + "/" + ui->tableWidSummary->item(index.row(), 0)->text() + "/" + ui->tableWidSummary->item(index.row(), 1)->text();
        QString pathplanningParams( statsFile + "/planner_stats.txt");
        PlannerStatsFileRead(pathplanningParams);

        ui->lbl_analysis->setStyleSheet("font-weight: bold; color: black");
        ui->lbl_analysis->setText("Planner Validation");

        ui->lbl_summry_lbl1->setText("Destination Reached");
        ui->lbl_summry_lbl1->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl2->setText("Collision");
        ui->lbl_summry_lbl2->setStyleSheet("font-weight: bold; color: black");

        ui->lblD_summry_lbl1->setText(statsData[1]);
        ui->lblD_summry_lbl2->setText(statsData[2]);

    }else{
        ui->lbl_analysis->setStyleSheet("font-weight: bold; color: black");
        ui->lbl_analysis->setText("Analysis");

        ui->lbl_summry_lbl1->setText("Data Field 1");
        ui->lbl_summry_lbl1->hide();
        ui->lbl_summry_lbl1->setStyleSheet("font-weight: bold; color: black");

        ui->lbl_summry_lbl2->setText("Data Field 2");
        ui->lbl_summry_lbl2->hide();
        ui->lbl_summry_lbl2->setStyleSheet("font-weight: bold; color: black");

        ui->lblD_summry_lbl1->hide();
        ui->lblD_summry_lbl2->hide();
    }
}

bool reportwindow::PlannerStatsFileRead(QString file_name){
    QString rData[4];
    QFile txtfile(file_name);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return false;

    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] = line;
        }
        txtfile.close();

        statsData[0] = rData[0];
        statsData[1] = rData[1]; // Destination reached
        statsData[2] = rData[2];


        if(rData[1] == "True"){
            return true;
        }else{
            return false;
        }
    }
}

bool reportwindow::ControlStatsFileRead(QString file_name){
    QString rData[4];
    QFile txtfile(file_name);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return false;

    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] = line;
        }
        txtfile.close();
        statsData[0] = rData[0];
        statsData[1] = rData[1];
        statsData[2] = rData[2];
        statsData[3] = rData[3]; // brake applied

        if(rData[3] == "True"){
//            return true;        // Hard code
            return false;

        }else{
            return false;
        }
    }
}

bool reportwindow::PerceptionStatsFileRead(QString file_name){
    QString rData[4];
    QFile txtfile(file_name);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return false;

    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] = line;
        }
        txtfile.close();
        statsData[0] = rData[0];
        statsData[1] = rData[1];
        statsData[2] = rData[2];
        statsData[3] = rData[3];

        // TODO need to read from the config file
        int detectionThresold = 40;
        if(rData[2].toFloat() > detectionThresold){
            return true;
        }else{
            return false;
        }

    }
}

bool reportwindow::LocalizationStatsFileRead(QString file_name){
    QString rData[4];
    QFile txtfile(file_name);
    if ( !txtfile.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return false;

    } else {
        QTextStream in(&txtfile);
        int i=0;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            rData[i++] = line;
        }
        txtfile.close();
        statsData[0] = rData[0];
        statsData[1] = rData[1];
        statsData[2] = rData[2];

        // TODO need to read from the config file
        int minDevThresold = 1;
        int maxDevThresold = 5;


        if(rData[0].toFloat() < maxDevThresold){
            return true;
        }else{
            return false;
        }

    }
}

