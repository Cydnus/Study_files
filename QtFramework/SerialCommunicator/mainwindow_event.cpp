#include "mainwindow.h"
#include <QDebug>


void MainWindow::ClearReceivedData()
{
    recevDataChar = 0;
    lblReceived->setText("Received Data : Received 0 Charactor");
    teReceivedData->clear();
}

void MainWindow::Connect()
{
    qDebug()<<comboRx["SerialPort"]->currentText();

    spPort->setPortName(comboRx["SerialPort"]->currentText());
    spPort->setBaudRate(mBaudrate[comboRx["BaudRate"]->currentText()]);
    spPort->setDataBits(mDatabit[comboRx["DataBits"]->currentText()]);
    spPort->setParity( mParity[comboRx["Parity"]->currentText()]);
    spPort->setStopBits(mStopbit[comboRx["StopBits"]->currentText()]);
    spPort->setFlowControl(QSerialPort::NoFlowControl);

    if(!spPort->open(QIODevice::ReadWrite))
    {
        //qDebug()<<"Failed to open";
        return;
    }

    spPort->setDataTerminalReady(true);
    spPort->setRequestToSend(true);
    sendDataChar = 0;
    lblSendData->setText(QString(tr("Send Data : Send %1 Charactor").arg(sendDataChar)));

    conPort = connect(spPort, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    comboRx["SerialPort"]->setEnabled(false);
    comboRx["BaudRate"]->setEnabled(false);
    comboRx["DataBits"]->setEnabled(false);
    comboRx["StopBits"]->setEnabled(false);
    comboRx["Parity"]->setEnabled(false);

    pbOpenCon->setEnabled(false);

    pbCloseCon->setEnabled(true);
    checkSet["DataRepeat"]->setEnabled(true);
}

void MainWindow::Disconnect()
{
    disconnect(conPort);
    spPort->close();

    comboRx["SerialPort"]->setEnabled(true);
    comboRx["BaudRate"]->setEnabled(true);
    comboRx["DataBits"]->setEnabled(true);
    comboRx["StopBits"]->setEnabled(true);
    comboRx["Parity"]->setEnabled(true);

    pbOpenCon->setEnabled(true);

    pbCloseCon->setEnabled(false);
    checkSet["DataRepeat"]->setEnabled(false);
}

void MainWindow::serialReceived()
{
    QByteArray received;

    while(spPort->bytesAvailable() > 0 || spPort->waitForReadyRead(0))
    {
        QByteArray temp = spPort->read(1);
        if(temp == "")
                continue;
        received += temp;
    }

    if(comboRx["Format"]->currentText() == "HEX")
    {
        recevDataChar += received.size();
        QString strData = "";
        int iTap = 0;
        for(char data : received.toHex() )
        {
            strData += QString(tr("%1").arg(data));
            if((++iTap) %2 == 0){
                strData += " ";
            }
        }
        teReceivedData->appendPlainText(strData);

    }
    else
    {
        recevDataChar += received.size();
        teReceivedData->appendPlainText(QString(tr("%1 ").arg(QString(received))));
    }

    lblReceived->setText(tr("Received Data : Received %1 Charactors").arg(recevDataChar));
}
void MainWindow::SendClicked()
{
    QPushButton* btnClick = (QPushButton*)sender();

     int index = 0;

     for(int i =0 ; i < MAX_ARRAY ; i++)
     {
         if(btnClick == pbSend[i])
         {
             index = i;
             break;
         }
     }

     SendData(index);

}

void MainWindow::SendData(int index)
{
    QByteArray ba;

    if(!spPort->isOpen())
    {
        QMessageBox::warning(this,"Com Port", "Seiral Port is not opened!\n open COM port.");
        return;
    }

    if( pbFormat[index]->text() == "HEX")
    {
       ba = StringToHex(leSendData[index]->text());
    }
    else
    {
        ba.append(leSendData[index]->text().toStdString().c_str());
    }

    if(checkSet["AddCRLF"]->isChecked())
    {
        ba.append(0x0d);
        ba.append(0x0a);
    }

    spPort->write(ba);
    sendDataChar += ba.size();
    lblSendData->setText(QString(tr("Send Data : Send %1 Charactor").arg(sendDataChar)));

}

QByteArray MainWindow::StringToHex(QString str)
{
    QByteArray baStr;
    str = str.toLower();

    if(str.size()%2 == 1)
         str += "0";

    for(int i = 0; i < str.size(); i+=2)
    {
        int high = str.mid(i,1).toInt(nullptr,16);
        int low = str.mid(i+1,1).toInt(nullptr,16);

        high = high << 4;
        high = high | low;

        baStr.append(high);
    }

    qDebug()<<baStr;
    return baStr;
}

void MainWindow::DataRepeatChecked(int state)
{
    if(state == Qt::Checked)
    {
        for(int i = 0; i < MAX_ARRAY ; i++)
        {
            rbAuto[i]->setEnabled(false);
        }

        leFreq->setEnabled(false);
        int iFreq = (int)((double)leFreq->text().toDouble()*1000);
        timerFreq->setInterval(iFreq);
        timerFreq->start();
    }
    else
    {
        timerFreq->stop();
        leFreq->setEnabled(true);

        for(int i = 0; i < MAX_ARRAY ; i++)
        {
            rbAuto[i]->setEnabled(true);
        }
    }
}



void  MainWindow::timerFreqCallBack()
{
    int index = 0;
    for(int i = 0; i < MAX_ARRAY ; i++)
    {
        if(rbAuto[i]->isChecked())
        {
            index = i;
            break;
        }
    }

    SendData(index);
}

