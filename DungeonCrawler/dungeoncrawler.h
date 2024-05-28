#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "terminalui.h"
#include "level.h"

class DungeonCrawler
{
public:
    DungeonCrawler(TerminalUI* terminal, Level* level);
    bool turn();
    ~DungeonCrawler();

private:
    TerminalUI* terminal;
    Level* level;
};

#endif // DUNGEONCRAWLER_H
