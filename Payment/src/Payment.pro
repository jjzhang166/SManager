#-------------------------------------------------
#
# Project created by QtCreator 2013-05-26T07:29:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMPlugin-Main
TEMPLATE = lib
DLLDESTDIR = ../SManager-plugins/plugins
CONFIG += c++11
INCLUDEPATH += ../../../PluginManager

Release:QMAKE_POST_LINK += upx -9 $(DESTDIR_TARGET)

QMAKE_CXXFLAGS += -std=c++11

SOURCES +=\
        mainwindow.cpp \
    logindlg.cpp \
    qlistctrl.cpp \
    addeditdialog.cpp \
    qsqlite.cpp \
    showasdlg.cpp \
    pluginmain.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    qlistctrl.h \
    addeditdialog.h \
    qsqlite.h \
    showasdlg.h \
    pluginmain.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    addeditdialog.ui \
    showasdlg.ui

RESOURCES += \
    res.qrc
