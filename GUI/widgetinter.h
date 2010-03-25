#ifndef WIDGETINTER_H
#define WIDGETINTER_H

#include <QtGui/QDockWidget>

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
    void modifierHistorique(const QString& pEvenement);
    void triggerBoucle(bool pActif);
    void finMonde();

signals:
    void tourSuivant();
    void boucle();
};

#endif // WIDGETINTER_H
