#ifndef QSQLITE_H
#define QSQLITE_H

#include <QtSql/QtSql>
#include <QDebug>

class QSqlite
{
public:
    explicit QSqlite(const QString & path = {"data.db"});
    ~QSqlite();

    typedef QMap<QString,QString> rowCondition;

    void addRow(QStringList &);
    void addRows(QVector<QStringList> &);

    QStringList getRow(const rowCondition&);

    void editRow(const rowCondition &,const QStringList &);

    void deleteRow(const rowCondition &);

    void clearAll();

private:
    QString databasePath;
    QSqlDatabase hDatabase;
    QSqlQuery query;
    QVector<QStringList> svecData;

    bool query(const QString &);
};

#endif // QSQLITE_H
