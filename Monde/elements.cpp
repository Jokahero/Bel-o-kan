#include "elements.h"

#include "monde.h"
#include "position.h"

Elements::Elements(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType) : m_pos(pAbcisse, pOrdonnee), m_monde(pMonde) {
    m_mort = false;
    m_type = pType;
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
    m_mort = pMort;
}
