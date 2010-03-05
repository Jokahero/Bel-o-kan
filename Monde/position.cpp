#include "position.h"

#include "monde.h"

#include <QtCore/QList>
#include <math.h>

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

QList<Position> Position::getPositionsAdjacentes(int pDistance) const {
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
    if (m_abcisse % 2 == 1 && m_ordonnee > 0 && m_abcisse > 0)
        liste.append(Position(m_abcisse - 1, m_ordonnee - 1));
    if (m_abcisse % 2 == 1 && m_ordonnee > 0 && m_abcisse < largeur)
        liste.append(Position(m_abcisse + 1, m_ordonnee - 1));
    if (m_abcisse % 2 == 0 && m_abcisse > 0 && m_ordonnee < hauteur)
        liste.append(Position(m_abcisse - 1, m_ordonnee + 1));
    if (m_abcisse % 2 == 0 && m_abcisse < largeur && m_ordonnee < hauteur)
        liste.append(Position(m_abcisse + 1, m_ordonnee + 1));

    if (pDistance > 1) {
        pDistance--;
        QList<Position> listeOrig = liste;
        for (int i = 0; i < listeOrig.size(); i++) {
            QList<Position> tmp = listeOrig.at(i).getPositionsAdjacentes(pDistance);
            for (int j = 0; j < tmp.size(); j++) {
                if (!liste.contains(tmp.at(j)) && tmp.at(j) != *this)
                    liste.append(tmp.at(j));
            }
        }
    }

    return liste;
}

int Position::distance(const Position &p) const {
    int decX;
    int decY;
    (getAbcisse() > p.getAbcisse()) ? decX = getAbcisse() - p.getAbcisse() : decX = p.getAbcisse() - getAbcisse();
    (getOrdonnee() > p.getOrdonnee()) ? decY = getOrdonnee() - p.getOrdonnee() : decY = p.getOrdonnee() - getOrdonnee();

    return sqrt((decX * decX) + (decY * decY));
}
