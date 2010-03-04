#include "male.h"

Male::Male(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Male) {
}

void Male::tour() {
    Peuple::tour();
}
