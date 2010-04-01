#include "puceron.h"
#include "../AppBase/Constantes.h"

Puceron::Puceron(Monde* pMonde, int pAbcisse, int pOrdonnee) : Ressources(pMonde, pAbcisse, pOrdonnee, 0, Constantes::nourriturePuceron, ParametresMonde::Puceron), Mobiles(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Puceron) {
    setVitesse((qrand() % Constantes::vitesseMaxPuceron) + 1);
    setPuceronsTot(getPuceronsTot() + 1);
}

Puceron::~Puceron() {
    setPuceronsTot(getPuceronsTot() - 1);
}

void Puceron::tour() {
    Mobiles::tour();
    deplacementAleatoire(getVitesse());
}
