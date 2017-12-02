#ifndef BOARD_H
#define BOARD_H

#include "element.h"

class Board : public Element
{
public:
    Board(XY pos, XY size, GameManager *game);
    void updateElement();
    void getHurt(int damage);
};

#endif // BOARD_H
