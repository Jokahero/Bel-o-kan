#include "carte.h"
#include "hexagone.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QPixmap>
#include <QtCore/QPoint>
#include <QtGui/QPolygon>
#include <QtCore/QDebug>

Carte::Carte() {
    m_scene = new QGraphicsScene();
    m_listeHexagones = new QVector<Hexagone*>;
    m_carte = new QVector<QVector<Hexagone*>*>;

    // Instruction d'ajout d'un icône superposé sur un Hexagone
    /*************************/
    //QGraphicsPixmapItem *testQGPI = new QGraphicsPixmapItem((new QPixmap("brindille-icon1.png"))->scaled(50,50)); // scaled() redimmensionnement
    //testQGPI->setPos(75,100); // Soit Hexagone(X,Y) → Icône(X,Y+20)
    //testQGPI->setZValue(1); // Positionnement selon Z par defaut 0 → définition a 1 pour mettre l'icône au premier plan
    //m_scene->addItem(testQGPI); // ajout de l'icone a la scène
    /*************************/

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

    for(int i=0; i < taille; i++) {
        m_carte->append(new QVector<Hexagone*>);
        m_listeHexagones->append(new Hexagone());
        m_carte->at(i)->append(m_listeHexagones->at(i));
    }

    int x=75, y=80;
    for (int i=0, j=1; i < taille; i++, j++) {
        m_listeHexagones->at(i)->setCoord(x, y);
        if (j == pHauteur) {
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

    /*QGraphicsPixmapItem *testQGPI = new QGraphicsPixmapItem(QPixmap("Hexa-ant-test.png"));
    testQGPI->setPos(75,80);
    m_scene->addItem(testQGPI);*/
}

void Carte::afficherIcone(ParametresMonde::typeElement pTypeElement, int pX, int pY) {
    qDebug() << "Carte avant setIcon";
    qDebug() << m_carte->at(pX)->size();
    qDebug() << "***";
    m_carte->at(pX)->at(pX)->setIcon(pTypeElement);
    qDebug() << "Carte après setIcon <> avant addItem et getIcon ";
    m_scene->addItem(m_carte->at(pX)->at(pY)->getIcon());
    qDebug() << "Carte après tout";
}
