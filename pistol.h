#ifndef PISTOL_H
#define PISTOL_H

#include "weapon.h"

class Pistol : public Weapon
{
public:
    Pistol(Aggressor *owner, XY owner_pos, GameManager *game);
};

#endif // PISTOL_H
