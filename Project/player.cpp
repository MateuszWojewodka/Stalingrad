#include "player.h"
#include <QDebug>
#include "gamemanager.h"

void Player::updateElement()
{
    if (checkIfDeathIsComming()) return;
    //uzycie funkcji z pozycja XY
    moveYourGunToPosition(_bead_pos);
}

void Player::spin(double angle)
{
    _bead_angle += angle;

    double add_x, add_y;
    add_x = (-1) * sin(_bead_angle) * _size.x/2;
    add_y = (-1) * cos(_bead_angle) * _size.y/2;

    _bead_pos = XY(_pos.x + _size.x/2 + add_x, _pos.y + _size.y/2 + add_y);
}

void Player::left_spin()
{
    //jesli kat mniejszy od 90 stopni
    if ( _bead_angle < ( 85*3.14/180 ) )
        spin( (1)  *_spin_step );
}

void Player::right_spin()
{
    //jesli kat wiekszy od 90 stopni
    if ( _bead_angle > ( -85*3.14/180 ) )
        spin( (-1)  *_spin_step );
}

XY Player::getShootDirect()
{
    XY center_of_player = _pos + ( _size * XY(0.5, 0.5) );
    XY bullet_versor = _bead_pos - center_of_player;
    return bullet_versor;
}

bool Player::attack()
{
    _weapon->shoot(getShootDirect());
    return true;
}

Player::Player(XY pos, int r, XY bead_size, Team *my_team, GameManager *game) :
    Aggressor(0, my_team, game->getTeams()),
    Element (pos, XY(2*r, 2*r), 1000, game)
{
    //celownik
    _bead_pos = XY( _pos.x + _size.x/2, _pos.y );
    _bead_angle = 0;
    _spin_step = 0.05;
    //dodawanie nowego celownika w grze
    _game->addBead(bead_size, this);
    //bron ktora bedzie uzywal gracz
    //_weapon = new Weapon(this, _bead_pos, _game);

    //zwykla bron
    _weapon = new Weapon(5, 0, this, _bead_pos, _game);

    //bazooka
    //_weapon = new Bazooka(this, _bead_pos, _game);
}

Player::~Player()
{
    delete _weapon;
}

XY Player::setBeadPos()
{
    return _bead_pos;
}
