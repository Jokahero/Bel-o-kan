#ifndef PEUPLE_H
#define PEUPLE_H

class Monde;

#include "mobiles.h"

class Peuple : public Mobiles {
public:
    Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee);
    inline static int getBrindilles() {return m_brindilles;};
    void setBrindilles(int pBrindilles);

    inline static int getNourriture() {return m_nourriture;};
    void setNourriture(int pNourriture);

    virtual void tour();

private:
    static bool init;
    static int m_brindilles;
    static int m_nourriture;

    void mort();
};

#endif // PEUPLE_H
