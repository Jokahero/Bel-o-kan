#include "male.h"

Male::Male(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Male) {
    setNbMales(getNbMales() + 1);
}

Male::~Male() {
    setNbMales(getNbMales() - 1);
}

void Male::tour() {
    Peuple::tour();
}
