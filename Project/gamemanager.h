

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "team.h"
#include "shooter.h"
#include "soldier.h"
#include "tower.h"
#include "box.h"
#include "sniper.h"
#include "pistol.h"
#include "bullet.h"
#include "board.h"
#include "player.h"
#include "bead.h"
#include "ground.h"
#include <QDialog>
#include <QTimer>
#include <string>

#include "bazookabullet.h"

struct SpawnDetails{
    int spawn_frequency;
    int spawn_bufor = 0;
    std::vector <XY> spawn_points;
    Team *team;
};

class GameManager : public QDialog
{
    Q_OBJECT

    //druzyny graczy
    Team *red;
    SpawnDetails red_spawner;

    Team *blue;
    SpawnDetails blue_spawner;

    std::vector <Team *> _teams;
    void initializeTeams();

    std::vector <Element *> _elements;

    //dlugosc przerw miedzy turami
    double _round_break;

    //elementy nieruchome
    void addGround(XY pos, XY size);
    void addBoard(XY pos, XY size);
    void createSandbox(XY pos, XY size);
    void addPlayer(XY pos, int r, XY bead_size, Team *team);
    void addBox(XY pos, XY size);

    Element* addSoldier(XY pos, Team *team);
    Element* addTower(XY pos, XY size, Team *team);
    Element* addSniper(XY pos, Team *team);

    XY sandbox_pos;
    XY sandbox_size;
    int added_area;

    Element* getTheSameElement(Element *e, XY pos, Team *team);
    void spawnTheSameElement(Element *e, XY pos, Team *team);
    void spawnElementInArea(SpawnDetails &details);
    void spawnerService(SpawnDetails &details);

    Player *_player;

public:
    GameManager();
    std::vector<Element *> *getElements();
    std::vector<Team *> *getTeams();

    void addBead(XY size, Player *p);
    void addBullet(XY pos, XY velo, int bullet_power, Team *aggressor_team, Weapon *creator);

    void addBazookaBullet(XY pos, XY velo, int bullet_power, int radius, Team *aggressor_team, Weapon *creator);

    void deleteElement( Element *e );

    Player *getPlayer();

    XY getSandboxPpos() const;

    XY getSandboxSize() const;

public slots:
    void updateElements();
};

#endif // GAMEMANAGER_H
