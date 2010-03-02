#include "position.h"

#include <QtGlobal>

#include <QtCore/QDebug>

Position::Position(int pAbcisseMax, int pOrdonneeMax) {
    qDebug() << "Debut";
    qDebug() << "pAbcisseMax : " << pAbcisseMax;
    qDebug() << "pOrdonneeMax : " << pOrdonneeMax;
    m_abcisse = qrand() % pAbcisseMax;
    m_ordonnee = qrand() % pOrdonneeMax;
    qDebug() << "m_abcisse : " << m_abcisse;
    qDebug() << "m_ordonnee : " << m_ordonnee;
    qDebug() << "pAbcisseMax : " << pAbcisseMax;
    qDebug() << "pOrdonneeMax : " << pOrdonneeMax;
    qDebug() << "Fin";
}

void Position::setAbcisse(int pAbcisse) {
    m_abcisse = pAbcisse;
}

void Position::setOrdonnee(int pOrdonnee) {
    m_ordonnee = pOrdonnee;
}
