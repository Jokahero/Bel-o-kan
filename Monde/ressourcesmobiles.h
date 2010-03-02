#ifndef RESSOURCESMOBILES_H
#define RESSOURCESMOBILES_H

#include "mobiles.h"
#include "ressources.h"

class RessourcesMobiles : public Mobiles, public Ressources {
public:
    RessourcesMobiles(Monde* pMonde, int pAbcisse, int pOrdonnee);
};

#endif // RESSOURCESMOBILES_H
