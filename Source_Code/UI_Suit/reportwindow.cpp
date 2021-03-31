#include "reportwindow.h"
#include "ui_reportwindow.h"
#include<QScreen>
#include <QDir>


reportwindow::reportwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportwindow)
{
    ui->setupUi(this);

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    this->setWindowTitle("Simulation Reports");
}

reportwindow::~reportwindow()
{
    delete ui;

}

void reportwindow::on_treeWidgetReportDir_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->treeWidgetReportDir->clear();
    //static bool flag1 = true;

}


void reportwindow::on_pushButton_clicked()
{
    QDir reportDir ;
    QString curr_path = QDir::currentPath();
    int pos = curr_path.lastIndexOf(QChar('/'));
    QString p_testCases = curr_path.left(pos) + "/PolyReports/Validation_report";
   // qDebug() << "new path : " + p_testCases;
    reportDir.setPath(p_testCases);
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
           // qDebug() << "In main dir : " << root->text(0) ;
            ui->treeWidgetReportDir->addTopLevelItem(root);
            flag = true;
        }
        else
        {
            QTreeWidgetItem *child = new  QTreeWidgetItem();
            child->setText(0,dir.dirName());
            root->addChild(child);

        }
    }
}
