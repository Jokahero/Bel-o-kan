#ifndef BRINDILLE_H
#define BRINDILLE_H

#include "ressources.h"

class Monde;

class Brindille : public Ressources {
public:
    Brindille(Monde *pMonde, int pAbcisse, int pOrdonnee);
};

#endif // BRINDILLE_H
