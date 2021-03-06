TARGET = Monde
TEMPLATE = lib
HEADERS += monde.h \
    elements.h \
    position.h \
    mobiles.h \
    ressources.h \
    peuple.h \ # ressourcesmobiles.h \
    male.h \
    femelle.h \
    petits.h \
    mycelium.h \
    brindille.h \
    puceron.h \
    construction.h \
    predateur.h
SOURCES += monde.cpp \
    elements.cpp \
    position.cpp \
    mobiles.cpp \
    ressources.cpp \
    peuple.cpp \ # ressourcesmobiles.cpp \
    male.cpp \
    femelle.cpp \
    petits.cpp \
    mycelium.cpp \
    brindille.cpp \
    puceron.cpp \
    construction.cpp \
    predateur.cpp
DESTDIR = ../
