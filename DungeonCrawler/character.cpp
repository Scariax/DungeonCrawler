#include "character.h"
#include "abstractui.h"

Character::Character(std::string texture):texture(texture), char_tile(nullptr), abstrUI(nullptr) {}

std::string Character::getTexture() const
{
    return texture;
}

Input Character::move()
{
    return abstrUI->move();
}

Tile *Character::getChar_tile() const
{
    return char_tile;
}

void Character::setChar_tile(Tile *newChar_tile)
{
    char_tile = newChar_tile;
}


