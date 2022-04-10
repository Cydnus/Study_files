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
        QStringList lst = str.split('=');
        map[lst[0].trimmed()] = lst[1].trimmed();
    }

    setConfig(map);



    QFile fLog("log.Maple");


    if(!fLog.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Not Open";
    }
    QTextStream tsLogs(&fLog);

    QStringList logs = tsLogs.readAll().split("\n");

    int row = 0;
    for(QString str : logs)
    {
        if(str.endsWith("False"))
            row++;
    }


    ui->Table->setRowCount(row);
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
    uint64_t total_sum = 0;
    uint64_t per4_sum = 0;
    uint64_t per3_sum = 0;
    row = 0;


    for(QString str : logs)
    {
        if(str.length()== 0)
            continue;
        QStringList lst = str.split("\t");

        if(lst[8]=="True")
            continue;

        ui->Table->setItem(row,0,new QTableWidgetItem(lst[0]));
        ui->Table->setItem(row,1,new QTableWidgetItem(lst[1]));
        ui->Table->setItem(row,2,new QTableWidgetItem(lst[2]));
        ui->Table->setItem(row,3,new QTableWidgetItem(lst[3]));
        ui->Table->setItem(row,4,new QTableWidgetItem(lst[4]));
        ui->Table->setItem(row,5,new QTableWidgetItem(lst[5]));
        uint64_t total = (uint64_t)(lst[5].toLongLong()*lst[3].toInt()* 0.95);
        uint64_t perOne = total/lst[6].toInt();
        total_sum += total;
        if(lst[6] == '3')
            per3_sum += perOne;
        else
            per4_sum += perOne;
        ui->Table->setItem(row,6,new QTableWidgetItem(QString::number(total)));
        ui->Table->setItem(row,7,new QTableWidgetItem(QString::number(perOne)));
        ui->Table->setItem(row,8,new QTableWidgetItem(lst[6]));
        ui->Table->setItem(row,9,new QTableWidgetItem(lst[7]));
        row++;
    }


    ui->Table->resizeColumnsToContents();
    ui->Table->resizeRowsToContents();

    ui->lblTotal->setText(QString("%L1 메소").arg(total_sum));
    ui->lblPer3->setText(QString("%L1 메소").arg(per3_sum));
    ui->lblPer4->setText(QString("%L1 메소").arg(per4_sum));

}



MainWindow::~MainWindow()
{
    delete ui;
}

