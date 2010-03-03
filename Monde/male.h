#ifndef MALE_H
#define MALE_H

class Monde;

#include "peuple.h"

class Male : public Peuple {
public:
    Male(Monde* pMonde, int pAbcisse, int pOrdonnee);

    virtual void tour();
};

#endif // MALE_H
