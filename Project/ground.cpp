#include "ground.h"

Ground::Ground(XY pos, XY size, GameManager *game) : Element(pos, size, 1, game)
{
}

void Ground::getHurt(int damage)
{
    //nie otrzymuje obrazen
}

bool Ground::isInContactWithMe(Element *e)
{
    return false;
}

void Ground::updateElement()
{
    //nic nie rob
}
