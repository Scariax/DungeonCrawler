#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "abstractcontroller.h"
#include "stationerycontroller.h"
#include "guardiancontroller.h"

class Tile;

class Character
{
public:
    Character(std::string texture, int strength, int stamina, bool hum = true);

    std::string getTexture() const;
    Input_mov move();
    virtual ~Character() = default;
    Tile *getChar_tile() const;
    void setChar_tile(Tile *newChar_tile);
    void setMoveDirection(Input_mov newMoveDirection);

    Input_mov getMoveDirection() const;

    bool isHuman() const;

    int getMaxHP();
    int getStrength() const;
    void setStrength(int newStrength);
    int getStamina() const;
    void setStamina(int newStamina);
    int getHitpoints() const;
    void setHitpoints(int newHitpoints);

private:
    std::string texture;
    Tile* char_tile;
    AbstractController* abstrCon;
    Input_mov moveDirection;
    bool human;
    int strength;
    int stamina;
    int hitpoints;
};

#endif // CHARACTER_H
