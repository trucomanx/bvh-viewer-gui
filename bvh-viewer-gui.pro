#-------------------------------------------------
#
# Project created by QtCreator 2018-10-02T10:59:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bvh-viewer-gui
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp

INCLUDEPATH += headers
HEADERS  += headers/mainwindow.h

FORMS    += ui/mainwindow.ui

RESOURCES += \
    $${TARGET}.qrc
