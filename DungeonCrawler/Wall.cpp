#include "Wall.h"

Wall::Wall(int row, int col, std::string texture) : Tile(row, col, texture) {

}

const std::string Wall::getTexture()
{
    return "#";
}

bool Wall::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Wall::onEnter(Character *who)
{
    return std::pair<bool, Tile *>(false, nullptr);
}
