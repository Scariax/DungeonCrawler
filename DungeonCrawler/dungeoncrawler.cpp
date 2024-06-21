#include "dungeoncrawler.h"
#include "level.h"
#include <iostream>

DungeonCrawler::DungeonCrawler(TerminalUI *terminal, Level *level):terminal(terminal), level(level) {
    //Test copy constructor
    std::cout << "testing copyconstructor" << std::endl << std::endl;
    auto* tmp = new Level(2,5,"#.X_<-OO?#");
    terminal->draw(tmp);
    std::cout << "Created Tmp" << std::endl << std::endl;
    auto* currentLevel = new Level(*tmp);
    terminal->draw(currentLevel);
    std::cout << "copyconst called created new level" << std::endl << std::endl;
    delete tmp;
    std::cout << "deleted tmp" << std::endl << std::endl;
    terminal->draw(currentLevel);
    std::cout << std::endl << std::endl;

    //Test assignment
    tmp = new Level(3,5,"##XOO._<-?####X");
    terminal->draw(tmp);
    std::cout << "created new tmp value" << std::endl << std::endl;
    *currentLevel =(*tmp);
    terminal->draw(currentLevel);
    std::cout << "called assignment operator" << std::endl << std::endl;
    delete tmp;
    std::cout << "cleaned everything up" << std::endl << std::endl;
    terminal->draw(currentLevel);
    delete currentLevel;
}

DungeonCrawler::~DungeonCrawler(){
    delete terminal;
    delete level;
}

bool DungeonCrawler::turn()
{
    for(Character* character:level->getCharacters()){
        if(character!=nullptr){
            Tile* current_tile = character->getChar_tile();
            bool notMoved = true;
            while(notMoved){
                terminal->draw(level);
                Input input_terminal = terminal->move();
                int dest_row = current_tile->getRow();
                int dest_col = current_tile->getCol();

                switch(input_terminal){
                case up:
                {
                    dest_row-=1;
                    int dest_col = current_tile->getCol();
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case down:
                {
                    dest_row+=1;
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case right:
                {
                    dest_col+=1;
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case left:
                {
                    dest_col-=1;
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case terminate:
                {
                    return false;
                }
                default:
                {
                    return true;
                }
                }
            }
        }
    }
    return true;
}
