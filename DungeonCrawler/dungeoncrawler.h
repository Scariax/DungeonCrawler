#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "terminalui.h"
#include "level.h"

class DungeonCrawler
{
public:
    DungeonCrawler(TerminalUI* UI, Level* level);
    ~DungeonCrawler();

    bool turn();

    TerminalUI* terminal;
    Level* level;
};

#endif // DUNGEONCRAWLER_H
