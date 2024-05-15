#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(TerminalUI *terminal, Level *level):terminal(terminal), level(level) {

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

                switch(input_terminal){
                case up:
                {
                    int dest_row = current_tile->getRow()-1;
                    int dest_col = current_tile->getCol();
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case down:
                {
                    int dest_row = current_tile->getRow()+1;
                    int dest_col = current_tile->getCol();
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case right:
                {
                    int dest_row = current_tile->getRow();
                    int dest_col = current_tile->getCol()+1;
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case left:
                {
                    int dest_row = current_tile->getRow();
                    int dest_col = current_tile->getCol()-1;
                    Tile* dest_tile = level->getTile(dest_row, dest_col);
                    if(current_tile->moveTo(dest_tile, character)){
                        notMoved = false;
                    }
                    break;
                }
                case terminate:
                {
                    return false;
                    break;
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
