#ifndef TOWER_H
#define TOWER_H

#include "element.h"
#include "aggressor.h"

class Tower : public Element, public Aggressor
{
public:
    Tower(XY pos, XY size, Team *team, GameManager *game);
    void updateElement();
};

#endif // TOWER_H
