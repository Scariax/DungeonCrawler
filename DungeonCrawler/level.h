#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "Tile.h"
#include "Character.h"
#include <string>

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();

    Tile* getTile(int row,int col);
    const Tile* getTile(int row, int col) const;
    void placeCharacter(Character* c, int row, int col);

    int getRows() const;
    int getColumns() const;

    std::vector<std::vector<Tile*>> Playfield;
    std::vector<Character*> Characters;
    std::string level_str;
private:

    int Rows;
    int Columns;
};

#endif // LEVEL_H
