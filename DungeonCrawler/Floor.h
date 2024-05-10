#ifndef DUNGEONCRAWLER_FLOOR_H
#define DUNGEONCRAWLER_FLOOR_H
#include "Tile.h"

class Floor : public Tile{
public:
    Floor(int row, int col, std::string texture);
    const std::string getTexture() override;
    bool onLeave(Tile *destTile, Character *who);
    std::pair<bool, Tile *> onEnter(Character *who) override;
};


#endif //DUNGEONCRAWLER_FLOOR_H
