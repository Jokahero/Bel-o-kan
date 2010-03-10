#include "widgetinfos.h"

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QFormLayout>
#include <QtGui/QWidget>

#include <QtCore/QDebug>

WidgetInfos::WidgetInfos() {
    setWindowTitle(tr("Informations"));

    m_nbMales = new QLabel(QString::number(0), this);
    m_nbFemelles = new QLabel(QString::number(0), this);
    m_nbPetits = new QLabel(QString::number(0), this);
    m_nbBrindilles = new QLabel(QString::number(0), this);
    m_qteNourriture = new QLabel(QString::number(0), this);

    m_jours = new QLabel(QString::number(0), this);

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


void WidgetInfos::setNbMales(int pNbMales) {
    m_nbMales->setText(QString::number(pNbMales));
}


void WidgetInfos::setNbFemelles(int pNbFemelles) {
    m_nbFemelles->setText(QString::number(pNbFemelles));
}


void WidgetInfos::setNbPetits(int pNbPetits) {
    m_nbPetits->setText(QString::number(pNbPetits));
}


void WidgetInfos::setNbBrindilles(int pNbBrindilles) {
    m_nbBrindilles->setText(QString::number(pNbBrindilles));
}


void WidgetInfos::setQteNourriture(int pQteNourriture) {
    m_qteNourriture->setText(QString::number(pQteNourriture));
}


void WidgetInfos::setJours(int pJours) {
    m_jours->setText(QString::number(pJours));
}


void WidgetInfos::ajoutMale() {
    m_nbMales->setText(QString::number(m_nbMales->text().toInt() + 1));
}


void WidgetInfos::ajoutFemelle() {
    m_nbFemelles->setText(QString::number(m_nbFemelles->text().toInt() + 1));
}


void WidgetInfos::ajoutPetit() {
    m_nbPetits->setText(QString::number(m_nbPetits->text().toInt() + 1));
}


void WidgetInfos::ajoutBrindille() {
    m_nbBrindilles->setText(QString::number(m_nbBrindilles->text().toInt() + 1));
}


void WidgetInfos::ajoutMycelium() {
}


void WidgetInfos::ajoutJour() {
    m_jours->setText(QString::number(m_jours->text().toInt() + 1));
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


void WidgetInfos::suppressionBrindille() {
    m_nbBrindilles->setText(QString::number(m_nbBrindilles->text().toInt() - 1));
}


void WidgetInfos::suppressionMycelium() {
    qDebug() << "Suppression mycelium";
    m_qteNourriture->setText(QString::number(m_qteNourriture->text().toInt() + 1));
}


void WidgetInfos::suppressionJour() {
    m_jours->setText(QString::number(m_jours->text().toInt() - 1));
}


void WidgetInfos::ajout(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)();
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::ajoutBrindille},
    {ParametresMonde::Femelle, &WidgetInfos::ajoutFemelle},
    {ParametresMonde::Male, &WidgetInfos::ajoutMale},
    {ParametresMonde::Mycelium, &WidgetInfos::ajoutMycelium},
    {ParametresMonde::Petits, &WidgetInfos::ajoutPetit}
};
    (this->*tab[pType].f)();
}


void WidgetInfos::suppression(ParametresMonde::typeElement pType) {
    static struct { ParametresMonde::typeElement t;
        void (WidgetInfos::*f)();
    } tab[] = {
    {ParametresMonde::Brindille, &WidgetInfos::suppressionBrindille},
    {ParametresMonde::Femelle, &WidgetInfos::suppressionFemelle},
    {ParametresMonde::Male, &WidgetInfos::suppressionMale},
    {ParametresMonde::Mycelium, &WidgetInfos::suppressionMycelium},
    {ParametresMonde::Petits, &WidgetInfos::suppressionPetit}
};
    (this->*tab[pType].f)();
}
