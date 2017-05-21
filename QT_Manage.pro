#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T13:28:06
#
#-------------------------------------------------

QT       += core gui webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Manage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapwindow.cpp \
    list.cpp \
    locationinfo.cpp \
    managewindow.cpp \
    addwindow.cpp \
    sendadd.cpp

HEADERS  += mainwindow.h \
    mapwindow.h \
    list.h \
    locationinfo.h \
    managewindow.h \
    addwindow.h \
    sendadd.h

FORMS    += mainwindow.ui \
    mapwindow.ui \
    managewindow.ui \
    addwindow.ui

RESOURCES += \
    resources.qrc
