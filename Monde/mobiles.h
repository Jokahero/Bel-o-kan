#ifndef MOBILES_H
#define MOBILES_H

class Monde;

#include "elements.h"

class Mobiles : public Elements {
public:
    Mobiles(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType);

    inline int getVitesse() const {return m_vitesse;}
    void setVitesse(int pVitesse);

    inline int getVue() const {return m_vue;}
    void setVue(int pVue);

    inline int getPv() const {return m_pv;}
    void setPv(int pPv);

    inline int getPvMax() const {return m_pvMax;}
    void setPvMax(int pPvMax);

    void degats(int pQte);

    virtual void mort();

    void deplacement(const Position& pDest);

private:
    int m_vitesse;
    int m_vue;
    int m_pv;
    int m_pvMax;
};

#endif // MOBILES_H
