#ifndef CARTE_H
#define CARTE_H

#include <QtGui/QGraphicsView>

#include "../AppBase/ParamsMonde.h"

class QGraphicsScene;
class Hexagone;
template <typename T> class QVector;

class Carte : public QGraphicsView {
    Q_OBJECT

public:
    Carte();
    ~Carte();

private:
    QVector<Hexagone*> *m_listeHexagones;
    QGraphicsScene *m_scene;

    QVector<QVector<Hexagone*>*> *m_carte;

public slots:
    void construireCarte(int pHauteur, int pLargeur);
    void afficherIcone(ParametresMonde::typeElement pTypeElement, int pX, int pY);
};

#endif // CARTE_H
