#ifndef DRAW_H
#define DRAW_H

#include <QBitmap>
#include <QPainter>
#include "gamemanager.h"

struct TeamPixMaps{
    QPixmap player_texture;
    QPixmap soldier_texture;
    QPixmap tower_texture;
    QPixmap sniper_texture;
};

class Draw
{
    std::string _imagesDirectory;
    QPixmap whoAreYou(Element *e);
public:   
    TeamPixMaps red_team;
    TeamPixMaps blue_team;
    //-----------------------------------
    QPixmap _ground_texture;
    QPixmap _soldier_texture;
    QPixmap _tower_texture;
    QPixmap _sniper_texture;
    QPixmap _bullet_texture;
    QPixmap _board_texture;
    QPixmap _player_texture;
    QPixmap _bead_texture;
    QPixmap _box_texture;
    QPixmap _bazooka_bullet_texture;
    //-----------------------------------
    Draw();
    void loadPixMaps();
    void drawElements(QPainter &painter, GameManager *game);
};

#endif // DRAW_H
