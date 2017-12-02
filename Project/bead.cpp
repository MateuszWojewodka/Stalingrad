#include "bead.h"
#include "gamemanager.h"

Bead::Bead(XY size, Player *p, GameManager *game) : Element(p->setBeadPos(), size, 1, game)
{
    _size = size;
    _p = p;
}

#include <QDebug>
Bead::~Bead()
{
    qDebug() << "CELOWNIK USUNIETY BEURKU KOCHANY" << endl;
}

void Bead::updateElement()
{
    if (checkIfDeathIsComming()) return;

    _pos = _p->setBeadPos();
    _pos -= XY(_size.x/2, _size.y/2);
}

void Bead::getHurt(int damage)
{
    _p->getHurt(damage);
}

bool Bead::checkIfDeathIsComming()
{
    if ( _p->getHp() < 0 ) {
        _game->deleteElement(this);
        return true;
    }
    return false;
}
