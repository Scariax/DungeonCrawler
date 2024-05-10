#include "Floor.h"

Floor::Floor(int row, int col, std::string texture) : Tile(row, col, texture) {
}

const std::string Floor::getTexture()
{
    return ".";
}

bool Floor::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Floor::onEnter(Character *who)
{
    return std::pair<bool, Tile *>(true, nullptr);
}

