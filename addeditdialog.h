#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class addEditDialog;
}

class addEditDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit addEditDialog(QWidget *parent = 0);
    ~addEditDialog();

    void setEdit(int);
    
private:
    Ui::addEditDialog *ui;
    int id;
    double amount;
    QString payType;
    QString note;
    QDateTime datetime;
};

#endif // ADDEDITDIALOG_H
