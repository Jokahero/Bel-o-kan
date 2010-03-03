#include "position.h"

#include "monde.h"

#include <QtCore/QList>

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

QList<Position> Position::getPositionsAdjacentes() const {
    QList<Position> liste;
    int hauteur = Monde::instance()->getParams().hauteur - 1;
    int largeur = Monde::instance()->getParams().largeur - 1;
    if (m_abcisse > 0)
        liste.append(Position(m_abcisse - 1, m_ordonnee));
    if (m_ordonnee > 0)
        liste.append(Position(m_abcisse, m_ordonnee - 1));
    if (m_abcisse < largeur)
        liste.append(Position(m_abcisse + 1, m_ordonnee));
    if (m_ordonnee < hauteur)
        liste.append(Position(m_abcisse, m_ordonnee + 1));
    if (m_abcisse % 2 == 0 && m_ordonnee < hauteur && m_abcisse > 0)
        liste.append(Position(m_abcisse - 1, m_ordonnee + 1));
    if (m_abcisse % 2 == 0 && m_ordonnee < hauteur && m_abcisse < largeur)
        liste.append(Position(m_abcisse + 1, m_ordonnee + 1));
    if (m_abcisse % 2 == 1 && m_ordonnee > 0 && m_abcisse > 0)
        liste.append(Position(m_abcisse - 1, m_ordonnee - 1));
    if (m_abcisse % 2 == 1 && m_ordonnee > 0 && m_abcisse < largeur)
        liste.append(Position(m_abcisse + 1, m_ordonnee + 1));

    return liste;
}
