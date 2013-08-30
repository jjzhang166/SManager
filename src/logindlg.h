#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();
public slots:
    void exitBtnPush();
    void unlockBtnPush();
    
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
private:
    Ui::LoginDlg *ui;
    QPoint m_nStart;

    bool checkKey(const QString &);
};

#endif // LOGINDLG_H
