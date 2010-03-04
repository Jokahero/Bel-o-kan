#include "petits.h"

#include "monde.h"

Petits::Petits(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Petits) {
}

void Petits::tour() {
    Peuple::tour();
}
