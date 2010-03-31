#ifndef WIDGETINTER_H
#define WIDGETINTER_H

#include <QtGui/QDockWidget>

#include "../AppBase/ParamsMonde.h"

class QPushButton;
class QTextEdit;

class WidgetInter : public QDockWidget {
    Q_OBJECT

public:
    WidgetInter();

private:
    QPushButton *m_tourSuivant;
    QPushButton *m_boucle;
    QTextEdit *m_historique;

public slots:
    void afficherDeplacement(ParametresMonde::typeElement, int pXOrig, int pYOrig, int pXDest, int pYDest);
    void modifierHistorique(ParametresMonde::typeInfo pEvenement);
    void triggerBoucle(bool pActif);
    void finMonde();

signals:
    void tourSuivant();
    void boucle();
};

#endif // WIDGETINTER_H
