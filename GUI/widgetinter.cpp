#include "widgetinter.h"

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

#include <QtCore/QDebug>

WidgetInter::WidgetInter() {
    QWidget *tmp = new QWidget;
    m_tourSuivant = new QPushButton(tr("Tour suivant"), this);
    m_boucle = new QPushButton(tr("Boucle"), this);
    m_boucle->setCheckable(true);
    m_boucle->setChecked(false);
    m_historique = new QTextEdit(this);
    m_historique->setReadOnly(true);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_historique);

    QGroupBox *group = new QGroupBox();
    QVBoxLayout *layoutBouton = new QVBoxLayout();
    layoutBouton->addWidget(m_tourSuivant);
    layoutBouton->addWidget(m_boucle);
    group->setLayout(layoutBouton);

    layout->addWidget(group);

    tmp->setLayout(layout);

    setWidget(tmp);
    connect(m_tourSuivant, SIGNAL(clicked()), this, SIGNAL(tourSuivant()));
    connect(m_boucle, SIGNAL(clicked()), this, SIGNAL(boucle()));
}

void WidgetInter::afficherDeplacement(ParametresMonde::typeElement pTE, int pXOrig, int pYOrig, int pXDest, int pYDest) {
    switch (pTE) {
    case ParametresMonde::Male:
        m_historique->append("Un mâle s'est déplacé de la position (" + QString::number(pXOrig) + "," +QString::number(pYOrig) + ") vers la position (" +QString::number(pXDest) + "," + QString::number(pYDest)+").");
        break;

    case ParametresMonde::Femelle:
        m_historique->append("Une femelle s'est déplacé de la position (" + QString::number(pXOrig) + "," +QString::number(pYOrig) + ") vers la position (" +QString::number(pXDest) + "," + QString::number(pYDest)+").");
        break;

    case ParametresMonde::Petits:
        m_historique->append("Un petit s'est déplacé de la position (" + QString::number(pXOrig) + "," +QString::number(pYOrig) + ") vers la position (" +QString::number(pXDest) + "," + QString::number(pYDest)+").");
        break;

    default:
        break;
    }
}

void WidgetInter::modifierHistorique(ParametresMonde::typeInfo pEvenement) {
    switch(pEvenement) {
        case ParametresMonde::NouveauPetit:
            m_historique->append("Nouveau petit dans la colonie.");
            break;

        case ParametresMonde::NouveauMale:
            m_historique->append("Nouveau mâle dans la colonie.");
            break;

        case ParametresMonde::NouvelleFemelle:
            m_historique->append("Nouvelle femelle dans la colonie.");
            break;

        default:
            break;
    }
}

void WidgetInter::triggerBoucle(bool pActif) {
    m_boucle->setChecked(pActif);
}

void WidgetInter::finMonde() {
    m_boucle->setEnabled(false);
    m_tourSuivant->setEnabled(false);
}
