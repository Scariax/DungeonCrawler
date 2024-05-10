#include "dungeoncrawler.h"

int main() {
    const std::string level1 = {
        "###########"
        "#O........#"
        "######..###"
        "#.........#"
        "###..######"
        "#........X#"
        "###########"
        "#........O#"
        "#.........#"
        "###########"
    };

    const int rows = 10;
    const int cols = 11;

    TerminalUI* UI = new TerminalUI();
    Level* level = new Level(rows,cols,level1);


    DungeonCrawler dungeonCrawler(UI,level);

    while (dungeonCrawler.turn()) {

    }

    return 0;
}
