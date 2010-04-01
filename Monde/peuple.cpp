#include "peuple.h"

#include "monde.h"
#include "../AppBase/Constantes.h"

#include <QtCore/QDebug>

int Peuple::m_brindilles = 0;
int Peuple::m_nourriture = 0;
int Peuple::m_pop = 0;
int Peuple::m_nbFemelles = 0;
int Peuple::m_nbMales = 0;
int Peuple::m_nbPetits = 0;

Peuple::Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType) : Mobiles(pMonde, pAbcisse, pOrdonnee, pType) {
    setAge(0);
    setPopulation(getPopulation() + 1);
    setPvMax(Constantes::pv);
    setPv(Constantes::pv);
    setVitesse((qrand() % Constantes::vitesseMaxPeuple) + 1);
    setVue((qrand() % Constantes::vueMaxPeuple) + 1);
}

Peuple::~Peuple() {
    qDebug() << "~Peuple";
    setPopulation(getPopulation() - 1);
}

void Peuple::setBrindilles(int pBrindilles) {
    m_brindilles = pBrindilles;
}

void Peuple::setNourriture(int pNourriture) {
    m_nourriture = pNourriture;
}

void Peuple::tour() {
    Elements::tour();
    // Consommation de nourriture
    if (getNourriture() > 0) {
        setNourriture(getNourriture() - 1);
        emit ajoutNourriture(-1);
    } else
        degats(1);

    // Il ne sert à rien de changer l'âge d'un cadavre
    if (isMort())
        return;

    // Augmentation de l'âge
    setAge(getAge() + 1);
    if (getAge() > Constantes::esperanceVie)
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

void Peuple::setNbFemelles(int pNbFemelles) {
    m_nbFemelles = pNbFemelles;
}

void Peuple::setNbMales(int pNbMales) {
    m_nbMales = pNbMales;
}

void Peuple::setNbPetits(int pNbPetits) {
    m_nbPetits = pNbPetits;
}

void Peuple::setAge(int pAge) {
    m_age = pAge;
}

void Peuple::reproduction(ParametresMonde::typeElement pTE, const Position& pPos) {
    deplacement(pPos);
    if (getPos() != pPos)
        return;

    ParametresMonde::typeElement type;
    if (pTE == ParametresMonde::Femelle)
        type = ParametresMonde::Male;
    else
        type = ParametresMonde::Femelle;

    Position partenaire;
    bool partTrouve = false;
    Position petit;
    bool petitTrouve = false;
    bool distanceOk = false;
    QList<Position> posAdj = pPos.getPositionsAdjacentes();
    for (int i = 0; i < posAdj.size() && (!partTrouve || !petitTrouve) && !distanceOk; i ++) {
        if (getMonde()->getInfos()->contains(posAdj.at(i))) {
            if (getMonde()->getElements()->at(getMonde()->getInfos()->value(posAdj.at(i)))->getType() == type) {
                partenaire = posAdj.at(i);
                partTrouve = true;
            }
        } else {
            petit = posAdj.at(i);
            petitTrouve = true;
        }
        if (petitTrouve && partTrouve)
            if (petit.distance(partenaire) == 1)
                distanceOk = true;
    }

    if (!getMonde()->getElements()->at(getMonde()->getInfos()->value(partenaire))->isBouge())
        getMonde()->ajoutPetit(petit);
}
