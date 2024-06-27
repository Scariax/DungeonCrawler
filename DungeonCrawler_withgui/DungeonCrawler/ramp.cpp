#include "ramp.h"

Ramp::Ramp(int row, int col, std::string texture): Tile(row, col, texture)
{

}

std::string Ramp::getTexture() const
{
    return Tile::getTexture();
}

bool Ramp::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Ramp::onEnter(Character *who)
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
