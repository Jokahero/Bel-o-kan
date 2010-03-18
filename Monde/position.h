#ifndef POSITION_H
#define POSITION_H

#include <QtCore/QDebug>

template <typename T> class QList;

class Position {
public:
    Position(int pAbcisse = 0, int pOrdonnee = 0);
    
    inline int getAbcisse() const {return m_abcisse;};
    void setAbcisse(int pAbcisse);
    
    inline int getOrdonnee() const {return m_ordonnee;};
    void setOrdonnee(int pOrdonnee);

    int distance(const Position& p) const;
    
    bool operator<(const Position& p) const {
        return (getAbcisse() < p.getAbcisse() ||
                (getAbcisse() == p.getAbcisse() &&
                 getOrdonnee() < p.getOrdonnee()));
    }

    bool operator==(const Position& p) const {
        return (getAbcisse() == p.getAbcisse() &&
                getOrdonnee() == p.getOrdonnee());
    }

    bool operator!=(const Position& p) const {
        return !(p == *this);
    }

    QList<Position> getPositionsAdjacentes(int pDistance = 1) const;
    
private:
    int m_abcisse;
    int m_ordonnee;
};

QDebug operator<<(QDebug dbg, const Position &pos);

#endif // POSITION_H
