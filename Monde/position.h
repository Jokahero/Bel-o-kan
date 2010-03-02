#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int pAbcisse, int pOrdonnee);

    inline int getAbcisse() const {return m_abcisse;};
    void setAbcisse(int pAbcisse);

    inline int getOrdonnee() const {return m_ordonnee;};
    void setOrdonnee(int pOrdonnee);

private:
    int m_abcisse;
    int m_ordonnee;
};

#endif // POSITION_H
