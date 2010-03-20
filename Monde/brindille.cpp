#include "brindille.h"

#include "monde.h"

Brindille::Brindille(Monde *pMonde, int pAbcisse, int pOrdonnee) : Ressources(pMonde, pAbcisse, pOrdonnee, 1, 0, ParametresMonde::Brindille) {
    setBrindillesTot(getBrindillesTot() + 1);
}

Brindille::~Brindille() {
    setBrindillesTot(getBrindillesTot() - 1);
}
