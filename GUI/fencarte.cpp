#include "fencarte.h"
#include "carte.h"
#include "widgetinfos.h"
#include "widgetinter.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtGui/QMessageBox>

FenCarte::FenCarte() {
    setWindowTitle(tr("Bel-O-Kan - Simulation"));
    QIcon icone("Ant-icon.png");
    setWindowIcon(icone);

    m_barreMenu = new QMenuBar(this);
    m_menuPrinc = new QMenu(tr("&Menu"), this);
    m_quitter = new QAction(tr("&Quitter"), this);
    m_quitter->setShortcut(tr("Ctrl+Q"));
    m_tourSuivant = new QAction(tr("Tour suivant"), this);
    m_tourSuivant->setShortcut(tr("Ctrl+T"));
    m_tourBoucle = new QAction(tr("Boucler"), this);
    m_tourBoucle->setCheckable(true);
    m_tourBoucle->setChecked(false);
    m_tourBoucle->setShortcut(tr("Ctrl+Shift+T"));

    m_menuPrinc->addAction(m_tourSuivant);
    m_menuPrinc->addAction(m_tourBoucle);
    m_menuPrinc->addAction(m_quitter);

    m_barreMenu->addMenu(m_menuPrinc);

    setMenuBar(m_barreMenu);

    m_carte = new Carte();
    setCentralWidget(m_carte);

    m_WInfos = new WidgetInfos();
    addDockWidget(Qt::RightDockWidgetArea, m_WInfos);

    m_WInter = new WidgetInter();
    addDockWidget(Qt::BottomDockWidgetArea, m_WInter);

    connect(m_quitter, SIGNAL(triggered()), this, SIGNAL(signalQuitter()));
    connect(m_tourSuivant, SIGNAL(triggered()), this, SIGNAL(tourSuivant()));
    connect(this, SIGNAL(afficherElement(ParametresMonde::typeElement,int,int)), m_carte, SLOT(afficherIcone(ParametresMonde::typeElement,int,int)));
    connect(this, SIGNAL(supprimerElement(ParametresMonde::typeElement,int,int)), m_carte, SLOT(supprimerIcone(ParametresMonde::typeElement,int,int)));
    connect(this, SIGNAL(deplacerElement(ParametresMonde::typeElement,int,int,int,int)), m_carte, SLOT(deplacerElement(ParametresMonde::typeElement, int, int, int, int)));
    connect(this, SIGNAL(afficherElement(ParametresMonde::typeElement,int,int)), m_WInfos, SLOT(ajout(ParametresMonde::typeElement)));
    connect(this, SIGNAL(supprimerElement(ParametresMonde::typeElement,int,int)), m_WInfos, SLOT(suppression(ParametresMonde::typeElement)));
    connect(this, SIGNAL(tourSuivantMonde()), m_WInfos, SLOT(ajoutJour()));
    connect(this, SIGNAL(ajoutBrindilles(int)), m_WInfos, SLOT(ajoutBrindilleStock(int)));
    connect(this, SIGNAL(ajoutNourriture(int)), m_WInfos, SLOT(ajoutNourritureStock(int)));
    connect(m_WInter, SIGNAL(tourSuivant()), m_tourSuivant, SLOT(trigger()));
    connect(m_WInter, SIGNAL(boucle()), m_tourBoucle, SLOT(trigger()));
    connect(m_tourBoucle, SIGNAL(toggled(bool)), m_WInter, SLOT(triggerBoucle(bool)));
    connect(m_tourBoucle, SIGNAL(triggered()), this, SLOT(boucle()));
}

void FenCarte::show(int pHauteur, int pLargeur) {
    m_carte->construireCarte(pHauteur, pLargeur);
    QMainWindow::showMaximized();
}

void FenCarte::finDuMonde(int pNbTours) {
    m_tourBoucle->setChecked(false);
    m_tourSuivant->setEnabled(false);
    m_tourBoucle->setEnabled(false);
    m_WInter->finMonde();
    QMessageBox msgBox;
    msgBox.setText(tr("Le peuple a été éliminé en %n tour(s).", "s", pNbTours));
    msgBox.exec();
}

void FenCarte::boucle() {
    while (m_tourBoucle->isChecked() && m_tourSuivant->isEnabled()) {
        m_tourSuivant->trigger();
        qApp->processEvents();
    }
}
