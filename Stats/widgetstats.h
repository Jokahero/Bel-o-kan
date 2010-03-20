#ifndef WIDGETSTATS_H
#define WIDGETSTATS_H

#include <QtGui/QWidget>
#include "../AppBase/ParamsMonde.h"

class QTabWidget;
template <typename T> class QVector;

class WidgetStats : public QWidget {
    Q_OBJECT

public:
    WidgetStats(QVector<ParametresMonde::ParamsMonde> *pVect);
    inline QVector<ParametresMonde::ParamsMonde>* getListeTours() {return m_listeTours;}

public slots:
    void dessin(int pNum);

private:
    QVector<ParametresMonde::ParamsMonde> *m_listeTours;
    QTabWidget *m_tab;
};

#endif // WIDGETSTATS_H
