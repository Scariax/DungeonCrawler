#ifndef LEVEL_H
#define LEVEL_H
#include "string"
#include <vector>
#include "tile.h"

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();
    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    int getRows() const;
    int getCols() const;

    std::vector<Character *> getCharacters() const;

private:
    std::vector<std::vector<Tile*>> field;
    std::vector<Character *> characters;
    std::string lvl_string;
    int rows;
    int cols;
};

#endif // LEVEL_H
