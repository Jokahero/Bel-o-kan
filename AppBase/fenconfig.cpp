#include "fenconfig.h"

#include "ParamsMonde.h"
#include "../GUI/fencarte.h"
#include "../Monde/monde.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QSpinBox>

FenConfig::FenConfig(FenCarte* pFenCarte, Monde* pMonde, QWidget* pParent) : QWidget(pParent), m_fenCarte(pFenCarte), m_monde(pMonde) {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Bel-O-Kan - Initialisation du monde"));
    QVBoxLayout* layout = new QVBoxLayout;

    QGroupBox *carteGroupBox = new QGroupBox(tr("Carte"));
    QFormLayout *carte = new QFormLayout;
    carteGroupBox->setLayout(carte);
    m_largeurCarte = new QSpinBox(carteGroupBox);
    m_largeurCarte->setRange(1, 50);
    m_hauteurCarte = new QSpinBox(carteGroupBox);
    m_hauteurCarte->setRange(1, 50);
    carte->addRow(tr("Largeur"), m_largeurCarte);
    carte->addRow(tr("Hauteur"), m_hauteurCarte);

    QGroupBox *peupleGroupBox = new QGroupBox(tr("Peuple"));
    QFormLayout *peuple = new QFormLayout;
    peupleGroupBox->setLayout(peuple);
    m_nbFemelles = new QSpinBox(peupleGroupBox);
    m_nbFemelles->setRange(1, 50);
    m_nbMales = new QSpinBox(peupleGroupBox);
    m_nbMales->setRange(1, 50);
    m_nbPetits = new QSpinBox(peupleGroupBox);
    m_nbPetits->setRange(1, 50);
    peuple->addRow(tr("Femelles"), m_nbFemelles);
    peuple->addRow(tr("Mâles"), m_nbMales);
    peuple->addRow(tr("Petits"), m_nbPetits);

    m_bbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    layout->addWidget(carteGroupBox);
    layout->addWidget(peupleGroupBox);
    layout->addWidget(m_bbox);
    setLayout(layout);

    connect(m_bbox, SIGNAL(accepted()), this, SLOT(lancer()));
    connect(m_bbox, SIGNAL(rejected()), qApp, SLOT(quit()));
}

FenConfig::~FenConfig() {
    delete m_largeurCarte;
    delete m_hauteurCarte;
    delete m_nbFemelles;
    delete m_nbMales;
    delete m_nbPetits;
    delete m_bbox;
}

void FenConfig::lancer() {
    ParamsMonde p;
    p.hauteur = m_hauteurCarte->value();
    p.largeur = m_largeurCarte->value();
    p.nbFemelles = m_nbFemelles->value();
    p.nbMales = m_nbMales->value();
    p.nbPetits = m_nbPetits->value();
    m_monde->init(p);
    m_fenCarte->show(p.hauteur, p.largeur);
    close();
}
