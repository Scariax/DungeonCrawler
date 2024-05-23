#include "level.h"
#include "portal.h"
#include "wall.h"
#include "floor.h"
#include "switch.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"

Level::Level(int row, int col, std::string lvl):rows(row), cols(col), lvl_string(lvl) {
    int index = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;

    Door* door1;
    Switch* switch1;

    bool portal1_found = false;
    bool door1_found = false;
    bool switch1_found = false;

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

            case '?':
                switch1 = new Switch(i, j, "?");
                field.at(i).at(j) = switch1;
                index++;
                switch1_found = true;
                break;

            case '-':
                door1 = new Door(i, j, "-");
                field.at(i).at(j) = door1;
                door1_found = true;
                index++;
                break;

            case '_':
                field.at(i).at(j) = new Pit(i, j, "_");
                index++;
                break;

            case '<':
                field.at(i).at(j) = new Ramp(i, j, "<");
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
    if(door1_found && switch1_found){
        switch1->attach(door1);
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

Level::Level(const Level &l):rows(l.getRows()), cols(l.getCols()), lvl_string(l.getLvl_string())
{
    int index = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;

    Door* door1;
    Switch* switch1;

    bool portal1_found = false;
    bool door1_found = false;
    bool switch1_found = false;

    field.resize(rows);
    for(int i = 0; i < rows; ++i){
        field.at(i).resize(cols, nullptr);
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

            case '?':
                switch1 = new Switch(i, j, "?");
                field.at(i).at(j) = switch1;
                index++;
                switch1_found = true;
                break;

            case '-':
                door1 = new Door(i, j, "-");
                field.at(i).at(j) = door1;
                door1_found = true;
                index++;
                break;

            case '_':
                field.at(i).at(j) = new Pit(i, j, "_");
                index++;
                break;

            case '<':
                field.at(i).at(j) = new Ramp(i, j, "<");
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
    if(door1_found && switch1_found){
        switch1->attach(door1);
    }
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

std::string Level::getLvl_string() const
{
    return lvl_string;
}
