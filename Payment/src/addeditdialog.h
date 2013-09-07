#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "qsqlite.h"

namespace Ui {
class addEditDialog;
}

class addEditDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit addEditDialog(QWidget *parent = 0);
    ~addEditDialog();

    void setEdit(QSqlite *,int);
public slots:
    void saveData();
    
private:
    Ui::addEditDialog *ui;
    int id;
    QSqlite * sqldb;
};

#endif // ADDEDITDIALOG_H
