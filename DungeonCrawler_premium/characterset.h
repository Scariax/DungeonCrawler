#ifndef CHARACTERSET_H
#define CHARACTERSET_H
#include "tile.h"

class CharacterSet : public Tile
{
public:
    CharacterSet(int row, int col, std::string texture);
};

#endif // CHARACTERSET_H
