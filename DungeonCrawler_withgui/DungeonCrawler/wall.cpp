#include "wall.h"

Wall::Wall(int row, int col, std::string texture) : Tile(row, col, texture)
{}

std::string Wall::getTexture() const
{
    if(hasCharacter()){
        return "X";
    }
    return Tile::getTexture();
}

bool Wall::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Wall::onEnter(Character *who)
{
    return {false, nullptr};
}
