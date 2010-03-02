#ifndef HEXAGONE_H
#define HEXAGONE_H

#include <QtGui/QPolygon>

class QPoint;

class Hexagone : public QPolygon
{
public:
    Hexagone();
    Hexagone(int pX, int pY);

    void construire();
    void setCoord(int pX, int pY);

private:
    int m_X, m_Y;
};

#endif // HEXAGONE_H
