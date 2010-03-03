#ifndef POSITION_H
#define POSITION_H

template <typename T> class QList;

class Position {
public:
    Position(int pAbcisse, int pOrdonnee);
    
    inline int getAbcisse() const {return m_abcisse;};
    void setAbcisse(int pAbcisse);
    
    inline int getOrdonnee() const {return m_ordonnee;};
    void setOrdonnee(int pOrdonnee);
    
    bool operator<(const Position& p) const {
        return (getAbcisse() < p.getAbcisse() ||
                (getAbcisse() == p.getAbcisse() &&
                 getOrdonnee() < p.getOrdonnee()));
    }

    QList<Position> getPositionsAdjacentes() const;
    
private:
    int m_abcisse;
    int m_ordonnee;
};

#endif // POSITION_H
