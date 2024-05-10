#ifndef DUNGEONCRAWLER_WALL_H
#define DUNGEONCRAWLER_WALL_H
#include <iostream>
#include "Tile.h"
#include <string>

class Wall : public Tile{
public:
    Wall(int row, int col, std::string texture);
    const std::string getTexture() override;

    bool onLeave(Tile *destTile, Character *who);
    std::pair<bool, Tile *> onEnter(Character *who) override;
};


#endif //DUNGEONCRAWLER_WALL_H
