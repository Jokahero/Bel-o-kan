#include "monde.h"

#include "brindille.h"
#include "elements.h"
#include "petits.h"
#include "femelle.h"
#include "male.h"
#include "mobiles.h"
#include "mycelium.h"
#include "position.h"
#include "puceron.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QMap>
#include <QtCore/QVector>

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

    for (int i = 0; i < pParams.pucerons; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append((Mobiles*)new Puceron(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
        emit afficherElement(ParametresMonde::Puceron, pos.getAbcisse(), pos.getOrdonnee());
    }

    emit ajoutBrindilles(m_params.nbBrindilles);
    emit ajoutNourriture(m_params.nbNourriture);

    Peuple::setBrindilles(m_params.nbBrindilles);
    Peuple::setNourriture(m_params.nbNourriture);
}

void Monde::tour() {
    m_nbTours++;
    for (int i = 0; i < m_elements->size() && m_nbTours > 0; i++)
        m_elements->at(i)->tour();

    bringOutYourDeads();

    emit sigTour(getEtat());

    if (Peuple::getPopulation() <= 0 && m_nbTours > 0)
        fin();

    for (int i = 0; i < Peuple::getPopulation() / 2; i++) {
        if (m_elements->size() < m_params.hauteur * m_params.largeur) {
            int repop = qrand() % 5;
            Position pos = posAleatoire(m_params.largeur, m_params.hauteur);

            switch (repop) {
            case 0:
                m_elements->append(new Brindille(this, pos.getAbcisse(), pos.getOrdonnee()));
                m_infos->insert(pos, m_elements->size() - 1);
                emit afficherElement(ParametresMonde::Brindille, pos.getAbcisse(), pos.getOrdonnee());
                break;
            case 1:
                m_elements->append(new Mycelium(this, pos.getAbcisse(), pos.getOrdonnee()));
                m_infos->insert(pos, m_elements->size() - 1);
                emit afficherElement(ParametresMonde::Mycelium, pos.getAbcisse(), pos.getOrdonnee());
                break;
            case 2:
                m_elements->append((Mobiles*)new Puceron(this, pos.getAbcisse(), pos.getOrdonnee()));
                m_infos->insert(pos, m_elements->size() - 1);
                emit afficherElement(ParametresMonde::Puceron, pos.getAbcisse(), pos.getOrdonnee());
                break;
            default:
                break;
            }
        }
    }
}

void Monde::fin() {
    emit finDuMonde(m_nbTours);
    m_nbTours = -1;
}

void Monde::bringOutYourDeads() {
    QVector<Elements*> tmp = *m_elements;
    for (int i = 0, sup = 0; i < tmp.size(); i++) {
        if (tmp.at(i)->isMort()) {
            emit supprimerElement(tmp.at(i)->getType(), tmp.at(i)->getPos().getAbcisse(), tmp.at(i)->getPos().getOrdonnee());
            m_infos->remove(tmp.at(i)->getPos());
            // Décalage des valeurs dans la map
            QMapIterator<Position, int> it(*m_infos);
            while (it.hasNext()) {
                it.next();
                if (it.value() > (i - sup))
                    (*m_infos)[it.key()] = it.value() - 1;
            }
            Elements* elmt = m_elements->at(i - sup);
            m_elements->remove(i - sup);
            delete elmt;
            sup++;
        }
    }
}

void Monde::deplacer(Elements *pE, const Position& pDest) {
    if (m_infos->contains(pDest)) {
        int rang = m_infos->value(pDest);
        Elements* tmp = m_elements->at(rang);
        emit supprimerElement(tmp->getType(), tmp->getPos().getAbcisse(), tmp->getPos().getOrdonnee());
        m_infos->remove(tmp->getPos());


        // Décalage des valeurs dans la map
        QMapIterator<Position, int> it(*m_infos);
        while (it.hasNext()) {
            it.next();
            if (it.value() > rang)
                (*m_infos)[it.key()] = it.value() - 1;
        }
        m_elements->remove(rang);



        switch (tmp->getType()) {
        case ParametresMonde::Mycelium:
            Peuple::setNourriture(Peuple::getNourriture() + dynamic_cast<Mycelium*>(tmp)->getNourriture());
            emit ajoutNourriture(dynamic_cast<Mycelium*>(tmp)->getNourriture());
            break;
        case ParametresMonde::Brindille:
            Peuple::setBrindilles(Peuple::getBrindilles() + dynamic_cast<Brindille*>(tmp)->getBrindilles());
            emit ajoutBrindilles(dynamic_cast<Brindille*>(tmp)->getBrindilles());
            break;
        case ParametresMonde::Puceron:
            Peuple::setNourriture(Peuple::getNourriture() + dynamic_cast<Puceron*>(tmp)->getNourriture());
            emit ajoutNourriture(dynamic_cast<Puceron*>(tmp)->getNourriture());
            break;
        default:
            // Regarder si il y a une femelle/homme à côté
            break;
        }
        delete tmp;
    }
    m_infos->insert(pDest, m_infos->value(pE->getPos()));
    m_infos->remove(pE->getPos());
    emit deplacerElement(pE->getType(), pE->getPos().getAbcisse(), pE->getPos().getOrdonnee(), pDest.getAbcisse(), pDest.getOrdonnee());
}

void Monde::evolution(const Position &pPos, int pSexe) {
    emit supprimerElement(ParametresMonde::Petits, pPos.getAbcisse(), pPos.getOrdonnee());
    if (pSexe == 0)
        emit afficherElement(ParametresMonde::Femelle, pPos.getAbcisse(), pPos.getOrdonnee());
    else
        emit afficherElement(ParametresMonde::Male, pPos.getAbcisse(), pPos.getOrdonnee());
}

ParametresMonde::ParamsMonde Monde::getEtat() const {
    ParametresMonde::ParamsMonde p;
    p.brindilles = Ressources::getBrindillesTot();
    p.hauteur = m_params.hauteur;
    p.largeur = m_params.largeur;
    p.mycelium = Ressources::getMyceliumTot();
    p.nbBrindilles = Peuple::getBrindilles();
    p.nbFemelles = Peuple::getNbFemelles();
    p.nbMales = Peuple::getNbMales();
    p.nbNourriture = Peuple::getNourriture();
    p.nbPetits = Peuple::getNbPetits();
    p.pucerons = Ressources::getPuceronsTot();
    return p;
}

void Monde::ajoutPetit(const Position& pPos) {
    m_elements->append(new Petits(this, pPos.getAbcisse(), pPos.getOrdonnee()));
    m_infos->insert(pPos, m_elements->size() - 1);
    emit afficherElement(ParametresMonde::Petits, pPos.getAbcisse(), pPos.getOrdonnee());
}
