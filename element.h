#ifndef ELEMENT_H
#define ELEMENT_H

#include "xy.h"

class GameManager;

class Element
{
protected:
    XY _pos; //okresla wspolrzedne na planszy
    XY _size; //okresla rozmiar xy danego elementu

    int _hp; //punkty zycia

public:
    GameManager *_game;
    Element(XY pos, XY size, int hp, GameManager *game);
    virtual ~Element();
    virtual void updateElement() = 0;
    XY getPos();
    XY getSize();
    int getHp();
    virtual bool checkIfDeathIsComming();
    virtual void getHurt(int damage);
    virtual bool isInContactWithMe(Element *e);
};

#endif // ELEMENT_H
