#include "widgetinter.h"

#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

#include <QtCore/QDebug>

WidgetInter::WidgetInter() {
    QWidget *tmp = new QWidget;
    m_tourSuivant = new QPushButton(tr("Tour suivant"), this);
    m_boucle = new QPushButton(tr("Boucle"), this);
    m_historique = new QTextEdit(this);
    m_historique->setReadOnly(true);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_historique);

    QGroupBox *group = new QGroupBox();
    QVBoxLayout *layoutBouton = new QVBoxLayout();
    layoutBouton->addWidget(m_tourSuivant);
    layoutBouton->addWidget(m_boucle);
    group->setLayout(layoutBouton);

    layout->addWidget(group);

    tmp->setLayout(layout);

    setWidget(tmp);
    connect(m_tourSuivant, SIGNAL(clicked()), this, SIGNAL(tourSuivant()));
    connect(m_boucle, SIGNAL(clicked()), this, SIGNAL(boucle()));
}

void WidgetInter::modifierHistorique(QString pEvenement) {
    m_historique->setPlainText(m_historique->toPlainText() + pEvenement);
}
