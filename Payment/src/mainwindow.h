#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QDateTime>
#include <QTimer>
#include <cstdlib>
#include <QMessageBox>
#include "qsqlite.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addNew();
    void edit();
    void delItem();
    void showAs();
    void countToday();
    void countAll();
    void flushData();
    void flushData(QSqlite::rowCondition&);
    void count();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    bool eventFilter(QObject *, QEvent *);
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    QPoint m_nStart;
    QSqlite sqlite;
};

#endif // MAINWINDOW_H
