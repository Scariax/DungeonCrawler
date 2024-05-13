#ifndef DUNGEONCRAWLER_TILE_H
#define DUNGEONCRAWLER_TILE_H
#include <string>
#include "Character.h"

class Character;

class Tile {
public:

    bool hasCharacter() const;
    bool moveTo(Tile* destTile, Character* who);
    bool onLeave(Tile* destTile, Character* who);
    virtual std::pair<bool, Tile*> onEnter(Character* who);

    int getRow() const;
    int getCol() const;
    Character *getCharacter() const;
    virtual Tile *getDestination();
    void setCharacter(Character *character);
    virtual const std::string getTexture() = 0;
    virtual ~Tile() = default;


protected:
    Tile(int row, int col, std::string texture);
    std::string texture;
    Character* character;
    int row;
    int col;

};


#endif //DUNGEONCRAWLER_TILE_H
