#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>
#include    <QGroupBox>
#include    <QLabel>
#include    <QtSerialPort/QSerialPort>
#include    <QVBoxLayout>
#include    <QGridLayout>
#include    <QPlainTextEdit>
#include    <QLineEdit>
#include    <QPushButton>
#include    <QComboBox>
#include    <QCheckBox>
#include    <QRadioButton>
#include    <QMap>
#include    <QMessageBox>

class MainWindow : public QMainWindow
{

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private :
    Q_OBJECT

    QLabel          *lblReceived;
    QLabel          *lblSendData;
    uint64_t        sendDataChar;
    uint64_t        recevDataChar;

    QPlainTextEdit  *teReceivedData;
    QLineEdit       *leSendData[5];
    QLineEdit       *leFreq;

    QPushButton     *pbClear;
    QPushButton     *pbOpenCon;
    QPushButton     *pbCloseCon;

    QPushButton     *pbFormat[5];
    QPushButton     *pbSend[5];

    QMap<QString, QComboBox*>       comboRx;

    QRadioButton    *rbAuto[5];

    QMap<QString, QCheckBox*>       checkSet;

    QSerialPort     *spPort;

    QMap<QString, QSerialPort::BaudRate>    mBaudrate;
    QMap<QString, QSerialPort::DataBits>    mDatabit;
    QMap<QString, QSerialPort::StopBits>    mStopbit;
    QMap<QString, QSerialPort::Parity>    mParity;

    QMetaObject::Connection conPort;

    //Method

    void init();
    QGroupBox*  createRXGroup();
    QGroupBox*  createTXGroup();

    void SendData(int);
    QByteArray StringToHex(QString);


public slots :
    void ClearReceivedData();
    void Connect();
    void Disconnect();
    void SendClicked();
    void serialReceived();


};
#endif // MAINWINDOW_H
