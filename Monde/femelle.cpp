#include "femelle.h"

#include "monde.h"
#include "position.h"
#include "../AppBase/ParamsMonde.h"

#include <QtCore/QMap>
#include <QtCore/QVector>

#include <QtCore/QDebug>

Femelle::Femelle(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Femelle) {
}

void Femelle::tour() {
    Peuple::tour();

    // On vérifie que ce n'est pas un zombie
    if (isMort())
        return;

    QList<Position> posAdj = getPos().getPositionsAdjacentes(getVue());
    QList<Position> nourriture;
    QList<Position> brindilles;
    for (int i = 0; i < posAdj.size(); i++) {
        if (getMonde()->getInfos()->contains(posAdj.at(i))) {
            switch (getMonde()->getElements()->at(getMonde()->getInfos()->value(posAdj.at(i)))->getType()) {
            case ParametresMonde::Mycelium:
                nourriture.append(posAdj.at(i));
                break;
            case ParametresMonde::Brindille:
                brindilles.append(posAdj.at(i));
                break;
            }
        }
    }

    // Déterminer un objectif

    // Recherche de la nourriture la plus proche
    if (nourriture.size() > 0) {
        Position ptmp = nourriture.at(0);
        for (int i = 1; i < nourriture.size(); i++) {
            if (getPos().distance(ptmp) > getPos().distance(nourriture.at(i)))
                ptmp = nourriture.at(i);
            if (getPos().distance(ptmp) == 1)
                break;
        }
        qDebug() << "Nourriture la plus proche : " << ptmp;
        deplacement(ptmp);
    }
}
