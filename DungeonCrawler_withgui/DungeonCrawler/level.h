#ifndef LEVEL_H
#define LEVEL_H
#include "string"
#include <vector>
#include "tile.h"

class List;

class Levelchanger;

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();
    Level(const Level& l);

    Level& operator=(const Level& l);

    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
    int getRows() const;
    int getCols() const;
    std::vector<Character *> getCharacters() const;

    std::string getLvl_string() const;

    std::vector<std::vector<Tile *> > getField() const;

    void setField(const std::vector<std::vector<Tile *> > &newField);

    void addCharacter(Character* newCharacter);
    void removeCharacter(int ind);

    void setLvl_string(const std::string &newLvl_string);

    void setRows(int newRows);

    void setCols(int newCols);

    bool operator==(Level lhs);
    bool operator!=(Level lhs);

    Levelchanger *getLevel_ch() const;
    void setLevel_ch(Levelchanger *newLevel_ch);

private:
    Levelchanger* level_ch;
    std::vector<std::vector<Tile*>> field;
    std::vector<Character *> characters;
    std::string lvl_string;
    int rows;
    int cols;
};

#endif // LEVEL_H
