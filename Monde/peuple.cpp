#include "peuple.h"

#include "monde.h"

#include <QtCore/QDebug>

bool Peuple::init = false;
int Peuple::m_brindilles = 0;
int Peuple::m_nourriture = 0;

Peuple::Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee) : Mobiles(pMonde, pAbcisse, pOrdonnee) {
    if (!init) {
        m_brindilles = getMonde()->getParams().nbBrindilles;
        m_nourriture = getMonde()->getParams().nbNourriture;
        init = true;
    }
}

void Peuple::setBrindilles(int pBrindilles) {
    m_brindilles = pBrindilles;
}

void Peuple::setNourriture(int pNourriture) {
    m_nourriture = pNourriture;
}

void Peuple::tour() {
    // Consommation de nourriture
    if (getNourriture() > 0)
        setNourriture(getNourriture() - 1);
    else
        mort();
}

void Peuple::mort() {
    qDebug() << "Un membre du peuple est mort";
}
