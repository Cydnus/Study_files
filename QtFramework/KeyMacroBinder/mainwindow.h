#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QPushButton>
#include <QStringListModel>
#include <map>
#include "convert.h"

using namespace std;

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
    QSerialPort *port;

    map<string, QPushButton*> btns;

    map<string, QMetaObject::Connection> conns;
    map<int,vector<int>> macro;

    int nowListOfBtn;


    void mappingButtons();
    void connection();

    void serialConenct();
    void serialDisconenct();
    void macroBtnClick(QPushButton*);
    void btnReset();
    void btnConfirm();
    void btnLoad();

    void setListView(int);


private slots:
    void btnClick();
    void serialReceived();
    void listAdd();
};


#endif // MAINWINDOW_H
