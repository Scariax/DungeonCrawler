#include "tile.h"
#include "list.h"
Tile::Tile(int row, int col, std::string texture):portal_type(0), texture(texture), character(nullptr), row(row), col(col)
{

}

std::string Tile::getTexture() const
{
    return texture;
}

bool Tile::hasCharacter() const
{
    if(character!=nullptr){
        return true;
    }
    return false;
}

bool Tile::moveTo(Tile *destTile, Character *who)
{
    std::pair<bool, Tile*> tempEnter = destTile->onEnter(who);
    bool tempLeave = this->onLeave(destTile, who);

    if(tempLeave)
    {
        if(tempEnter.first)
        {
            if(tempEnter.second==nullptr){
                destTile->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(destTile);
                return true;
            }
            else{
                if(tempEnter.second->getTexture() == "O"){
                    Tile* por_dest = tempEnter.second;
                    por_dest->setCharacter(who);
                    this->setCharacter(nullptr);
                    who->setChar_tile(por_dest);
                    return true;
                }
                if(tempEnter.second->getTexture() == "&"){
                    Tile* por_dest = tempEnter.second;
                    por_dest->setCharacter(who);
                    this->setCharacter(nullptr);
                    who->setChar_tile(por_dest);

                    return true;
                }
            }
        }
    }
    return false;
}

bool Tile::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Tile::onEnter(Character *who)
{
    return {true,nullptr};
}

Character *Tile::getCharacter() const
{
    return character;
}

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getCol() const
{
    return col;
}

int Tile::getPortal_type() const
{
    return portal_type;
}

void Tile::setPortal_type(int newPortal_type)
{
    portal_type = newPortal_type;
}

int Tile::getFloor_tile_typ() const
{
    return floor_tile_typ;
}

void Tile::setFloor_tile_typ(int newFloor_tile_typ)
{
    floor_tile_typ = newFloor_tile_typ;
}
