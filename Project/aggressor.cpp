#include "aggressor.h"

void Aggressor::buforService()
{
    if (_bufor < _attack_frequency) {
        _buforIsOverload = false;
        _bufor++;
    }
    else {
        _buforIsOverload = true;
        _bufor = 0;
    }
}

void Aggressor::findClosestTarger()
{
    _target = NULL;
    //zmienna pomocnicza do znalezienia minimalnej odleglosci
    double min = -1;
    std::vector <Element *> *elements;
    for ( int i=0; i < _teams->size(); i++ ) {
        //jezeli rozpatruje te sama druzyne to pomin ja
        if ( (*_teams)[i] == _my_team ) continue;
        //teraz rozpatrujemy elementy innej, wrogiej druzyny
        elements = (*_teams)[i]->getTeamElements();
        for ( int j=0; j < elements->size(); j++ ) {
            //jesli min jest ujemne, czyli jeszcze nigdy nie bylo ustawiane
            if ( min < 0 ) {
                min = calculateDistanceFromElement( (*elements)[j] );
                _target = (*elements)[j];
            }
            //w przeciwnym razie sprawdz czy dany element jest blizej jesli tak to go przypisz
            else {
                if ( calculateDistanceFromElement( (*elements)[j] ) < min ) {
                    min = calculateDistanceFromElement( (*elements)[j] );
                    _target = (*elements)[j];
                }
            }
        }
    }
}

bool Aggressor::isInWeaponRange(Element *e)
{
    //jesli obiekt jest pusty to wyrzuc falsz
    if ( e == NULL ) return false;
    //jesli istnieje to oblicz odleglosc
    if ( calculateDistanceFromElement(e) <= _weapon->getWeaponRange() )
        return true;
    return false;
}

double Aggressor::calculateDistanceFromElement(Element *e)
{
    double d; //odleglosc miedzy elementami
    XY diff; //pomocniczy zmienna/wektor o wartosciach roznicy w x i y
    diff = _weapon->_pos - e->getPos();
    d = pow( pow(diff.x, 2) + pow(diff.y, 2), 0.5 ); //pierwiastek z sumy kwadratow
    return d;
}

void Aggressor::moveYourGunToPosition(XY pos)
{
    _weapon->_pos = pos;
}

XY Aggressor::getShootDirect()
{
    XY start_pos = _weapon->_pos;
    XY bullet_versor = _target->getPos() + _target->getSize() * XY(0.5,0.5) - start_pos;
    return bullet_versor;
}

Team *Aggressor::getTeam()
{
    return _my_team;
}

Aggressor::Aggressor(int attack_frequency, Team *my_team, std::vector<Team *> *teams)
{
    _target = NULL;
    _my_team = my_team;
    _teams = teams;
    _attack_frequency = attack_frequency;
    _buforIsOverload = false;
    _bufor = 0;
}

Aggressor::~Aggressor()
{
}

bool Aggressor::attack()
{
    buforService();
    if (_buforIsOverload) {
        findClosestTarger();
        if (isInWeaponRange(_target))
            _weapon->shoot(getShootDirect());
        }
    return false;
    }
