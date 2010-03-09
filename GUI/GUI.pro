TARGET = GUI
TEMPLATE = lib
HEADERS += hexagone.h \
    carte.h \
    fencarte.h \
    widgetinfos.h
SOURCES += hexagone.cpp \
    carte.cpp \
    fencarte.cpp \
    widgetinfos.cpp
DESTDIR = ../
RESOURCES += Images.qrc
