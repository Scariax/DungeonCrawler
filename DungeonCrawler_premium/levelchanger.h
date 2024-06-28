#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "portal.h"
#include "characterset.h"

class Level;

class LevelChanger : public Portal
{
public:
    LevelChanger(int row, int col, std::string texture);
    ~LevelChanger() = default;

    std::pair<bool, Tile*> onEnter(Character* who) override;

    CharacterSet* getDestination() const;
    void setDestination(CharacterSet* newDestination);

    Level* getLevel_dest() const;
    void setLevel_dest(Level* newLevel_dest);

    QPixmap* getTex_ui() const override;

private:
    Level* level_dest;
    CharacterSet* destination;
};

#endif // LEVELCHANGER_H
