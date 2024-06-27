#include "mainwindow.h"
#include "startscreen.h"
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "level.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#.3.#"
        "#11__#...#"
        "#...X#...#"
        "######-###"
        "#O...2...#"
        "#...?....#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O..3...1#"
        "#...<..###"
        "#..___.#W#"
        "#&...###.#"
        "#....#...#"
        "######-###"
        "#O......1#"
        "#...2...?#"
        "##########"
    };

    const int rows = 10;
    const int cols = 10;

    QApplication a(argc, argv);

    StartScreen s;
    s.showFullScreen();
    a.exec();

    MainWindow w(rows, cols, l, nullptr);
    GraphicalUI* UI = new GraphicalUI(&w);
    w.getDc()->setGr_ui(UI);
    w.getDc()->push_level_back(new Level(rows, cols, l_n));

    UI->draw();

    w.showFullScreen();
    a.exec();

    return 0;
}
