#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "AchieveEntity.h"

#include "achieve.h"

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

    void insertRow();

    void tableInsert(AchieveEntity ae);

private slots:
    void btnClick();

};
#endif // MAINWINDOW_H
