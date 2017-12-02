#include "sniper.h"
#include "gamemanager.h"

Sniper::Sniper(XY pos, Team *team, GameManager *game)  :
    Shooter(pos, XY(50,50), 50, 0.5, 300, team, game)
{
    _weapon = new Weapon(1, 400, this, _gun_pos, _game);
}
