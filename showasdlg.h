#ifndef SHOWASDLG_H
#define SHOWASDLG_H

#include <QDialog>
#include <QComboBox>
#include <QDate>
#include <mainwindow.h>

namespace Ui {
class ShowAsDlg;
}

class ShowAsDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit ShowAsDlg(QWidget *parent = 0);
    ~ShowAsDlg();
    
    void show();

private:
    Ui::ShowAsDlg *ui;
    MainWindow *MW;
};

#endif // SHOWASDLG_H
