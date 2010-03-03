#include "position.h"

#include <QtGlobal>

#include <QtCore/QDebug>

Position::Position(int pAbcisse, int pOrdonnee) {
    m_abcisse = pAbcisse;
    m_ordonnee = pOrdonnee;
}

void Position::setAbcisse(int pAbcisse) {
    m_abcisse = pAbcisse;
}

void Position::setOrdonnee(int pOrdonnee) {
    m_ordonnee = pOrdonnee;
}
