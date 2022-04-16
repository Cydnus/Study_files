#include "mainwindow.h"
#include "./ui_mainwindow.h"


QStringList getcbItemsFromFile(QString fileName)
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

void MainWindow::setConfig()
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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    TableSetHeader();
    setTable();


    connect(ui->pbInsert, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCalEnd, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCopy, SIGNAL(clicked()), this, SLOT(btnClick()));

}

void MainWindow::TableSetHeader()
{

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
}


void MainWindow::tableInsert( AchieveEntity entity )
{
    //qDebug()<<entity.getDate();
    int row = ui->Table->rowCount();


    ui->Table->insertRow(row);

   // row --;

    ui->Table->setItem(row,0, new QTableWidgetItem(entity.getDate().toString("yy-MM-dd (ddd)")));

    ui->Table->setItem(row,1, new QTableWidgetItem(entity.getBossLevel()));
    ui->Table->setItem(row,2, new QTableWidgetItem(entity.getBossName()));
    ui->Table->setItem(row,3, new QTableWidgetItem(entity.getItemName()));

    ui->Table->setItem(row,4, new QTableWidgetItem(QString::number(entity.getItemCount())));
    ui->Table->setItem(row,5, new QTableWidgetItem(QString::number(entity.getPrice())));

    uint64_t price = entity.getItemCount() * entity.getPrice() * 0.95;
    uint64_t ppo = price / entity.getPartyCount();

    QTableWidgetItem *pri = new QTableWidgetItem(QString::number(price)), *po =new QTableWidgetItem(QString::number(ppo));

    pri->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    po->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->Table->setItem(row,6, pri);
    ui->Table->setItem(row,7, po );


    ui->Table->setItem(row,8, new QTableWidgetItem(QString::number(entity.getPartyCount())));

    QCheckBox *box = new QCheckBox();

    QWidget *cellWidget = new QWidget();

    QHBoxLayout *layoutCB = new QHBoxLayout(cellWidget);
    layoutCB->addWidget(box);
    layoutCB->setAlignment(Qt::AlignCenter);
    cellWidget->setLayout(layoutCB);

    box->setObjectName(QString::number(row));

    if(entity.isCalEnd() == true)
        box->setChecked(true);
    ui->Table->setCellWidget(row,9, cellWidget);

    connect(box,SIGNAL(clicked()),this,SLOT(checkBoxStateChange()));

}


void MainWindow::checkBoxStateChange()
{
    QObject *obj = sender();

    int row = obj->objectName().toInt();

    achieve->setCalEnd(achieve->getVisibleList()[row].getId(), ((QCheckBox*)obj)->isChecked());

    setTable();


}


void MainWindow::btnClick()
{
    QObject* obj = sender();
    if( obj == ui->pbInsert )
        insertRow();

    else if( obj == ui->pbCalEnd )
        calculateEnd();

    else if( obj == ui->pbCopy )
        copyToClipboard();
}

void MainWindow::insertRow()
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
    achieve->AppendData(ae);

    tableInsert(ae);

}


void  MainWindow::setTable()
{
    vector<AchieveEntity> entitys = achieve->getVisibleList();

    uint64_t total_sum = 0;
    uint64_t per4_sum = 0;
    uint64_t per3_sum = 0;

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

    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();

    ui->lblTotal->setText(QString("%L1 메소").arg(total_sum));
    ui->lblPer3->setText(QString("%L1 메소").arg(per3_sum));
    ui->lblPer4->setText(QString("%L1 메소").arg(per4_sum));

}

void MainWindow::calculateEnd()
{
    qDebug()<<"ui->pbCalEnd";

    ui->Table->clear();
    TableSetHeader();

    achieve->setAllCalEnd();
    setTable();

}

void MainWindow::copyToClipboard()
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
    QString text2 = QString("%1 : %2").arg(ui->lbl02->text()).arg(ui->lblPer3->text());
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

    for(int i = 0 ; i < ui->Table->columnCount(); i++)
    {
        painter.drawRect(QRect(sx,sy,col_width[i],row_height));
        painter.setPen(QPen(Qt::black));
        painter.drawText(QRect(sx,sy,col_width[i],row_height),Qt::AlignCenter,header[i]);

        start_x.push_back(sx);
        sx += col_width[i];
        // 72 point=96 pixel    3:4
    }
    sy += row_height;

    int rowCount = ui->Table->rowCount(), colCount = ui->Table->columnCount();


    vector<AchieveEntity> list = achieve->getVisibleList();
    // table List
    for(int i = 0; i<rowCount; i++)
    {
        if(i%2 == 0)
            painter.setBrush(Qt::lightGray);
        else
            painter.setBrush(Qt::white);


        painter.setPen(QPen(Qt::black));

        painter.drawRect(QRect(start_x[0],sy,col_width[0],row_height));
        painter.drawText(QRect(start_x[0],sy,col_width[0],row_height), Qt::AlignCenter, list[i].getDate().toString("yyyy-MM-dd (ddd)"));

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

        int pp = list[i].getItemCount() *list[i].getPrice() *0.95;

        painter.drawRect(QRect(start_x[6],sy,col_width[6],row_height));
        painter.drawText(QRect(start_x[6],sy,col_width[6],row_height), Qt::AlignCenter, QString("%L1").arg(pp));

        int ppo = pp/list[i].getPartyCount();

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


MainWindow::~MainWindow()
{
    achieve->saveData();
    delete ui;
}

