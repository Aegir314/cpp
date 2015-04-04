#-------------------------------------------------
#
# Project created by QtCreator 2015-01-18T12:58:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tooltips
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    linkfilter.cpp

HEADERS  += dialog.h \
    linkfilter.h

FORMS    += dialog.ui

RESOURCES += \
    MyRes.qrc
