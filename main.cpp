#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDlg dlg;
    dlg.exec();
    MainWindow w;
    w.show();
    
    return a.exec();
}
