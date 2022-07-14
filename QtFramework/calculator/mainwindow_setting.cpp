#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::setConfig()   /* 기본설정 (폰트/ 사이즈) */
{
    ui->sbParty->setValue(conf["Party_Count"].toInt());

    //버튼 설정
    QFont font(conf["Button_Insert_Font_Family"],conf["Button_Insert_Font_Size"].toInt());
    ui->pbInsert->setFont(font);

    font.setFamily(conf["Button_End_Font_Family"]);
    font.setPointSize(conf["Button_End_Font_Size"].toInt());
    ui->pbCalEnd->setFont(font);

    font.setFamily(conf["Button_Copy_Font_Family"]);
    font.setPointSize(conf["Button_Copy_Font_Size"].toInt());
    ui->pbCopy->setFont(font);

    font.setFamily(conf["Button_SelectEnd_Font_Family"]);
    font.setPointSize(conf["Button_SelectEnd_Font_Size"].toInt());
    ui->pbSelectCheck->setFont(font);

    //입력 받는 부분 설정
    font.setFamily(conf["TextBox_ItemCount_Font_Family"]);
    font.setPointSize(conf["TextBox_ItemCount_Font_Size"].toInt());
    ui->sbCount->setFont(font);

    font.setFamily(conf["TextBox_Price_Font_Family"]);
    font.setPointSize(conf["TextBox_Price_Font_Size"].toInt());
    ui->lePrice->setFont(font);

    font.setFamily(conf["TextBox_Party_Font_Family"]);
    font.setPointSize(conf["TextBox_Party_Font_Size"].toInt());
    ui->sbParty->setFont(font);

    font.setFamily(conf["TextBox_Date_Font_Family"]);
    font.setPointSize(conf["TextBox_Date_Font_Size"].toInt());
    ui->deDate->setFont(font);

    font.setFamily(conf["TextBox_BossLevel_Font_Family"]);
    font.setPointSize(conf["TextBox_BossLevel_Font_Size"].toInt());
    ui->cbBossLevel->setFont(font);

    font.setFamily(conf["TextBox_BossName_Font_Family"]);
    font.setPointSize(conf["TextBox_BossName_Font_Size"].toInt());
    ui->cbBossName->setFont(font);

    font.setFamily(conf["TextBox_ItemName_Font_Family"]);
    font.setPointSize(conf["TextBox_ItemName_Font_Size"].toInt());
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

    ui->lblPer4->installEventFilter(this);
#if (MODE_RELEASE != 1)
    ui->lblPer3->installEventFilter(this);
#endif
    connect(ui->pbInsert, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCalEnd, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbCopy, SIGNAL(clicked()), this, SLOT(btnClick()));
    connect(ui->pbSelectCheck, SIGNAL(clicked()), this, SLOT(btnClick()));

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


MainWindow::~MainWindow() /* 소멸자 */
{
    achieve->saveData();
    delete ui;
}

