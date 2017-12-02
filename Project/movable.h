#ifndef MOVABLE_H
#define MOVABLE_H

#include <vector>
#include "board.h"
#include "player.h"
#include <cmath>

class Movable : public Element
{
    //bufor zwiekszajacy swoja wartosc z kazda tura
    XY _bufor;
    //musi byc prywatna zeby nikt jej zle nie ustawil bo moze byc maxymalnie jedynka
    XY _velo;
    XY _velo_bufor;
    double calculateDistanceFromElement(Element *e);
protected:
    double _velo_value;
    void basicMove();
    //zmienna do przechowywania nastepnego ruchu w turze z bufor service
    XY _next_step;
    void buforService();
    //sprawdza czy jest nieoczywista kolizja z pojedynczym elementem
    virtual void handleCollisions();
    std::vector <Element *> *_elements;
    void goToElement(Element *e, int distance_from_element);
    void pauseMoving();
    void resumeMoving();
    void setVelo(XY velo);
public:
    Movable(XY pos, XY size, int hp, XY velo, GameManager *game);
    Movable(XY pos, XY size, int hp, double velo_value, GameManager *game);
    //czy jest kolizja prosta czyli taka oczywista
    bool isCollisionWithElement(Element *e);
    void move();
};

#endif // MOVABLE_H
