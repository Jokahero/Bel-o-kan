#include "hexagone.h"
#include "math.h"

#include <QtGui/QGraphicsPixmapItem>
#include <QtCore/QPoint>
#include <QtCore/QDebug>

Hexagone::Hexagone() {
    m_X = 0;
    m_Y = 0;

    m_mapIcones = new QMap<ParametresMonde::typeElement, QString>;
    m_mapIcones->insert(ParametresMonde::Brindille, ":/Icônes/brindille-icon1.png");
    m_mapIcones->insert(ParametresMonde::Femelle, ":/Icônes/fourmis-icon1.jpg");
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
    m_icone = new QGraphicsPixmapItem((new QPixmap(m_mapIcones->value(pTypeElement)))->scaled(50,50)); // scaled() redimmensionnement
    m_icone->setPos(m_X,m_Y+20); // Soit Hexagone(X,Y) → Icône(X,Y+20)
    m_icone->setZValue(1); // Positionnement selon Z par defaut 0 → définition a 1 pour mettre l'icône au premier plan
}

QGraphicsPixmapItem* Hexagone::getIcon() {
    return m_icone;
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
