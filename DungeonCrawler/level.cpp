#include "level.h"
#include "Wall.h"
#include "Floor.h"
#include "Portal.h"

Level::Level(int row, int col, std::string lvl):Rows(row),Columns(col),level_str(lvl)
{
    int index=0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1_found=false;

    Playfield.resize(Rows);
    for (int i = 0; i < Rows; ++i) {
        Playfield.at(i).resize(Columns, nullptr);
    }

    for(int i=0;i<Rows;i++){
        for(int j=0; j<Columns; j++){
            if(level_str.at(index)=='#'){
                Playfield.at(i).at(j)= new Wall(i,j,"#");
                index++;
            }
            else if(level_str.at(index)=='.'){
                Playfield.at(i).at(j)= new Floor(i,j,".");
                index++;
            }
            else if(level_str.at(index)=='O'){
                if(portal1_found){
                    portal2 = new Portal(i,j,"O");
                    Playfield.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found=false;
                }
                else{
                    portal1 = new Portal(i,j,"O");
                    Playfield.at(i).at(j) = portal1;
                    portal1_found=true;
                }
                index++;
            }
            else if(level_str.at(index)=='X'){
                Playfield.at(i).at(j)= new Floor(i,j,".");
                index++;
                Character* new_char= new Character("X");
                Characters.push_back(new_char);
                Playfield.at(i).at(j)->setCharacter(new_char);
                new_char->setTile(Playfield.at(i).at(j));
            }
        }
    }
}

Level::~Level()
{
    for(auto& x:Playfield){
        for(auto y:x){
            delete y;
        }
    }
    Playfield.clear();

    for(auto y:Characters){
        delete y;
    }
    Characters.clear();
}

Tile *Level::getTile(int row, int col)
{
    return Playfield.at(row).at(col);
}

const Tile *Level::getTile(int row, int col) const
{
    return Playfield.at(row).at(col);
}

void Level::placeCharacter(Character *c, int row, int col)
{
    Playfield.at(row).at(col)->setCharacter(c);
}

int Level::getRows() const
{
    return Rows;
}

int Level::getColumns() const
{
    return Columns;
}
