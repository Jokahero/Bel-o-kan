#include "statstab.h"

#include "widgetstats.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsTextItem>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>

StatsTab::StatsTab(WidgetStats* pParent, int pPos) : m_parent(pParent), m_pos(pPos) {
    QHBoxLayout *layout = new QHBoxLayout;
    m_scene = new QGraphicsScene;
    m_view = new QGraphicsView(m_scene);
    layout->addWidget(m_view);
    setLayout(layout);
}

void StatsTab::dessin() {
    switch (m_pos) {
    case 0:
        dessinPopulation();
        break;
    case 1:
        dessinRessources();
        break;
    case 2:
        dessinStock();
        break;
    }
}

void StatsTab::resizeEvent(QResizeEvent *pEvent) {
    dessin();
    QWidget::resizeEvent(pEvent);
}

void StatsTab::dessinPopulation() {
    delete m_scene;
    m_scene = new QGraphicsScene;
    m_view->setScene(m_scene);

    int l = m_view->width() - 50;
    int h = m_view->height() - 75;

    QPen graphe(QColor(Qt::black));
    QPen femelles(QColor(Qt::red));
    QPen males(QColor(Qt::blue));
    QPen petits(QColor(Qt::green));

    // Dessin du graphique lui même
    m_scene->addLine(0, 0, 0, h, graphe);
    m_scene->addLine(0, h, l, h, graphe);

    int xMax = m_parent->getListeTours()->size();

    // Détermination de la valeur la plus élevée en ordonnées
    int yMax = 0;
    for (int i = 0; i < m_parent->getListeTours()->size(); i++) {
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).nbFemelles);
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).nbMales);
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).nbPetits);
    }

    int pasX = l / xMax;
    int pasY = h / yMax;

    // Dessin de la légende
    m_scene->addRect(QRectF(0, h + 30, 20, 10), femelles, QBrush(femelles.color()));
    m_scene->addText(tr("Femelles"))->moveBy(30, h + 25);
    m_scene->addRect(QRectF(100, h + 30, 20, 10), males, QBrush(males.color()));
    m_scene->addText(tr("Mâles"))->moveBy(130, h + 25);
    m_scene->addRect(QRectF(200, h + 30, 20, 10), petits, QBrush(petits.color()));
    m_scene->addText(tr("Petits"))->moveBy(230, h + 25);

    // Dessin des courbes
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbFemelles * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbFemelles * pasY), femelles);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbMales * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbMales * pasY), males);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbPetits * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbPetits * pasY), petits);
}

void StatsTab::dessinRessources() {
    delete m_scene;
    m_scene = new QGraphicsScene;
    m_view->setScene(m_scene);

    int l = m_view->width() - 50;
    int h = m_view->height() - 50;

    QPen graphe(QColor(Qt::black));
    QPen brindilles(QColor(Qt::red));
    QPen mycelium(QColor(Qt::blue));
    QPen puceron(QColor(Qt::green));

    m_scene->addLine(0, 0, 0, h, graphe);
    m_scene->addLine(0, h, l, h, graphe);

    int xMax = m_parent->getListeTours()->size();

    // Détermination de la valeur la plus élevée en ordonnées
    int yMax = 0;
    for (int i = 0; i < m_parent->getListeTours()->size(); i++) {
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).brindilles);
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).mycelium);
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).pucerons);
    }

    int pasX = l / xMax;
    int pasY = h / yMax;

    // Dessin de la légende
    m_scene->addRect(QRectF(0, h + 30, 20, 10), brindilles, QBrush(brindilles.color()));
    m_scene->addText(tr("Brindilles"))->moveBy(30, h + 25);
    m_scene->addRect(QRectF(100, h + 30, 20, 10), mycelium, QBrush(mycelium.color()));
    m_scene->addText(tr("Mycéliums"))->moveBy(130, h + 25);
    m_scene->addRect(QRectF(200, h + 30, 20, 10), puceron, QBrush(puceron.color()));
    m_scene->addText(tr("Pucerons"))->moveBy(230, h + 25);

    // Dessin des courbes
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).brindilles * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).brindilles * pasY), brindilles);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).mycelium * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).mycelium * pasY), mycelium);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).pucerons * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).pucerons * pasY), puceron);
}

void StatsTab::dessinStock() {
    delete m_scene;
    m_scene = new QGraphicsScene;
    m_view->setScene(m_scene);

    int l = m_view->width() - 50;
    int h = m_view->height() - 50;

    QPen graphe(QColor(Qt::black));
    QPen brindilles(QColor(Qt::red));
    QPen nourriture(QColor(Qt::blue));

    m_scene->addLine(0, 0, 0, h, graphe);
    m_scene->addLine(0, h, l, h, graphe);

    int xMax = m_parent->getListeTours()->size();

    // Détermination de la valeur la plus élevée en ordonnées
    int yMax = 0;
    for (int i = 0; i < m_parent->getListeTours()->size(); i++) {
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).nbBrindilles);
        yMax = qMax(yMax, m_parent->getListeTours()->at(i).nbNourriture);
    }

    int pasX = l / xMax;
    int pasY = h / yMax;

    // Dessin de la légende
    m_scene->addRect(QRectF(0, h + 30, 20, 10), brindilles, QBrush(brindilles.color()));
    m_scene->addText(tr("Brindilles"))->moveBy(30, h + 25);
    m_scene->addRect(QRectF(100, h + 30, 20, 10), nourriture, QBrush(nourriture.color()));
    m_scene->addText(tr("Nourriture"))->moveBy(130, h + 25);

    // Dessin des courbes
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbBrindilles * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbBrindilles * pasY), brindilles);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbNourriture * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbNourriture * pasY), nourriture);
}
