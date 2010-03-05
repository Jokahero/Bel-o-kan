#ifndef FENCARTE_H
#define FENCARTE_H

#include <QMainWindow>

#include "../AppBase/ParamsMonde.h"

class Carte;
class QMenuBar;
class QMenu;
class QAction;

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

public slots:
    void show(int pHauteur, int pLargeur);

signals:
    void signalQuitter();
    void tourSuivant();
    void afficherElement(ParametresMonde::typeElement, int, int);
    void supprimerElement(ParametresMonde::typeElement, int, int);
    void deplacerElement(ParametresMonde::typeElement, int, int, int, int);
};

#endif // FENCARTE_H
