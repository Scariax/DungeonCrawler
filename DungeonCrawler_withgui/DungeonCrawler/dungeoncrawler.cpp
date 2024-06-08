#include "dungeoncrawler.h"
#include "level.h"
#include <iostream>


DungeonCrawler::DungeonCrawler()
{

}

DungeonCrawler::DungeonCrawler(Level *level):level(level){

}

DungeonCrawler::~DungeonCrawler(){
    delete level;
}

Level *DungeonCrawler::getLevel() const
{
    return level;
}

bool DungeonCrawler::turn(Input input_terminal)
{
    bool Moved = false;
    for(Character* character:level->getCharacters()){
        if(character!=nullptr){

            Tile* current_tile = character->getChar_tile();
            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            switch(input_terminal){
            case up:
            {
                dest_row-=1;
                int dest_col = current_tile->getCol();
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    Moved = true;
                }
                break;
            }
            case down:
            {
                dest_row+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    Moved = true;
                }
                break;
            }
            case right:
            {
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    Moved = true;
                }
                break;
            }
            case left:
            {
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    Moved = true;
                }
                break;
            }
            case terminate:
            {
                return false;
            }
            }
        }
    }
    return Moved;
}
