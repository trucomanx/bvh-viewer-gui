#-------------------------------------------------
#
# Project created by QtCreator 2018-10-02T10:59:12
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bvh-viewer-gui
TEMPLATE = app
CONFIG += c++11

SOURCES += src/main.cpp\
        src/mainwindow.cpp\
        src/BVHObject.cpp

INCLUDEPATH += headers
HEADERS  += headers/mainwindow.h\
            headers/BVHObject.h\
            headers/Channel.h\
            headers/Joint.h\
            headers/Vector3.h

FORMS    += ui/mainwindow.ui

RESOURCES += \
    $${TARGET}.qrc


LIBS += -lGLU -lGL
INCLUDEPATH += /usr/include/libdrm

LIBS += -lglut

