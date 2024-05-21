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

bool Portal::onLeave(Tile *destTile, Character *who)
{
    if( destTile->getTexture()=="_" ){
        return false;
    }
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
