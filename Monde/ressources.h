#ifndef RESSOURCES_H
#define RESSOURCES_H

#include "elements.h"

class Ressources : public Elements {
public:
    Ressources(Monde* pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture, ParametresMonde::typeElement pType);

    inline int getBrindilles() const {return m_brindilles;};
    void setBrindilles(int pBrindilles);

    inline int getNourriture() const {return m_nourriture;};
    void setNourriture(int pNourriture);

    virtual void tour() {};

private:
    int m_brindilles;
    int m_nourriture;
};

#endif // RESSOURCES_H
