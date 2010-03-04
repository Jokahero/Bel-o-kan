#include "mobiles.h"

#include "monde.h"

#include <QtCore/QDebug>

Mobiles::Mobiles(Monde* pMonde, int pAbcisse, int pOrdonnee) : Elements(pMonde, pAbcisse, pOrdonnee) {
    setVitesse((qrand() % 3) + 1);
    setVue((qrand() % 3) + 1);
}

void Mobiles::setVitesse(int pVitesse) {
    m_vitesse = pVitesse;
}

void Mobiles::setVue(int pVue) {
    m_vue = pVue;
}
