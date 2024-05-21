#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "abstractui.h"

class Tile;

class Character
{
public:
    Character(std::string texture);

    std::string getTexture() const;

    Input move();

    virtual ~Character() = default;

    Tile *getChar_tile() const;

    void setChar_tile(Tile *newChar_tile);

private:
    std::string texture;
    Tile* char_tile;
    AbstractUI* abstrUI;
};

#endif // CHARACTER_H
