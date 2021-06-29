#ifndef STATSTAB_H
#define STATSTAB_H

#include <QtWidgets/QWidget>

class QGraphicsScene;
class QGraphicsView;
class WidgetStats;

class StatsTab : public QWidget {
    Q_OBJECT

public:
    StatsTab(WidgetStats* pParent, int pPos);
    void dessin();

private:
    WidgetStats *m_parent;
    int m_pos;

    void resizeEvent(QResizeEvent *pEvent);

    void dessinPopulation();
    void dessinRessources();
    void dessinStock();

    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
};

#endif // STATSTAB_H
