#ifndef PLUGINMAIN_H
#define PLUGINMAIN_H

#include <QVariant>
#include <QString>
#include <QObject>
#include "mainwindow.h"
#include "logindlg.h"
#include <QFile>
#include <QtSql/QtSql>
#include "pluginInterface.h"

class pluginmain : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "asia.gkc.Plugin.SManager.Main/1.0")
    Q_INTERFACES(PluginInterface)
public:
    pluginmain();
    const QString name() const{
        return QString("Main");
    }
    const QString version() const{
        return QString("1.0");
    }
    const QString author() const{
        return QString("Jakes");
    }
    const QString signature() const{
        return QString("asia.gkc.Plugin.SManager.Main");
    }
    const QString function() const {
        return QString("asia.gkc.function.Main");
    }
    void setParentObject(QObject * parent){
        this->parent = parent;
    }
    int isPlugin() const {
        return 11011010;
    }
    QVariant run(QVariant value,const QString & function);
private:
    QObject * parent;
};

#endif // PLUGINMAIN_H
