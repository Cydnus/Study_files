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
#include    <QTimer>
#include    <QFile>
#include    <QSettings>


#define     MAX_ARRAY   5

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
    QLineEdit       *leSendData[MAX_ARRAY];
    QLineEdit       *leFreq;

    QPushButton     *pbClear;
    QPushButton     *pbOpenCon;
    QPushButton     *pbCloseCon;

    QPushButton     *pbFormat[MAX_ARRAY];
    QPushButton     *pbSend[MAX_ARRAY];

    QMap<QString, QComboBox*>       comboRx;

    QRadioButton    *rbAuto[MAX_ARRAY];

    QMap<QString, QCheckBox*>       checkSet;

    QSerialPort     *spPort;

    QMap<QString, QSerialPort::BaudRate>    mBaudrate;
    QMap<QString, QSerialPort::DataBits>    mDatabit;
    QMap<QString, QSerialPort::StopBits>    mStopbit;
    QMap<QString, QSerialPort::Parity>    mParity;

    QMetaObject::Connection conPort;
    QMetaObject::Connection conTimerFreq;

    QTimer  *timerFreq;
    //Method

    void init();
    QGroupBox*  createRXGroup();
    QGroupBox*  createTXGroup();

    void SendData(int);
    QByteArray StringToHex(QString);

    void DataLoad();
    void DataSave();

    void closeEvent(QCloseEvent*);

public slots :
    void ClearReceivedData();
    void Connect();
    void Disconnect();
    void SendClicked();
    void serialReceived();
    void DataRepeatChecked(int);
    void timerFreqCallBack();



};
#endif // MAINWINDOW_H
