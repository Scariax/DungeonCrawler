#include "dungeoncrawler.h"
#include "graphicalui.h"

DungeonCrawler::DungeonCrawler() {}

DungeonCrawler::DungeonCrawler(Level* level):
    current_level(level)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):
    current_level(new Level(rows, cols, l))
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(current_level);
}

DungeonCrawler::~DungeonCrawler()
{
        delete gr_ui;
        gr_ui = nullptr;
        //delete current_level;
        current_level = nullptr;

        // Properly delete all levels in the list
        //while (!level_list.is_empty())
        //{
        //    level_list.pop_front();
        //}

        // Ensure current_level is not double-deleted
}

void DungeonCrawler::setGr_ui(GraphicalUI* newGr_ui)
{
    gr_ui = newGr_ui;
}

void DungeonCrawler::push_level_back(Level *level_n)
{
    level_list.push_back(level_n);

    (level_list.begin().operator *())->getLevel_ch()->setDestination(level_n->getLevel_ch());
    (level_list.begin().operator *())->getLevel_ch()->setLevel_dest(level_n);

    level_n->getLevel_ch()->setDestination((level_list.begin().operator *())->getLevel_ch());
    level_n->getLevel_ch()->setLevel_dest((level_list.begin().operator *()));

    if(level_list.begin().operator *() != level_n){
        for(auto chara:level_list.begin().operator *()->getCharacters()){
            if(chara->getTexture()=="X"){
                level_n->addCharacter(chara);
            }
        }
    }
}

void DungeonCrawler::check_alive()
{
    int ind = 0;
    for(auto charac : current_level->getCharacters())
    {
        if(!(charac->getAlive()))
        {
            if(charac->isHuman())
            {
                human_alive = false;
            }
            charac->getChar_tile()->setCharacter(nullptr);
            current_level->removeCharacter(ind);
        }
        ind++;
    }
}

bool DungeonCrawler::isHuman_alive() const
{
    return human_alive;
}

bool DungeonCrawler::getLootchest_found() const
{
    return lootchest_found;
}

bool DungeonCrawler::turn()
{
    bool stop = false;
    bool Moved = false;
    for(Character* character:current_level->getCharacters())
    {
        if(stop)
        {
            break;
        }
        if(character!=nullptr)
        {
            Tile* current_tile = character->getChar_tile();

            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            Input_mov input_terminal;

            if(character->isHuman())
            {
                input_terminal = gr_ui->move();
            }
            else
            {
                input_terminal = character->move();
            }

            switch(input_terminal)
            {
                case up:
                {
                    dest_row-=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(up);
                        Moved = true;
                    }
                    break;
                }
                case upleft:
                {
                    dest_row-=1;
                    dest_col-=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(left);
                        Moved = true;
                    }
                    break;
                }
                case upright:
                {
                    dest_row-=1;
                    dest_col+=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(right);
                        Moved = true;
                    }
                    break;
                }
                case down:
                {
                    dest_row+=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(down);
                        Moved = true;
                    }
                    break;
                }
                case downright:
                {
                    dest_row+=1;
                    dest_col+=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(right);
                        Moved = true;
                    }
                    break;
                }
                case downleft:
                {
                    dest_row+=1;
                    dest_col-=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(left);
                        Moved = true;
                    }
                    break;
                }
                case right:
                {
                    dest_col+=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(right);
                        Moved = true;
                    }
                    break;
                }
                case left:
                {
                    dest_col-=1;
                    Tile* dest_tile = current_level->getTile(dest_row, dest_col);
                    if(dest_tile->getTexture()=="&")
                    {
                        current_level = current_level->getLevel_ch()->getLevel_dest();
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(current_tile->moveTo(dest_tile, character))
                    {
                        character->setMoveDirection(left);
                        Moved = true;
                    }
                    break;
                }
                case terminate:
                {
                    character->setMoveDirection(terminate);
                    return false;
                    break;
                }
                case stand:
                {
                    character->setMoveDirection(character->getMoveDirection());
                    Moved = true;
                    break;
                }
            }
        }
    }
    check_alive();
    return Moved;
}

Level *DungeonCrawler::getCurrentLevel() const
{
    return current_level;
}

void DungeonCrawler::levelswitch(auto character) //DO NOT USE WILL BREAK //WILL BE MAYBE REMOVED //STAY AWAY //DO NOT TOUCH
{
    //check if makes more sence to pushback currentlevel to save the 'state'
    level_list.push_back((level_list.begin()).operator *());
    level_list.pop_front();
    current_level = (level_list.begin()).operator *();
    /*current_level = current_level->getLevel_ch()->getLevel_dest();
    current_level->addCharacter(character);*/
}
