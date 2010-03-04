#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "../AppBase/ParamsMonde.h"

class Monde;
class Position;

class Elements {
public:
    Elements(Monde* pMonde, int pAbcisse, int pOrdonnee, ParametresMonde::typeElement pType);
    ~Elements();
    void setPos(Position* pPos);
    Position getPos() const;
    inline Monde* getMonde() const {return m_monde;}

    inline bool isMort() const {return m_mort;}
    void setMort(bool pMort);

    inline ParametresMonde::typeElement getType() const {return m_type;}

    virtual void tour() = 0;

private:
    bool m_mort;
    Position* m_pos;
    Monde* m_monde;
    ParametresMonde::typeElement m_type;
};

#endif // ELEMENTS_H
