#include "widgetinfos.h"

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

WidgetInfos::WidgetInfos() {
    setWindowTitle(tr("Informations"));

    m_nbMales = new QLabel(tr("Nombre de mâles: "), this);
    m_nbFemelles = new QLabel(tr("Nombre de femelles: "), this);
    m_nbPetits = new QLabel(tr("Nombre de petits: "), this);
    m_nbBrindilles = new QLabel(tr("Nombre de brindilles: "), this);
    m_qteNourriture = new QLabel(tr("Quantité de nourriture: "), this);

    m_jours = new QLabel(tr("Age de la colonie (jours): "), this);

    QGroupBox *groupePopulation = new QGroupBox(tr("Population"), this);
    QVBoxLayout *layoutPopulation = new QVBoxLayout(groupePopulation);
    layoutPopulation->addWidget(m_nbMales);
    layoutPopulation->addWidget(m_nbFemelles);
    layoutPopulation->addWidget(m_nbPetits);
    groupePopulation->setLayout(layoutPopulation);

    QGroupBox *groupeStocks = new QGroupBox(tr("Stocks"), this);
    QVBoxLayout *layoutStocks = new QVBoxLayout(groupeStocks);
    layoutStocks->addWidget(m_nbBrindilles);
    layoutStocks->addWidget(m_qteNourriture);
    groupeStocks->setLayout(layoutStocks);

    QGroupBox *groupeSimulation = new QGroupBox(tr("Simulation"), this);
    QVBoxLayout *layoutSimulation = new QVBoxLayout(groupeSimulation);
    layoutSimulation->addWidget(m_jours);
    groupeSimulation->setLayout(layoutSimulation);

    QWidget *tmp = new QWidget(this);

    QHBoxLayout *layoutPrincipal = new QHBoxLayout(tmp);
    layoutPrincipal->addWidget(groupePopulation);
    layoutPrincipal->addWidget(groupeStocks);
    layoutPrincipal->addWidget(groupeSimulation);

    tmp->setLayout(layoutPrincipal);

    setWidget(tmp);
}
