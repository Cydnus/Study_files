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
        if(str.endsWith('0'))
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

    int indexs[] = {0,1,2,3, 4,5,8,9};

    vector<QCheckBox*> boxes;
    for(QString str : logs)
    {
        if(str.length()== 0)
            continue;
        QStringList lst = str.split("\t");

        if(lst[7]=="1")
            continue;

        for(int i = 0; i<7; i++)
        {
            ui->Table->setItem(row,indexs[i],new QTableWidgetItem(lst[i]));
        }
        uint64_t total = (uint64_t)(lst[5].toLongLong()*lst[3].toInt()* 0.95);
        uint64_t perOne = total/lst[6].toInt();
        total_sum += total;
        if(lst[6] == '3')
            per3_sum += perOne;
        else
            per4_sum += perOne;
        ui->Table->setItem(row,6,new QTableWidgetItem(QString::number(total)));
        ui->Table->setItem(row,7,new QTableWidgetItem(QString::number(perOne)));
        QWidget *cellWidget = new QWidget();
        QCheckBox *cb = new QCheckBox();

        QHBoxLayout *layoutCB = new QHBoxLayout(cellWidget);
        layoutCB->addWidget(cb);
        layoutCB->setAlignment(Qt::AlignCenter);
        cellWidget->setLayout(layoutCB);

        if(lst[7] == '0')
        {
            cb->setChecked(false);
        }
        else
        {
            cb->setChecked(true);
        }
        ui->Table->setCellWidget(row,9,cellWidget);
        boxes.push_back(cb);

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

