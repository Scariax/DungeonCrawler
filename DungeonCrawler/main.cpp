#include "dungeoncrawler.h"

int main()
{
    const std::string l={
        "##########"
        "#O.......#"
        "#...<....#"
        "#..___...#"
        "#..___..X#"
        "#........#"
        "######-###"
        "#O.......#"
        "#...?....#"
        "##########"
    };

    const int rows = 10;
    const int cols = 10;

    TerminalUI* UI = new TerminalUI();
    Level* level = new Level(rows, cols, l);
    auto dungeon = new DungeonCrawler(UI, level);
    while(dungeon->turn()){}
    delete dungeon;
    return 0;
}
