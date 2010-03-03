#ifndef FEMELLE_H
#define FEMELLE_H

class Monde;

#include "peuple.h"

class Femelle : public Peuple {
public:
    Femelle(Monde* pMonde, int pAbcisse, int pOrdonnee);

    virtual void tour();
};

#endif // FEMELLE_H
