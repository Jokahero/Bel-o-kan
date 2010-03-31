#include "predateur.h"
#include "monde.h"

Predateur::Predateur(Monde* pMonde, int pAbcisse, int pOrdonnee) : Mobiles(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Predateur) {}

void Predateur::tour() {
    if(!isMort()) {
        QList<Position> posAdj = getPos().getPositionsAdjacentes(3);
        if (posAdj.size() == 0)
            return;
        int pos;
        Position tmp;
        pos = qrand() % posAdj.size();
        tmp = posAdj.takeAt(pos);
        if (getMonde()->getInfos()->contains(tmp))
            getMonde()->getElements()->at(getMonde()->getInfos()->value(tmp))->setMort(true);
        deplacement(tmp);
    }
}
