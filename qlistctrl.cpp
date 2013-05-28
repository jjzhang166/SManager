#include "qlistctrl.h"

#include <QtGui>
QListCtrl::QListCtrl(QWidget * parent,int cols):rows(0),cols(cols),model(new QStandardItemModel),QTableView(parent){
    model->setColumnCount(cols);
// --------- Initialize The QListCtrl Style ---------
    setColHeight();
    setNoEdit(true);
    rowSelection(true);
    vHeaderHide(true);
    headerHighLight(false);
    setModel(model);
    setHeaderEnabled(false);
    singleSelection(true);
    hideHorizontalScrollBar(true);
// --------- End Init ---------
}
QListCtrl::~QListCtrl(){
// ----- Delete Variable -----
    delete model;
// ----- End Delete -----
}
void QListCtrl::setHeaderName(int cols,const QString & name){
    model->setHeaderData(cols,Qt::Horizontal,name);
}
void QListCtrl::setHeaderName(QStringList & string){
    for(int i = string.size();i < cols;++i)
        string << tr("");
    for(int i = 0;i < cols;++i)
        model->setHeaderData(i,Qt::Horizontal,tr(string.at(i).toLocal8Bit()));
}
void QListCtrl::setCols(int cols){
    model->setColumnCount(cols);
    this->cols = cols;
}
void QListCtrl::addRow(QStringList & string){
    for(int i = string.size();i < cols;++i)
        string << tr("");
    for(int i = 0;i < cols;++i)
        model->setItem(rows,i,new QStandardItem(tr(string.at(i).toLocal8Bit())));
    setColHeight(rows,horizontalHeader()->height());
    rows++;
    if(vScrollBarVisible())
        QTableView::setColumnWidth(cols - 1,lastColLen - verticalScrollBar()->sizeHint().width() - 2);
    else
        QTableView::setColumnWidth(cols - 1,lastColLen);
}
void QListCtrl::setColHeight(int height){
    horizontalHeader()->setFixedHeight(height);
    for(int i = 0;i < rows;++i)
        setRowHeight(i,height);
}
void QListCtrl::setColHeight(int row,int height){
    horizontalHeader()->setFixedHeight(height);
    setRowHeight(row,height);
}
void QListCtrl::setNoEdit(bool bEdit){
    setEditTriggers(bEdit?QTableView::NoEditTriggers:QTableView::AllEditTriggers);
}
void QListCtrl::setWidth(){
    setFixedWidth(parentWidget()->width());
}
void QListCtrl::setWidth(int width){
    setFixedWidth(width);
}
void QListCtrl::hideHorizontalScrollBar(bool bHHS){
    setHorizontalScrollBarPolicy(bHHS?Qt::ScrollBarAlwaysOff:Qt::ScrollBarAsNeeded);
}
void QListCtrl::hideVerticalScrollBar(bool bHVS){
    setHorizontalScrollBarPolicy(bHVS?Qt::ScrollBarAlwaysOff:Qt::ScrollBarAsNeeded);
}
void QListCtrl::rowSelection(bool bRow){
    setSelectionBehavior(bRow?QTableView::SelectRows:QTableView::SelectItems);
}
void QListCtrl::singleSelection(bool bSS){
    setSelectionMode(bSS?QAbstractItemView::SingleSelection:QAbstractItemView::MultiSelection);
}
void QListCtrl::vHeaderHide(bool bVHide){
    verticalHeader()->setHidden(bVHide);
}
void QListCtrl::setHeaderEnabled(bool bSE){
    horizontalHeader()->setEnabled(bSE);
}
void QListCtrl::headerHighLight(bool bHL){
    horizontalHeader()->setHighlightSections(bHL);
}
bool QListCtrl::vScrollBarVisible() const{
    if(qCeil(horizontalHeader()->height()*(rows + 1)) >= geometry().height())
        return true;
    else
        return false;
}
void QListCtrl::setColumnWidth(int column, int width){
    setWidth();
    QTableView::setColumnWidth(column,width);
    int leftColWidth = width;
    for(int i = 0;i < column;i++)
        leftColWidth += columnWidth(i);
    for(int i = column + 1;i < cols;++i)
        QTableView::setColumnWidth(i,(this->width() - leftColWidth)/(cols - column - 1) - 2);
    lastColLen = columnWidth(cols - 1);
}
void QListCtrl::removeRow(int row){
    model->removeRow(row);
}
void QListCtrl::clear(){
    model->removeRows(0,rows);
    QTableView::setColumnWidth(cols - 1,lastColLen);
    rows = 0;
}
