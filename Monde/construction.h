#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include "elements.h"

class Monde;

class Construction : public Elements {
public:
    Construction(Monde* pMonde, int pAbcisse, int pOrdonnee);
    virtual void tour() {};
};

#endif // CONSTRUCTION_H
