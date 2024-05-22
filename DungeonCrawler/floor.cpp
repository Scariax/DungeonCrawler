#include "floor.h"

Floor::Floor(int row, int col, std::string texture): Tile(row, col, texture)
{}

std::string Floor::getTexture() const
{
    if(hasCharacter()){
        return "X";
    }
    return Tile::getTexture();
}

bool Floor::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Floor::onEnter(Character *who)
{
    return {true, nullptr};
}
