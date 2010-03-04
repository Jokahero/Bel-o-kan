#ifndef MOBILES_H
#define MOBILES_H

class Monde;

#include "elements.h"

class Mobiles : public Elements {
public:
    Mobiles(Monde* pMonde, int pAbcisse, int pOrdonnee);

    inline int getVitesse() const {return m_vitesse;}
    void setVitesse(int pVitesse);

    inline int getVue() const {return m_vue;}
    void setVue(int pVue);

private:
    int m_vitesse;
    int m_vue;
};

#endif // MOBILES_H
