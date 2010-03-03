#include "fencarte.h"
#include "carte.h"

#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QAction>

FenCarte::FenCarte()
{
    m_barreMenu = new QMenuBar(this);
    m_menuPrinc = new QMenu("Menu", this);
    m_quitter = new QAction("&Quitter", this);

    m_menuPrinc->addAction(m_quitter);

    m_barreMenu->addMenu(m_menuPrinc);

    setMenuBar(m_barreMenu);

    m_carte = new Carte();
    setCentralWidget(m_carte);
}

void FenCarte::show(int pHauteur, int pLargeur) {
    m_carte->construireCarte(pHauteur, pLargeur);
    QMainWindow::show();
}
