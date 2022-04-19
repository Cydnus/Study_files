#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "AchieveEntity.h"

#include "achieve.h"

#include <QClipboard>
#include <QMimeData>
#include <QPainter>
#include <QLocale>


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
    QMetaObject::Connection tableConnect;

    QMap<QString, QString> conf;
    Achieve *achieve = Achieve::getInstance();
    void setConfig();
    void tableInsert(AchieveEntity ae);
    void setTableHeader();
    void setTableBody();
    void insertRow();
    void calculateEnd();
    void copyToClipboard();

private slots:
    void btnClick();
    void checkBoxStateChange();
    void cellChanged(int row, int col);

};
#endif // MAINWINDOW_H
