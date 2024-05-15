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

bool Wall::hasCharacter() const
{
    return Tile::hasCharacter();
}

bool Wall::moveTo(Tile *destTile, Character *who)
{
    return Tile::moveTo(destTile, who);
}

bool Wall::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Wall::onEnter(Character *who)
{
    return {false, nullptr};
}

Character *Wall::getCharacter() const
{
    return Tile::getCharacter();
}

void Wall::setCharacter(Character *newCharacter)
{
    Tile::setCharacter(newCharacter);
}
