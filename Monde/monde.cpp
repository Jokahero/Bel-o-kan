#include "monde.h"

#include "elements.h"
#include "petits.h"
#include "femelle.h"
#include "male.h"
#include "position.h"

#include <QtCore/QMap>
#include <QtCore/QVector>

Monde::Monde(const ParamsMonde& pParams) {
    m_infos = new QMap<Position, int>;
    m_elements = new QVector<Elements*>;

    for (int i = 0; i < pParams.nbFemelles; i++) {
        Position pos(pParams.largeur, pParams.hauteur);
        while (m_infos->contains(pos)) {
            pos = Position(pParams.largeur, pParams.hauteur);
        }
        m_elements->append(new Femelle(this, pos.getAbcisse(), pos.getOrdonnee()));
        m_infos->insert(pos, m_elements->size() - 1);
    }

    for (int i = 0; i < pParams.nbMales; i++) {
        m_elements->append(new Male(this, 0, 0));
    }

    for (int i = 0; i < pParams.nbPetits; i++) {
        m_elements->append(new Petits(this, 0, 0));
    }
}

Monde::~Monde() {
    for (int i = 0; i < m_elements->size(); i++)
        delete m_elements->at(i);
    delete m_infos;
    delete m_elements;
}
