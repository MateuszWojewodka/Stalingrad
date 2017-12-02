#ifndef TEAM_H
#define TEAM_H

#include "element.h"
#include <vector>
#include <algorithm>
#include <string>

class Team
{
    std::vector <Element *> _elements;
    std::string _colour;
    int _max_elements;
public:
    Team(std::string colour, int max_elements);
    void addElementToTeam(Element *e);
    std::vector <Element *> _possible_units;
    void addPossibleUnit(Element *e);
    void deleteElement(Element *e);
    std::vector<Element *> *getTeamElements();
    bool isElementInThisTeam( Element *e );
    bool ifCanSpawnNewElement();
    std::string getColour();
};

#endif // TEAM_H
