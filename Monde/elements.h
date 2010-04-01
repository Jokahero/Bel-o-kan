#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "../AppBase/ParamsMonde.h"
#include "position.h"

#include <QtCore/QObject>

class Monde;

class Elements : public QObject {
    Q_OBJECT

public:
    Elements(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType);
    ~Elements();
    void setPos(const Position& pPos);
    Position getPos() const;
    inline Monde* getMonde() const {return m_monde;}

    inline bool isMort() const {return m_mort;}
    void setMort(bool pMort);

    inline ParametresMonde::typeElement getType() const {return m_type;}

    virtual void tour() {setBouge(true);}

    inline bool isBouge() const {return m_bouge;}
    void setBouge(bool pBouge);

private:
    bool m_mort;
    Position m_pos;
    Monde* m_monde;
    ParametresMonde::typeElement m_type;
    bool m_bouge;

signals:
    void ajoutBrindilles(int pQte);
    void ajoutNourriture(int pQte);
};

#endif // ELEMENTS_H
