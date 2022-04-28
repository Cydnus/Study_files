#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lvMapping->setContextMenuPolicy(Qt::ActionsContextMenu);

    this->setWindowTitle("KeyBoard Macro Binder");

    QAction *actionAdd = new QAction("추가" , ui->lvMapping);
    QAction *actionDelete = new QAction("삭제" , ui->lvMapping);

    connect(actionAdd, SIGNAL(triggered()),this,SLOT(listAdd()));
    connect(actionDelete, SIGNAL(triggered()),this,SLOT(listDelete()));

    ui->lvMapping->addAction(actionAdd);
    ui->lvMapping->addAction(actionDelete);

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

    //qDebug()<<btnClick->objectName();

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
        //qDebug()<<"Failed to open";
        return;
    }
    btns["connect"]->setText("Disconnect");
    ui->cbCom->setEnabled(false);

    conns["port"] = connect(port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    port->write(0x00);


    for(auto i = btns.begin(); i!=btns.end(); i++)
    {
        i->second->setEnabled(true);
    }
    ui->lvMapping->setEnabled(true);

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
    ui->lvMapping->setEnabled(false);
    btns["connect"]->setEnabled(true);
    btns["connect"]->setText("Connect");

}

void MainWindow::btnLoad()
{
    //qDebug()<<"load";
    QByteArray ba;
    /*
    QString str;
    str+=(char)0xc0;
    str+=(char)0xf0;
    str+= (char) 0x00;
    str+=(char)0xc0;
    */

    ba.append((char)0xc0);
    ba.append((char)0xA0);
    ba.append((char)0x80);
    ba.append((char)0xc0);

  //  ba.append((char)0x0D);
  //  ba.append((char)0x0A);

    //port->write(str.toStdString().c_str());
    port->write(ba);
    qDebug()<<"Serial wirte : >>"<<ba;

}

void MainWindow::serialReceived()
{
    QByteArray received;

    while(port->bytesAvailable() > 0)
    {
        QByteArray temp = port->read(1);
        if( temp == "\n" || temp == "\r")
            continue;
        received +=temp;
    }
    qDebug()<<"Serial input : >>"<<received;

    received.replace("\r\n","");

    int size = received.size();
    //qDebug()<<received[0]<<"\t"<<received[size-1];

    if( size < 2)
        return;

    if(received[0] == (char)0xc0 && received[size-1] == (char)0xc0 )
    {
        if((received[1] & 0xf0) == 0xA0)
        {
            macro.clear();

            int op = 2;

            for(int i = 0; i < 15 || op < size -1; i++)
            {
                if(i == 12)
                    continue;
                uint8_t opc = (uint8_t)received[op] & 0x7f;
                int j = 1;
                while(received[op+j] != (char)0xff)
                {
                    macro[opc].push_back((uint8_t)received[op+j]);
                    j++;
                }
                op = op + j + 1;
                qDebug()<<op;
            }
            if(ui->lblNowList->text() != "")
                setListView(ui->lblNowList->text().mid(3,2).toInt());
        }
        else if((received[1] & 0xf0) == 0x30)
        {
            QMessageBox::information(this,"저장완료", "설정이 저장되었습니다.");
            qDebug()<<"Insert Clear";
            qDebug()<<received;
        }
    }
    else
    {
        QMessageBox::information(this,"로딩 실패", "다시 로딩해 주시기 바랍니다.");
        port->flush();
    }
}

void MainWindow::setListView(int no)
{
    QStringListModel *model = new QStringListModel(this);
    QStringList strlist;
    ui->lvMapping->reset();

    strlist.clear();

    for(int a : macro[no])
    {
        strlist.push_back(Convert::getInstance()->getKeyString(a));
    }
    model->setStringList(strlist);
    ui->lvMapping->setModel(model);
}

void MainWindow::macroBtnClick(QPushButton* btn)
{
    int btnName = btn->objectName().sliced(3,2).toInt();
    //qDebug()<<btnName;
    setListView(btnName);
    ui->lblNowList->setText(btn->text());
}

void MainWindow::btnReset()
{
    int no = ui->lblNowList->text().mid(3,2).toInt();
    //qDebug()<<no;
    setListView(no);
}

void MainWindow::btnConfirm()
{
    QByteArray ba;
    ba.append(0xc0);
    int no = ui->lblNowList->text().mid(3,2).toInt();
    ba.append((char)no | 0x30);

    QStringListModel *model = (QStringListModel *)ui->lvMapping->model();
    QStringList strlist = model->stringList();

     macro[no].clear();
    foreach(QString str, strlist)
    {
        // str->index
        //qDebug()<<str;
        int code = Convert::getInstance()->getKeyCode(str);
        ba.append((char)code );
        macro[no].push_back(code);
    }
    ba.append(0xff);
    ba.append(0xc0);
   // ba.append(0x0a);

    qDebug()<<ba;

    port->write(ba);


}
void MainWindow::listAdd()
{    
    //qDebug()<<"insert";
    InsertDialog *dlg = new InsertDialog(this);
    dlg->setModal(true);
    dlg->exec();
}
void MainWindow::insertDialogmsg(QString str)
{
    //qDebug()<<str;

    int no = ui->lblNowList->text().mid(3,2).toInt();
    macro[no].push_back(Convert::getInstance()->getKeyCode(str));
    QStringListModel *model = (QStringListModel *)ui->lvMapping->model();
    QStringList strlist = model->stringList();
    strlist.push_back(str);
    model->setStringList(strlist);

}

void MainWindow::listDelete()
{
    if(ui->lvMapping->selectionModel()==nullptr)
        return;

    vector<int> list;

    foreach(const QModelIndex &index, ui->lvMapping->selectionModel()->selectedIndexes())
        list.push_back(index.row());

    QStringListModel *model = (QStringListModel *)ui->lvMapping->model();
    QStringList strlist = model->stringList();

    sort(list.begin(),list.end(),[](int a,int b){return a>b;});
    //qDebug()<<list;

    foreach(int ind, list)
    {
        strlist.removeAt(ind);
    }

    model->setStringList(strlist);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if( ui->lvMapping->selectionModel() == nullptr)
        return ;
    QModelIndexList select = ui->lvMapping->selectionModel()->selectedRows();

    if(select.size() >=0)
    {
        if(event->nativeVirtualKey() == Qt::Key_Delete || event->key() == Qt::Key_Delete)
        {
            listDelete();
        }
    }
}

MainWindow::~MainWindow()
{
    if(port != nullptr && port->isOpen())
        port->close();

    delete ui;
}

