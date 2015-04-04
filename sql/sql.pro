#-------------------------------------------------
#
# Project created by QtCreator 2015-03-05T09:10:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sql
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mainwindow.cpp \
    login.cpp

HEADERS  += dialog.h \
    mainwindow.h \
    login.h

FORMS    += dialog.ui \
    mainwindow.ui \
    login.ui

RESOURCES +=

DISTFILES +=
