#ifndef PEUPLE_H
#define PEUPLE_H

class Monde;

#include "mobiles.h"

class Peuple : public Mobiles {
public:
    Peuple(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType);
    virtual ~Peuple();
    inline static int getBrindilles() {return m_brindilles;};
    static void setBrindilles(int pBrindilles);

    inline static int getNourriture() {return m_nourriture;};
    static void setNourriture(int pNourriture);

    inline static int getPopulation() {return m_pop;};
    void setPopulation(int pPopulation);

    inline static int getNbFemelles() {return m_nbFemelles;};
    void setNbFemelles(int pNbFemelles);

    inline static int getNbMales() {return m_nbMales;};
    void setNbMales(int pNbMales);

    inline static int getNbPetits() {return m_nbPetits;};
    void setNbPetits(int pNbPetits);

    virtual void tour();

    inline int getAge() {return m_age;};
    void setAge(int pAge);

    virtual void mort();

    void reproduction(ParametresMonde::typeElement pTE, const Position& pPos);

private:
    static int m_brindilles;
    static int m_nourriture;
    static int m_pop;
    static int m_nbFemelles;
    static int m_nbMales;
    static int m_nbPetits;

    int m_age;
};

#endif // PEUPLE_H
