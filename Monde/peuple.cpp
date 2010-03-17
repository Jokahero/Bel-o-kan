#include "peuple.h"

#include "monde.h"
#include "../AppBase/Constantes.h"

#include <QtCore/QDebug>

bool Peuple::init = false;
int Peuple::m_brindilles = 0;
int Peuple::m_nourriture = 0;
int Peuple::m_pop = 0;

Peuple::Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType) : Mobiles(pMonde, pAbcisse, pOrdonnee, pType) {
    if (!init) {
        m_brindilles = getMonde()->getParams().nbBrindilles;
        m_nourriture = getMonde()->getParams().nbNourriture;
        m_pop = 0;
        init = true;
    }
    setAge(0);
    setPopulation(getPopulation() + 1);
    setPv(Constantes::esperanceVie);
}

void Peuple::setBrindilles(int pBrindilles) {
    m_brindilles = pBrindilles;
}

void Peuple::setNourriture(int pNourriture) {
    m_nourriture = pNourriture;
}

void Peuple::tour() {
    // Consommation de nourriture
    if (getNourriture() > 0) {
        setNourriture(getNourriture() - 1);
        emit ajoutNourriture(-1);
        setAge(getAge() + 1);
    } else
        degats(1);
}

void Peuple::mort() {
    Mobiles::mort();
    setPopulation(getPopulation() - 1);
    qDebug() << "Un membre du peuple est mort, population restante : " << getPopulation();
    if (getPopulation() <= 0)
        getMonde()->fin();
}

void Peuple::setPopulation(int pPopulation) {
    m_pop = pPopulation;
}

void Peuple::setAge(int pAge) {
    m_age = pAge;
}
