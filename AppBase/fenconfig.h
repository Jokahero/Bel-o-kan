#ifndef FENCONFIG_H
#define FENCONFIG_H

#include <QtGui/QWidget>

class Carte;
class Monde;
class QDialogButtonBox;

class FenConfig : public QWidget {
    Q_OBJECT

public:
    FenConfig(Carte* pCarte, Monde* pMonde, QWidget* pParent = 0);
    ~FenConfig();

public slots:
    void lancer();

private:
    Carte* m_carte;
    Monde* m_monde;
    QDialogButtonBox* m_bbox;
};

#endif // FENCONFIG_H
