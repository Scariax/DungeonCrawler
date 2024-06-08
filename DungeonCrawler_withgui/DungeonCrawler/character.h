#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "abstractcontroller.h"

class Tile;

class Character
{
public:
    Character(std::string texture);

    std::string getTexture() const;

    Input move(char input);

    virtual ~Character() = default;

    Tile *getChar_tile() const;

    void setChar_tile(Tile *newChar_tile);

private:
    std::string texture;
    Tile* char_tile;
    AbstractController* abstrCon;
};

#endif // CHARACTER_H
