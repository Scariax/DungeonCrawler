#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include "tile.h"
#include "levelchanger.h"

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();
    Level(const Level& l);
    Level& operator=(const Level& l);
    Tile* getTile(int row, int col);
    void placeCharacter(Character* c, int row, int col);
    int getRows() const;
    int getCols() const;
    void setRows();
    void setCols();
    void removeCharacter(int ind);
    std::vector<Character*> getCharacters() const;
    std::string getLvl_string() const;
    std::vector<std::vector<Tile*>> getField() const;
    void setField(const std::vector<std::vector<Tile *> > &newField);
    void addCharacter(Character* newCharacter);
    void setLvl_string(const std::string &newLvl_string);
    void setCols(int newCols);
    void setRows(int newRows);
    LevelChanger *getLevel_ch();
    void setLevel_ch(LevelChanger *newLevel_ch);
    bool operator!=(Level lhs);
    void eraseAllCharacters();
    bool operator==(Level lhs);

    void setCharacters(const std::vector<Character *> &newCharacters);

    void removeCharacter(Character *c);
private:
    LevelChanger* level_ch;
    std::vector<std::vector<Tile*>> field;
    std::vector<Character*> characters;
    std::string lvl_string;
    int rows;
    int cols;
};

#endif // LEVEL_H
