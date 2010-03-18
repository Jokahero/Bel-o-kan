#include "carte.h"
#include "hexagone.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QPixmap>
#include <QtCore/QPoint>
#include <QtGui/QPolygon>

Carte::Carte() {
    m_scene = new QGraphicsScene();
    m_listeHexagones = new QVector<Hexagone*>;
    m_carte = new QVector<QVector<Hexagone*>*>;

    m_scene->setBackgroundBrush(QBrush(Qt::black));

    setScene(m_scene);
}

Carte::~Carte() {
    delete m_scene;
    for(int i=0; m_listeHexagones->size() > 0; i++)
        delete m_listeHexagones->at(i);
    delete m_listeHexagones;
}

void Carte::construireCarte(int pHauteur, int pLargeur) {
    int taille = pHauteur * pLargeur;
    bool basse = false;

    for (int i=0; i < taille; i++)
        m_listeHexagones->append(new Hexagone());

    m_carte->append(new QVector<Hexagone*>);

    int x=75, y=80;
    for (int i=0, j=1, col = 0; i < taille; i++, j++) {
        m_listeHexagones->at(i)->setCoord(x, y);
        m_carte->at(col)->append(m_listeHexagones->at(i));
        if (j == pHauteur) {
            col++;
            m_carte->append(new QVector<Hexagone*>);
            if (basse == false) {
                x += 75;
                y = 125;
                j = 0;
                basse = true;
            } else {
                x += 75;
                y = 80;
                j = 0;
                basse = false;
            }
        } else
            y += 90;
    }

    QPen pen(Qt::black, 1, Qt::SolidLine);
    QBrush brush(Qt::green);

    for (int i=0; i < m_listeHexagones->size(); i++) {
        m_listeHexagones->at(i)->construire();
        m_scene->addPolygon(*m_listeHexagones->at(i), pen, brush);
    }
}

void Carte::afficherIcone(ParametresMonde::typeElement pTypeElement, int pX, int pY) {
    pY = m_carte->at(pX)->size() - pY - 1;
    m_carte->at(pX)->at(pY)->setIcon(pTypeElement);
    m_scene->addItem(m_carte->at(pX)->at(pY)->getIcon());
}

void Carte::supprimerIcone(ParametresMonde::typeElement /*pTE*/, int pX, int pY) {
    pY = m_carte->at(pX)->size() - pY - 1;
    delete m_carte->at(pX)->at(pY)->getIcon();
    //m_scene->removeItem(m_scene->itemAt(m_carte->at(pX)->at(pY)->getIcon()->pos()));
    m_carte->at(pX)->at(pY)->setIcon();
}

void Carte::deplacerElement(ParametresMonde::typeElement pTE, int pXOrig, int pYOrig, int pXDest, int pYDest) {
    supprimerIcone(pTE, pXOrig, pYOrig);
    afficherIcone(pTE, pXDest, pYDest);
}
