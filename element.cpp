#include "element.h"
#include "gamemanager.h"

XY Element::getPos()
{
    return _pos;
}

XY Element::getSize()
{
    return _size;
}

int Element::getHp()
{
    return _hp;
}

bool Element::checkIfDeathIsComming()
{
    if ( _hp < 0 ) {
        _game->deleteElement(this);
        return true;
    }
    return false;
}

void Element::getHurt(int damage)
{
    _hp -= damage;
}

bool Element::isInContactWithMe(Element *e)
{

    XY start_bounds = _pos - e->getSize();
    XY end_bounds = _pos + _size;
    if ( e->getPos().x >= start_bounds.x && e->getPos().x <= end_bounds.x
         &&
         e->getPos().y >= start_bounds.y && e->getPos().y <= end_bounds.y )
        return true;

    return false;
}

Element::Element(XY pos, XY size, int hp, GameManager *game)
{
    _game = game;
    _pos = pos;
    _size = size;
    _hp = hp;
}

Element::~Element()
{
}
