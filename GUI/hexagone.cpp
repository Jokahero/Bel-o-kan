#include "hexagone.h"
#include "math.h"

#include <QtCore/QPoint>
#include <QtCore/QDebug>

Hexagone::Hexagone() {
    m_X = 0;
    m_Y = 0;
}

Hexagone::Hexagone(int pX, int pY) : QPolygon(6) {
    m_X = pX;
    m_Y = pY;
}

void Hexagone::construire() {
    setPoints(6, m_X, m_Y, (m_X-25), (m_Y+45), m_X, (m_Y+90), (m_X+50), (m_Y+90), (m_X+75), (m_Y+45), (m_X+50), m_Y);
}

void Hexagone::setCoord(int pX, int pY) {
    m_X = pX;
    m_Y = pY;
}

void Hexagone::setIcon(ParametresMonde::typeElement pTypeElement) {
    // Instruction d'ajout d'un icône superposé sur un Hexagone
    /*************************/
    //QGraphicsPixmapItem *GPI = new QGraphicsPixmapItem((new QPixmap("icon.png"))->scaled(50,50)); // scaled() redimmensionnement
    //GPI->setPos(m_X,m_Y+20); // Soit Hexagone(X,Y) → Icône(X,Y+20)
    //GPI->setZValue(1); // Positionnement selon Z par defaut 0 → définition a 1 pour mettre l'icône au premier plan
    //m_scene->addItem(GPI); // ajout de l'icone a la scène
    /*************************/
}
/* Calculs pour l'hexagone:
   Construction droite
       Point de départ "en haut a gauche" → X, Y
       2e point → X - 25, Y + 45
       3e point → X, Y + 50
       4e point → X + 50, Y + 50
       5e point → X + 75, Y + 45
       6e point → X + 50, Y
    */