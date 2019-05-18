TEMPLATE = app
include(../../streamworld.pri)
QT += widgets

TARGET = streamworld
DESTDIR = $$STREAMWORLD_BIN_PATH
LIBS += -L$$STREAMWORLD_LIB_PATH

SOURCES += main.cpp \
    mainwindow.cpp \
    videodialog.cpp \
    settingsdialog.cpp \
    radiodialog.cpp

FORMS += \
    mainwindow.ui \
    videodialog.ui \
    settingsdialog.ui \
    radiodialog.ui

HEADERS += \
    mainwindow.h \
    videodialog.h \
    settingsdialog.h \
    radiodialog.h

RESOURCES += \
    resource.qrc
