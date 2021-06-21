#include "widgetstats.h"

#include "statstab.h"

#include <QtCore/QStringList>
#include <QtCore/QVector>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTabWidget>

WidgetStats::WidgetStats(QVector<ParametresMonde::ParamsMonde> *pVect) : m_listeTours(pVect) {
    setAttribute(Qt::WA_DeleteOnClose);
    QHBoxLayout *layout = new QHBoxLayout;
    m_tab = new QTabWidget;
    QStringList titres;
    titres << tr("Population") << tr("Ressources à l'état sauvage") << tr("Ressources en stock");
    for (int i = 0; i < 3; i++)
        m_tab->addTab(new StatsTab(this, i), titres.at(i));
    layout->addWidget(m_tab);
    setLayout(layout);

    connect(m_tab, SIGNAL(currentChanged(int)), this, SLOT(dessin(int)));

    resize(640, 480);
}

void WidgetStats::dessin(int pNum) {
    qobject_cast<StatsTab*>(m_tab->widget(pNum))->dessin();
}
