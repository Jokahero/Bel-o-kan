#ifndef MONDE_H
#define MONDE_H

class Elements;
class Position;
template<typename Key, typename T> class QMap;
template<typename T> class QVector;

class Monde {
public:
    Monde();
    ~Monde();

private:
    QMap<Position, int>* m_infos;
    QVector<Elements*>* m_elements;
};

#endif // MONDE_H
