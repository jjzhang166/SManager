#include "addeditdialog.h"
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

void addEditDialog::setEdit(int id){
    this->id = id;
}
