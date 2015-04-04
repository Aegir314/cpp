#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T16:55:35
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = ATcpServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    myclient.cpp \
    mytask.cpp

HEADERS += \
    myserver.h \
    myclient.h \
    mytask.h
