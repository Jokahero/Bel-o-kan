#ifndef ELEMENTS_H
#define ELEMENTS_H

class Monde;
class Position;

class Elements {
public:
    Elements(Monde* pMonde, int pAbcisse, int pOrdonnee);
    ~Elements();
    void setPos(Position* pPos);
    Position getPos() const;
    inline Monde* getMonde() const {return m_monde;}

    inline bool isMort() const {return m_mort;}
    void setMort(bool pMort);

    virtual void tour() = 0;

private:
    bool m_mort;
    Position* m_pos;
    Monde* m_monde;
};

#endif // ELEMENTS_H
