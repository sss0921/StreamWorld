TEMPLATE = app
include(../../streamworld.pri)
QT += widgets

TARGET = streamworld
DESTDIR = $$STREAMWORLD_BIN_PATH
LIBS += -L$$STREAMWORLD_LIB_PATH

SOURCES += main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

RESOURCES += \
    resource.qrc
