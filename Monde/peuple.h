#ifndef PEUPLE_H
#define PEUPLE_H

class Monde;

#include "mobiles.h"

class Peuple : public Mobiles {
public:
    Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee);
};

#endif // PEUPLE_H
