#ifndef QQListCtrl_H
#define QQListCtrl_H

#include <QTableView>
#include <QHeaderView>
#include <QScrollBar>
#include <QStringList>
#include <QStandardItemModel>
#include <QWidget>
class QListCtrl : public QTableView{
    Q_OBJECT
public:
    QListCtrl(QWidget * parent = 0, int cols = 1);
    ~QListCtrl();
    void setHeaderName(int,const QString&);
    void setHeaderName(QStringList&);
    void setCols(int cols);
    int row() const;
    void addRow(const QStringList&);
    QString getItem(int,int col = 0);
    void setColHeight(int height = 20);
    void setColHeight(int row,int height);
    void setNoEdit(bool);
    void setWidth();
    void hideHorizontalScrollBar(bool);
    void hideVerticalScrollBar(bool);
    void setWidth(int width);
    void rowSelection(bool);
    void singleSelection(bool);
    void vHeaderHide(bool);
    void setHeaderEnabled(bool);
    void headerHighLight(bool);
    bool vScrollBarVisible() const;
    void setColumnWidth(int column, int width);
    void removeRow(int row = 0);
    void clear();

protected:
    void contextMenuEvent(QContextMenuEvent *);
private:
    int rows,cols;
    int lastColLen;
    QStandardItemModel *model;
    QMenu *popMenu;
    QAction * addItemAction;
    QAction * editItemAction;
    QAction * delItemAction;
    QAction * showAction;
    QAction * countTodayAction;
    QAction * countAllAction;

};

#endif
