#ifndef FENCONFIG_H
#define FENCONFIG_H

#include <QtGui/QWidget>

class FenCarte;
class Monde;
class QDialogButtonBox;

class FenConfig : public QWidget {
    Q_OBJECT

public:
    FenConfig(FenCarte* pCarte, Monde* pMonde, QWidget* pParent = 0);
    ~FenConfig();

public slots:
    void lancer();

private:
    FenCarte* m_fenCarte;
    Monde* m_monde;
    QDialogButtonBox* m_bbox;
};

#endif // FENCONFIG_H
