#include "mobiles.h"

#include "elements.h"
#include "monde.h"

#include <QtCore/QDebug>

Mobiles::Mobiles(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType) : Elements(pMonde, pAbcisse, pOrdonnee, pType) {
    setVitesse((qrand() % 3) + 1);
    setVue((qrand() % 3) + 1);
}

void Mobiles::setVitesse(int pVitesse) {
    m_vitesse = pVitesse;
}

void Mobiles::setVue(int pVue) {
    m_vue = pVue;
}

void Mobiles::deplacement(const Position &pDest) {
    Position dest = pDest;

    // On vérifie que la distance ne soit pas trop longue, auquel cas on va le plus loin possible en direction de la destination
    while (getPos().distance(dest) > getVitesse() && dest != getPos()) {
        if (getPos().getAbcisse() > dest.getAbcisse())
            dest.setAbcisse(dest.getAbcisse() + 1);
        else if (getPos().getAbcisse() < dest.getAbcisse())
            dest.setAbcisse(dest.getAbcisse() - 1);
        else if (getPos().getOrdonnee() > dest.getOrdonnee())
            dest.setOrdonnee(dest.getOrdonnee() + 1);
        else if (getPos().getOrdonnee() < dest.getOrdonnee())
            dest.setOrdonnee(dest.getOrdonnee() - 1);
        else
            dest = getPos();
    }

    if (dest != getPos()) {
        getMonde()->deplacer(this, dest);
        setPos(dest);
    }
}

void Mobiles::setPv(int pPv) {
    if (pPv <= getPvMax())
        m_pv = pPv;
    else
        m_pv = getPvMax();
}

void Mobiles::setPvMax(int pPvMax) {
    if (pPvMax < getPv())
        m_pv = pPvMax;
    m_pvMax = pPvMax;

}

void Mobiles::degats(int pQte) {
    setPv(getPv() - pQte);
    if (getPv() <= 0)
        mort();
}

void Mobiles::mort() {
    setMort(true);
}
