#ifndef FENCONFIG_H
#define FENCONFIG_H

#include <QtWidgets/QWidget>

class FenCarte;
class Monde;
class QDialogButtonBox;
class QSpinBox;
class Stats;

class FenConfig : public QWidget {
    Q_OBJECT

public:
    FenConfig(FenCarte* pCarte, Monde* pMonde, Stats* pStats, QWidget* pParent = 0);
    ~FenConfig();

private slots:
    void lancer();
    void verifCoherence();

private:
    FenCarte* m_fenCarte;
    Monde* m_monde;
    Stats* m_stats;

    QDialogButtonBox* m_bbox;
    QSpinBox* m_largeurCarte;
    QSpinBox* m_hauteurCarte;

    QSpinBox* m_nbFemelles;
    QSpinBox* m_nbMales;
    QSpinBox* m_nbPetits;
    QSpinBox* m_nbPredateurs;
    QSpinBox* m_nbConstructions;

    QSpinBox* m_nbMyceliums;
    QSpinBox* m_nbPucerons;
    QSpinBox* m_nbBrindillesC;

    QSpinBox* m_nbBrindilles;
    QSpinBox* m_nbNourriture;
};

#endif // FENCONFIG_H
