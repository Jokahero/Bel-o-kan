#ifndef PREDATEUR_H
#define PREDATEUR_H

#include "mobiles.h"

class Predateur : public Mobiles {
public:
    Predateur(Monde* pMonde, int pAbcisse, int pOrdonnee);

    virtual void tour();
};

#endif // PREDATEUR_H
