#ifndef WIDGETINFOS_H
#define WIDGETINFOS_H

#include <QtGui/QDockWidget>

class QLabel;

class WidgetInfos : public QDockWidget
{
public:
    WidgetInfos();

private:
    QLabel *m_nbMales;
    QLabel *m_nbFemelles;
    QLabel *m_nbPetits;
    QLabel *m_nbBrindilles;
    QLabel *m_qteNourriture;

    QLabel *m_jours;
};

#endif // WIDGETINFOS_H
