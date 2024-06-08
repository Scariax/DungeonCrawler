#include "ramp.h"

Ramp::Ramp(int row, int col, std::string texture): Tile(row, col, texture)
{

}

std::string Ramp::getTexture() const
{
    return Tile::getTexture();
}

bool Ramp::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Ramp::onEnter(Character *who)
{
    return {true, nullptr};
}
