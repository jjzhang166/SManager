#include "qsqlite.h"

QSqlite::QSqlite(const QString & path):databasePath(path),hDatabase(QSqlDatabase::addDatabase("QSQLITE")),
    tableName_("test"),cols(1),query_(hDatabase)
{
    hDatabase.setDatabaseName(databasePath);
    if(!hDatabase.open()){
        qDebug()<<"Connection error"<<endl;
    }
    query_.clear();
}

QSqlite::~QSqlite(){
    hDatabase.close();
}

void QSqlite::addRow(QStringList & row){
    for(int i = row.size();i < cols;++i)
        row<<"";
    QString queryTmp = QString("insert into `%1` values(").arg(tableName_);
    for(int i = 0;i < cols;++i){
        queryTmp += QSqlite::toString(row.at(i));
        queryTmp.append(((i+1)!=cols?",":")"));
    }
    query(queryTmp);
    qDebug()<<query_.lastError();
}

void QSqlite::addRows(QVector<QStringList> & svecRows){
    for(QVector<QStringList>::iterator iter = svecRows.begin();
        iter != svecRows.end();++iter){
        addRow(*iter);
    }
}

QVector<QStringList> QSqlite::getRow(const rowCondition & rcond){
    QString queryTmp = QString("select * from `%1` where ").arg(tableName_);
    int nCount = 1;
    for(auto iter = rcond.constBegin();iter != rcond.constEnd();++iter,++nCount){
        queryTmp += QString("%1 = %2").arg(iter.key()).arg(iter.value());
        queryTmp.append(nCount<rcond.size()?" AND ":" ");
    }
    query(queryTmp);
    getData();
    return svecData;
}

int QSqlite::getRowNum(){
    rowCondition rcond;
    rcond.insert("1","1");
    getRow(rcond);
    return svecData.size();
}

void QSqlite::editRow(const rowCondition & rcond, const columnPairs & cols){
    QString queryTmp = QString("update `%1` set ").arg(tableName_);
    int nCount = 1;
    for(auto citer = cols.cbegin();
        citer != cols.cend();++citer,++nCount){
        queryTmp += QString(" %1 = %2").arg(citer.key()).arg(citer.value());
        queryTmp.append(nCount<cols.size()?",":" ");
    }
    queryTmp += "where ";
    nCount = 1;
    for(auto citer = rcond.cbegin();
        citer != rcond.cend();++citer,++nCount){
        queryTmp += QString(" %1 = %2").arg(citer.key()).arg(QSqlite::toString(citer.value()));
        queryTmp.append(nCount<rcond.size()?",":" ");
    }
    query(queryTmp);
}

void QSqlite::deleteRow(const rowCondition &){

}

void QSqlite::setTableName(const QString & name){
    tableName_ = name;
}

void QSqlite::setColsNum(int cols){
    this->cols = cols;
}

QString QSqlite::addSlashes(const QString & str){
    return QString(str).replace("\"","\\\"");
}

QString QSqlite::stripSlashes(const QString & str){
    return QString(str).replace("\\\"","\"");
}

bool QSqlite::query(const QString & queryString){
    return query_.exec(queryString);
}

int QSqlite::colsNum() const{
    return cols;
}

QString QSqlite::tableName() const{
    return tableName_;
}

void QSqlite::getData(){
    svecData.clear();
    QStringList SlTmp;
    while(query_.next()){
        for(int i = 0;i < cols;++i){
            SlTmp<<query_.value(i).toString();
        }
        svecData.append(SlTmp);
        SlTmp.clear();
    }
    query_.clear();
}
