#ifndef HEXAGONE_H
#define HEXAGONE_H

#include <QtGui/QPolygon>
#include <QtCore/QObject>

#include "../AppBase/ParamsMonde.h"

class QPoint;
template <typename Key, typename T> class QMap;

class Hexagone : public QObject, public QPolygon {
    Q_OBJECT

public:
    Hexagone();
    Hexagone(int pX, int pY);

    void construire();
    void setCoord(int pX, int pY);

private:
    int m_X, m_Y;
    QMap<ParametresMonde::typeElement, QString>* m_infos;

public slots:
    void setIcon(ParametresMonde::typeElement pTypeElement);

    /* Icones
       * affichage de l'icone
       * instruction d'ajout en utilisant m_X et m_Y
       * → nouvelle fonction
    */

    /* Map ou tablal ...
       * → correspondance nom du fichier .png
       * param → type de l'élément
       * => enum des types
    */

    //TODO: modifier tous les icônes avec la crampe
};

#endif // HEXAGONE_H
