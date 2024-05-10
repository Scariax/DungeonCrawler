#include "Portal.h"

Portal::Portal(int row, int col, std::string texture): Tile(row, col, texture),destination(nullptr) {

}

const std::string Portal::getTexture()
{
    return this->texture;
}

Portal* Portal::getDestination() {
    return destination;
}
bool Portal::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Portal::onEnter(Character *who)
{
    return std::pair<bool, Tile *>(true, this->getDestination());
}

void Portal::setDestination(Portal *newDestination)
{
    destination = newDestination;
}
