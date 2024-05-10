#include "Character.h"


const std::string &Character::getTexture() const {
    return texture;
}

Character::Character(std::string texture) : texture(texture)
{
}

void Character::setTile(Tile *tile) {
    Character::tile = tile;
}

Tile *Character::getTile() const
{
    return tile;
}
