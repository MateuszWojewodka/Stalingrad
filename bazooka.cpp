#include "bazooka.h"
#include "gamemanager.h"

Bazooka::Bazooka(Aggressor *owner, XY owner_pos, GameManager *game) :
    Weapon(200, 300, owner, owner_pos, game)
{

}

#include <cmath>
void Bazooka::shoot(XY velo_versor)
{
    double x,y,d; //pomocnicze zmienne gdzie x, y , d to wsp i dlugosc pomocniczego wektora
    x = velo_versor.x;
    y = velo_versor.y;
    d = pow( pow(x,2) + pow(y,2) , 0.5 ); //przeciwprostokatna pierw z sumy kwadratow

    //wspolczynnik do przeciwprostokatnych wynikajacy ze wzoru
    double hypos_ratio = _bullets_velo / d;

    XY final_velo = XY(x * hypos_ratio, y * hypos_ratio);

    //--------------------------------------------------------

    //_game->addBullet(_pos, final_velo, _weapon_power, _owner->getTeam(), this);

    _game->addBazookaBullet(_pos, final_velo, _weapon_power, 200, _owner->getTeam(), this);
}
