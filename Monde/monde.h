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
    inline ParamsMonde getParams() const {return m_params;};

public slots:
    void init(const ParamsMonde& pParams);
    void destroy();

private:
    static Monde*_instance;
    Monde();
    ~Monde();
    QMap<Position, int>* m_infos;
    QVector<Elements*>* m_elements;
    ParamsMonde m_params;
};

#endif // MONDE_H
