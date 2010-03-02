#include "monde.h"

#include "elements.h"
#include "position.h"

#include <QtCore/QMap>
#include <QtCore/QVector>

Monde::Monde() {
    m_infos = new QMap<Position, int>;
    m_elements = new QVector<Elements*>;
}

Monde::~Monde() {
    delete m_infos;
    delete m_elements;
}
