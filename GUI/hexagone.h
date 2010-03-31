#ifndef HEXAGONE_H
#define HEXAGONE_H

#include <QtGui/QPolygon>
#include <QtCore/QObject>

#include "../AppBase/ParamsMonde.h"

class QGraphicsPixmapItem;
class QPoint;
template <typename Key, typename T> class QMap;

class Hexagone : public QObject, public QPolygon {
    Q_OBJECT

public:
    Hexagone();
    Hexagone(int pX, int pY);

    void construire();
    void setCoord(int pX, int pY);

    QGraphicsPixmapItem* getIcon();

private:
    int m_X, m_Y;
    QGraphicsPixmapItem *m_icone;
    QMap<ParametresMonde::typeElement, QString>* m_mapIcones;

public slots:
    void setIcon();
    void setIcon(ParametresMonde::typeElement pTypeElement);
};

#endif // HEXAGONE_H
