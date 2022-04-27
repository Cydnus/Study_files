#include "insertdialog.h"
#include "ui_insertdialog.h"

InsertDialog::InsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItems(Convert::getInstance()->getKeyStrings());


    connect(ui->buttonBox, SIGNAL(accepted()),this,SLOT(btnBox_Click()));
}


void InsertDialog::btnBox_Click()
{

    connect(this, SIGNAL(sendData(QString)), parent(), SLOT(insertDialogmsg(QString)));
    //  sendData 함수를 메인 윈도우의  recData 함수로  전송
    emit sendData(ui->comboBox->currentText());

}
InsertDialog::~InsertDialog()
{
    delete ui;
}
