#include "Tile.h"

Tile::Tile(int row, int col, std::string texture):row(row),col(col),texture(texture),character(nullptr)
{

}

bool Tile::hasCharacter() const {
    if(character != nullptr){
        return true;
    }
    return false;
}

int Tile::getRow() const {
    return row;
}

int Tile::getCol() const {
    return col;
}

Character *Tile::getCharacter() const {
    return character;
}

Tile *Tile::getDestination()
{
    return nullptr;
}

void Tile::setCharacter(Character *character) {
    Tile::character = character;
}


const std::string Tile::getTexture(){
    return texture;
}

bool Tile::moveTo(Tile *destTile, Character *who) {
    if(this->onLeave(destTile,who)){
        if(destTile->onEnter(who).first){
            if(destTile->onEnter(who).second==nullptr){
                destTile->setCharacter(who);
                this->setCharacter(nullptr);
                who->setTile(destTile);
                return true;
            }
            else{
                Tile* por_dest=destTile->onEnter(who).second;
                por_dest->setCharacter(who);
                this->setCharacter(nullptr);
                who->setTile(por_dest);
                return true;
            }
        }
    }
    return false;
}

bool Tile::onLeave(Tile *destTile, Character *who) {
    return true;
}

std::pair<bool, Tile *> Tile::onEnter(Character *who) {
    return std::pair<bool, Tile *>(true, nullptr);
}



