#include "levelchanger.h"
#include "level.h"

Levelchanger::Levelchanger(int row, int col, std::string texture):Portal(row, col, texture)
{
//    const std::string l_n{
//        "##########"
//        "#O.......#"
//        "#...<....#"
//        "#..___...#"
//        "#..___..X#"
//        "#........#"
//        "######-###"
//        "#O.....&.#"
//        "#...?....#"
//        "##########"
//    };
    //    this->level_dest = new Level(10,10,l_n);
}

std::pair<bool, Tile *> Levelchanger::onEnter(Character *who)
{
    return {true, destination};
}

Levelchanger *Levelchanger::getDestination() const
{
    return destination;
}

void Levelchanger::setDestination(Levelchanger *newDestination)
{
    destination = newDestination;
}

Level *Levelchanger::getLevel_dest() const
{
    return level_dest;
}

void Levelchanger::setLevel_dest(Level *newLevel_dest)
{
    level_dest = newLevel_dest;
}
