#ifndef SNIPER_H
#define SNIPER_H

#include "shooter.h"

class Sniper : public Shooter
{
public:
    Sniper(XY pos, Team *team, GameManager *game);
};

#endif // SNIPER_H
