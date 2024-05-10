#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(TerminalUI* UI, Level* level):terminal(UI),level(level)
{
}

DungeonCrawler::~DungeonCrawler()
{
    delete terminal;
    delete level;
}

bool DungeonCrawler::turn()
{
    for(Character* character:level->Characters){
        if(character!=nullptr){
            Tile* current_tile = character->getTile();
            bool notMoved = true;
            while(notMoved){
                terminal->draw(level);
                Input input_terminal = terminal->move();

                if(input_terminal==up){
                    int dest_row = current_tile->getRow()-1;
                    int dest_col = current_tile->getCol();
                    Tile* dest_tile=level->Playfield[dest_row][dest_col];
                    if(current_tile->moveTo(dest_tile,character)){

                        notMoved=false;
                    }
                }
                else if(input_terminal==down){
                    int dest_row=(current_tile->getRow())+1;
                    int dest_col=current_tile->getCol();
                    Tile* dest_tile=level->Playfield[dest_row][dest_col];
                    if(current_tile->moveTo(dest_tile,character)){
                        notMoved=false;
                    }
                }
                else if(input_terminal==right){
                    int dest_row=current_tile->getRow();
                    int dest_col=(current_tile->getCol())+1;
                    Tile* dest_tile=level->Playfield[dest_row][dest_col];
                    if(current_tile->moveTo(dest_tile,character)){
                        notMoved=false;
                    }
                }
                else if(input_terminal==left){
                    int dest_row=current_tile->getRow();
                    int dest_col=(current_tile->getCol())-1;
                    Tile* dest_tile=level->Playfield[dest_row][dest_col];
                    if(current_tile->moveTo(dest_tile,character)){
                        notMoved=false;
                    }
                }
                else if(input_terminal==exiting){
                    return false;
                    break;
                }
            }
        }
    }
    return true;
}
