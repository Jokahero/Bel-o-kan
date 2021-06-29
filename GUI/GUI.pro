TARGET = GUI
TEMPLATE = lib
HEADERS += hexagone.h \
    carte.h \
    fencarte.h \
    widgetinfos.h \
    flowlayout.h \
    widgetinter.h
SOURCES += hexagone.cpp \
    carte.cpp \
    fencarte.cpp \
    widgetinfos.cpp \
    flowlayout.cpp \
    widgetinter.cpp
DESTDIR = ../
RESOURCES += Images.qrc
QT += gui widgets
