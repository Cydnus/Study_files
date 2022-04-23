#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
    {
        ui->cbCom->addItem(info.portName());
    }

    mappingButtons();
    connection();
}

void MainWindow::mappingButtons()
{
    btns["connect"] = ui->btnConnect;
    btns["load"] = ui->btnLoad;

    btns["btn00"] = ui->btn00;
    btns["btn01"] = ui->btn01;
    btns["btn02"] = ui->btn02;
    btns["btn03"] = ui->btn03;
    btns["btn04"] = ui->btn04;
    btns["btn05"] = ui->btn05;
    btns["btn06"] = ui->btn06;
    btns["btn07"] = ui->btn07;
    btns["btn08"] = ui->btn08;
    btns["btn09"] = ui->btn09;
    btns["btn10"] = ui->btn10;
    btns["btn11"] = ui->btn11;
    btns["btn13"] = ui->btn13;
    btns["btn14"] = ui->btn14;

    btns["reset"] = ui->btnReset;
    btns["confirm"] = ui->btnConfirm;

}

void MainWindow::connection()
{
    for(auto i = btns.begin(); i!=btns.end(); i++)
    {
        conns[ i->first ] = connect(i->second,SIGNAL(clicked()),this, SLOT(btnClick()));
    }
}

void MainWindow::btnClick()
{
    QPushButton* btnClick = (QPushButton*)sender();

    qDebug()<<btnClick->objectName();

    if(btnClick == btns["connect"])
    {
        if(btnClick->text() == "Connect")
            serialConenct();
        else
            serialDisconenct();
    }
    if(btnClick == btns["load"])
        btnLoad();
}

void MainWindow::serialConenct()
{
    port = new QSerialPort(this);
    port->setPortName(ui->cbCom->currentText());
    port->setBaudRate(QSerialPort::Baud19200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if(!port->open(QIODevice::ReadWrite))
    {
        qDebug()<<"Failed to open";
        return;
    }
    btns["connect"]->setText("Disconnect");
    ui->cbCom->setEnabled(false);

    conns["port"] = connect(port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    for(auto i = btns.begin(); i!=btns.end(); i++)
    {
        i->second->setEnabled(true);
    }
    btnLoad();
}
void MainWindow::serialDisconenct()
{
    if(port->isOpen())
    {
        disconnect(conns["port"]);
        port->close();
    }
    ui->cbCom->setEnabled(true);

    for(auto i = btns.begin(); i!=btns.end(); i++)
    {
        i->second->setEnabled(false);
    }
    btns["connect"]->setEnabled(true);
    btns["connect"]->setText("Connect");

}

void MainWindow::btnLoad()
{
    qDebug()<<"load";
    port->write("50");
}

void MainWindow::serialReceived()
{
    QString received;

    while(port->canReadLine())
    {
        received = port->readLine();
        qDebug()<<received;
    }

}


MainWindow::~MainWindow()
{
    if(port->isOpen())
        port->close();

    delete ui;
}

