#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T23:00:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileExplorer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    aboutform.cpp \
    qfexpath.cpp \
    searchform.cpp

HEADERS  += mainwindow.h \
    aboutform.h \
    qfexpath.h \
    searchform.h

FORMS    += \
    mainwindow.ui \
    aboutform.ui \
    searchform.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
