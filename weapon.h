#ifndef WEAPON_H
#define WEAPON_H

#include "xy.h"
class GameManager;
class Aggressor;

class Weapon
{
protected:
    Aggressor *_owner;
    int _weapon_range;
    int _weapon_power;
    double _bullets_velo; //to jest ta przeciwprostokatna predkosci tych w xy
    GameManager *_game;
public:
    //Weapon(Aggressor *owner, XY owner_pos, GameManager *game);
    Weapon(int weapon_power, int weapon_range, Aggressor *owner, XY owner_pos, GameManager *game);
    virtual ~Weapon();
    int getWeaponRange();
    virtual void shoot(XY velo_versor);
    XY _pos;
};

#endif // WEAPON_H
