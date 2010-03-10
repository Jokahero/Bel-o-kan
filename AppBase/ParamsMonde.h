#ifndef PARAMSMONDE_H
#define PARAMSMONDE_H
namespace ParametresMonde {
    typedef struct {
        // Carte
        int hauteur;
        int largeur;
        // Peuple
        int nbMales;
        int nbFemelles;
        int nbPetits;
        // Autres éléments
        int mycelium;
        int brindilles;
        // Ressources
        int nbBrindilles;
        int nbNourriture;
    } ParamsMonde;

    enum typeElement {
        Brindille,
        Femelle,
        Male,
        Mycelium,
        Petits,
    };
}
#endif // PARAMSMONDE_H
