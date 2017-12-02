#ifndef BEAD_H
#define BEAD_H

#include "player.h"

class Player;

class Bead : public Element
{
    Player *_p;
public:
    Bead(XY size, Player *p, GameManager *game);
    ~Bead();
    void updateElement();
    void getHurt(int damage);
    bool checkIfDeathIsComming();
};

#endif // BEAD_H
