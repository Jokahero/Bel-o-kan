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
        // Ressources
        int nbBrindilles;
        int nbNourriture;
    } ParamsMonde;

    enum typeElement {
        Male,
        Femelle,
        Petit,
        Brindille,
        Mycelium,
    };
}
#endif // PARAMSMONDE_H
