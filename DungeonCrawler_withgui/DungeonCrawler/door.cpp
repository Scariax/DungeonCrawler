#include "door.h"

Door::Door(int row, int col, std::string texture):Tile(row,col,texture),Passive()
{
    Open=false;
}

std::string Door::getTexture() const
{
    if(Open){
        return "\\";
    }
    else{
        return Tile::getTexture();
    }
}

bool Door::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Door::onEnter(Character *who)
{
    if(Open){
        if(this->hasCharacter()){
            Character* present_char = this->getCharacter();
            if(!who->isHuman() && !present_char->isHuman()){
                return {false, nullptr};
            }
            if(present_char->getHitpoints() - who->getStrength() <= 0){
                present_char->setAlive(false);
            }
            else{
                present_char->setHitpoints(present_char->getHitpoints() - who->getStrength());
                if(who->getHitpoints() - present_char->getStrength() <= 0){
                    who->setAlive(false);
                }
                else{
                    who->setHitpoints(who->getHitpoints() - present_char->getStrength());
                }
                return {false, nullptr};
            }
        }
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
