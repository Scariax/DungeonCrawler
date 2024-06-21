#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "level.h"
#include "list.h"
#include "graphicalui.h"

class GraphicalUI;

class DungeonCrawler
{
public:
    DungeonCrawler();
    DungeonCrawler(Level* level);
    DungeonCrawler(int rows, int cols, std::string l);
    bool turn();
    ~DungeonCrawler();

    Level *getLevel() const;
    void push_level_back(Level* level);


    void setGr_ui(GraphicalUI *newGr_ui);

private:
    Level* level;
    List list_of_levels;
    GraphicalUI* gr_ui;

};

#endif // DUNGEONCRAWLER_H
