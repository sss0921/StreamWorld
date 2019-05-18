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
    model/stationgroup.cpp \
    model/stationlist.cpp \
    tools/textio.cpp \
    widget/adddialog.cpp


FORMS += \
    mainwindow.ui \
    videodialog.ui \
    settingsdialog.ui \
    radiodialog.ui \
    widget/adddialog.ui

HEADERS += \
    mainwindow.h \
    videodialog.h \
    settingsdialog.h \
    radiodialog.h \
    model/station.h \
    model/stationgroup.h \
    model/stationlist.h \
    tools/textio.h \
    widget/adddialog.h


RESOURCES += \
    resource.qrc
