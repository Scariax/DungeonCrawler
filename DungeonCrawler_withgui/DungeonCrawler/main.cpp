#include "startscreen.h"
#include "dungeoncrawler.h"
#include "mainwindow.h"
#include "graphicalui.h"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
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

    QApplication a(argc, argv);

    StartScreen s;
    s.show();
    a.exec();

    Level* level = new Level(rows, cols, l);
    auto dungeon = new DungeonCrawler(level);

    MainWindow w(dungeon, nullptr);

    GraphicalUI* UI = new GraphicalUI(&w);
    UI->draw(level);
    w.show();
    a.exec();

    delete dungeon;
    return 0;
}
