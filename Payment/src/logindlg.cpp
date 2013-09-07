#include "logindlg.h"
#include "ui_logindlg.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    QFile style(":/res/qss/logindlg.qss");
    style.open(QFile::ReadOnly);
    setStyleSheet(style.readAll());
    ui->lineEdit->setFocus();
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::exitBtnPush(){
    exit(0);
}

void LoginDlg::mousePressEvent(QMouseEvent *e){
    m_nStart = e->globalPos() - pos();
}
void LoginDlg::mouseMoveEvent(QMouseEvent *e){
    move(e->globalPos() - m_nStart);
}
void LoginDlg::paintEvent(QPaintEvent*){
    QBitmap bmap(size());
    QPainter p(&bmap);
    QRect btnRect;
    p.fillRect(rect(),Qt::white);
    p.setBrush(Qt::black);
    p.drawRoundedRect(0,0,width() - 1,height() - 1,5,5);
    setMask(bmap);
}

void LoginDlg::unlockBtnPush(){
    QString key = ui->lineEdit->text();
    if(checkKey(key))
        accept();
    else
        emit ui->exitButton->click();
}

bool LoginDlg::checkKey(const QString & key){
    if(key == "jakes")
        return true;
    return false;
}
