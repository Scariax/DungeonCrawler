#include "mainwindow.h"
#include "startscreen.h"
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "level.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <istream>

int main(int argc, char* argv[])
{
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#.3.#"
        "#11__#...#"
        "#..SX#...#"
        "######-###"
        "#O...2...#"
        "#...?....#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O...4...#"
        "#......###"
        "#......#&#"
        "#S...###.#"
        "#....#...#"
        "######-###"
        "#O......1#"
        "#...2...?#"
        "##########"
    };

    const std::string l_2{
        "##########"
        "#O...#...#"
        "#...<#...#"
        "#..__#.3.#"
        "#11__#...#"
        "#..S.#...#"
        "######-###"
        "#O...2...#"
        "#...?...W#"
        "##########"
    };

    QApplication a(argc, argv);

    StartScreen s;
    s.show();
    a.exec();

    std::string l_tmp;
    int rows_tmp;
    int cols_tmp;
    int level_num_tmp;
    std::ifstream file("savegame.txt");
    if(!file)
    {
        std::cerr << "Unable to open file" << std::endl;
        return 0;
    }
        file >> level_num_tmp;
        file >> rows_tmp;
        file >> cols_tmp;
        file >> l_tmp;
        MainWindow w(rows_tmp, cols_tmp, l_tmp, nullptr);
        GraphicalUI* UI = new GraphicalUI(&w);
        w.getDc()->setGr_ui(UI);
        while(!file.eof())
        {
            file >> rows_tmp;
            file >> cols_tmp;
            file >> l_tmp;
            if(rows_tmp<=0 || cols_tmp<=0 || l_tmp=="")
            {
                break;
            }
            w.getDc()->push_level_back(new Level(rows_tmp, cols_tmp, l_tmp));
        }
        file.close();


        //testing for getting positions of characters (human)
        /*std::pair<int, int> tmp;
        for(auto i : w.getDc()->getCurrentLevel()->getCharacters())
        {
            if(i->isHuman())
            {
                tmp = i->getChar_tile()->getCords();
            }
        }
        std::cout << tmp.first << " " << tmp.second << std::endl;*/


        UI->draw();
        w.show();
        a.exec();
    return 0;

/*    const int rows = 10;
    const int cols = 10;

    MainWindow w(rows, cols, l, nullptr);
    GraphicalUI* UI = new GraphicalUI(&w);
    w.getDc()->setGr_ui(UI);
    w.getDc()->push_level_back(new Level(rows, cols, l_n));
    w.getDc()->push_level_back(new Level(rows, cols, l_2));

    UI->draw();

    w.show();
    a.exec();
    return 0;*/
}
