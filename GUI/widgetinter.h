#ifndef WIDGETINTER_H
#define WIDGETINTER_H

#include <QtGui/QDockWidget>

class QTextEdit;
class QPushButton;

class WidgetInter : public QDockWidget
{
    Q_OBJECT

public:
    WidgetInter();

private:
    QPushButton *m_tourSuivant;
    QPushButton *m_boucle;
    QTextEdit *m_historique;

public slots:
    void modifierHistorique(QString pEvenement);

signals:
    void tourSuivant();
    void boucle();
};

#endif // WIDGETINTER_H
