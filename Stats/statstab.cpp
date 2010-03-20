#include "statstab.h"

#include "widgetstats.h"

#include <QtGui/QGraphicsScene>
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
    int h = m_view->height() - 50;

    QPen graphe(QColor(Qt::black));
    QPen femelles(QColor(Qt::red));
    QPen males(QColor(Qt::blue));
    QPen petits(QColor(Qt::green));

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

    // Dessin des courbes
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbFemelles * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbFemelles * pasY), femelles);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbMales * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbMales * pasY), males);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbPetits * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbPetits * pasY), petits);
}

void StatsTab::dessinRessources() {

}

void StatsTab::dessinStock() {
    delete m_scene;
    m_scene = new QGraphicsScene;
    m_view->setScene(m_scene);

    int l = m_view->width() - 50;
    int h = m_view->height() - 50;

    QPen graphe(QColor(Qt::black));
    QPen nourriture(QColor(Qt::red));
    QPen brindilles(QColor(Qt::blue));

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

    // Dessin des courbes
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbBrindilles * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbBrindilles * pasY), brindilles);
    for (int i = 0; i < xMax - 1; i++)
        m_scene->addLine(i * pasX, h - m_parent->getListeTours()->at(i).nbNourriture * pasY, (i + 1) * pasX, h - (m_parent->getListeTours()->at(i + 1).nbNourriture * pasY), nourriture);
  }
