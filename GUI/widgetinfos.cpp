#include "widgetinfos.h"

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

    QHBoxLayout *layoutPrincipal = new QHBoxLayout(tmp);
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


void WidgetInfos::ajout(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)(int);
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::ajoutBrindilleCarte},
    {ParametresMonde::Femelle, &WidgetInfos::ajoutFemelle},
    {ParametresMonde::Male, &WidgetInfos::ajoutMale},
    {ParametresMonde::Mycelium, &WidgetInfos::ajoutMyceliumCarte},
    {ParametresMonde::Petits, &WidgetInfos::ajoutPetit},
    {ParametresMonde::Puceron, &WidgetInfos::ajoutPuceron}
};
    (this->*tab[pType].f)(1);
}


void WidgetInfos::suppression(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)();
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::suppressionBrindilleCarte},
    {ParametresMonde::Femelle, &WidgetInfos::suppressionFemelle},
    {ParametresMonde::Male, &WidgetInfos::suppressionMale},
    {ParametresMonde::Mycelium, &WidgetInfos::suppressionMyceliumCarte},
    {ParametresMonde::Petits, &WidgetInfos::suppressionPetit},
    {ParametresMonde::Puceron, &WidgetInfos::suppressionPuceron}
};
    (this->*tab[pType].f)();
}
