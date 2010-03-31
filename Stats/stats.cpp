#include "stats.h"

#include "widgetstats.h"

#include <QtCore/QVector>

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
    WidgetStats* ws = new WidgetStats(m_listeTours);
    ws->show();
}
