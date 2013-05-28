#-------------------------------------------------
#
# Project created by QtCreator 2013-05-26T07:29:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Payment
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    qlistctrl.cpp \
    addeditdialog.cpp \
    qsqlite.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    qlistctrl.h \
    addeditdialog.h \
    qsqlite.h

FORMS    += mainwindow.ui \
    logindlg.ui \
    addeditdialog.ui

RESOURCES += \
    res.qrc
