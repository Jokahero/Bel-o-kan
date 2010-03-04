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
    static Monde* instance();
    Position posAleatoire(int pAbcisseMax,int pOrdonneeMax);
    inline ParametresMonde::ParamsMonde getParams() const {return m_params;}

public slots:
    void init(const ParametresMonde::ParamsMonde& pParams);
    void destroy();

    void tour();
    void fin();

private:
    static Monde*_instance;
    Monde();
    ~Monde();
    QMap<Position, int>* m_infos;
    QVector<Elements*>* m_elements;
    ParametresMonde::ParamsMonde m_params;

    int m_nbTours;

signals:
    void finDuMonde(int pNbTours);
};

#endif // MONDE_H
