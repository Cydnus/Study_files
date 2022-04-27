#ifndef INSERTDIALOG_H
#define INSERTDIALOG_H

#include <QDialog>
#include "convert.h"

namespace Ui {
class InsertDialog;
}

class InsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDialog(QWidget *parent = nullptr);
    ~InsertDialog();

private:
    Ui::InsertDialog *ui;

signals:
      void sendData(QString text);
private slots:
      void btnBox_Click();
};

#endif // INSERTDIALOG_H
