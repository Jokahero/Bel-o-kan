#ifndef PEUPLE_H
#define PEUPLE_H

class Monde;

#include "mobiles.h"

class Peuple : public Mobiles {
public:
    Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType);
    inline static int getBrindilles() {return m_brindilles;};
    static void setBrindilles(int pBrindilles);

    inline static int getNourriture() {return m_nourriture;};
    static void setNourriture(int pNourriture);

    inline static int getPopulation() {return m_pop;};
    void setPopulation(int pPopulation);

    virtual void tour();

private:
    static bool init;
    static int m_brindilles;
    static int m_nourriture;
    static int m_pop;

    void mort();
};

#endif // PEUPLE_H
