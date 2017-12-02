#ifndef PLAYER_H
#define PLAYER_H

//#include "weapon.h"
#include "bazooka.h"
#include "aggressor.h"
#include <QWidget>
#include <cmath>

class GameManager;
class Bead;

class Player :
        public QWidget,
        public Element,
        public Aggressor
{    
    //CELOWNIK
    //----------------------------------------------------
    XY _bead_pos; //celownik
    //odpowiednio kat celownika i skok kroku przy obrocie celownika
    double _bead_angle;
    double _spin_step;
    //metody pomocnicze do obracania celownikiem
    void spin(double angle);
    //----------------------------------------------------
    XY getShootDirect();

public:
    Player(XY pos, int r, XY bead_size, Team *my_team, GameManager *game);
    ~Player();
    XY setBeadPos();
    void left_spin();
    void right_spin();
    bool attack();
    void updateElement();
};

#endif // PLAYER_H
