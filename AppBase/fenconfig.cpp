#include "fenconfig.h"

#include "ParamsMonde.h"
#include "../GUI/fencarte.h"
#include "../Monde/monde.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

FenConfig::FenConfig(FenCarte* pFenCarte, Monde* pMonde, QWidget* pParent) : QWidget(pParent), m_fenCarte(pFenCarte), m_monde(pMonde) {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Bel-O-Kan - Initialisation du monde"));

    QIcon *icone = new QIcon("Ant-icon.png");
    setWindowIcon(*icone);

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
    m_nbFemelles->setRange(0, 50);
    m_nbMales = new QSpinBox(peupleGroupBox);
    m_nbMales->setRange(0, 50);
    m_nbPetits = new QSpinBox(peupleGroupBox);
    m_nbPetits->setRange(0, 50);
    peuple->addRow(tr("Femelles"), m_nbFemelles);
    peuple->addRow(tr("Mâles"), m_nbMales);
    peuple->addRow(tr("Petits"), m_nbPetits);

    QGroupBox *resGroupBox = new QGroupBox(tr("Ressources"));
    QFormLayout *res= new QFormLayout;
    resGroupBox->setLayout(res);
    m_nbMyceliums = new QSpinBox(resGroupBox);
    m_nbMyceliums->setRange(0, 50);
    res->addRow(tr("Mycéliums"), m_nbMyceliums);

    QGroupBox *stockGroupBox = new QGroupBox(tr("Stock"));
    QFormLayout *stock= new QFormLayout;
    stockGroupBox->setLayout(stock);
    m_nbBrindilles = new QSpinBox(stockGroupBox);
    m_nbBrindilles->setRange(0, 50);
    stock->addRow(tr("Brindilles"), m_nbBrindilles);
    m_nbNourriture = new QSpinBox(stockGroupBox);
    m_nbNourriture->setRange(0, 50);
    stock->addRow(tr("Nourriture"), m_nbNourriture);

    m_bbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    layout->addWidget(carteGroupBox);
    layout->addWidget(peupleGroupBox);
    layout->addWidget(resGroupBox);
    layout->addWidget(stockGroupBox);
    layout->addWidget(m_bbox);
    setLayout(layout);

    verifCoherence();

    connect(m_bbox, SIGNAL(accepted()), this, SLOT(lancer()));
    connect(m_bbox, SIGNAL(rejected()), qApp, SLOT(quit()));
    connect(m_largeurCarte, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
    connect(m_hauteurCarte, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
    connect(m_nbFemelles, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
    connect(m_nbMales, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
    connect(m_nbPetits, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
    connect(m_nbMyceliums, SIGNAL(valueChanged(int)), this, SLOT(verifCoherence()));
}

FenConfig::~FenConfig() {
    delete m_largeurCarte;
    delete m_hauteurCarte;
    delete m_nbFemelles;
    delete m_nbMales;
    delete m_nbPetits;
    delete m_nbMyceliums;
    delete m_nbBrindilles;
    delete m_nbNourriture;
    delete m_bbox;
}

void FenConfig::lancer() {
    ParamsMonde p;
    p.hauteur = m_hauteurCarte->value();
    p.largeur = m_largeurCarte->value();
    p.nbFemelles = m_nbFemelles->value();
    p.nbMales = m_nbMales->value();
    p.nbPetits = m_nbPetits->value();
    p.mycelium = m_nbMyceliums->value();
    p.nbBrindilles = m_nbBrindilles->value();
    p.nbNourriture = m_nbNourriture->value();
    m_monde->init(p);
    m_fenCarte->show(p.hauteur, p.largeur);
    close();
}

void FenConfig::verifCoherence() {
    int nbCellules = m_hauteurCarte->value() * m_largeurCarte->value();
    int nbElements = 0;
    nbElements += m_nbFemelles->value();
    nbElements += m_nbMales->value();
    nbElements += m_nbPetits->value();
    nbElements += m_nbMyceliums->value();

    m_bbox->button(QDialogButtonBox::Ok)->setEnabled(nbElements <= nbCellules);
}
