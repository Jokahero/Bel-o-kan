#ifndef MYCELIUM_H
#define MYCELIUM_H

#include "ressources.h"

class Monde;

class Mycelium : public Ressources {
    Q_OBJECT

public:
    Mycelium(Monde *pMonde, int pAbcisse, int pOrdonnee);
    ~Mycelium();
};

#endif // MYCELIUM_H
