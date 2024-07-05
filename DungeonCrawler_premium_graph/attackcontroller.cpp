#include "attackcontroller.h"

AttackController::AttackController(Level *level) : level(level),moves(0)
{
}

Input_mov AttackController::move()
{
    std::pair<int, int> next_Tile;
    moves++;
    if(moves <= 2){
        return stand;
    }
    moves = 0;
    std::pair<int, int> from =getZombiePosition();
    std::pair<int, int> to =getHumanPosition();

    if(to == std::pair(-1,-1)){
        return terminate;
    }

    auto pfad = level->getPath(from, to);
    if(pfad.empty() || pfad.size() == 0){
        return terminate;
    }
    next_Tile = pfad[1]->Position;

    if(next_Tile.first == from.first-1 && next_Tile.second == from.second-1){
        return upleft;
    }
    if(next_Tile.first == from.first-1 && next_Tile.second == from.second){
        return up;
    }
    if(next_Tile.first == from.first-1 && next_Tile.second == from.second+1){
        return upright;
    }
    if(next_Tile.first == from.first && next_Tile.second == from.second-1){
        return left;
    }
    if(next_Tile.first == from.first && next_Tile.second == from.second){
        return terminate;
    }
    if(next_Tile.first == from.first && next_Tile.second == from.second+1){
        return right;
    }
    if(next_Tile.first == from.first+1 && next_Tile.second == from.second-1){
        return downleft;
    }
    if(next_Tile.first == from.first+1 && next_Tile.second == from.second){
        return down;
    }
    if(next_Tile.first == from.first+1 && next_Tile.second == from.second+1){
        return downright;
    }
    return terminate;
}

void AttackController::setTheZombie(Character *newTheZombie)
{
    theZombie = newTheZombie;
}

std::pair<int, int> AttackController::getZombiePosition()
{
    std::pair<int, int> ZombiePosition;
    ZombiePosition = theZombie->getChar_tile()->getCords();
    return ZombiePosition;
}

std::pair<int, int> AttackController::getHumanPosition()
{
    for(auto charac: level->getCharacters()){
        if(charac->isHuman()){
            return charac->getChar_tile()->getCords();
        }
    }
    return std::make_pair(-1,-1);
}
