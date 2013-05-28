#ifndef QSQLITE_H
#define QSQLITE_H

#include <QtSql/QtSql>
#include <QDebug>

class QSqlite
{
public:
    explicit QSqlite(const QString & path = {"data.db"});
    ~QSqlite();

    typedef QMap<QString,QString> rowCondition,columnPairs;

    void addRow(QStringList &);
    void addRows(QVector<QStringList> &);

    QVector<QStringList> getRow(const rowCondition&);

    void editRow(const rowCondition &,const columnPairs &);

    void deleteRow(const rowCondition &);

    void setTableName(const QString &);
    void setColsNum(int);

    static QString addSlashes(const QString &);
    static QString stripSlashes(const QString &);

    template<typename T>
    QString toString(const T& string){
        QString str(string);
        return QString("\"%1\"").arg(addSlashes(str));
    }

    int colsNum(void) const;
    QString tableName(void) const;

    void clearAll();

private:
    QString databasePath;
    QSqlDatabase hDatabase;
    QSqlQuery query_;
    QVector<QStringList> svecData;

    QString tableName_;
    int cols;

    bool query(const QString &);
    void getData();
};

#endif // QSQLITE_H
