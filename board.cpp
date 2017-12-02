#include "board.h"

Board::Board(XY pos, XY size, GameManager *game) : Element(pos, size, 1, game)
{
    //_pos = pos;
    //_size = size;
}

void Board::updateElement()
{
    //nic sie nie moze zmienic
}

void Board::getHurt(int damage)
{
    //cannot be damage
}
