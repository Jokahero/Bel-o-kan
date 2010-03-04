#include "femelle.h"

#include "monde.h"

Femelle::Femelle(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee) {
}

void Femelle::tour() {
    Peuple::tour();
}
