#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "level.h"
#include "list.h"

class GraphicalUI;

class DungeonCrawler : public List<Level*>
{
public:
    DungeonCrawler();
    ~DungeonCrawler();
    DungeonCrawler(Level* level);
    DungeonCrawler(int rows, int cols, std::string l);
    bool turn();
    Level* getCurrentLevel() const;
    void setGr_ui(GraphicalUI* newGr_ui);
    void levelswitch(auto character);
    void push_level_back(Level* level);
    void check_alive();
    bool isHuman_alive() const;
    bool getLootchest_found() const;

private:
    List<Level*> level_list;
    GraphicalUI* gr_ui;
    Level* current_level;
    bool lootchest_found;
    bool human_alive;
};

#endif // DUNGEONCRAWLER_H
