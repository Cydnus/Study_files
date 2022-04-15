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

void MainWindow::setConfig(QMap<QString, QString> map)
{
    ui->sbParty->setValue(map["Party_Count"].toInt());

    QFont font(map["Button_Font_Family"],map["Button_Font_Size"].toInt());

    ui->pbInsert->setFont(font);
    ui->pbCalEnd->setFont(font);
    ui->pbCopy->setFont(font);

    font.setFamily(map["TextBox_Font_Family"]);
    font.setPointSize(map["TextBox_Font_Size"].toInt());

    ui->sbCount->setFont(font);
    ui->lePrice->setFont(font);
    ui->sbParty->setFont(font);
    ui->deDate->setFont(font);
    ui->cbBossLevel->setFont(font);
    ui->cbBossName->setFont(font);
    ui->cbItemName->setFont(font);

    font.setFamily(map["Label_Font_Family"]);
    font.setPointSize(map["Label_Font_Size"].toInt());
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


    font.setFamily(map["GridBox_Font_Family"]);
    font.setPointSize(map["GridBox_Font_Size"].toInt());

    ui->Table->setFont(font);


    font.setFamily(map["Title_Font_Family"]);
    font.setPointSize(map["Title_Font_Size"].toInt());
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
    QMap<QString, QString> map;

    QTextStream tsConfItems(&fConfig);

    QStringList conList = tsConfItems.readAll().split("\n");

    for(QString str : conList)
    {
        if(str.length() == 0 ||str[0] == '#')
            continue;
      // qDebug()<<str;
        QStringList lst = str.split('=');
        map[lst[0].trimmed()] = lst[1].trimmed();
    }

    setConfig(map);

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

    int width = 100, height = 100;
    QImage *image = new QImage(width, height, QImage::Format_ARGB32_Premultiplied);

    image->fill(0xffffffff);

    data->setImageData(*image);
    clipboard->setMimeData(data, QClipboard::Clipboard);
}


MainWindow::~MainWindow()
{
    achieve->saveData();
    delete ui;
}

