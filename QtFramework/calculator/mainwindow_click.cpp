#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::btnClick() /* 버튼 클릭 분류  */
{
    QObject* obj = sender();
    if( obj == ui->pbInsert )
        insertRow();
    else if( obj == ui->pbCalEnd && QMessageBox::information(this, "CalculateEnd", "정산 완료 하시겠습니까?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
            calculateEnd();
    else if( obj == ui->pbCopy )
    {
        copyToClipboard();
        QMessageBox::information(this, "Copy", "Copied");
    }
    else if(obj == ui->pbSelectCheck && QMessageBox::information(this, "CalculateEnd", "정산 완료 하시겠습니까?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
    {
        selectCheck();
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if((watched == ui->lblPer3||watched == ui->lblPer4 ) && event->type() == QMouseEvent::MouseButtonPress)
    {
        QString str = ((QLabel *)watched)->text();
        str.replace(" 메소","");
        str.replace(",","");
        qDebug()<<str.toInt();

        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->setText(str,QClipboard::Clipboard);
        QMessageBox::information(this, "Copy", "Copied");

    }
    return QWidget::eventFilter(watched, event);
}



void MainWindow::selectCheck()
{
    ui->Table->disconnect();

    QModelIndexList select = ui->Table->selectionModel()->selectedRows();

    if(select.size() > 0)
    {
        for(int i = 0 ; i<select.size(); i++)
        {
            ((QCheckBox*)ui->Table->cellWidget(select[i].row(),9))->setChecked(!((QCheckBox*)ui->Table->cellWidget(select[i].row(),9))->isChecked());
            cellChanged(select[i].row(),9);
        }
    }
    //setTable();
    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));
}


