#include "petits.h"

#include "../AppBase/Constantes.h"
#include "femelle.h"
#include "male.h"
#include "monde.h"

Petits::Petits(Monde* pMonde, int pAbcisse, int pOrdonnee) : Peuple(pMonde, pAbcisse, pOrdonnee, ParametresMonde::Petits) {
    setNbPetits(getNbPetits() + 1);
}

void Petits::tour() {
    Peuple::tour();
    // Est-il grand ?
    if (getAge() >= Constantes::seuilAge) {
        Position tmp = getPos();
        int rang = getMonde()->getInfos()->value(tmp);
        int sexe = qrand() % 2;
        if (sexe == 0)
            (*getMonde()->getElements())[rang] = new Femelle(getMonde(), tmp.getAbcisse(), tmp.getOrdonnee());
        else
            (*getMonde()->getElements())[rang] = new Male(getMonde(), tmp.getAbcisse(), tmp.getOrdonnee());
        getMonde()->evolution(tmp, sexe);
        this->deleteLater();
    }
}
