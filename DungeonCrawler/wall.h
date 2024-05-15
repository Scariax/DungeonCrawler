#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : public Tile
{
public:
    Wall(int row, int col, std::string texture);
    virtual ~Wall() = default;
    std::string getTexture() const override;
    bool hasCharacter() const override;
    bool moveTo(Tile *destTile, Character *who) override;
    bool onLeave(Tile *destTile, Character *who) override;
    std::pair<bool, Tile *> onEnter(Character *who) override;
    Character *getCharacter() const override;
    void setCharacter(Character *newCharacter) override;
};

#endif // WALL_H
