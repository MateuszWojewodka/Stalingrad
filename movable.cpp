#include "movable.h"
#include <QDebug>
#include "gamemanager.h"

double Movable::calculateDistanceFromElement(Element *e)
{
    double d; //odleglosc miedzy elementami
    XY diff; //pomocniczy zmienna/wektor o wartosciach roznicy w x i y
    diff = _pos - e->getPos();
    d = pow( pow(diff.x, 2) + pow(diff.y, 2), 0.5 ); //pierwiastek z sumy kwadratow
    return d;
}

void Movable::basicMove()
{
    _pos += _next_step;
}

void Movable::buforService()
{
    /*
     bufor zbiera co kazda ture wartosc predkosci i jesli sie wypelni
     ustawia wartosc przesuniecia danego obiekt o jeden pixel w danym kierunku xy
     a jesli nie to ustawia po prostu zero
    */

    _bufor += _velo;

    XY return_state(0,0);

    if (abs(_bufor.x) >= 1)
    {
        if (_bufor.x > 1)
        {
            _bufor.x -= 1;
            return_state.x = 1;
        }
        if (_bufor.x < -1)
        {
            _bufor.x += 1;
            return_state.x = -1;
        }
    }
    if (abs(_bufor.y) >= 1)
    {
        if (_bufor.y > 1)
        {
            _bufor.y -= 1;
            return_state.y = 1;
        }
        if (_bufor.y < -1)
        {
            _bufor.y += 1;
            return_state.y = -1;
        }
    }
    _next_step = return_state;
}

bool Movable::isCollisionWithElement(Element *e)
{
    //wspolrzedne po hipotetycznym ruchu
    XY moved_pos = _pos + _next_step;

    XY pos_bufor = _pos;
    _pos = moved_pos;

    //sprawdza czy z perspektywy innego elementu czy ja jestem z nim w kontakcie
    bool return_state = e->isInContactWithMe(this);

    _pos = pos_bufor;
    return return_state;
}

void Movable::handleCollisions()
{
    //pomocniczy bufor zastepujacy zmienna
    XY next_step_bufor = _next_step;

    for (int i=0; i<_elements->size(); i++)
    {
        //czyli jesli nie sprawdza samego siebie, jesli element jest w grze oraz jesli jest kolizja
        if ( (*_elements)[i] != this
             && isCollisionWithElement((*_elements)[i]) )
        {
            //_next_step = XY(0,0);
            _velo *= XY(-1,-1);
            next_step_bufor *=  XY(-1,-1);
            _next_step += next_step_bufor;
        }
    }
}

void Movable::goToElement(Element *e, int distance_from_element)
{
    if ( e == NULL ) {
        setVelo(XY(0,0));
        return;
    }
    if ( calculateDistanceFromElement(e) < distance_from_element ) {
        setVelo(XY(0,0));
        return;
    }
    //okreslenie pomocniczego wektora
    XY velo_versor = e->getPos() - _pos;
    //teraz ten velo versor

    double x,y,d; //pomocnicze zmienne gdzie x, y , d to wsp i dlugosc pomocniczego wektora
    x = velo_versor.x;
    y = velo_versor.y;
    d = pow( pow(x,2) + pow(y,2) , 0.5 ); //przeciwprostokatna pierw z sumy kwadratow

    //wspolczynnik do przeciwprostokatnych wynikajacy ze wzoru
    double hypos_ratio = _velo_value / d;

    _velo = XY(x * hypos_ratio, y * hypos_ratio);
}

void Movable::pauseMoving()
{
    _velo_bufor = _velo;
    _velo = XY(0,0);
}

void Movable::resumeMoving()
{
    //zamien tylo gdy predkosc rowna jest zero bo inaczej moze to prowadzic do bledow
    if ( _velo == XY(0,0) ) _velo = _velo_bufor;
}

Movable::Movable(XY pos, XY size, int hp, XY velo, GameManager *game) : Element(pos, size, hp, game)
{
    setVelo(velo);
    _velo_value = pow( pow(_velo.x,2) + pow(_velo.y,2), 0.5 );
    _bufor = XY(0,0);
    _next_step = XY(0,0);
    _velo_bufor = XY(0,0);
    _elements = _game->getElements();
}

Movable::Movable(XY pos, XY size, int hp, double velo_value, GameManager *game) : Element(pos, size, hp, game)
{
    _velo_value = velo_value;
    setVelo( XY(0,0) );
    _bufor = XY(0,0);
    _next_step = XY(0,0);
    _velo_bufor = XY(0,0);
    _elements = _game->getElements();
}

void Movable::setVelo(XY velo)
{
    if ( abs(velo.x) > 1 ) {
        if (velo.x > 1) _velo.x = 1;
        if (velo.x < -1) _velo.x = -1;
    }
    else
        _velo.x = velo.x;
    if ( abs(velo.y) > 1 ) {
        if (velo.y > 1) _velo.y = 1;
        if (velo.y < -1) _velo.y = -1;
    }
    else
        _velo.y = velo.y;
}

void Movable::move()
{
    buforService();
    handleCollisions();
    basicMove();
}
