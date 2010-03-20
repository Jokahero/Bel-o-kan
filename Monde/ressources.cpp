#include "ressources.h"

#include "monde.h"

int Ressources::m_brindillesTot = 0;
int Ressources::m_myceliumTot = 0;
int Ressources::m_puceronsTot = 0;

Ressources::Ressources(Monde *pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture, ParametresMonde::typeElement pType) : Elements(pMonde, pAbcisse, pOrdonnee, pType), m_brindilles(pBrindilles), m_nourriture(pNourriture) {
}

void Ressources::setBrindilles(int pBrindilles) {
    m_brindilles = pBrindilles;
}

void Ressources::setNourriture(int pNourriture) {
    m_nourriture = pNourriture;
}

void Ressources::setBrindillesTot(int pBrindillesTot) {
    m_brindillesTot = pBrindillesTot;
}

void Ressources::setMyceliumTot(int pMyceliumTot) {
    m_myceliumTot = pMyceliumTot;
}

void Ressources::setPuceronsTot(int pPuceronsTot) {
    m_puceronsTot = pPuceronsTot;
}
