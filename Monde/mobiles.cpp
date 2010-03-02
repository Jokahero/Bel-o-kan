#include "mobiles.h"

#include "monde.h"

Mobiles::Mobiles(Monde* pMonde, int pAbcisse, int pOrdonnee) : Elements(pMonde, pAbcisse, pOrdonnee) {
}

void Mobiles::setVitesse(int pVitesse) {
    m_vitesse = pVitesse;
}

void Mobiles::setVue(int pVue) {
    m_vue = pVue;
}
