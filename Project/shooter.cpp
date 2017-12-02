#include "shooter.h"
#include "gamemanager.h"
#include <QDebug>

void Shooter::updateGunPos()
{
    _gun_pos = _pos + XY(_size.x, _size.y/2);
    moveYourGunToPosition(_gun_pos);
}

Shooter::Shooter(XY pos, XY size, int hp, double velo_value, int attack_frequency,
                 Team *my_team, GameManager *game) :
    Aggressor(attack_frequency, my_team, game->getTeams()),
    Movable(pos, size, hp, velo_value, game)
{
    //_elements = _game->getElements();
    _gun_pos = _pos + XY(_size.x, _size.y/2);
    //_weapon = new Weapon(this, _gun_pos, game);
}

void Shooter::updateElement()
{
    if (checkIfDeathIsComming()) return;
    updateGunPos();
    attack();
    goToElement(_target, _weapon->getWeaponRange() / 2);
    move();
}

Shooter::~Shooter()
{
}
