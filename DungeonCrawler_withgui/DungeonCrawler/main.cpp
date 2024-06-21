#include "startscreen.h"
#include "dungeoncrawler.h"
#include "mainwindow.h"
#include "graphicalui.h"
#include "level.h"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#...#"
        "#..__#...#"
        "#...X#...#"
        "######-###"
        "#O...2...#"
        "#...?....#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O.......#"
        "#...<..###"
        "#..___.#<#"
        "#&...###.#"
        "#....#...#"
        "######-###"
        "#O..2....#"
        "#.......?#"
        "##########"
    };

    const int rows = 10;
    const int cols = 10;

    QApplication a(argc, argv);

    StartScreen s;
    s.showFullScreen();
    a.exec();


    auto dungeon = new DungeonCrawler(rows, cols, l);

    Level* level_n = new Level(rows, cols, l_n);

    dungeon->push_level_back(level_n);

    MainWindow w(dungeon, nullptr);

    GraphicalUI* UI = new GraphicalUI(&w);

    dungeon->setGr_ui(UI);

    UI->draw();

    w.showFullScreen();
    a.exec();

    delete dungeon;
    delete UI;
    return 0;
}
