#ifndef SOLDIER_H
#define SOLDIER_H

#include "shooter.h"

class Soldier : public Shooter
{
public:
    Soldier(XY pos, Team *team, GameManager *game);
};

#endif // SOLDIER_H
