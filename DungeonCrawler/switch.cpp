#include "switch.h"

Switch::Switch(int row, int col, std::string texture): Tile(row, col, texture), Active()
{}

std::string Switch::getTexture() const
{
    if(hasCharacter()){
        return "X";
    }
    return Tile::getTexture();
}

bool Switch::onLeave(Tile *destTile, Character *who)
{
    if(destTile->getTexture()=="_"){
        return false;
    }
    return true;
}

std::pair<bool, Tile *> Switch::onEnter(Character *who)
{
    this->activate();
    return {true, nullptr};
}
