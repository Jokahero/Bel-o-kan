#ifndef FENCARTE_H
#define FENCARTE_H

#include <QMainWindow>

#include "../AppBase/ParamsMonde.h"

class Carte;
class QMenuBar;
class QMenu;
class QAction;
class WidgetInfos;
class WidgetInter;

class FenCarte : public QMainWindow {
    Q_OBJECT

public:
    FenCarte();

private:
    Carte *m_carte;

    QMenuBar *m_barreMenu;
    QMenu *m_menuPrinc;
    QAction *m_quitter;
    QAction *m_tourSuivant;
    QAction *m_tourBoucle;

    WidgetInfos *m_WInfos;
    WidgetInter *m_WInter;

public slots:
    void show(int pHauteur, int pLargeur);
    void finDuMonde(int pNbTours);

private slots:
    void boucle();

signals:
    void signalQuitter();
    void tourSuivantMonde();
    void tourSuivant();
    void afficherElement(ParametresMonde::typeElement, int, int);
    void supprimerElement(ParametresMonde::typeElement, int, int);
    void deplacerElement(ParametresMonde::typeElement, int, int, int, int);
    void ajoutBrindilles(int pQte);
    void ajoutNourriture(int pQte);
};

#endif // FENCARTE_H
