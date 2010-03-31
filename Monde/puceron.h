#ifndef PUCERON_H
#define PUCERON_H

#include "ressources.h"
#include "mobiles.h"
//#include "ressourcesmobiles.h"
#include "../AppBase/ParamsMonde.h"

class Puceron : virtual public Ressources, virtual public Mobiles {
public:
    Puceron(Monde* pMonde, int pAbcisse, int pOrdonnee);
    ~Puceron();

    virtual void tour();
};

#endif // PUCERON_H
