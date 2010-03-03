#ifndef CARTE_H
#define CARTE_H

#include <QtGui/QGraphicsView>

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

    // QVector<QVector*><Hexagone*> *m_carte;

public slots:
    void construireCarte(int pHauteur, int pLargeur);
};

#endif // CARTE_H
