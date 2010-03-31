#include "widgetinfos.h"
#include "flowlayout.h"

#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

WidgetInfos::WidgetInfos() {
    setWindowTitle(tr("Informations"));

    m_nbMales = new QLabel(QString::number(0), this);
    m_nbFemelles = new QLabel(QString::number(0), this);
    m_nbPetits = new QLabel(QString::number(0), this);
    m_nbPredateurs = new QLabel(QString::number(0), this);
    m_qteBrindillesStock = new QLabel(QString::number(0), this);
    m_qteNourritureStock = new QLabel(QString::number(0), this);
    m_nbBrindillesCarte = new QLabel(QString::number(0), this);
    m_nbMyceliumCarte = new QLabel(QString::number(0), this);
    m_nbPucerons = new QLabel(QString::number(0), this);

    m_jours = new QLabel(QString::number(0), this);

    QGroupBox *groupePopulation = new QGroupBox(tr("Population"), this);
    QFormLayout *layoutPopulation = new QFormLayout(groupePopulation);
    layoutPopulation->addRow(tr("Nombre de mâles :"), m_nbMales);
    layoutPopulation->addRow(tr("Nombre de femelles :"), m_nbFemelles);
    layoutPopulation->addRow(tr("Nombre de petits :"), m_nbPetits);
    layoutPopulation->addRow(tr("Nombre de prédateurs:"), m_nbPredateurs);
    groupePopulation->setLayout(layoutPopulation);

    QGroupBox *groupeStocks = new QGroupBox(tr("Stocks"), this);
    QFormLayout *layoutStocks = new QFormLayout(groupeStocks);
    layoutStocks->addRow(tr("Nombre de brindilles :"), m_qteBrindillesStock);
    layoutStocks->addRow(tr("Quantité de nourriture :"), m_qteNourritureStock);
    groupeStocks->setLayout(layoutStocks);

    QGroupBox *groupeCarte = new QGroupBox(tr("Carte"), this);
    QFormLayout *layoutCarte = new QFormLayout(groupeCarte);
    layoutCarte->addRow(tr("Nombre de brindilles à l'état sauvage :"), m_nbBrindillesCarte);
    layoutCarte->addRow(tr("Nombre de mycélium :"), m_nbMyceliumCarte);
    layoutCarte->addRow(tr("Nombre de pucerons :"), m_nbPucerons);
    groupeCarte->setLayout(layoutCarte);

    QGroupBox *groupeSimulation = new QGroupBox(tr("Simulation"), this);
    QFormLayout *layoutSimulation = new QFormLayout(groupeSimulation);
    layoutSimulation->addRow(tr("Âge de la colonie (jours) :"), m_jours);
    groupeSimulation->setLayout(layoutSimulation);

    QWidget *tmp = new QWidget(this);

    FlowLayout *layoutPrincipal = new FlowLayout(tmp);
    layoutPrincipal->addWidget(groupePopulation);
    layoutPrincipal->addWidget(groupeStocks);
    layoutPrincipal->addWidget(groupeCarte);
    layoutPrincipal->addWidget(groupeSimulation);

    tmp->setLayout(layoutPrincipal);

    setWidget(tmp);
}

void WidgetInfos::setNbMales(int pNbMales) {
    m_nbMales->setText(QString::number(pNbMales));
}

void WidgetInfos::setNbFemelles(int pNbFemelles) {
    m_nbFemelles->setText(QString::number(pNbFemelles));
}

void WidgetInfos::setNbPetits(int pNbPetits) {
    m_nbPetits->setText(QString::number(pNbPetits));
}

void WidgetInfos::setNbPredateurs(int pNbPredateurs) {
    m_nbPredateurs->setText(QString::number(pNbPredateurs));
}

void WidgetInfos::setQteBrindillesStock(int pNbBrindilles) {
    m_qteBrindillesStock->setText(QString::number(pNbBrindilles));
}

void WidgetInfos::setNbBrindillesCarte(int pNbBrindilles) {
    m_nbBrindillesCarte->setText(QString::number(pNbBrindilles));
}

void WidgetInfos::setQteNourritureStock(int pQteNourriture) {
    m_qteNourritureStock->setText(QString::number(pQteNourriture));
}

void WidgetInfos::setNbMyceliumCarte(int pNbMycelium) {
    m_nbMyceliumCarte->setText(QString::number(pNbMycelium));
}

void WidgetInfos::setNbPucerons(int pNbPucerons) {
    m_nbPucerons->setText(QString::number(pNbPucerons));
}

void WidgetInfos::setNbConstructions(int pQteConstructions) {
    m_nbConstructions->setText(QString::number(pQteConstructions));
}

void WidgetInfos::setJours(int pJours) {
    m_jours->setText(QString::number(pJours));
}

void WidgetInfos::ajoutMale(int pNb) {
    m_nbMales->setText(QString::number(m_nbMales->text().toInt() + pNb));
}

void WidgetInfos::ajoutFemelle(int pNb) {
    m_nbFemelles->setText(QString::number(m_nbFemelles->text().toInt() + pNb));
}

void WidgetInfos::ajoutPetit(int pNb) {
    m_nbPetits->setText(QString::number(m_nbPetits->text().toInt() + pNb));
}

void WidgetInfos::ajoutPredateurs(int pNb) {
    m_nbPetits->setText(QString::number(m_nbPredateurs->text().toInt() + pNb));
}

void WidgetInfos::ajoutBrindilleStock(int pNb) {
    m_qteBrindillesStock->setText(QString::number(m_qteBrindillesStock->text().toInt() + pNb));
}

void WidgetInfos::ajoutBrindilleCarte(int pNb) {
    m_nbBrindillesCarte->setText(QString::number(m_nbBrindillesCarte->text().toInt() + pNb));
}

void WidgetInfos::ajoutNourritureStock(int pNb) {
    m_qteNourritureStock->setText(QString::number(m_qteNourritureStock->text().toInt() + pNb));
}

void WidgetInfos::ajoutMyceliumCarte(int pNb) {
    m_nbMyceliumCarte->setText(QString::number(m_nbMyceliumCarte->text().toInt() + pNb));
}

void WidgetInfos::ajoutPuceron(int pNb) {
    m_nbPucerons->setText(QString::number(m_nbPucerons->text().toInt() + pNb));
}

void WidgetInfos::ajoutConstruction(int pNb) {
    m_nbConstructions->setText(QString::number(m_nbConstructions->text().toInt() + pNb));
}

void WidgetInfos::ajoutJour(int pNb) {
    m_jours->setText(QString::number(m_jours->text().toInt() + pNb));
}

void WidgetInfos::suppressionMale() {
    m_nbMales->setText(QString::number(m_nbMales->text().toInt() - 1));
}


void WidgetInfos::suppressionFemelle() {
    m_nbFemelles->setText(QString::number(m_nbFemelles->text().toInt() - 1));
}


void WidgetInfos::suppressionPetit() {
    m_nbPetits->setText(QString::number(m_nbPetits->text().toInt() - 1));
}

void WidgetInfos::suppressionPredateur() {
    m_nbPredateurs->setText(QString::number(m_nbPredateurs->text().toInt() - 1));
}

void WidgetInfos::suppressionBrindilleStock() {
    m_qteBrindillesStock->setText(QString::number(m_qteBrindillesStock->text().toInt() - 1));
}

void WidgetInfos::suppressionBrindilleCarte() {
    m_nbBrindillesCarte->setText(QString::number(m_nbBrindillesCarte->text().toInt() - 1));
}

void WidgetInfos::suppressionNourritureStock() {
    m_qteNourritureStock->setText(QString::number(m_qteNourritureStock->text().toInt() - 1));
}

void WidgetInfos::suppressionMyceliumCarte() {
    m_nbMyceliumCarte->setText(QString::number(m_nbMyceliumCarte->text().toInt() - 1));
}

void WidgetInfos::suppressionPuceron() {
    m_nbPucerons->setText(QString::number(m_nbPucerons->text().toInt() - 1));
}

void WidgetInfos::suppressionConstruction() {
    m_nbConstructions->setText(QString::number(m_nbConstructions->text().toInt() - 1));
}


void WidgetInfos::ajout(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)(int);
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::ajoutBrindilleCarte},
    {ParametresMonde::Construction, &WidgetInfos::ajoutConstruction},
    {ParametresMonde::Femelle, &WidgetInfos::ajoutFemelle},
    {ParametresMonde::Male, &WidgetInfos::ajoutMale},
    {ParametresMonde::Mycelium, &WidgetInfos::ajoutMyceliumCarte},
    {ParametresMonde::Petits, &WidgetInfos::ajoutPetit},
    {ParametresMonde::Predateur, &WidgetInfos::ajoutPredateurs},
    {ParametresMonde::Puceron, &WidgetInfos::ajoutPuceron}
};
    (this->*tab[pType].f)(1);
}


void WidgetInfos::suppression(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)();
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::suppressionBrindilleCarte},
    {ParametresMonde::Construction, &WidgetInfos::suppressionConstruction},
    {ParametresMonde::Femelle, &WidgetInfos::suppressionFemelle},
    {ParametresMonde::Male, &WidgetInfos::suppressionMale},
    {ParametresMonde::Mycelium, &WidgetInfos::suppressionMyceliumCarte},
    {ParametresMonde::Petits, &WidgetInfos::suppressionPetit},
    {ParametresMonde::Predateur, &WidgetInfos::suppressionPredateur},
    {ParametresMonde::Puceron, &WidgetInfos::suppressionPuceron}
};
    (this->*tab[pType].f)();
}
