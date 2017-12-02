#include "weapon.h"
#include "gamemanager.h"
#include <cmath>

Weapon::Weapon(int weapon_power, int weapon_range, Aggressor *owner, XY owner_pos, GameManager *game)
{
    _owner = owner;
    _pos = owner_pos;
    _game = game;
    _weapon_power = weapon_power;
    _weapon_range = weapon_range;
    _bullets_velo = 1;
}

Weapon::~Weapon()
{
}

int Weapon::getWeaponRange()
{
    return _weapon_range;
}

void Weapon::shoot(XY velo_versor)
{
    double x,y,d; //pomocnicze zmienne gdzie x, y , d to wsp i dlugosc pomocniczego wektora
    x = velo_versor.x;
    y = velo_versor.y;
    d = pow( pow(x,2) + pow(y,2) , 0.5 ); //przeciwprostokatna pierw z sumy kwadratow

    //wspolczynnik do przeciwprostokatnych wynikajacy ze wzoru
    double hypos_ratio = _bullets_velo / d;

    XY final_velo = XY(x * hypos_ratio, y * hypos_ratio);

    //--------------------------------------------------------

    _game->addBullet(_pos, final_velo, _weapon_power, _owner->getTeam(), this);
}
