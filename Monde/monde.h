#ifndef MONDE_H
#define MONDE_H

#include "../AppBase/ParamsMonde.h"
#include <QtCore/QObject>

class Elements;
class Position;
template<typename Key, typename T> class QMap;
template<typename T> class QVector;

class Monde : public QObject{
    Q_OBJECT
public:
    Monde();
    ~Monde();
    Position posAleatoire(int pAbcisseMax,int pOrdonneeMax);

public slots:
    void init(const ParamsMonde& pParams);

private:
    QMap<Position, int>* m_infos;
    QVector<Elements*>* m_elements;
};

#endif // MONDE_H
