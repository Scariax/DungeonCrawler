#ifndef DUNGEONCRAWLER_PORTAL_H
#define DUNGEONCRAWLER_PORTAL_H
#include "Tile.h"

class Portal : public Tile{
private:
    Portal* destination;
public:
    Portal(int row, int col, std::string texture);
    ~Portal() = default;

    const std::string getTexture() override;
    Portal *getDestination() override;
    void setDestination(Portal *newDestination);
    bool onLeave(Tile *destTile, Character *who);
    std::pair<bool, Tile *> onEnter(Character *who) override;
};


#endif //DUNGEONCRAWLER_PORTAL_H
