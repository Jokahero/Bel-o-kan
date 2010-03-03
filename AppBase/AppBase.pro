TEMPLATE = app
TARGET = Bel-O-Kan

DESTDIR = ../

HEADERS += ParamsMonde.h \
    fenconfig.h
SOURCES += main.cpp \
    fenconfig.cpp

LIBS += -L.. -lMonde -lGUI
