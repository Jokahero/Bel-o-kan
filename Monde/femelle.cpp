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
    for (int i = 0; i < posAdj.size(); i++) {
        if (getMonde()->getInfos()->contains(posAdj.at(i))) {
            switch (getMonde()->getElements()->at(getMonde()->getInfos()->value(posAdj.at(i)))->getType()) {
            case ParametresMonde::Mycelium:
                qDebug() << "Nourriture trouvée en (" + QString::number(posAdj.at(i).getAbcisse()) + ", " + QString::number(posAdj.at(i).getOrdonnee()) + ")";
                break;
            case ParametresMonde::Brindille:
                qDebug() << "Brindille trouvée en (" + QString::number(posAdj.at(i).getAbcisse()) + ", " + QString::number(posAdj.at(i).getOrdonnee()) + ")";
                break;
            }
        }
    }
}
