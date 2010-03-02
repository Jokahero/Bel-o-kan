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

private:
    Position* m_pos;
    Monde* m_monde;
};

#endif // ELEMENTS_H
