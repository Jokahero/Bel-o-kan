#ifndef WIDGETINFOS_H
#define WIDGETINFOS_H

#include <QtWidgets/QDockWidget>

#include "../AppBase/ParamsMonde.h"

class QLabel;

class WidgetInfos : public QDockWidget {
    Q_OBJECT

public:
    WidgetInfos();

public slots:
    void setNbMales(int pNbMales);
    void setNbFemelles(int pNbFemelles);
    void setNbPetits(int pNbPetits);
    void setNbPredateurs(int pNbPredateurs);
    void setQteBrindillesStock(int pNbBrindilles);
    void setNbBrindillesCarte(int pNbBrindilles);
    void setQteNourritureStock(int pQteNourriture);
    void setNbMyceliumCarte(int pQteNourriture);
    void setNbPucerons(int pQteNourriture);
    void setNbConstructions(int pQteConstructions);
    void setJours(int pJours);

    void ajoutMale(int pNb = 1);
    void ajoutFemelle(int pNb = 1);
    void ajoutPetit(int pNb = 1);
    void ajoutPredateurs(int pNb = 1);
    void ajoutBrindilleStock(int pNb = 1);
    void ajoutBrindilleCarte(int pNb = 1);
    void ajoutNourritureStock(int pNb = 1);
    void ajoutMyceliumCarte(int pNb = 1);
    void ajoutPuceron(int pNb = 1);
    void ajoutConstruction(int pNb = 1);
    void ajoutJour(int pNb = 1);

    void suppressionMale();
    void suppressionFemelle();
    void suppressionPetit();
    void suppressionPredateur();
    void suppressionBrindilleStock();
    void suppressionBrindilleCarte();
    void suppressionNourritureStock();
    void suppressionMyceliumCarte();
    void suppressionPuceron();
    void suppressionConstruction();

    void ajout(ParametresMonde::typeElement pType);
    void suppression(ParametresMonde::typeElement pType);

private:
    QLabel *m_nbMales;
    QLabel *m_nbFemelles;
    QLabel *m_nbPetits;
    QLabel *m_nbPredateurs;
    QLabel *m_qteBrindillesStock;
    QLabel *m_nbBrindillesCarte;
    QLabel *m_qteNourritureStock;
    QLabel *m_nbMyceliumCarte;
    QLabel *m_nbPucerons;
    QLabel *m_nbConstructions;

    QLabel *m_jours;
};

#endif // WIDGETINFOS_H
