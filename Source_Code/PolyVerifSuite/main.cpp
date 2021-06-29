#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // a.styleSheet("QTabWidget{color : blue ; background-color : green}");
    QSplashScreen *splashs = new QSplashScreen;
    splashs->setPixmap(QPixmap(":/splash/AV_Testing.jpg"));
    a.setWindowIcon(QIcon(":/wall/logo.png"));
    splashs->show();
    splashs->showMessage("Module Loading...",Qt::AlignBottom,Qt::white);
    MainWindow w;
    QTimer::singleShot(5000,splashs,SLOT(close()));
    QTimer::singleShot(5000,&w,SLOT(show()));

    return a.exec();
}
