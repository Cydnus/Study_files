#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::checkBoxStateChange(bool state) /* 체크박스 체크/해제시 동작 이벤트  */
{
    QObject *obj = sender();

    int row = obj->objectName().toInt();

    achieve->setCalEnd(row, state);

    setTable();

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();
}



void MainWindow::calculateEnd() /* 정산완료 동작 이벤트  */
{
    qDebug()<<"ui->pbCalEnd";

    ui->Table->clear();

    achieve->setAllCalEnd();

    setTable();

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();
}


void MainWindow::cellChanged(int row, int col) /* 셀 값 변경시 동작 이벤트 */
{
    qDebug()<<row<<"\t"<<col;
    AchieveEntity ae;
    QTableWidget * table = ui->Table;

    qDebug()<<table->item(row, 0)->text();

    ae.setDate(QDate::fromString(table->item(row, 0)->text().sliced(0,8),"yy-MM-dd").addYears(100));
    ae.setBossLevel(table->item(row, 1)->text());
    ae.setBossName(table->item(row, 2)->text());
    ae.setItemName(table->item(row, 3)->text());
    ae.setItemCount(table->item(row, 4)->text().toInt());
    ae.setPrice(getMeso(table->item(row, 5)->text()));
    ae.setPartyCount(table->item(row, 8)->text().toInt());

    ae.setCalEnd(((QCheckBox*)table->cellWidget(row,9))->isChecked());
    qDebug()<<"cellChanged : \t "<<((QCheckBox*) table->cellWidget(row,9))->isChecked();


    ae.setId(table->cellWidget(row,9)->objectName().toULongLong());

    ae.setVisible(false);
    qDebug()<<ae.toString();


    uint64_t total_sum = getMeso(ui->lblTotal->text());

#if (MODE_RELEASE != 1)
    uint64_t per3_sum = getMeso(ui->lblPer3->text());
#endif
    uint64_t per4_sum = getMeso(ui->lblPer4->text());

    AchieveEntity before = achieve->getAchieveEntity(ae.getId());

    uint64_t pre_price = before.getItemCount() * before.getPrice() * 0.95;
    uint64_t pre_ppo = pre_price / before.getPartyCount();

    if(before.isCalEnd()==false)
    {
        total_sum -= pre_price;

#if (MODE_RELEASE != 1)
        if(before.getPartyCount() == 3)
            per3_sum -= pre_ppo;
        else
            per4_sum -= pre_ppo;
#else
        per4_sum -= pre_ppo;
#endif
    }

    uint64_t price = ae.getItemCount() * ae.getPrice() * 0.95;
    uint64_t ppo = price / ae.getPartyCount();


    if(ae.isCalEnd()==false)
    {
        total_sum += price;
#if (MODE_RELEASE != 1)
        if(ae.getPartyCount() == 3)
            per3_sum += ppo;
        else
            per4_sum += ppo;
#else
        per4_sum += ppo;
#endif
    }


    ui->lblTotal->setText(QString("%L1 메소").arg(total_sum));

#if (MODE_RELEASE != 1)
    ui->lblPer3->setText(QString("%L1 메소").arg(per3_sum));
#endif
    ui->lblPer4->setText(QString("%L1 메소").arg(per4_sum));

    achieve->changeData(ae);
    QLocale lo = QLocale::system();

    setTableSomeRow(row,price,ppo, QString(ae.getDate().toString("yy-MM-dd") + " (" + lo.dayName(ae.getDate().dayOfWeek(),QLocale::ShortFormat) +")"));
}

void MainWindow::setTableSomeRow(int row, uint64_t price, uint64_t ppo, QString strdate)
{
    ui->Table->disconnect();


    ui->Table->setItem(row,0, new QTableWidgetItem(strdate));

    ui->Table->setItem(row,6, new QTableWidgetItem(QString("%L1").arg(price)));
    ui->Table->setItem(row,7, new QTableWidgetItem(QString("%L1").arg(ppo)));
    ui->Table->item(row,6)->setBackground(ui->Table->item(row,5)->background());
    ui->Table->item(row,7)->setBackground(ui->Table->item(row,5)->background());


    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();

    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
   QModelIndexList select = ui->Table->selectionModel()->selectedRows();

   if(select.size() >=0)
   {
       if(event->nativeVirtualKey() == Qt::Key_Delete || event->key() == Qt::Key_Delete)
       {
           vector<uint64_t> list;
           if(event->modifiers()  == Qt::ShiftModifier)
           {
               if(QMessageBox::question(this, "완전 삭제", "정말 삭제하시겠습니까?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
               {
                   for(int i = 0 ; i<select.count(); i ++)
                   {
                       qDebug()<<"Shift + Delete \t" <<ui->Table->cellWidget(select[i].row(),9)->objectName();
                       list.push_back(ui->Table->cellWidget(select[i].row(),9)->objectName().toULongLong());
                   }
                    achieve->remove(list);
               }

           }
           else
           {
               if(QMessageBox::question(this, "정산완료", "정산 완료 되었는지 확인 부탁드립니다.\n목록에서 삭제하시겠습니까?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
               {
                   for(int i = 0 ; i<select.count(); i ++)
                   {
                       qDebug()<<"toLog\t"<<ui->Table->cellWidget(select[i].row(),9)->objectName();
                       list.push_back(ui->Table->cellWidget(select[i].row(),9)->objectName().toULongLong());
                   }
                   achieve->toLog(list);
               }
           }

           setTable();

           ui->Table->resizeColumnsToContents();
           ui->Table->resizeRowsToContents();

       }
   }

}
