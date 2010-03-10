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
    void setNbBrindilles(int pNbBrindilles);
    void setQteNourriture(int pQteNourriture);
    void setJours(int pJours);

    void ajoutMale();
    void ajoutFemelle();
    void ajoutPetit();
    void ajoutBrindille();
    void ajoutMycelium();
    void ajoutJour();

    void suppressionMale();
    void suppressionFemelle();
    void suppressionPetit();
    void suppressionBrindille();
    void suppressionMycelium();
    void suppressionJour();

    void ajout(ParametresMonde::typeElement pType);
    void suppression(ParametresMonde::typeElement pType);

private:
    QLabel *m_nbMales;
    QLabel *m_nbFemelles;
    QLabel *m_nbPetits;
    QLabel *m_nbBrindilles;
    QLabel *m_qteNourriture;

    QLabel *m_jours;
};

#endif // WIDGETINFOS_H
