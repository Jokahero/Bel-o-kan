#include "elements.h"

#include "position.h"

Elements::Elements() {
    m_pos = new Position;
}

Elements::~Elements() {
    delete m_pos;
}
