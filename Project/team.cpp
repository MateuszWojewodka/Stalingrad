#include "team.h"

std::vector<Element *> *Team::getTeamElements()
{
    return &_elements;
}

bool Team::isElementInThisTeam(Element *e)
{
    std::vector <Element *>::iterator iterator;
    iterator = std::find (_elements.begin(), _elements.end(), e);

    //jesli iterator nie wyszedl poza zakres wektora i wskazuje na jakis element
    //to znaczy ze on tam jest wiec wyrzuc ten element z kontenera a nastepnie usun
    if (iterator != _elements.end()) return true;
    return false;
}

bool Team::ifCanSpawnNewElement()
{
    if ( _elements.size() < _max_elements ) return true;
    return false;
}

std::string Team::getColour()
{
    return _colour;
}

void Team::addPossibleUnit(Element *e)
{
    _possible_units.push_back(e);
}

Team::Team(std::string colour,  int max_elements)
{
    _max_elements = max_elements;

    if ( colour == "red" || colour == "blue" )
        _colour = colour;
    else _colour = "red";
}

void Team::addElementToTeam(Element *e)
{
    _elements.push_back(e);
}

void Team::deleteElement(Element *e)
{
    std::vector <Element *>::iterator iterator;
    iterator = std::find (_elements.begin(), _elements.end(), e);

    //jesli iterator nie wyszedl poza zakres wektora i wskazuje na jakis element
    //to wyrzuc go z kontenera a nastepnie usun
    if (iterator != _elements.end()) {
        _elements.erase(iterator);
    }
}
