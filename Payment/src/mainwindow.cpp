#include "mainwindow.h"
#include "addeditdialog.h"
#include "showasdlg.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QFile style(":/res/qss/main.qss");
    style.open(QFile::ReadOnly);
    setStyleSheet(style.readAll());
    ui->titleLabel->installEventFilter(this);
    ui->CTime_Label->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"));
    ui->qListCtrl->setCols(7);

    ui->qListCtrl->setColumnWidth(0,33);
    ui->qListCtrl->setColumnWidth(1,100);
    ui->qListCtrl->setColumnWidth(2,110);
    ui->qListCtrl->setColumnWidth(3,50);
    ui->qListCtrl->setColumnWidth(4,50);
    ui->qListCtrl->setColumnWidth(5,50);
    ui->qListCtrl->setColumnWidth(6,256);
    ui->qListCtrl->setFixedSize(649,281);
    QStringList strHeaderName;
    strHeaderName<<tr("ID")<<tr("Amount")<<tr("PayType")<<tr("Year")<<tr("Month")<<tr("Day")<<tr("Note");
    ui->qListCtrl->setHeaderName(strHeaderName);

    sqlite.setTableName("payData");
    sqlite.setColsNum(7);
    flushData();

    QTimer *timer = new QTimer(this);
    QObject::connect(timer,&QTimer::timeout,[&](){
        ui->CTime_Label->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"));
    });
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    m_nStart = e->globalPos() - pos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e){
    move(e->globalPos() - m_nStart);
}
void MainWindow::paintEvent(QPaintEvent*){
    QBitmap bmap(size());
    QPainter p(&bmap);
    QRect btnRect;
    p.fillRect(rect(),Qt::white);
    p.setBrush(Qt::black);
    p.drawRoundedRect(0,0,width() - 1,height() - 1,5,5);
    setMask(bmap);
}
bool MainWindow::eventFilter(QObject * obj, QEvent * e){
    static bool bButtonPress = false;
    if(obj == ui->titleLabel){
        QMouseEvent * event = static_cast<QMouseEvent *>(e);
        if(e->type() == QEvent::MouseButtonPress){
            bButtonPress = true;
            m_nStart = event->globalPos() - pos();
        }else if(e->type() == QEvent::MouseMove ){
            if(bButtonPress)
                move(event->globalPos() - m_nStart);
        }else if(e->type() == QEvent::MouseButtonRelease){
            bButtonPress = false;
        }else{
            return false;
        }
        return true;
    }else{
        return false;
    }
}
void MainWindow::addNew(){
    auto dlg = new addEditDialog(this);
    dlg->setWindowTitle(tr("Add New"));
    dlg->setEdit(&sqlite,-1);
    ui->statusLabel->setText("Add new...");
    dlg->exec();

    flushData();
    delete dlg;
    ui->statusLabel->setText("Ready...");
}
void MainWindow::edit(){
    QString id = ui->qListCtrl->getItem(ui->qListCtrl->currentIndex().row());
    if(id != QString("")){
        auto dlg = new addEditDialog(this);
        dlg->setWindowTitle(tr("Edit"));
        dlg->setEdit(&sqlite,id.toInt());
        ui->statusLabel->setText("Editing...");
        dlg->exec();
        flushData();
        delete dlg;
    }else{
        ui->statusLabel->setText("Please select an item...");
    }
}
void MainWindow::delItem(){
    QString id = ui->qListCtrl->getItem(ui->qListCtrl->currentIndex().row());
    if(id != QString("") && QMessageBox::warning(this,"Delete Warning",QString("Do you really want to delete item (id=%1) ?").arg(id),QMessageBox::Yes|QMessageBox::No)
            != QMessageBox::No){
        ui->statusLabel->setText("Deleting...");
        QSqlite::rowCondition rcond;
        rcond.insert("id",id);
        sqlite.deleteRow(rcond);
        flushData();
        ui->statusLabel->setText("Ready...");
    }else{
        ui->statusLabel->setText("Please select an item...");
    }
}
void MainWindow::showAs(){
    auto dlg = new ShowAsDlg(this);
    dlg->exec();
    delete dlg;
}
void MainWindow::countToday(){
    QDate date = QDate::currentDate();
    QSqlite::rowCondition rcond;
    rcond.insert("day",QSqlite::toString(date.toString("d")));
    rcond.insert("month",QSqlite::toString(date.toString("M")));
    rcond.insert("year",QSqlite::toString(date.toString("yy")));
    qDebug()<<rcond;
    flushData(rcond);
    count();
}
void MainWindow::countAll(){
    flushData();
    count();
}
void MainWindow::flushData(){
    QSqlite::rowCondition rcond;
    rcond.insert("1","1");
    flushData(rcond);
}
void MainWindow::flushData(QSqlite::rowCondition& rcond){
    ui->statusLabel->setText("Refreshing...");
    auto db = sqlite.getRow(rcond);
    ui->qListCtrl->clear();
    for(auto iter = db.begin();
        iter != db.end();++iter){
        ui->qListCtrl->addRow(*iter);
    }
    ui->statusLabel->setText("Ready...");
}
void MainWindow::count(){
    int rows = ui->qListCtrl->row();
    double amount = 0;
    for(int i = 0;i < rows;++i){
        amount += ui->qListCtrl->getItem(i,1).toDouble();
    }
    ui->statusLabel->setText(QString("Amount of all is <font color=\"red\">%1</font>￥").arg(amount));
}
