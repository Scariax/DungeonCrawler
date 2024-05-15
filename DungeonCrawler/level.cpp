#include "level.h"
#include "portal.h"
#include "wall.h"
#include "floor.h"

Level::Level(int row, int col, std::string lvl):rows(row), cols(col), lvl_string(lvl) {
    int index = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1_found = false;

    field.resize(rows);
    for(int i = 0; i < rows; ++i){
        field.at(i).resize(col, nullptr);
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            switch(lvl_string.at(index)){
            case '#':
                field.at(i).at(j) = new Wall(i, j, "#");
                index++;
                break;

            case '.':
                field.at(i).at(j) = new Floor(i, j, ".");
                index++;
                break;

            case 'O':
                if(portal1_found)
                {
                    portal2 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                }
                else
                {
                    portal1 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal1;
                    portal1_found = true;
                }
                index++;
                break;

            case 'X':
                field.at(i).at(j) = new Floor(i, j, ".");
                index++;
                Character* new_char = new Character("X");
                characters.push_back(new_char);
                field.at(i).at(j)->setCharacter(new_char);
                new_char->setChar_tile(field.at(i).at(j));
                break;
            }
        }
    }
}

Level::~Level()
{
    for(auto& x:field){
        for(auto y:x){
            delete y;
        }
    }
    field.clear();

    for(auto& z:characters){
        delete z;
    }
    characters.clear();
}

Tile *Level::getTile(int row, int col)
{
    return field.at(row).at(col);
}

const Tile *Level::getTile(int row, int col) const
{
    return field.at(row).at(col);
}

void Level::placeCharacter(Character *c, int row, int col)
{
    field.at(row).at(col)->setCharacter(c);
}

int Level::getRows() const
{
    return rows;
}

int Level::getCols() const
{
    return cols;
}

std::vector<Character *> Level::getCharacters() const
{
    return characters;
}
