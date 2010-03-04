#include "elements.h"

#include "monde.h"
#include "position.h"

Elements::Elements(Monde* pMonde, int pAbcisse, int pOrdonnee) : m_monde(pMonde) {
    m_pos = new Position(pAbcisse, pOrdonnee);
    m_mort = false;
}

Elements::~Elements() {
    delete m_pos;
}

void Elements::setPos(Position *pPos) {
    m_pos = pPos;
}

Position Elements::getPos() const {
    return *m_pos;
}

void Elements::setMort(bool pMort) {
    m_mort = pMort;
}
