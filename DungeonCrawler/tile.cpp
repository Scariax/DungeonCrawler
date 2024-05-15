#include "tile.h"

Tile::Tile(int row, int col, std::string texture):texture(texture), row(row), col(col), character(nullptr)
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
    if(this->onLeave(destTile, who))
    {
        if(destTile->onEnter(who).first)
        {
            if(destTile->onEnter(who).second==nullptr)
            {
                destTile->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(destTile);
                return true;
            }
            else
            {
                Tile* por_dest = destTile->onEnter(who).second;
                por_dest->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(por_dest);
                return true;
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
