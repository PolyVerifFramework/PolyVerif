#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>
#include <QTreeWidgetItem>
namespace Ui {
class reportwindow;
}

class reportwindow : public QDialog
{
    Q_OBJECT

public:
    explicit reportwindow(QWidget *parent = 0);
    ~reportwindow();

private slots:

    void on_treeWidgetReportDir_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();

private:
    Ui::reportwindow *ui;
};

#endif // REPORTWINDOW_H
