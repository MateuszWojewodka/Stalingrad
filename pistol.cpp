#include "pistol.h"

Pistol::Pistol(Aggressor *owner, XY owner_pos, GameManager *game) :
    Weapon(1, 100, owner, owner_pos, game)
{
}
