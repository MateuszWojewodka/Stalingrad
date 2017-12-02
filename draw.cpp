#include "draw.h"
#include <QDir>

QPixmap Draw::whoAreYou(Element *e)
{
    Ground *gr;
    Bullet *bu;
    Board *bo;
    Bead *be;
    Player *pl;
    Shooter *sh;
    Soldier *sol;
    Tower *tow;
    Sniper *sni;
    Box *box;

    BazookaBullet *bbu;

    bbu = dynamic_cast <BazookaBullet *> (e);
    if (bbu) return _bazooka_bullet_texture;

    //NEUTRAL ELEMENTS
    gr = dynamic_cast <Ground *> (e);
    if (gr) return _ground_texture;

    bu = dynamic_cast <Bullet *> (e);
    if (bu) return _bullet_texture;

    bo = dynamic_cast <Board *> (e);
    if (bo) return _board_texture;

    be = dynamic_cast <Bead *> (e);
    if (be) return _bead_texture;

    box = dynamic_cast <Box *> (e);
    if (box) return _box_texture;

    //NON-NEUTRAL ELEMENTS
    pl = dynamic_cast <Player *> (e);
    if (pl) {
        if (pl->getTeam()->getColour() == "red")
            return red_team.player_texture;
        else if (pl->getTeam()->getColour() == "blue")
            return  blue_team.player_texture;
        else return _soldier_texture;
    }

    sol = dynamic_cast <Soldier *> (e);
    if (sol) {
        if (sol->getTeam()->getColour() == "red")
            return red_team.soldier_texture;
        else if (sol->getTeam()->getColour() == "blue")
            return  blue_team.soldier_texture;
        else return _soldier_texture;
    }

    tow = dynamic_cast <Tower *> (e);
    if (tow) {
        if (tow->getTeam()->getColour() == "red")
            return red_team.tower_texture;
        else if (tow->getTeam()->getColour() == "blue")
            return  blue_team.tower_texture;
        else return _tower_texture;
    }

    sni = dynamic_cast <Sniper *> (e);
    if (sni) {
        if (sni->getTeam()->getColour() == "red")
            return red_team.sniper_texture;
        else if (sni->getTeam()->getColour() == "blue")
            return  blue_team.sniper_texture;
        else return _tower_texture;
    }
}

Draw::Draw()
{
    _imagesDirectory = QDir::currentPath().toStdString() + "/img/";
}

void Draw::loadPixMaps()
{
    _ground_texture = QPixmap((_imagesDirectory + "ground.png").c_str());
    _soldier_texture = QPixmap((_imagesDirectory + "soldier.png").c_str());
    _tower_texture = QPixmap((_imagesDirectory + "tower.png").c_str());
    _sniper_texture = QPixmap((_imagesDirectory + "sniper.png").c_str());
    _bullet_texture = QPixmap((_imagesDirectory + "bullet.png").c_str());
    _board_texture = QPixmap((_imagesDirectory + "board.png").c_str());
    _player_texture = QPixmap((_imagesDirectory + "player.png").c_str());
    _bead_texture = QPixmap((_imagesDirectory + "bead.png").c_str());
    _box_texture = QPixmap((_imagesDirectory + "box.png").c_str());
    _bazooka_bullet_texture = QPixmap((_imagesDirectory + "bazooka_bullet.png").c_str());
    //--------------------------------------
    //RED TEAM
    red_team.player_texture = QPixmap((_imagesDirectory + "player.png").c_str());
    red_team.soldier_texture = QPixmap((_imagesDirectory + "red_soldier.png").c_str());
    red_team.tower_texture = QPixmap((_imagesDirectory + "red_tower.png").c_str());
    red_team.sniper_texture = QPixmap((_imagesDirectory + "red_sniper.png").c_str());
    //BLUE TEAM
    blue_team.player_texture = QPixmap((_imagesDirectory + "player.png").c_str());
    blue_team.soldier_texture = QPixmap((_imagesDirectory + "blue_soldier.png").c_str());
    blue_team.tower_texture = QPixmap((_imagesDirectory + "blue_tower.png").c_str());
    blue_team.sniper_texture = QPixmap((_imagesDirectory + "blue_sniper.png").c_str());
}

void Draw::drawElements(QPainter &painter, GameManager *game)
{

    XY pos, size; //odpowiednio pomocnicze wspolrzedne i rozmiary
    std::vector <Element *> *elements = game->getElements();
    for (int i=0; i < elements->size(); i++) {
        pos = (*elements)[i]->getPos();
        size = (*elements)[i]->getSize();
        painter.drawPixmap(pos.x, pos.y, size.x, size.y, whoAreYou( (*elements)[i]) );
    }

}
