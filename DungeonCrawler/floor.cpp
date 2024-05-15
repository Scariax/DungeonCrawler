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

Character *Floor::getCharacter() const
{
    return Tile::getCharacter();
}

void Floor::setCharacter(Character *newCharacter)
{
    Tile::setCharacter(newCharacter);
}

bool Floor::moveTo(Tile *destTile, Character *who)
{
    return Tile::moveTo(destTile, who);
}

bool Floor::hasCharacter() const
{
    return Tile::hasCharacter();
}
