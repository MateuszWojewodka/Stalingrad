#include "tower.h"
#include "gamemanager.h"

Tower::Tower(XY pos, XY size, Team *team, GameManager *game) :
    Aggressor(300, team, game->getTeams()),
    Element(pos, size, 300, game)
{
    XY center_of_tower = _pos + _size*XY(0.5,0.5);
    //_weapon = new Weapon(this, _pos + _size*XY(0.5,0.5), game);
    _weapon = new Weapon(3, 500, this, center_of_tower, _game);
}

void Tower::updateElement()
{
    if (checkIfDeathIsComming()) return;
    attack();
}
