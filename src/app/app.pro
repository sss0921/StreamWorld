TEMPLATE = app
include(../../streamworld.pri)
QT += widgets

TARGET = streamworld
DESTDIR = $$STREAMWORLD_BIN_PATH
LIBS += -L$$STREAMWORLD_LIB_PATH

SOURCES += main.cpp \
    mainwindow.cpp \
    videodialog.cpp \
    settingsdialog.cpp

FORMS += \
    mainwindow.ui \
    videodialog.ui \
    settingsdialog.ui

HEADERS += \
    mainwindow.h \
    videodialog.h \
    settingsdialog.h

RESOURCES += \
    resource.qrc
