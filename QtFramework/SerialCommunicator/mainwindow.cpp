#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    init();

    QWidget *widget = new QWidget;
    QVBoxLayout *vbox = new QVBoxLayout(widget);

    vbox->addWidget(createRXGroup(),0);
    vbox->addWidget(createTXGroup(),1);
    vbox->setStretch(0,4);
    vbox->setStretch(1,3);
    widget->setLayout(vbox);
    this->setCentralWidget(widget);
    setFixedSize(800,600);

    DataLoad();
    if(checkSet["AutoConnect"]->isChecked())
    {
        Connect();
    }
}

void MainWindow::DataLoad()
{
    QSettings settings("SerialComm", "mySerial");

    //RX
    comboRx[QString("SerialPort")]->setCurrentText(settings.value("RX/Port").toString());
    comboRx[QString("BaudRate")]->setCurrentText(settings.value("RX/Baudrate").toString());
    comboRx[QString("DataBits")]->setCurrentText(settings.value("RX/DataBit").toString());
    comboRx[QString("StopBits")]->setCurrentText(settings.value("RX/StopBit").toString());
    comboRx[QString("Parity")]->setCurrentText(settings.value("RX/Parity").toString());
    checkSet["AutoConnect"]->setChecked(settings.value("RX/AutoConnect").toBool());
    comboRx[QString("Format")]->setCurrentText(settings.value("RX/Format").toString()=""? "HEX":settings.value("RX/Format").toString());


    //TX
    checkSet["AddCRLF"]->setChecked(settings.value("TX/AddCRLF").toBool());

    for(int i = 0; i< MAX_ARRAY; i++)
    {
        leSendData[i]->setText(settings.value(tr("TX/Data_%1").arg(i)).toString());
        pbFormat[i]->setText(settings.value(tr("TX/Format_%1").arg(i)).toString()=""?"HEX":settings.value(tr("TX/Format_%1").arg(i)).toString());
        rbAuto[i]->setChecked(settings.value(tr("TX/Auto_%1").arg(i)).toBool());
    }
    leFreq->setText(settings.value("TX/Freq").toString());

}

void MainWindow::closeEvent(QCloseEvent *event)
{

    if(spPort->isOpen())
    {
        spPort->close();
    }
    QSettings settings("SerialComm", "mySerial");

    //RX
    settings.setValue("RX/Port",       comboRx[QString("SerialPort")]->currentText() );
    settings.setValue("RX/Baudrate",   comboRx[QString("BaudRate")]->currentText() );
    settings.setValue("RX/DataBit",    comboRx[QString("DataBits")]->currentText() );
    settings.setValue("RX/StopBit",    comboRx[QString("StopBits")]->currentText() );
    settings.setValue("RX/Parity",     comboRx[QString("Parity")]->currentText() );
    settings.setValue("RX/AutoConnect", checkSet["AutoConnect"]->isChecked());

    settings.setValue("RX/Format",comboRx[QString("Format")]->currentText());

     // TX

    settings.setValue("TX/AddCRLF",checkSet["AddCRLF"]->isChecked() );

    for(int i = 0; i< MAX_ARRAY; i++)
    {
        settings.setValue(tr("TX/Data_%1").arg(i), leSendData[i]->text() );
        settings.setValue(tr("TX/Auto_%1").arg(i), rbAuto[i]->isChecked() );
        settings.setValue(tr("TX/Format_%1").arg(i), pbFormat[i]->text() );
    }

    settings.setValue("TX/Freq", leFreq->text() );



    QMainWindow::closeEvent(event);
}

void MainWindow::init()
{
    sendDataChar = 0;
    recevDataChar = 0;
    lblReceived = new QLabel("Received Data : Received 0 Charactor");
    lblSendData = new QLabel(QString(tr("Send Data : Send %1 Charactor").arg(sendDataChar)));

    teReceivedData = new QPlainTextEdit;

    pbClear = new QPushButton("Clear");
    pbOpenCon = new QPushButton(tr("&Open Connect"));
    pbCloseCon = new QPushButton(tr("&Close Connect"));
    pbCloseCon->setEnabled(false);
    connect(pbClear, SIGNAL(clicked()), this, SLOT(ClearReceivedData()));
    connect(pbOpenCon, SIGNAL(clicked()), this, SLOT(Connect()));
    connect(pbCloseCon, SIGNAL(clicked()), this, SLOT(Disconnect()));


    comboRx[QString("Format")]       = new QComboBox;
    comboRx[QString("SerialPort")]   = new QComboBox;
    comboRx[QString("BaudRate")]     = new QComboBox;
    comboRx[QString("DataBits")]     = new QComboBox;
    comboRx[QString("StopBits")]     = new QComboBox;
    comboRx[QString("Parity")]       = new QComboBox;

    comboRx["Format"]->addItems({"HEX","ASCII"});

    for(int i = 1 ; i <= 20; i++)
    {
        comboRx["SerialPort"]->addItems({QString("COM%1").arg(i)});
    }
    comboRx["BaudRate"]->addItems({"1200",     "2400",     "4800",     "9600",
                            "19200",    "38400",    "57600",    "115200"});
    comboRx["DataBits"]->addItems({"5", "6", "7", "8"});
    comboRx["StopBits"]->addItems({"1","2"});
    comboRx["Parity"]->addItems({"None","Odd","Even"});


    for(int i = 0; i < MAX_ARRAY; i++)
    {
        leSendData[i] = new QLineEdit;
        pbFormat[i] = new QPushButton("HEX");
        connect(pbFormat[i], &QPushButton::clicked, [=](){
            if(pbFormat[i]->text() == "HEX") pbFormat[i]->setText("ASCII");
                    else pbFormat[i]->setText("HEX");});

        pbSend[i] = new QPushButton("Send");
        connect(pbSend[i], SIGNAL(clicked()), this, SLOT(SendClicked()));
        rbAuto[i] = new QRadioButton("Auto");
    }


    checkSet["AutoConnect"] = new QCheckBox("Auto Connect");
    checkSet["DataRepeat"] = new QCheckBox("Send Data Repeatedly");
    checkSet["DataRepeat"] ->setEnabled(false);
    checkSet["AddCRLF"] = new QCheckBox("Add CR/LF");
    leFreq = new QLineEdit("0.5");

    spPort = new QSerialPort(this);

    mBaudrate.insert( "1200",    QSerialPort::Baud1200);
    mBaudrate.insert( "2400",    QSerialPort::Baud2400);
    mBaudrate.insert( "4800",    QSerialPort::Baud4800);
    mBaudrate.insert( "9600",    QSerialPort::Baud9600);
    mBaudrate.insert( "19200",   QSerialPort::Baud19200);
    mBaudrate.insert( "38400",   QSerialPort::Baud38400);
    mBaudrate.insert( "57600",   QSerialPort::Baud57600);
    mBaudrate.insert( "115200",  QSerialPort::Baud115200);
    mDatabit.insert( "5", QSerialPort::Data5);
    mDatabit.insert( "6", QSerialPort::Data6);
    mDatabit.insert( "7", QSerialPort::Data7);
    mDatabit.insert( "8", QSerialPort::Data8);
    mStopbit.insert( "1", QSerialPort::OneStop);
    mStopbit.insert( "2", QSerialPort::TwoStop);
    mParity.insert( "None",     QSerialPort::NoParity);
    mParity.insert( "Even",     QSerialPort::EvenParity);
    mParity.insert( "Odd",     QSerialPort::OddParity);

    connect(checkSet["DataRepeat"],  &QCheckBox::stateChanged, this, &MainWindow::DataRepeatChecked);

    timerFreq = new QTimer(this);
    conTimerFreq = connect(timerFreq, &QTimer::timeout, this, &MainWindow::timerFreqCallBack);

}


QGroupBox*  MainWindow::createRXGroup()
{
    QGroupBox   *gbRX = new QGroupBox("RX");

    QGridLayout *glRXLayout = new QGridLayout;

    glRXLayout->addWidget(lblReceived, 0,0,1,2);

    QLabel *lblSetting = new QLabel("Com Port Setting");
    glRXLayout->addWidget(lblSetting, 0,2);

    glRXLayout->addWidget(teReceivedData, 1,0,1,2);

    glRXLayout->addWidget(pbClear, 2,0, Qt::AlignLeft);

    QWidget *wBtnConnect = new QWidget;
    QHBoxLayout *hboxBtnConnect = new QHBoxLayout(wBtnConnect);
    hboxBtnConnect->addWidget(pbOpenCon);
    hboxBtnConnect->addWidget(pbCloseCon);
    wBtnConnect->setLayout(hboxBtnConnect);
    glRXLayout->addWidget(wBtnConnect,2,2);

    QWidget *wFormat = new QWidget;
    QHBoxLayout *hboxFormat = new QHBoxLayout(wFormat);
    QLabel *lblFormat = new QLabel("Rx Format");
    hboxFormat->addWidget(lblFormat);
    hboxFormat->addWidget(comboRx["Format"]);
    wFormat->setLayout(hboxFormat);
    glRXLayout->addWidget(wFormat, 2,1, Qt::AlignRight);

    QWidget *wPortSetting = new QWidget;
    QGridLayout *glPort = new QGridLayout(wPortSetting);

    QLabel *lblPort     = new QLabel("Serial Port");
    QLabel *lblBaud     = new QLabel("Baudrate");
    QLabel *lblDBit     = new QLabel("Data Bits");
    QLabel *lblSBit     = new QLabel("Stop Bits");
    QLabel *lblParity   = new QLabel("Parity");

    glPort->addWidget(lblPort   , 0, 0);
    glPort->addWidget(lblBaud   , 1, 0);
    glPort->addWidget(lblDBit   , 2, 0);
    glPort->addWidget(lblSBit   , 3, 0);
    glPort->addWidget(lblParity , 4, 0);

    glPort->addWidget(comboRx["SerialPort"] , 0, 1);
    glPort->addWidget(comboRx["BaudRate"]   , 1, 1);
    glPort->addWidget(comboRx["DataBits"]   , 2, 1);
    glPort->addWidget(comboRx["StopBits"]   , 3, 1);
    glPort->addWidget(comboRx["Parity"]     , 4, 1);

    glPort->addWidget(checkSet["AutoConnect"]     , 5, 1, Qt::AlignCenter);

    wPortSetting->setLayout(glPort);
    glRXLayout->addWidget(wPortSetting, 1, 2);


    gbRX->setLayout(glRXLayout);
    return gbRX;
}

QGroupBox*  MainWindow::createTXGroup()
{
    QGroupBox   *gbTX = new QGroupBox("TX");
    QGridLayout *glTXLayout = new QGridLayout;

    glTXLayout->addWidget(lblSendData, 0,0,1,9, Qt::AlignLeft);

    QLabel *lblFormat = new QLabel("Format");
    QLabel *lblSend = new QLabel("Send");
    glTXLayout->addWidget(lblFormat, 0,11, Qt::AlignCenter);
    glTXLayout->addWidget(lblSend, 0,12, Qt::AlignCenter);


    for(int i = 0; i<5; i++)
    {

        glTXLayout->addWidget(leSendData[i],i+1,0,1,9);
        glTXLayout->addWidget(rbAuto[i], i+1,10,Qt::AlignLeft );
        glTXLayout->addWidget(pbFormat[i],i+1, 11, Qt::AlignCenter );
        glTXLayout->addWidget(pbSend[i],i+1, 12, Qt::AlignCenter );

    }

    glTXLayout->addWidget(checkSet["DataRepeat"] , 6,0,Qt::AlignLeft);

    QWidget *wFreq = new QWidget;
    QHBoxLayout *hblFreq = new QHBoxLayout(wFreq);
    QLabel *lblFreq = new QLabel("Frequency : ");
    QLabel *lblPerSec = new QLabel(" /Seconds");
    hblFreq->addWidget(lblFreq);
    hblFreq->addWidget(leFreq);
    hblFreq->addWidget(lblPerSec);
    wFreq->setLayout(hblFreq);
    glTXLayout->addWidget(wFreq,7,0,Qt::AlignRight );


    glTXLayout->addWidget(checkSet["AddCRLF"],7,12,Qt::AlignRight );


    gbTX->setLayout(glTXLayout);
    return gbTX;
}


MainWindow::~MainWindow()
{
    if(spPort->isOpen())
    {
        spPort->close();
    }
}

