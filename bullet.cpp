#include "bullet.h"
#include "gamemanager.h"

void Bullet::handleCollisions()
{
    hurtElements();
    if (_is_damage_dealed) {
        _game->deleteElement(this);
    }
}

void Bullet::hurtElements()
{
    for (int i=0; i<_elements->size(); i++)
    {
        //czyli jesli nie sprawdza samego siebie, oraz jesli jest kolizja
        if ( (*_elements)[i] != this
             && isCollisionWithElement((*_elements)[i])
             && _aggressor_team->isElementInThisTeam((*_elements)[i]) == false) {

            _is_damage_dealed = true;
            (*_elements)[i]->getHurt(_power);
        }
    }
}

Bullet::Bullet(XY pos, XY velo, int bullet_power, Team *aggressor_team, GameManager *game) :
    Movable(pos, XY(10,10), 1, velo, game)
{
    _power = bullet_power;
    _aggressor_team = aggressor_team;
    _elements = _game->getElements();

    _hp = 1;
    _is_damage_dealed = false;
}

bool Bullet::isInContactWithMe(Element *e)
{
    return false;
    //inne obiekty nie moga sie odbijac od pocisku
}

void Bullet::getHurt(int damage)
{
    //cannot be hurt
}

#include <QDebug>
void Bullet::updateElement()
{
    move();
}

