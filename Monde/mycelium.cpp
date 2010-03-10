#include "mycelium.h"

#include "monde.h"
#include "../AppBase/Constantes.h"

Mycelium::Mycelium(Monde *pMonde, int pAbcisse, int pOrdonnee) : Ressources(pMonde, pAbcisse, pOrdonnee, 0, Constantes::nourritureMycelium, ParametresMonde::Mycelium) {
}
