#include "puceron.h"
#include "../AppBase/Constantes.h"

Puceron::Puceron(Monde* pMonde, int pAbcisse, int pOrdonnee) : RessourcesMobiles(pMonde, pAbcisse, pOrdonnee, 0, Constantes::nourriturePuceron, ParametresMonde::Puceron) {
    setVitesse((qrand() % Constantes::vitesseMaxPuceron) + 1);
    setPuceronsTot(getPuceronsTot() + 1);
}

Puceron::~Puceron() {
    setPuceronsTot(getPuceronsTot() - 1);
}

void Puceron::tour() {
    deplacementAleatoire(getVitesse());
}
