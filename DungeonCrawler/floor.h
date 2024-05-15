#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"

class Floor : public Tile
{
public:
    Floor(int row, int col, std::string texture);
    virtual ~Floor() = default;
    std::string getTexture() const override;
    bool moveTo(Tile* destTile, Character* who) override;
    bool hasCharacter() const override;
    bool onLeave(Tile *destTile, Character *who) override;
    std::pair<bool, Tile *> onEnter(Character *who) override;
    Character *getCharacter() const override;
    void setCharacter(Character *newCharacter) override;
};

#endif // FLOOR_H
