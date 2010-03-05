#include "monde.h"

#include "brindille.h"
#include "elements.h"
#include "petits.h"
#include "femelle.h"
#include "male.h"
#include "mycelium.h"
#include "position.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QMap>
#include <QtCore/QVector>
#include <QtCore/QDebug>

Monde *Monde::_instance = 0;

Monde *Monde::instance() {
        if (_instance == 0)
                _instance = new Monde;
        return _instance;
}

void Monde::destroy() {
    delete _instance;
    _instance = 0;
}

Monde::Monde() {
    m_infos = new QMap<Position, int>;
    m_elements = new QVector<Elements*>;

    connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(destroy()));
}

Monde::~Monde() {
    for (int i = 0; i < m_elements->size(); i++)
        delete m_elements->at(i);
    delete m_infos;
    delete m_elements;
}

Position Monde::posAleatoire(int pAbcisseMax, int pOrdonneeMax) {
    int abcisse = qrand() % pAbcisseMax;
    int ordonnee = qrand() % pOrdonneeMax;
    Position *pos = new Position(abcisse, ordonnee);
    while (m_infos->contains(*pos)) {
        delete pos;
        abcisse = qrand() % pAbcisseMax;
        ordonnee = qrand() % pOrdonneeMax;
        pos = new Position(abcisse, ordonnee);
    }

    return *pos;
}

void Monde::init(const ParametresMonde::ParamsMonde &pParams) {
    m_params = pParams;
    m_nbTours = 0;

    for (int i = 0; i < pParams.nbFemelles; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Femelle(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Femelle, pos.getAbcisse(), pos.getOrdonnee());
    }

    for (int i = 0; i < pParams.nbMales; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Male(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Male, pos.getAbcisse(), pos.getOrdonnee());
    }

    for (int i = 0; i < pParams.nbPetits; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Petits(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Petits, pos.getAbcisse(), pos.getOrdonnee());
    }

    for (int i = 0; i < pParams.brindilles; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Brindille(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Brindille, pos.getAbcisse(), pos.getOrdonnee());
    }

    for (int i = 0; i < pParams.mycelium; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Mycelium(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Mycelium, pos.getAbcisse(), pos.getOrdonnee());
    }
}

void Monde::tour() {
    for (int i = 0; i < m_elements->size(); i++)
        m_elements->at(i)->tour();

    bringOutYourDeads();
    m_nbTours++;
}

void Monde::fin() {
    emit finDuMonde(m_nbTours);
}

void Monde::bringOutYourDeads() {
    QVector<Elements*> tmp = *m_elements;
    for (int i = 0, sup = 0; i < tmp.size(); i++) {
        if (tmp.at(i)->isMort()) {
            emit supprimerElement(tmp.at(i)->getType(), tmp.at(i)->getPos().getAbcisse(), tmp.at(i)->getPos().getOrdonnee());
            m_infos->remove(tmp.at(i)->getPos());
            m_elements->remove(i - sup);
            sup++;
        }
    }
}

void Monde::deplacer(Elements *pE, const Position& pDest) {
    if (m_infos->contains(pDest)) {
        Elements* tmp = m_elements->at(m_infos->value(pDest));
        emit supprimerElement(tmp->getType(), tmp->getPos().getAbcisse(), tmp->getPos().getOrdonnee());
        m_infos->remove(tmp->getPos());
        if (tmp->getType() == ParametresMonde::Mycelium)
            Peuple::setNourriture(Peuple::getNourriture() + qobject_cast<Mycelium*>(tmp)->getNourriture());
    }
    m_infos->insert(pDest, m_infos->value(pE->getPos()));
    m_infos->remove(pE->getPos());
    emit deplacerElement(pE->getType(), pE->getPos().getAbcisse(), pE->getPos().getOrdonnee(), pDest.getAbcisse(), pDest.getOrdonnee());
}
