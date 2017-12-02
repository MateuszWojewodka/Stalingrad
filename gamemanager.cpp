#include "gamemanager.h"
#include <algorithm>

std::vector<Element *> *GameManager::getElements()
{
    return &_elements;
}

std::vector<Team *> *GameManager::getTeams()
{
    return &_teams;
}

void GameManager::initializeTeams()
{
    Element *e;
    //RED TEAM
    red = new Team("red", 15);
    red_spawner.spawn_frequency = 100;
    red_spawner.team = red;
    //dodawanie spawn pointow
    red_spawner.spawn_points.push_back(sandbox_pos + XY(0,sandbox_size.y)
                                       - XY(added_area/4, added_area/(4)));
    red_spawner.spawn_points.push_back(sandbox_pos + XY(sandbox_size.x, sandbox_size.y)
                                       - XY(added_area/4, added_area/(4)));
    //dodawanie mozliwych jednostek
    e = new Soldier(XY(0,0), red, this);
    red->addPossibleUnit(e);



    //BLUE TEAM
    blue = new Team("blue", 50);
    blue_spawner.spawn_frequency = 20;
    blue_spawner.team = blue;
     //dodawanie spawn pointow
    blue_spawner.spawn_points.push_back(sandbox_pos + sandbox_size*XY(0.1,0) +
                                        XY(added_area/(-4),added_area/(-4)));
    blue_spawner.spawn_points.push_back(sandbox_pos + XY(sandbox_size.x/2, added_area/(-4)));
    blue_spawner.spawn_points.push_back(sandbox_pos + XY(sandbox_size.x*0.9, 0)
                                        - XY(added_area/4, added_area/(4)));
    //dodawanie mozliwych jednostek
    e = new Soldier(XY(0,0), blue, this);
    blue->addPossibleUnit(e);

    //e = new Sniper(XY(0,0), blue, this);
    //blue->addPossibleUnit(e);


    //do wektora druzyn dodaje druzyny
    _teams.push_back(red);
    _teams.push_back(blue);
}

void GameManager::addGround(XY pos, XY size)
{
    Element *e = new Ground(pos, size, this);
    _elements.push_back(e);
}

void GameManager::addBoard(XY pos, XY size)
{
    Element *e = new Board(pos, size, this);
    _elements.push_back(e);
}

void GameManager::createSandbox(XY pos, XY size)
{
    XY pos_corr = pos;
    XY size_corr = size;

    int player_radius = std::min(size.x, size.y)/5;
    XY player_center = pos_corr + XY( size_corr.x/2, size_corr.y );
    XY player_pos = player_center - XY(player_radius, player_radius);
    XY bead_size = XY(player_radius/10, player_radius/10);

    XY tower_size = XY(100,100);
    XY first_tower_pos = XY( player_pos.x - (25+tower_size.x),
                       pos_corr.y + size_corr.y - (tower_size.y + 25) );
    XY second_tower_pos = XY( player_pos.x + 2*player_radius + 25,
                             pos_corr.y + size_corr.y - (tower_size.y + 25) );

    int board_bigger_size = added_area;
    XY board_left_pos = pos_corr - XY(board_bigger_size/2, board_bigger_size/2);
    XY board_left_size = XY(1, size_corr.y + board_bigger_size);
    XY board_right_pos = pos_corr + XY(size_corr.x, 0) + XY(board_bigger_size/2,board_bigger_size/(-2));
    XY board_right_size = XY(1, size_corr.y + board_bigger_size);
    XY board_up_pos = pos_corr - XY(board_bigger_size/2, board_bigger_size/2);
    XY board_up_size = XY(size_corr.x + board_bigger_size, 1);
    XY board_down_pos = pos_corr + XY(0, size_corr.y) + XY(board_bigger_size/(-2), board_bigger_size/2);
    XY board_down_size = XY(size_corr.x + board_bigger_size, 1);

    //tworzenie krawedzi
    addBoard(board_left_pos, board_left_size); //po lewej
    addBoard(board_right_pos, board_right_size); //z prawej
    addBoard(board_up_pos, board_up_size); //z gory
    addBoard(board_down_pos, board_down_size); //z dolu
    //dodawanie podloza
    addGround(pos_corr, size_corr);
    //dodanie przeszkod
    //XY box_size = XY(100, 20);
    //XY box_pos = pos_corr + size_corr*XY(0.5,0.5) - box_size*XY(0.5,0.5);
    //addBox(box_pos * XY(0.3,1), box_size);
    //addBox(box_pos, box_size);
    //addBox(box_pos * XY(0.7,1), box_size);
    addPlayer(player_pos, player_radius, bead_size, red);
    //addTower();
    addTower( first_tower_pos, tower_size, red);
    addTower( second_tower_pos, tower_size, red);

}

void GameManager::addPlayer(XY pos, int r, XY bead_size, Team *team)
{
    Element *e = new Player(pos, r, bead_size, team, this);
    _elements.push_back(e);
    team->addElementToTeam(e);
    _player = dynamic_cast <Player *> (e);
}

void GameManager::addBox(XY pos, XY size)
{
    Element *e = new Box(pos, size, this);
    _elements.push_back(e);
}

void GameManager::addBead(XY size, Player *p)
{
    Element *e = new Bead(size, p, this);
    _elements.push_back(e);
    p->getTeam()->addElementToTeam(e);
}

void GameManager::addBullet(XY pos, XY velo, int bullet_power, Team *aggressor_team, Weapon *creator)
{
    Element *e = new Bullet(pos, velo, bullet_power, aggressor_team, this);
    _elements.push_back(e);
}

void GameManager::addBazookaBullet(XY pos, XY velo, int bullet_power, int radius, Team *aggressor_team, Weapon *creator)
{
    //Element *e = new Bullet(pos, velo, bullet_power, aggressor_team, this);
    Element *e = new BazookaBullet(pos, velo, bullet_power, radius, aggressor_team,this);
    _elements.push_back(e);
}

Element *GameManager::addSoldier(XY pos, Team *team)
{
    Element *e = new Soldier(pos, team, this);
    _elements.push_back(e);
    team->addElementToTeam(e);
    return e;
}

Element *GameManager::addTower(XY pos, XY size, Team *team)
{
    Element *e = new Tower(pos, size, team, this);
    _elements.push_back(e);
    team->addElementToTeam(e);
    return e;
}

Element *GameManager::addSniper(XY pos, Team *team)
{
    Element *e = new Sniper(pos, team, this);
    _elements.push_back(e);
    team->addElementToTeam(e);
    return e;
}

XY GameManager::getSandboxSize() const
{
    return sandbox_size;
}

XY GameManager::getSandboxPpos() const
{
    return sandbox_pos;
}

Element *GameManager::getTheSameElement(Element *e, XY pos, Team *team)
{
    Element *e_ret;
    Soldier *sol;
    Sniper *sni;

    sol = dynamic_cast <Soldier *> (e);
    if (sol) {
        return e_ret = new Soldier(pos, team, this);
    }

    sni = dynamic_cast <Sniper *> (e);
    if (sni){
        return e_ret = new Sniper(pos, team, this);
    }
}

void GameManager::spawnTheSameElement(Element *e, XY pos, Team *team)
{
    Soldier *sol;
    Sniper *sni;

    sol = dynamic_cast <Soldier *> (e);
    if (sol) {
        addSoldier(pos, team);
        return;
    }

    sni = dynamic_cast <Sniper *> (e);
    if (sni){
        addSniper(pos, team);
        return;
    }
}

void GameManager::spawnElementInArea(SpawnDetails &details)
{
    srand( time( NULL ) );
    //losowanie spawn pointa
    int num_of_spawn_points = details.spawn_points.size();  
    int draw = ( std::rand()  % num_of_spawn_points );
    XY spawn_point = details.spawn_points[draw];
    //losowanie jednostki
    int num_of_units = details.team->_possible_units.size();
    draw = ( std::rand()  % num_of_units );
    Element *e =
            getTheSameElement(details.team->_possible_units[draw], spawn_point, details.team);

    //sprawdzanie czy nie ma kolizji
    bool is_collision = false;
    for (int i=0; i<_elements.size(); i++) {
        if ( _elements[i]->isInContactWithMe(e) == true ){
            is_collision = true;
        }
    }
    if (!is_collision) {
        spawnTheSameElement(e, spawn_point, details.team);
        delete e;
    }
}


void GameManager::spawnerService(SpawnDetails &details)
{
    if ( details.team->ifCanSpawnNewElement() == false ) return;

    details.spawn_bufor++;
    if (details.spawn_bufor >= details.spawn_frequency) {
        spawnElementInArea(details);
        details.spawn_bufor = 0;
    }
}

Player *GameManager::getPlayer()
{
    return _player;
}

#include <QDebug>
void GameManager::deleteElement(Element *e)
{
    //qDebug() << "uruchomiono usuwanie" << endl;
    //usuwanie elementu z okreslonej druzyny
    for (int i=0; i<_teams.size(); i++) {
        if ( _teams[i]->isElementInThisTeam(e) ) {
            _teams[i]->deleteElement(e);
            break;
        }
    }

    std::vector <Element *>::iterator iterator;
    iterator = std::find (_elements.begin(), _elements.end(), e);

    //jesli iterator nie wyszedl poza zakres wektora i wskazuje na jakis element
    //to wyrzuc go z kontenera a nastepnie usun
    if (iterator != _elements.end()) {
        _elements.erase(iterator);
        delete e;
    }
}

GameManager::GameManager()
{
    sandbox_pos = XY(0,0);
    sandbox_size = XY(700,500);
    added_area = 200;

    initializeTeams();
    _round_break = 7; //ustawianie dlugosci przerwy miedzy turami

    createSandbox(sandbox_pos, sandbox_size);

    //timer
    QTimer *update_timer = new QTimer;
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateElements()));
    update_timer->start( _round_break );
}

void GameManager::updateElements()
{
    spawnerService(blue_spawner);
    spawnerService(red_spawner);
    for (int i=0; i<_elements.size(); i++)
    {
        _elements[i]->updateElement();
    }
}
