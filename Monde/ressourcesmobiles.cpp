#include "ressourcesmobiles.h"

RessourcesMobiles::RessourcesMobiles(Monde* pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture) : Mobiles(pMonde, pAbcisse, pOrdonnee), Ressources(pMonde, pAbcisse, pOrdonnee, pBrindilles, pNourriture) {
}
