#include "position.h"

#include <QtGlobal>

Position::Position(int pAbcisseMax, int pOrdonneeMax) {
    m_abcisse = qrand() % pAbcisseMax;
    m_ordonnee = qrand() % pOrdonneeMax;
}

void Position::setAbcisse(int pAbcisse) {
    m_abcisse = pAbcisse;
}

void Position::setOrdonnee(int pOrdonnee) {
    m_ordonnee = pOrdonnee;
}
