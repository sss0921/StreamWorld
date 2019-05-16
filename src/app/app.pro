TEMPLATE = app
include(../../streamworld.pri)
QT += widgets

TARGET = streamworld
DESTDIR = $$STREAMWORLD_BIN_PATH
LIBS += -L$$STREAMWORLD_LIB_PATH

SOURCES += main.cpp \
    mainwindow.cpp \
    listdialog.cpp \
    videodialog.cpp

FORMS += \
    mainwindow.ui \
    listdialog.ui \
    videodialog.ui

HEADERS += \
    mainwindow.h \
    listdialog.h \
    videodialog.h

RESOURCES += \
    resource.qrc
