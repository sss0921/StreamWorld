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
    radiodialog.cpp \
    model/station.cpp \
    model/stationgroup.cpp

FORMS += \
    mainwindow.ui \
    videodialog.ui \
    settingsdialog.ui \
    radiodialog.ui

HEADERS += \
    mainwindow.h \
    videodialog.h \
    settingsdialog.h \
    radiodialog.h \
    model/station.h \
    model/stationgroup.h

RESOURCES += \
    resource.qrc
