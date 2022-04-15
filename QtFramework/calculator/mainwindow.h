#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "AchieveEntity.h"

#include "achieve.h"

#include <QClipboard>
#include <QMimeData>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Achieve *achieve = Achieve::getInstance();
    void setConfig(QMap<QString, QString> map);
    void tableInsert(AchieveEntity ae);
    void TableSetHeader();
    void setTable();

    void insertRow();
    void calculateEnd();
    void copyToClipboard();

private slots:
    void btnClick();
    void checkBoxStateChange();

};
#endif // MAINWINDOW_H
