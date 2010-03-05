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
    getMonde()->deplacer(this, pDest);
    setPos(pDest);
}
