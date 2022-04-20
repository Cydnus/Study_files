#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon("qrc:/Icon/i15952174095.ico"));
    w.show();
    return a.exec();
}
