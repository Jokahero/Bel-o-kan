#ifndef STATS_H
#define STATS_H

#include <QtCore/QObject>
#include "../AppBase/ParamsMonde.h"

template <typename T> class QVector;

class Stats : public QObject {
    Q_OBJECT

public:
    Stats();
    ~Stats();

public slots:
    void tour(const ParametresMonde::ParamsMonde& pMonde);
    void fin();

private:
    QVector<ParametresMonde::ParamsMonde> *m_listeTours;
};

#endif // STATS_H
