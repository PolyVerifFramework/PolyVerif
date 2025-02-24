    // if(selected.isEmpty())
    // {
    //     QMessageBox msg;
    //     msg.setText("Please select the scenario!");
    //     msg.exec();
    //     return;
    // }
    ui->avp_button->setEnabled(true);
    ui->treeWidget->setDisabled(true);

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
    QString testcasepath = par;
    qDebug()<<"testcasepath:"<<testcasepath;
    QString reportPath = "PolyReports/Validation_report/" + dateTimeString + "/Detection" + "/";

    stream <<"./Poly_Suite/support_files/validate_p.sh &"<<"\n"<<"ls \n";

    // foreach(QString s,selected){
    //     int scenarioPos = s.indexOf(".");
    //     QString tCase = s.left(scenarioPos);
    //     stream << "mkdir -p " << reportPath + tCase <<" && touch "<<reportPath + tCase+"/"<<"\n";
    //     stream << "echo \""<< reportPath + tCase<<" \" > PolyReports/Validation_report/config.txt; \n";
    //     csv_ReportPath = reportPath + tCase;
    //     stream << "echo \"Running Scenario :" << testcasepath +s<<" \" > ./Poly_Suite/logfiles/logInfo.txt; \n";
    //     stream << "python3 ." + testcasepath + s+"\n";
    // }
    stream << "mkdir -p " << reportPath<<" && touch "<<reportPath <<"\n";
    stream << "echo \""<< reportPath <<" \" > PolyReports/Validation_report/config.txt; \n";

    stream <<"./Poly_Suite/support_files/engage.sh"<<"\n";
    qDebug()<<"reportPath"<<reportPath;
    csv_ReportPath = reportPath;
    fp.close();
    selected.clear();

    //if(parameters.Script != ""){
    QString c_path = QDir::currentPath() + "/q_scenario_setup.sh";
    executeShell(c_path);
    // }

    ui->b_run_scenario->setDisabled(true);
    ui->b_stop_scenario->setEnabled(true);