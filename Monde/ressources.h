#ifndef RESSOURCES_H
#define RESSOURCES_H

#include "elements.h"

class Ressources : public Elements {
    Q_OBJECT

public:
    Ressources(Monde* pMonde, int pAbcisse, int pOrdonnee, int pBrindilles, int pNourriture, ParametresMonde::typeElement pType);

    inline int getBrindilles() const {return m_brindilles;};
    void setBrindilles(int pBrindilles);

    inline int getNourriture() const {return m_nourriture;};
    void setNourriture(int pNourriture);

    virtual void tour() {};

    inline static int getBrindillesTot() {return m_brindillesTot;};
    void setBrindillesTot(int pBrindillesTot);

    inline static int getMyceliumTot() {return m_myceliumTot;};
    void setMyceliumTot(int pMyceliumTot);

    inline static int getPuceronsTot() {return m_puceronsTot;};
    void setPuceronsTot(int pPuceronsTot);

private:
    static int m_brindillesTot;
    static int m_myceliumTot;
    static int m_puceronsTot;
    int m_brindilles;
    int m_nourriture;
};

#endif // RESSOURCES_H
