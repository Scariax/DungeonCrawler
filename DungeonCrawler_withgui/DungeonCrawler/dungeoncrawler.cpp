#include "dungeoncrawler.h"
#include "level.h"
#include "levelchanger.h"
#include <iostream>


DungeonCrawler::DungeonCrawler()
{

}

DungeonCrawler::DungeonCrawler(Level *level):level(level)
{
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):level(new Level(rows, cols, l))
{
    push_level_back(level);
}

DungeonCrawler::~DungeonCrawler(){
    delete level;
}

Level *DungeonCrawler::getLevel() const
{
    return level;
}



void DungeonCrawler::push_level_back(Level *level_n)
{
    list_of_levels.push_back(level_n);

    (list_of_levels.begin().operator *())->getLevel_ch()->setDestination(level_n->getLevel_ch());

    level_n->getLevel_ch()->setDestination((list_of_levels.begin().operator *())->getLevel_ch());

    if(list_of_levels.begin().operator *() != level_n){
        for(auto chara:list_of_levels.begin().operator *()->getCharacters()){
            if(chara->getTexture()=="X"){
                level_n->addCharacter(chara);
            }
        }
    }
}

void DungeonCrawler::setGr_ui(GraphicalUI *newGr_ui)
{
    gr_ui = newGr_ui;
}

bool DungeonCrawler::turn()
{
    bool Moved = false;
    for(Character* character:level->getCharacters()){
        if(character!=nullptr){

            Tile* current_tile = character->getChar_tile();

            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            Input_mov input_terminal;

            if(character->isHuman()){
                input_terminal = gr_ui->move();
            }
            else{
                input_terminal = character->move();
            }

            switch(input_terminal){
            case up:
            {
                dest_row-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(up);
                    Moved = true;
                }
                break;
            }
            case upleft:
            {
                dest_row-=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                break;
            }
            case upright:
            {
                dest_row-=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                break;
            }
            case down:
            {
                dest_row+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(down);
                    Moved = true;
                }
                break;
            }
            case downright:
            {
                dest_row+=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                break;
            }
            case downleft:
            {
                dest_row+=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                break;
            }
            case right:
            {
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                break;
            }
            case left:
            {
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    list_of_levels.push_back((list_of_levels.begin()).operator *());
                    list_of_levels.pop_front();
                    level = (list_of_levels.begin()).operator *();
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                break;
            }
            case terminate:
            {
                character->setMoveDirection(terminate);
                return false;
            }
            }
        }

    }
    return Moved;
}
