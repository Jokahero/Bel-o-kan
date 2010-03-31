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
        int nbPredateurs;
        // Autres éléments
        int mycelium;
        int brindilles;
        int pucerons;
        // Ressources
        int nbBrindilles;
        int nbNourriture;
    } ParamsMonde;

    enum typeElement {
        Brindille,
        Construction,
        Femelle,
        Male,
        Mycelium,
        Petits,
        Predateur,
        Puceron,
    };

    enum typeInfo {
        NouvelleFemelle,
        NouveauMale,
        NouveauPetit,
        MortFemelle,
        MortMale,
    };
}
#endif // PARAMSMONDE_H
