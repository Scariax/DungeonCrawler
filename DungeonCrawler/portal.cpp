#include "portal.h"

Portal::Portal(int row, int col, std::string texture) : Tile(row, col, texture), destination(nullptr)
{}

std::string Portal::getTexture() const
{
    if(hasCharacter()){
        return "X";
    }
    return Tile::getTexture();
}

bool Portal::hasCharacter() const
{
    return Tile::hasCharacter();
}

bool Portal::moveTo(Tile *destTile, Character *who)
{
    return Tile::moveTo(destTile, who);
}

bool Portal::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Portal::onEnter(Character *who)
{
    return {true, destination};
}

Portal *Portal::getDestination() const
{
    return destination;
}

void Portal::setDestination(Portal *newDestination)
{
    destination = newDestination;
}

Character *Portal::getCharacter() const
{
    return Tile::getCharacter();
}

void Portal::setCharacter(Character *newCharacter)
{
    Tile::setCharacter(newCharacter);
}
