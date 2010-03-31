#include "male.h"

#include "monde.h"

Male::Male(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Male) {
    setNbMales(getNbMales() + 1);
}

Male::~Male() {
    setNbMales(getNbMales() - 1);
}

void Male::tour() {
    Peuple::tour();

    // On vérifie que ce n'est pas un zombie
    if (isMort())
        return;

    QList<Position> posAdj = getPos().getPositionsAdjacentes(getVue());
    QList<Position> nourriture;
    QList<Position> brindilles;
    QList<Position> femelles;
    QList<Position> constructions;
    for (int i = 0; i < posAdj.size(); i++) {
        if (getMonde()->getInfos()->contains(posAdj.at(i))) {
            switch (getMonde()->getElements()->at(getMonde()->getInfos()->value(posAdj.at(i)))->getType()) {
            case ParametresMonde::Mycelium:
                nourriture.append(posAdj.at(i));
                break;
            case ParametresMonde::Brindille:
                brindilles.append(posAdj.at(i));
                break;
            case ParametresMonde::Puceron:
                nourriture.append(posAdj.at(i));
                break;
            case ParametresMonde::Femelle:
                femelles.append(posAdj.at(i));
                break;
            case ParametresMonde::Construction:
                constructions.append(posAdj.at(i));
                break;
            default:
                break;
            }
        }
    }

    // On récupère les cases autour des femelles assez proches
    QList<Position> reprod;
    for (int i = 0; i < femelles.size(); i++) {
        QList<Position> tmp = femelles.at(i).getPositionsAdjacentes();
        for (int j = 0; j < tmp.size(); j++)
            if (!getMonde()->getInfos()->contains(tmp.at(j)))
                reprod.append(tmp.at(j));
    }

    // Et les cases contenant des constructions
    QList<Position> constructionsRep;
    for (int i = 0; i < constructions.size(); i++) {
        bool ok = false;
        for (int j = 0; j < reprod.size() && !ok; j++)
            if (reprod.at(j).distance(constructions.at(i) < 2))
                ok = true;
        if (getPos().distance(constructions.at(i) < 2) && ok)
            constructionsRep.append(constructions.at(i));
    }

    // Déterminer un objectif

    // Si il n'y pas a beaucoup de nourriture, on en recherche
    if (nourriture.size() > 0 && getNourriture() < getPopulation() * 3) {
        Position ptmp = nourriture.at(0);
        for (int i = 1; i < nourriture.size(); i++) {
            if (getPos().distance(ptmp) > getPos().distance(nourriture.at(i)))
                ptmp = nourriture.at(i);
            if (getPos().distance(ptmp) == 1)
                break;
        }
        deplacement(ptmp);
    } else if (brindilles.size() > 0 && getBrindilles() < 2) {
        Position ptmp = brindilles.at(0);
        for (int i = 1; i < brindilles.size(); i++) {
            if (getPos().distance(ptmp) > getPos().distance(brindilles.at(i)))
                ptmp = brindilles.at(i);
            if (getPos().distance(ptmp) == 1)
                break;
        }
        deplacement(ptmp);
    } else if (reprod.size() > 0 && (getBrindilles() > 0 || constructionsRep.size() > 0)) {                   // Reproduction
        Position ptmp = reprod.at(0);

        if (constructionsRep.size() > 0) {
            bool trouve = false;
            for (int i = 1; i < reprod.size() && !trouve; i++) {
                Position bat = constructionsRep.size();
                for (int j = 0; j < constructionsRep.size(); j++)
                    if (getPos().distance(bat) > getPos().distance(constructionsRep.at(i))) {
                        bat = constructionsRep.at(i);
                        trouve = true;
                    }
                if (getPos().distance(ptmp) > getPos().distance(reprod.at(i)) && trouve)
                    ptmp = reprod.at(i);
                if (getPos().distance(ptmp) == 1)
                    break;
            }
            if (trouve) {
                qDebug() << "Trouvé !";
                reproduction(ptmp);
                //deplacement(ptmp);
            }
        } else if (getBrindilles() > 0) {
            qDebug() << "Reproduction, assez de brindilles pour construire";
            //construction()
        } else
            deplacementAleatoire(getVue());
    } else if (nourriture.size() > 0) {                 // On n'a pas besoin de nourriture, mais on n'a rien de mieux à faire…
        Position ptmp = nourriture.at(0);
        for (int i = 1; i < nourriture.size(); i++) {
            if (getPos().distance(ptmp) > getPos().distance(nourriture.at(i)))
                ptmp = nourriture.at(i);
            if (getPos().distance(ptmp) == 1)
                break;
        }
        deplacement(ptmp);
    } else if (brindilles.size() > 0) {                 // On n'a pas besoin de brindilles, mais on n'a rien de mieux à faire…
        Position ptmp = brindilles.at(0);
        for (int i = 1; i < brindilles.size(); i++) {
            if (getPos().distance(ptmp) > getPos().distance(brindilles.at(i)))
                ptmp = brindilles.at(i);
            if (getPos().distance(ptmp) == 1)
                break;
        }
        deplacement(ptmp);
    } else {        // Sinon, on se déplace aléatoirement
        deplacementAleatoire(getVue());
    }
}
