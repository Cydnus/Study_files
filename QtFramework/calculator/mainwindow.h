#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "AchieveEntity.h"

#include "achieve.h"
#include "utilitys.h"

#include <QClipboard>
#include <QMimeData>
#include <QPainter>
#include <QLocale>
#include <QKeyEvent>
#include <QMessageBox>


#define MODE_RELEASE    1
// 1 : Release Mode
// other : Minimum size release or debug

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
    void setTable();
    void insertRow();
    void calculateEnd();
    void copyToClipboard();
    void setTableSomeRow(int, uint64_t,uint64_t, QString);
    void keyPressEvent(QKeyEvent *event);

    void selectCheck();

    bool eventFilter(QObject *watched, QEvent *event);


private slots:
    void btnClick();
    void checkBoxStateChange(bool);
    void cellChanged(int row, int col);

};
#endif // MAINWINDOW_H
