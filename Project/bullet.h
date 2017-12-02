#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include "movable.h"

class Bullet : public Movable
{
protected:
    Team *_aggressor_team;
    bool _is_damage_dealed;
    int _power;
public:
    virtual void hurtElements();
    Bullet(XY pos, XY velo, int bullet_power, Team *aggressor_team, GameManager *game);
    //przeladowywane funkcje
    bool isInContactWithMe(Element *e);
    void getHurt(int damage);
    void handleCollisions();
    void updateElement();
};

#endif // BULLET_H
