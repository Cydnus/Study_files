#include "mainwindow.h"
#include "./ui_mainwindow.h"


uint64_t getMeso(QString str)
{
    if(str.contains("메소"))
        return str.sliced(0,str.size()-2).replace(",","").toULongLong();
    return str.replace(",","").toULongLong();
}


QStringList getcbItemsFromFile(QString fileName) /* 파일 읽어오기 */
{
    QFile fItemName(fileName);

    if(!fItemName.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";

    }

    QTextStream tsItems(&fItemName);

    QStringList items;
    while(!tsItems.atEnd())
    {
        QString item = tsItems.readLine();
        items.append(item);
    }
    return items;
}

void MainWindow::setConfig()   /* 기본설정 (폰트/ 사이즈) */
{
    ui->sbParty->setValue(conf["Party_Count"].toInt());

    QFont font(conf["Button_Font_Family"],conf["Button_Font_Size"].toInt());

    ui->pbInsert->setFont(font);
    ui->pbCalEnd->setFont(font);
    ui->pbCopy->setFont(font);

    font.setFamily(conf["TextBox_Font_Family"]);
    font.setPointSize(conf["TextBox_Font_Size"].toInt());

    ui->sbCount->setFont(font);
    ui->lePrice->setFont(font);
    ui->sbParty->setFont(font);
    ui->deDate->setFont(font);
    ui->cbBossLevel->setFont(font);
    ui->cbBossName->setFont(font);
    ui->cbItemName->setFont(font);

    font.setFamily(conf["Label_Font_Family"]);
    font.setPointSize(conf["Label_Font_Size"].toInt());
    ui->lbl01->setFont(font);
    ui->lbl02->setFont(font);
    ui->lbl03->setFont(font);
    ui->lbl04->setFont(font);
    ui->lbl05->setFont(font);
    ui->lbl06->setFont(font);
    ui->lbl07->setFont(font);
    ui->lbl08->setFont(font);
    ui->lbl09->setFont(font);
    ui->lbl10->setFont(font);


    font.setFamily(conf["GridBox_Font_Family"]);
    font.setPointSize(conf["GridBox_Font_Size"].toInt());

    ui->Table->setFont(font);


    font.setFamily(conf["Title_Font_Family"]);
    font.setPointSize(conf["Title_Font_Size"].toInt());
    ui->lblTotal->setFont(font);
    ui->lblPer3->setFont(font);
    ui->lblPer4->setFont(font);
    this->setFont(font);

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) /* 생성자  */
{
    ui->setupUi(this);

#if (MODE_RELEASE == 1)
    ui->lbl02->setText("");
    ui->lblPer3->setText("");
    ui->lbl02->setEnabled(false);
    ui->lblPer3->setEnabled(false);
    ui->lbl03->setText("1인당 분배금액");
#endif

    QDate date;
    ui->deDate->setDate(date.currentDate());


    QFile fConfig("conf.Maple");
    QStringList itemList = getcbItemsFromFile("info/item_name");
    QStringList bnameList = getcbItemsFromFile("info/boss_name");
    QStringList blevelList = getcbItemsFromFile("info/boss_level");

    ui->cbItemName->addItems(itemList);
    ui->cbBossName->addItems(bnameList);
    ui->cbBossLevel->addItems(blevelList);


    if(!fConfig.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";
    }

    QTextStream tsConfItems(&fConfig);

    QStringList conList = tsConfItems.readAll().split("\n");

    for(QString str : conList)
    {
        if(str.length() == 0 ||str[0] == '#')
            continue;
      // qDebug()<<str;
        QStringList lst = str.split('=');
        conf[lst[0].trimmed()] = lst[1].trimmed();
    }
    fConfig.close();
    setConfig();

    setTable();

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();
    ui->Table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->Table->setSelectionMode(QAbstractItemView::SingleSelection);


    connect(ui->pbInsert, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCalEnd, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCopy, SIGNAL(clicked()), this, SLOT(btnClick()));

    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));

}

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

void MainWindow::checkBoxStateChange(bool state) /* 체크박스 체크/해제시 동작 이벤트  */
{
    QObject *obj = sender();

    int row = obj->objectName().toInt();

    achieve->setCalEnd(row, state);

    setTable();

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();
}

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
            if(entity.getPartyCount() == 3)
                per3_sum += ppo;
            else
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

    ae.setDate(QDate::fromString(table->item(row, 0)->text().split(' ')[0],"yy-MM-dd").addYears(100));
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
    setTableSomeRow(row,price,ppo);
}

void MainWindow::setTableSomeRow(int row, uint64_t price, uint64_t ppo)
{
    ui->Table->disconnect();

    ui->Table->setItem(row,6, new QTableWidgetItem(QString("%L1").arg(price)));
    ui->Table->setItem(row,7, new QTableWidgetItem(QString("%L1").arg(ppo)));
    ui->Table->item(row,6)->setBackground(ui->Table->item(row,5)->background());
    ui->Table->item(row,7)->setBackground(ui->Table->item(row,5)->background());


    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();

    tableConnect = connect(ui->Table, SIGNAL(cellChanged(int,int)), this, SLOT(cellChanged(int, int)));

}


void MainWindow::copyToClipboard() /* Copy/복사버튼 입력시 동작 이벤트 */
{
    qDebug()<<"ui->pbCopy";
    QClipboard *clipboard = QGuiApplication::clipboard();
    QMimeData *data = new QMimeData;

    double mang = ((double)conf["CopyTable_Font_Size"].toInt() /(double)10);
    int row_height = ui->Table->rowHeight(0)*mang;

    int width = 20 , height = 100 + ( (ui->Table->rowCount()+1) * row_height);

    vector<int> col_width;
    for(int i = 0 ; i<ui->Table->columnCount();i++)
    {
        int size = ui->Table->columnWidth(i) * mang;
        width += size;
        col_width.push_back(size);
    }

    QImage *image = new QImage(width, height, QImage::Format_ARGB32_Premultiplied);
    image->fill(0xffffffff);
    QPainter painter(image);
    painter.setPen(QPen(Qt::black));
    painter.setFont(QFont(conf["CopyTop_Font_Family"], conf["CopyTop_Font_Size"].toInt()));


    // HEADER Insert

    QString text1 = QString("%1 : %2").arg(ui->lbl01->text()).arg(ui->lblTotal->text());

#if (MODE_RELEASE != 1)
    QString text2 = QString("%1 : %2").arg(ui->lbl02->text()).arg(ui->lblPer3->text());
#else
    QString text2 = "";
#endif

    QString text3 = QString("%1 : %2").arg(ui->lbl03->text()).arg(ui->lblPer4->text());



    int loca_width = (width-100) / (text1.count()+text2.count()+text3.count());


    int sx=10, sy=20;

    painter.drawText(QRect(sx,sy,loca_width*text1.count(),60),Qt::AlignCenter, text1);

    sx= 10+(loca_width*text1.count()) ;

    painter.drawText(QRect(sx,sy,loca_width*text2.count(),60),Qt::AlignCenter, text2);


    sx=10+(loca_width*(text1.count()+text2.count()));

    painter.drawText(QRect(sx,sy,loca_width*text3.count(),60),Qt::AlignCenter,text3);

    // Table Insert

    //table Header
    sx=10;
    sy=90;

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

    painter.setFont(QFont(conf["CopyTable_Font_Family"], conf["CopyTable_Font_Size"].toInt()));

    vector<int> start_x;
    int rowCount = ui->Table->rowCount(), colCount = ui->Table->columnCount();

    for(int i = 0 ; i < colCount; i++)
    {
        painter.drawRect(QRect(sx,sy,col_width[i],row_height));
        painter.setPen(QPen(Qt::black));
        painter.drawText(QRect(sx,sy,col_width[i],row_height),Qt::AlignCenter,header[i]);

        start_x.push_back(sx);
        sx += col_width[i];
        // 72 point=96 pixel    3:4
    }
    sy += row_height;

    // table List
    QLocale lo = QLocale::system();

    vector<AchieveEntity> list = achieve->getVisibleList();
    for(int i = 0; i<rowCount; i++)
    {
        if(i%2 == 0)
            painter.setBrush(Qt::lightGray);
        else
            painter.setBrush(Qt::white);


        painter.setPen(QPen(Qt::black));

        painter.drawRect(QRect(start_x[0],sy,col_width[0],row_height));
        painter.drawText(QRect(start_x[0],sy,col_width[0],row_height), Qt::AlignCenter, list[i].getDate().toString("yyyy-MM-dd")  + " (" + lo.dayName(list[i].getDate().dayOfWeek(),QLocale::ShortFormat) +")" );

        painter.drawRect(QRect(start_x[1],sy,col_width[1],row_height));
        painter.drawText(QRect(start_x[1],sy,col_width[1],row_height), Qt::AlignCenter, list[i].getBossLevel());

        painter.drawRect(QRect(start_x[2],sy,col_width[2],row_height));
        painter.drawText(QRect(start_x[2],sy,col_width[2],row_height), Qt::AlignCenter, list[i].getBossName());

        painter.drawRect(QRect(start_x[3],sy,col_width[3],row_height));
        painter.drawText(QRect(start_x[3],sy,col_width[3],row_height), Qt::AlignCenter, list[i].getItemName());

        painter.drawRect(QRect(start_x[4],sy,col_width[4],row_height));
        painter.drawText(QRect(start_x[4],sy,col_width[4],row_height), Qt::AlignCenter, QString("%L1").arg(list[i].getItemCount()));

        painter.drawRect(QRect(start_x[5],sy,col_width[5],row_height));
        painter.drawText(QRect(start_x[5],sy,col_width[5],row_height), Qt::AlignCenter, QString("%L1").arg(list[i].getPrice()));

        uint64_t pp = list[i].getItemCount() *list[i].getPrice() *0.95;

        painter.drawRect(QRect(start_x[6],sy,col_width[6],row_height));
        painter.drawText(QRect(start_x[6],sy,col_width[6],row_height), Qt::AlignCenter, QString("%L1").arg(pp));

        uint64_t ppo = pp/list[i].getPartyCount();

        painter.drawRect(QRect(start_x[7],sy,col_width[7],row_height));
        painter.drawText(QRect(start_x[7],sy,col_width[7],row_height), Qt::AlignCenter, QString("%L1").arg(ppo));

        painter.drawRect(QRect(start_x[8],sy,col_width[8],row_height));
        painter.drawText(QRect(start_x[8],sy,col_width[8],row_height), Qt::AlignCenter, QString::number(list[i].getPartyCount()));

        painter.drawRect(QRect(start_x[9],sy,col_width[9],row_height));
        painter.drawText(QRect(start_x[9],sy,col_width[9],row_height), Qt::AlignCenter, (list[i].isCalEnd()?"■":"□"));


        sy += row_height;
    }

    data->setImageData(*image);
    clipboard->setMimeData(data, QClipboard::Clipboard);
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

MainWindow::~MainWindow() /* 소멸자 */
{
    achieve->saveData();
    delete ui;
}

