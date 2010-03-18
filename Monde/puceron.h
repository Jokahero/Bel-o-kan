#ifndef PUCERON_H
#define PUCERON_H

#include "ressourcesmobiles.h"
#include "../AppBase/ParamsMonde.h"

class Puceron : public RessourcesMobiles {
public:
    Puceron(Monde* pMonde, int pAbcisse, int pOrdonnee);

    virtual void tour() {}
};

#endif // PUCERON_H
