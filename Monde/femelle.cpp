#include "femelle.h"

#include "monde.h"
#include "position.h"
#include "../AppBase/ParamsMonde.h"

#include <QtCore/QMap>
#include <QtCore/QVector>

#include <QtCore/QDebug>

Femelle::Femelle(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Femelle) {
    setNbFemelles(getNbFemelles() + 1);
}

Femelle::~Femelle() {
    setNbFemelles(getNbFemelles() - 1);
}

void Femelle::tour() {
    Peuple::tour();

    // On vérifie que ce n'est pas un zombie
    if (isMort())
        return;

    QList<Position> posAdj = getPos().getPositionsAdjacentes(getVue());
    QList<Position> nourriture;
    QList<Position> brindilles;
    QList<Position> males;
    for (int i = 0; i < posAdj.size(); i++) {
        if (getMonde()->getInfos()->contains(posAdj.at(i))) {
            switch (getMonde()->getElements()->at(getMonde()->getInfos()->value(posAdj.at(i)))->getType()) {
            case ParametresMonde::Mycelium:
                nourriture.append(posAdj.at(i));
                break;
            case ParametresMonde::Brindille:
                brindilles.append(posAdj.at(i));
                break;
            case ParametresMonde::Male:
                males.append(posAdj.at(i));
                break;
            default:
                break;
            }
        }
    }

    // On récupère les cases autour des femelles assez proches
    QList<Position> reprod;
    for (int i = 0; i < males.size(); i++) {
        QList<Position> tmp = males.at(i).getPositionsAdjacentes();
        for (int j = 0; j < tmp.size(); j++)
            if (!getMonde()->getInfos()->contains(tmp.at(j)))
                reprod.append(tmp.at(j));
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
    } else if (reprod.size() > 0 && getNourriture() > getPopulation() * 2 && getMonde()->getInfos()->size() < (getMonde()->getParams().hauteur * getMonde()->getParams().largeur)) {                   // Reproduction
        Position ptmp = reprod.at(0);
        for (int i = 0; i < reprod.size() && getPos().distance(ptmp) > 1; i++)
            if (getPos().distance(reprod.at(i)) < getPos().distance(ptmp))
                ptmp = reprod.at(i);
        reproduction(ParametresMonde::Femelle, ptmp);
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
