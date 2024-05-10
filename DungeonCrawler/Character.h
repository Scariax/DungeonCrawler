#ifndef DUNGEONCRAWLER_CHARACTER_H
#define DUNGEONCRAWLER_CHARACTER_H

#include <string>

class Tile;

class Character {
public:
    Character(std::string texture);
    const std::string &getTexture() const;
    void setTile(Tile *tile);
    Tile *getTile() const;

private:
    std::string texture;
    Tile* tile;
};


#endif //DUNGEONCRAWLER_CHARACTER_H
