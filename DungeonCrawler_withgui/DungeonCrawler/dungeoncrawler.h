#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "level.h"

class DungeonCrawler
{
public:
    DungeonCrawler();
    DungeonCrawler(Level* level);
    bool turn(Input input_terminal);
    ~DungeonCrawler();

    Level *getLevel() const;

private:
    Level* level;
};

#endif // DUNGEONCRAWLER_H
