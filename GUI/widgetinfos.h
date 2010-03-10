#ifndef WIDGETINFOS_H
#define WIDGETINFOS_H

#include <QtGui/QDockWidget>

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
    void setQteBrindillesStock(int pNbBrindilles);
    void setNbBrindillesCarte(int pNbBrindilles);
    void setQteNourritureStock(int pQteNourriture);
    void setNbMyceliumCarte(int pQteNourriture);
    void setJours(int pJours);

    void ajoutMale();
    void ajoutFemelle();
    void ajoutPetit();
    void ajoutBrindilleStock();
    void ajoutBrindilleCarte();
    void ajoutNourritureStock();
    void ajoutMyceliumCarte();
    void ajoutJour();

    void suppressionMale();
    void suppressionFemelle();
    void suppressionPetit();
    void suppressionBrindilleStock();
    void suppressionBrindilleCarte();
    void suppressionNourritureStock();
    void suppressionMyceliumCarte();

    void ajout(ParametresMonde::typeElement pType);
    void suppression(ParametresMonde::typeElement pType);

private:
    QLabel *m_nbMales;
    QLabel *m_nbFemelles;
    QLabel *m_nbPetits;
    QLabel *m_qteBrindillesStock;
    QLabel *m_nbBrindillesCarte;
    QLabel *m_qteNourritureStock;
    QLabel *m_nbMyceliumCarte;

    QLabel *m_jours;
};

#endif // WIDGETINFOS_H
