#ifndef AGGRESSOR_H
#define AGGRESSOR_H

#include "team.h"
#include "weapon.h"

class Aggressor
{
    int _bufor;
    bool _buforIsOverload;
    void buforService();
    double calculateDistanceFromElement(Element *e);
protected:
    Element *_target;
    Team *_my_team;
    std::vector <Team *> *_teams;
    //zmienna okreslajaca co ile tur ma atakowac
    int _attack_frequency;
    Weapon *_weapon;
    void moveYourGunToPosition(XY pos);
    //funkjce oblugujace atak
    void findClosestTarger();
    bool isInWeaponRange(Element *e);
    //void findTargetInWeaponsRange();
    virtual XY getShootDirect();
public:
    Aggressor(int attack_frequency, Team *my_team, std::vector <Team *> *teams);
    virtual ~Aggressor();
    Team *getTeam();
    virtual bool attack();
};

#endif // AGGRESSOR_H
