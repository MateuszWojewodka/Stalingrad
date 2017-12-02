#ifndef GROUND_H
#define GROUND_H

#include "element.h"

class Ground : public Element
{
public:
    Ground(XY pos, XY size, GameManager *game);
    void getHurt(int damage);
    bool isInContactWithMe(Element *e);
    void updateElement();
};

#endif // GROUND_H
