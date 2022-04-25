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
    else if(btnClick == btns["load"])
        btnLoad();
    else if(btnClick == btns["reset"])
        btnReset();
    else if(btnClick == btns["confirm"])
        btnConfirm();
    else
        macroBtnClick(btnClick);

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
    port->write("\n");

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
    QByteArray ba;
    /*
    QString str;
    str+=(char)0xc0;
    str+=(char)0xf0;
    str+= (char) 0x00;
    str+=(char)0xc0;
    */

    ba.append((char)0xc0);
    ba.append((char)0xf0);
    ba.append((char)0x00);
    ba.append((char)0xc0);

    //port->write(str.toStdString().c_str());
    port->write(ba);
    port->write("\n");
}

void MainWindow::serialReceived()
{
    QByteArray received;

    while(port->canReadLine())
    {
        received = port->readLine();
    }
    received.replace("\n","");

    int size = received.size();
    qDebug()<<received;
    //qDebug()<<received[0]<<"\t"<<received[size-1];


    if(received[0] == (char)0xc0 && received[size-1] == (char)0xc0 )
    {
        int op = 1;
        int opr_head = op+1;

        for(int i = 0; i < 15 && op < size-1; i++)
        {
            if(i == 12)
                continue;
            int opc = received[op];
            int opr_size = received[opr_head];
            for(int j = 1; j<=opr_size; j++)
            {
                macro[opc].push_back((uint8_t)received[opr_head+j]);
            }
            op = opr_size+opr_head+1;
            opr_head = op+1;
            qDebug()<<op<<"\t"<<opr_head;
        }
    }
}

void MainWindow::setListView(int no)
{
    QStringListModel *model = new QStringListModel(this);
    QStringList strlist;
    ui->lvMapping->reset();

    strlist.clear();

    foreach( int a, macro[no])
    {
        if( a > 127)
            strlist.push_back(KeyMap[a]);
        else
            strlist.push_back(QString((char)a));
    }
    model->setStringList(strlist);
    ui->lvMapping->setModel(model);
}

void MainWindow::macroBtnClick(QPushButton* btn)
{
    int btnName = btn->objectName().sliced(3,2).toInt();
    qDebug()<<btnName;
    setListView(btnName);

}

void MainWindow::btnReset()
{

}

void MainWindow::btnConfirm()
{

}


MainWindow::~MainWindow()
{
    if(port != nullptr && port->isOpen())
        port->close();

    delete ui;
}

