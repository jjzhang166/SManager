#include "addeditdialog.h"
#include "mainwindow.h"
#include "ui_addeditdialog.h"

addEditDialog::addEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEditDialog),id(-1)
{
    ui->setupUi(this);
    ui->payTypeComboBox->addItems(QStringList()<<tr("Breakfast")<<tr("Lunch")<<tr("Dinner")<<tr("Other"));
    ui->amountEdit->setValidator(new QRegExpValidator(QRegExp("^[\-]?[1-9][0-9]*[\.]?[0-9]*$"),this));
}

addEditDialog::~addEditDialog()
{
    delete ui;
}

void addEditDialog::setEdit(QSqlite * db,int id){
    this->id = id;
    sqldb = db;
    QSqlite::rowCondition rcond;
    rcond.insert("id",QString("%1").arg(id));
    QVector<QStringList> svecData = sqldb->getRow(rcond);
    qDebug()<<id<<svecData<<rcond;
    if(svecData.size() != 0){
        ui->amountEdit->setText(svecData.at(0).at(1));
        ui->payTypeComboBox->setCurrentText(svecData.at(0).at(2));
        ui->noteTextEdit->setText(svecData.at(0).at(6));
    }
}

void addEditDialog::saveData(){
    QDate date = QDate::currentDate();

    if(id > -1){
        QSqlite::rowCondition rcond;
        QSqlite::columnPairs cols;
        rcond.insert("id",QString("%1").arg(id));
        cols.insert("amount",QSqlite::toString(ui->amountEdit->text()));
        cols.insert("paytype",QSqlite::toString(ui->payTypeComboBox->currentText()));
//        cols.insert("year",QSqlite::toString(date.toString("yy")));
//        cols.insert("month",QSqlite::toString(date.toString("M")));
//        cols.insert("day",QSqlite::toString(date.toString("d")));
        cols.insert("note",QSqlite::toString(ui->noteTextEdit->toPlainText()));
        sqldb->editRow(rcond,cols);
    }else{
        QStringList line;
        line<<QString("%1").arg(sqldb->getRowNum()+1)<<ui->amountEdit->text()<<ui->payTypeComboBox->currentText()
              <<date.toString("yy")<<date.toString("M")<<date.toString("d")
                <<ui->noteTextEdit->toPlainText();
        qDebug()<<line<<id;
        sqldb->addRow(line);
    }
    accept();
}
