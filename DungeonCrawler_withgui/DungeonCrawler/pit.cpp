#include "pit.h"

Pit::Pit(int row, int col, std::string texture): Tile(row, col, texture)
{

}

std::string Pit::getTexture() const
{
    return Tile::getTexture();
}

bool Pit::onLeave(Tile *destTile, Character *who)
{
    if(destTile->getTexture()=="_" || destTile->getTexture()== "<"){
        return true;
    }
    return false;
}

std::pair<bool, Tile *> Pit::onEnter(Character *who)
{
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
