#ifndef BOX_H
#define BOX_H

#include "element.h"

class Box : public Element
{
public:
    Box(XY pos,  XY size, GameManager *game);
    void getHurt(int damage);
    void updateElement();
};

#endif // BOX_H
