#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::tableInsert( AchieveEntity entity )  /* 테이블에 한줄 입력  */
{
    //qDebug()<<entity.getDate();
    int row = ui->Table->rowCount();


    ui->Table->insertRow(row);

   // row --;

    QLocale lo = QLocale::system();

    ui->Table->setItem(row,0, new QTableWidgetItem(entity.getDate().toString("yy-MM-dd") + " (" + lo.dayName(entity.getDate().dayOfWeek(),QLocale::ShortFormat) +")"));

    ui->Table->setItem(row,1, new QTableWidgetItem(entity.getBossLevel()));
    ui->Table->setItem(row,2, new QTableWidgetItem(entity.getBossName()));
    ui->Table->setItem(row,3, new QTableWidgetItem(entity.getItemName()));

    ui->Table->setItem(row,4, new QTableWidgetItem(QString::number(entity.getItemCount())));
    ui->Table->setItem(row,5, new QTableWidgetItem(QString::number(entity.getPrice())));

    uint64_t price = entity.getItemCount() * entity.getPrice() * 0.95;
    uint64_t ppo = price / entity.getPartyCount();
    QTableWidgetItem *pri = new QTableWidgetItem(QString("%L1").arg(price)), *po =new QTableWidgetItem(QString("%L1").arg(ppo));

    pri->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    po->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->Table->setItem(row,6, pri);
    ui->Table->setItem(row,7, po );


    ui->Table->setItem(row,8, new QTableWidgetItem(QString::number(entity.getPartyCount())));

    QCheckBox *box = new QCheckBox();

    box->setObjectName(QString::number(entity.getId()));

    if(entity.isCalEnd() == true)
        box->setChecked(true);
    //box->setStyleSheet(box->styleSheet() + "margin-left:20%; margin-right:10%;");

    ui->Table->setCellWidget(row,9, box);

    if( row % 2 == 1)
    {
        ui->Table->item(row,0)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,1)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,2)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,3)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,4)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,5)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,6)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,7)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->item(row,8)->setBackground(QBrush(QColor(215, 214, 213)));
        ui->Table->cellWidget(row,9)->setStyleSheet( ui->Table->cellWidget(row,9)->styleSheet() + "padding-left:20%;padding-right:10%;background-color:#d7d6d5");
    }
    else
        ui->Table->cellWidget(row,9)->setStyleSheet( ui->Table->cellWidget(row,9)->styleSheet() + "padding-left:20%;padding-right:10%;");
    connect(box,SIGNAL(toggled(bool)),this,SLOT(checkBoxStateChange(bool)));

}



void MainWindow::insertRow() /* 항목 추가 이벤트  */
{
    AchieveEntity ae;
    ae.setId(achieve->getAddIndex());
    ae.setDate(QDate::currentDate());
    ae.setBossLevel(ui->cbBossLevel->currentText());
    ae.setBossName(ui->cbBossName->currentText());
    ae.setItemName(ui->cbItemName->currentText());
    ae.setItemCount(ui->sbCount->value());
    ae.setPrice(ui->lePrice->text().toULongLong());
    ae.setPartyCount(ui->sbParty->value());
    ae.setCalEnd(false);
    ae.setVisible(false);

    qDebug() << ae.toString();

    ui->Table->disconnect();
    tableInsert(ae);
    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();
    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));

    achieve->AppendData(ae);

}

void MainWindow::setTable() /* 테이블 항목 추가  */
{
    ui->Table->clear();

    ui->Table->disconnect();

    vector<AchieveEntity> entitys = achieve->getVisibleList();

    uint64_t total_sum = 0;
    uint64_t per4_sum = 0;
    uint64_t per3_sum = 0;

    ui->Table->setRowCount(0);
    ui->Table->setColumnCount(10);

    QStringList header = {
        QString("날자"),
        QString("보스등급"),
        QString("보스명"),
        QString("아이템명"),
        QString("갯수"),
        QString("가격"),
        QString("수수료 제외한 금액"),
        QString("1인당 분배금액"),
        QString("파티원수"),
        QString("분배여부")};

    ui->Table->setHorizontalHeaderLabels(header);

    for(AchieveEntity entity : entitys)
    {
        tableInsert(entity);
        uint64_t price = entity.getItemCount() * entity.getPrice() * 0.95;
        uint64_t ppo = price / entity.getPartyCount();

        if(entity.isCalEnd()==false)
        {
            total_sum += price;

#if (MODE_RELEASE != 1)
            if(entity.getPartyCount() == 3)
                per3_sum += ppo;
            else
                per4_sum += ppo;
#endif
            per4_sum += ppo;

        }
    }


    ui->lblTotal->setText(QString("%L1 메소").arg(total_sum));
#if (MODE_RELEASE != 1)
    ui->lblPer3->setText(QString("%L1 메소").arg(per3_sum));
#endif
    ui->lblPer4->setText(QString("%L1 메소").arg(per4_sum));

    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));

}
