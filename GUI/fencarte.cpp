#include "fencarte.h"
#include "carte.h"

#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QIcon>

FenCarte::FenCarte()
{
    setWindowTitle(tr("Bel-O-Kan - Simulation"));
    QIcon *icone = new QIcon("Ant-icon.png");
    setWindowIcon(*icone);

    m_barreMenu = new QMenuBar(this);
    m_menuPrinc = new QMenu("Menu", this);
    m_quitter = new QAction("&Quitter", this);
    m_quitter->setShortcut(tr("Ctrl+Q"));

    m_menuPrinc->addAction(m_quitter);

    m_barreMenu->addMenu(m_menuPrinc);

    setMenuBar(m_barreMenu);

    m_carte = new Carte();
    setCentralWidget(m_carte);

    QObject::connect(m_quitter, SIGNAL(triggered()), this, SLOT(emmettreSignalQuitter()));
}

void FenCarte::show(int pHauteur, int pLargeur) {
    m_carte->construireCarte(pHauteur, pLargeur);
    QMainWindow::show();
}

void FenCarte::emmettreSignalQuitter() {
    emit signalQuitter();
}
