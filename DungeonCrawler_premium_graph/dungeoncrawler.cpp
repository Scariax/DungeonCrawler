#include "dungeoncrawler.h"
#include "graphicalui.h"
#include <fstream>
#include <iostream>
#include <istream>

DungeonCrawler::DungeonCrawler() {}

DungeonCrawler::DungeonCrawler(Level* level):
    current_level(level),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):
    current_level(new Level(rows, cols, l)),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(current_level);
}

DungeonCrawler::~DungeonCrawler()
{
    saveGame();
    delete gr_ui;
    gr_ui = nullptr;
    //delete current_level;
    current_level = nullptr;
}

void DungeonCrawler::setGr_ui(GraphicalUI* newGr_ui)
{
    gr_ui = newGr_ui;
}

void DungeonCrawler::push_level_back(Level *level_n)
{
    level_list.push_back(level_n);
    if(level_list.second_to_last() == nullptr)
    {
        (level_list.begin().operator *())->getLevel_ch()->setDestination(level_n->getChar_set());
        (level_list.begin().operator *())->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination((level_list.begin().operator *())->getChar_set());
            level_n->getLevel_ch()->setLevel_dest((level_list.begin().operator *()));
        }
    }
    else
    {
        level_list.second_to_last()->getLevel_ch()->setDestination(level_n->getChar_set());
        level_list.second_to_last()->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination(level_list.begin().operator *()->getChar_set());
            level_n->getLevel_ch()->setLevel_dest(level_list.begin().operator *());
        }
    }

    if(level_list.begin().operator *() != level_n){
        for(auto chara:level_list.begin().operator *()->getCharacters()){
            if(chara->isHuman()){
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

void DungeonCrawler::loadGame()
{
    std::ifstream file("savegame.txt");
    if(!file)
    {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    if(file.is_open())
    {
        file >> level_num;
        current_level = level_list.begin().operator *();
        for(int i = 0; i < level_num; i++)
        {
            auto tmp = current_level->getLevel_ch()->getDestination();
            for(auto chara : current_level->getCharacters())
            {
                if(chara->isHuman())
                {
                    current_level = current_level->getLevel_ch()->getLevel_dest();
                    tmp->setCharacter(chara);
                    chara->setChar_tile(tmp);
                }
            }
        }
    }
    file.close();
}

void DungeonCrawler::saveGame()
{
    std::remove("savegame.txt");
    std::ofstream file("savegame.txt");
    //std::ifstream file;
    //file.open("savegame.txt");
    if(!file)
    {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    if(file.is_open())
    {
        file << this->getLevel_num() << std::endl;
        for(auto level : level_list)
        {
            file << level->getRows() << std::endl;
            file << level->getCols() << std::endl;
            file << level->getLvl_string() << std::endl;
        }
        file << -1;
    }
    file.close();
}

int DungeonCrawler::getLevel_num() const
{
    return level_num;
}

void DungeonCrawler::setLevel_num(int newLevel_num)
{
    level_num = newLevel_num;
}

bool DungeonCrawler::turn()
{
    bool stop = false;
    bool Moved = false;

    for(Character* character:current_level->getCharacters())
    {
        bool dooropended = false;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
                        level_num++;
                        stop = true;
                    }
                    if(dest_tile->getTexture()=="W")
                    {
                        lootchest_found = true;
                    }
                    if(dest_tile->getTexture()=="?")
                    {
                        dooropended = true;
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
        if(dooropended){
            current_level->updateGraph();
        }
    }
    check_alive();
    return Moved;
}

Level *DungeonCrawler::getCurrentLevel() const
{
    return current_level;
}
