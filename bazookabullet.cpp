#include "bazookabullet.h"
#include "gamemanager.h"

void BazookaBullet::setRadiusDamage()
{
    for (int i=0; i<_elements->size(); i++)
    {
        //czyli jesli nie sprawdza samego siebie, oraz jesli jest kolizja
        if ( (*_elements)[i] != this
             && _aggressor_team->isElementInThisTeam((*_elements)[i]) == false) {


            if ( isInRadius((*_elements)[i]) ) {
                (*_elements)[i]->getHurt(_power);
            }
            //_is_damage_dealed = true;
            //(*_elements)[i]->getHurt(_power);
        }
    }
}

bool BazookaBullet::isInRadius(Element *e)
{
    double d, dx, dy;
    XY e_pos = e->getPos() - _pos;
    dx = e_pos.x;
    dy = e_pos.y;

    d = pow ( pow(dx,2) + pow(dy,2), 0.5 );

    if (d <= _radius) return true;
    return false;
}



BazookaBullet::BazookaBullet(XY pos, XY velo, int bullet_power, int radius, Team *aggressor_team, GameManager *game) :
    Bullet(pos, velo, bullet_power, aggressor_team, game)
{
    _radius = radius;
}

void BazookaBullet::hurtElements()
{
    for (int i=0; i<_elements->size(); i++)
    {
        //czyli jesli nie sprawdza samego siebie, oraz jesli jest kolizja
        if ( (*_elements)[i] != this
             && isCollisionWithElement((*_elements)[i])
             && _aggressor_team->isElementInThisTeam((*_elements)[i]) == false) {

            _is_damage_dealed = true;
            //(*_elements)[i]->getHurt(_power);
            setRadiusDamage();
            return;
        }
    }
}

void BazookaBullet::handleCollisions()
{
    hurtElements();
    if (_is_damage_dealed) {
        _game->deleteElement(this);
    }
}
