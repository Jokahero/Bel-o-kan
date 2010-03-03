#include "fencarte.h"
#include "carte.h"

#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>

FenCarte::FenCarte() {
    m_barreMenu = new QMenuBar(this);
    m_menuPrinc = new QMenu(tr("Menu"), this);
    m_quitter = new QAction(tr("&Quitter"), this);
    m_quitter->setShortcut(tr("Ctrl+Q"));
    m_tourSuivant = new QAction(tr("Tour suivant"), this);

    m_menuPrinc->addAction(m_quitter);
    m_menuPrinc->addAction(m_tourSuivant);

    m_barreMenu->addMenu(m_menuPrinc);

    setMenuBar(m_barreMenu);

    m_carte = new Carte();
    setCentralWidget(m_carte);

    connect(m_quitter, SIGNAL(triggered()), this, SIGNAL(signalQuitter()));
    connect(m_tourSuivant, SIGNAL(triggered()), this, SIGNAL(tourSuivant()));
}

void FenCarte::show(int pHauteur, int pLargeur) {
    m_carte->construireCarte(pHauteur, pLargeur);
    QMainWindow::show();
}
