#include "showasdlg.h"
#include "ui_showasdlg.h"

ShowAsDlg::ShowAsDlg(QWidget *parent) :
    QDialog(parent),ui(new Ui::ShowAsDlg),MW(static_cast<MainWindow*>(parent))
{
    ui->setupUi(this);
    QDate date = QDate::currentDate();
    for(int i = 1;i <= 31;++i)
        ui->comboBox_Day->addItem(QString("%1").arg(i));
    for(int i = 1;i <= 12;++i)
        ui->comboBox_Month->addItem(QString("%1").arg(i));
    int now = date.year();
    for(int i = 2010;i <= now;++i)
        ui->comboBox_Year->addItem(QString("%1").arg(i));
    ui->comboBox_Day->addItem("ALL");
    ui->comboBox_Month->addItem("ALL");
    ui->comboBox_Year->addItem("ALL");
    ui->comboBox_Day->setCurrentText(date.toString("d"));
    ui->comboBox_Month->setCurrentText(date.toString("M"));
    ui->comboBox_Year->setCurrentText(date.toString("yyyy"));
    connect(ui->pushButton,&QPushButton::clicked,this,&ShowAsDlg::show);
}

ShowAsDlg::~ShowAsDlg()
{
    delete ui;
}

void ShowAsDlg::show(){
    QSqlite::rowCondition rcond;
    if(ui->comboBox_Day->currentText() != "ALL"){
        rcond.insert("day",ui->comboBox_Day->currentText());
    }
    if(ui->comboBox_Month->currentText() != "ALL"){
        rcond.insert("month",ui->comboBox_Month->currentText());
    }
    if(ui->comboBox_Year->currentText() != "ALL"){
        rcond.insert("year",ui->comboBox_Year->currentText().right(2));
    }
    rcond.insert("1","1");
    MW->flushData(rcond);
    MW->count();
    accept();
}
