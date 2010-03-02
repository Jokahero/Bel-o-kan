#ifndef PETITS_H
#define PETITS_H

class Monde;

#include "peuple.h"

class Petits : public Peuple {
public:
    Petits(Monde* pMonde, int pAbcisse, int pOrdonnee);
};

#endif // PETITS_H
