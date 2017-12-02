#ifndef BAZOOKABULLET_H
#define BAZOOKABULLET_H

#include "bullet.h"

class BazookaBullet : public Bullet
{
    void setRadiusDamage();
    bool isInRadius(Element *e);
    int _radius;
public:
    BazookaBullet(XY pos, XY velo, int bullet_power, int radius, Team *aggressor_team, GameManager *game);
    void hurtElements();
    void handleCollisions();
};

#endif // BAZOOKABULLET_H
