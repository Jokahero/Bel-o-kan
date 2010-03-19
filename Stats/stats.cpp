#include "stats.h"

#include <QtCore/QVector>

#include <QtCore/QDebug>

Stats::Stats() {
    m_listeTours = new QVector<ParametresMonde::ParamsMonde>;
}

Stats::~Stats() {
    delete m_listeTours;
}

void Stats::tour(const ParametresMonde::ParamsMonde& pMonde) {
    m_listeTours->append(pMonde);
}

void Stats::fin() {
    qDebug() << "Taille vector : " << m_listeTours->size();
    for (int i = 0; i < m_listeTours->size(); i++) {
        qDebug() << "Tour " << i;
        qDebug() << "Nourriture : " << m_listeTours->at(i).nbNourriture;
        qDebug() << "--------------------------";
    }
}
