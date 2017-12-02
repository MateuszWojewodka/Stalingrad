#ifndef SHOOTER_H
#define SHOOTER_H

#include "aggressor.h"
#include "movable.h"

class Shooter :
        public Aggressor,
        public Movable
{
    void updateGunPos();
protected:
    XY _gun_pos;
public:
    Shooter(XY pos, XY size, int hp, double velo_value, int attack_frequency, Team *my_team, GameManager *game);
    void updateElement();
    ~Shooter();
};

#endif // SHOOTER_H
