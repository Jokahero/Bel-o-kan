TEMPLATE = app
TARGET = Bel-O-Kan

DESTDIR = ../

HEADERS += ParamsMonde.h
SOURCES += main.cpp

LIBS += -L.. -lMonde -lGUI
