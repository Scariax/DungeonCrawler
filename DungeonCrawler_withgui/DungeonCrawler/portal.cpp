#include "portal.h"

Portal::Portal(int row, int col, std::string texture) : Tile(row, col, texture), destination(nullptr)
{}

std::string Portal::getTexture() const
{
    return Tile::getTexture();
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

int Portal::getPortal_type() const
{
    return Tile::getPortal_type();
}

void Portal::setPortal_type(int newPortal_type)
{
    Tile::setPortal_type(newPortal_type);
}
