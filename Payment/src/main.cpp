#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"
#include <QFile>
#include <QtSql/QtSql>
bool databaseCreate(){
    QSqlDatabase dbconn=QSqlDatabase::addDatabase("QSQLITE");
    dbconn.setDatabaseName("data.db");
    if(!dbconn.open())    {
      qDebug()<<"dbconn fail"<<endl;
      return false;
    }
    QSqlQuery query;
    return query.exec("create table payData(id int auto_increment primary key,amount varchar,paytype varchar,year varchar,month varchar,day varchar,note varchar)");
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDlg dlg;
    dlg.exec();
    if(!QFile::exists("data.db")){
        if(QMessageBox::warning(nullptr,"Database Error!","Datebase is invalid, create it ?(yes/NO)",QMessageBox::Yes|QMessageBox::No)
                == QMessageBox::No)
            return 1;
        else
            if(!databaseCreate())
                return 1;
    }
    MainWindow w;
    w.show();
    
    return a.exec();
}
