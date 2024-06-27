#include "levelchanger.h"
#include "level.h"

LevelChanger::LevelChanger(int row, int col, std::string texture):
    Portal(row, col, texture, 1),
    level_dest(nullptr),
    destination(nullptr)
{
    setTex_ui(new QPixmap(":/textures/portal/portal3.png"));
}


std::pair<bool, Tile*> LevelChanger::onEnter(Character* who)
{
    return {true, destination};
}

LevelChanger* LevelChanger::getDestination() const
{
    return destination;
}

void LevelChanger::setDestination(LevelChanger* newDestination)
{
    destination = newDestination;
}

Level* LevelChanger::getLevel_dest() const
{
    return level_dest;
}

void LevelChanger::setLevel_dest(Level* newLevel_dest)
{
    level_dest = newLevel_dest;
}

//void LevelChanger::setTex_ui(const QPixmap &newTex_ui)
//{
//    tex_ui = newTex_ui;
//}

QPixmap* LevelChanger::getTex_ui() const
{
    return Tile::getTex_ui();
}
