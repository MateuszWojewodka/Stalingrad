#include "soldier.h"
#include "gamemanager.h"

Soldier::Soldier(XY pos, Team *team, GameManager *game) :
    Shooter(pos,  XY(50,50), 50, 0.5, 50, team, game)
{
    _weapon = new Weapon(1, 200, this, _gun_pos, _game);
}
