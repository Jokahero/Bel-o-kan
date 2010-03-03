#include "fenconfig.h"

#include "ParamsMonde.h"
#include "../GUI/carte.h"
#include "../Monde/monde.h"
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>

FenConfig::FenConfig(Carte* pCarte, Monde* pMonde, QWidget* pParent) : QWidget(pParent), m_carte(pCarte), m_monde(pMonde) {
    setWindowTitle(tr("Bel-O-Kan - Initialisation du monde"));
    QHBoxLayout* layout = new QHBoxLayout;
    m_bbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout->addWidget(m_bbox);
    setLayout(layout);

    connect(m_bbox, SIGNAL(accepted()), this, SLOT(lancer()));
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
    m_carte->construireCarte(p.hauteur, p.largeur);
    m_carte->show();
}
