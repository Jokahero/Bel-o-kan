#include "ressourcesmobiles.h"

RessourcesMobiles::RessourcesMobiles(Monde* pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture, ParametresMonde::typeElement pType) : Mobiles(pMonde, pAbcisse, pOrdonnee, pType), Ressources(pMonde, pAbcisse, pOrdonnee, pBrindilles, pNourriture, pType) {
}
