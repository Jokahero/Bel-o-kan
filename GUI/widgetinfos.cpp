#include "widgetinfos.h"

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QFormLayout>
#include <QtGui/QWidget>

WidgetInfos::WidgetInfos() {
    setWindowTitle(tr("Informations"));

    m_nbMales = new QLabel(/*tr("Nombre de mâles: "), */this);
    m_nbFemelles = new QLabel(/*tr("Nombre de femelles: "), */this);
    m_nbPetits = new QLabel(/*tr("Nombre de petits: "), */this);
    m_nbBrindilles = new QLabel(/*tr("Nombre de brindilles: "), */this);
    m_qteNourriture = new QLabel(/*tr("Quantité de nourriture: "), */this);

    m_jours = new QLabel(/*tr("Age de la colonie (jours): "), */this);

    QGroupBox *groupePopulation = new QGroupBox(tr("Population"), this);
    QFormLayout *layoutPopulation = new QFormLayout(groupePopulation);
    layoutPopulation->addRow(tr("Nombre de mâles :"), m_nbMales);
    layoutPopulation->addRow(tr("Nombre de femelles :"), m_nbFemelles);
    layoutPopulation->addRow(tr("Nombre de petits :"), m_nbPetits);
    groupePopulation->setLayout(layoutPopulation);

    QGroupBox *groupeStocks = new QGroupBox(tr("Stocks"), this);
    QFormLayout *layoutStocks = new QFormLayout(groupeStocks);
    layoutStocks->addRow(tr("Nombre de brindilles :"), m_nbBrindilles);
    layoutStocks->addRow(tr("Quantité de nourriture :"), m_qteNourriture);
    groupeStocks->setLayout(layoutStocks);

    QGroupBox *groupeSimulation = new QGroupBox(tr("Simulation"), this);
    QFormLayout *layoutSimulation = new QFormLayout(groupeSimulation);
    layoutSimulation->addRow(tr("Âge de la colonie (jours) :"), m_jours);
    groupeSimulation->setLayout(layoutSimulation);

    QWidget *tmp = new QWidget(this);

    QHBoxLayout *layoutPrincipal = new QHBoxLayout(tmp);
    layoutPrincipal->addWidget(groupePopulation);
    layoutPrincipal->addWidget(groupeStocks);
    layoutPrincipal->addWidget(groupeSimulation);

    tmp->setLayout(layoutPrincipal);

    setWidget(tmp);
}
