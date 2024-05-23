#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"

class Tile
{
protected:
    Tile(int row, int col, std::string texture);

public:
    virtual ~Tile() = default;
    virtual std::string getTexture() const;
    virtual bool hasCharacter() const;
    virtual bool moveTo(Tile* destTile, Character* who);
    virtual bool onLeave(Tile* destTile, Character* who);
    virtual std::pair<bool, Tile*> onEnter(Character* who);
    virtual Character *getCharacter() const;
    virtual void setCharacter(Character *newCharacter);

    int getRow() const;

    int getCol() const;

private:
    std::string texture;
    Character* character;
    const int row;
    const int col;
};

#endif // TILE_H
