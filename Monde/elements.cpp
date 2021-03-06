#include "elements.h"

#include "monde.h"
#include "position.h"

Elements::Elements(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType) : m_pos(pAbcisse, pOrdonnee), m_monde(pMonde) {
    m_mort = false;
    m_type = pType;

    connect(this, SIGNAL(ajoutBrindilles(int)), getMonde(), SIGNAL(ajoutBrindilles(int)));
    connect(this, SIGNAL(ajoutNourriture(int)), getMonde(), SIGNAL(ajoutNourriture(int)));
}

Elements::~Elements() {
}

void Elements::setPos(const Position &pPos) {
    m_pos = Position(pPos.getAbcisse(), pPos.getOrdonnee());
}

Position Elements::getPos() const {
    return m_pos;
}

void Elements::setMort(bool pMort) {
    if (pMort)
        qDebug() << "Un élément est mort en " << getPos();
    m_mort = pMort;
}

void Elements::setBouge(bool pBouge) {
    m_bouge = pBouge;
}
