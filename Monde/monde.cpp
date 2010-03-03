#include "monde.h"

#include "elements.h"
#include "petits.h"
#include "femelle.h"
#include "male.h"
#include "position.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QMap>
#include <QtCore/QVector>

#include <QtCore/QDebug>
#include <QtCore/QList>

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

    qDebug() << "position adjacentes, 2, (" + QString::number(pos->getAbcisse()) + ", " + QString::number(pos->getOrdonnee()) + ")";
    QList<Position> tmp = pos->getPositionsAdjacentes(2);
    for (int i = 0; i < tmp.size(); i++)
        qDebug() << "(" + QString::number(tmp.at(i).getAbcisse()) + ", " + QString::number(tmp.at(i).getOrdonnee()) + ")";
    return *pos;
}

void Monde::init(const ParamsMonde &pParams) {
    m_params = pParams;

    for (int i = 0; i < pParams.nbFemelles; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Femelle(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
    }

    for (int i = 0; i < pParams.nbMales; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Male(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
    }

    for (int i = 0; i < pParams.nbPetits; i++) {
        Position pos = posAleatoire(pParams.largeur, pParams.hauteur);
        m_elements->append(new Petits(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
    }
}
