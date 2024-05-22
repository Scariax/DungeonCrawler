#include "door.h"

Door::Door(int row, int col, std::string texture):Tile(row,col,texture),Passive()
{
    Open=false;
}

std::string Door::getTexture() const
{
    if(hasCharacter()){
        return "X";
    }
    else if(Open){
        return "\\";
    }
    else{
        return Tile::getTexture();
    }
}

bool Door::onLeave(Tile *destTile, Character *who)
{
    if(destTile->getTexture()=="_"){
        return false;
    }
    return true;
}

std::pair<bool, Tile *> Door::onEnter(Character *who)
{
    if(Open){
        return {true, nullptr};
    }
    return {false, nullptr};
}

void Door::notify()
{
    Open = !(Open);
}

bool Door::getOpen() const
{
    return Open;
}
