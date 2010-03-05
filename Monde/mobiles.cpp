#include "mobiles.h"

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
    while (getPos().distance(dest) > getVitesse()) {
        if (getPos().getAbcisse() > dest.getAbcisse())
            dest.setAbcisse(dest.getAbcisse() + 1);
        else if (getPos().getAbcisse() < dest.getAbcisse())
            dest.setAbcisse(dest.getAbcisse() - 1);
        else if (getPos().getOrdonnee() > dest.getOrdonnee())
            dest.setOrdonnee(dest.getOrdonnee() + 1);
        else
            dest.setOrdonnee(dest.getOrdonnee() - 1);
    }
    getMonde()->deplacer(this, dest);
    setPos(dest);
}
