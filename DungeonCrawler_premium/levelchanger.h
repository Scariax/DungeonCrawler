#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "portal.h"

class Level;

class LevelChanger : public Portal
{
public:
    LevelChanger(int row, int col, std::string texture);
    ~LevelChanger() = default;

    std::pair<bool, Tile*> onEnter(Character* who) override;

    LevelChanger* getDestination() const;
    void setDestination(LevelChanger* newDestination);

    Level* getLevel_dest() const;
    void setLevel_dest(Level* newLevel_dest);

    //void setTex_ui(const QPixmap &newTex_ui);

    QPixmap* getTex_ui() const override;

private:
    Level* level_dest;
    LevelChanger* destination;
};

#endif // LEVELCHANGER_H
