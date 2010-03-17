#ifndef BRINDILLE_H
#define BRINDILLE_H

#include "ressources.h"

class Monde;

class Brindille : public Ressources {
    Q_OBJECT

public:
    Brindille(Monde *pMonde, int pAbcisse, int pOrdonnee);
};

#endif // BRINDILLE_H
