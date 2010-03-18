#include "puceron.h"
#include "../AppBase/Constantes.h"

Puceron::Puceron(Monde* pMonde, int pAbcisse, int pOrdonnee) : RessourcesMobiles(pMonde, pAbcisse, pOrdonnee, 0, Constantes::nourriturePuceron, ParametresMonde::Puceron) {
}
