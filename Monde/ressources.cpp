#include "ressources.h"

#include "monde.h"

Ressources::Ressources(Monde *pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture) : Elements(pMonde, pAbcisse, pOrdonnee), m_brindilles(pBrindilles), m_nourriture(pNourriture) {
}

void Ressources::setBrindilles(int pBrindilles) {
    m_brindilles = pBrindilles;
}

void Ressources::setNourriture(int pNourriture) {
    m_nourriture = pNourriture;
}
