#include "fenconfig.h"

#include "ParamsMonde.h"
#include "../GUI/fencarte.h"
#include "../Monde/monde.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>

FenConfig::FenConfig(FenCarte* pFenCarte, Monde* pMonde, QWidget* pParent) : QWidget(pParent), m_fenCarte(pFenCarte), m_monde(pMonde) {
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Bel-O-Kan - Initialisation du monde"));
    QHBoxLayout* layout = new QHBoxLayout;
    m_bbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(m_bbox);
    setLayout(layout);

    connect(m_bbox, SIGNAL(accepted()), this, SLOT(lancer()));
    connect(m_bbox, SIGNAL(rejected()), qApp, SLOT(quit()));
}

FenConfig::~FenConfig() {
    delete m_bbox;
}

void FenConfig::lancer() {
    ParamsMonde p;
    p.hauteur = 15;
    p.largeur = 11;
    p.nbFemelles = 3;
    p.nbMales = 3;
    p.nbPetits = 2;
    m_monde->init(p);
    m_fenCarte->show(p.hauteur, p.largeur);
    close();
}
