#ifndef BAZOOKA_H
#define BAZOOKA_H

#include "weapon.h"

class Bazooka : public Weapon
{
    //int radius;
public:
    Bazooka(Aggressor *owner, XY owner_pos, GameManager *game);
    void shoot(XY velo_versor);
};

#endif // BAZOOKA_H
