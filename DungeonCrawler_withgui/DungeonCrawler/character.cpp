#include "character.h"
#include "stationerycontroller.h"
#include "guardiancontroller.h"
#include "tile.h"

Character::Character(std::string texture, int strength, int stamina, bool hum):texture(texture), char_tile(nullptr), moveDirection(down), human(hum), strength(strength), stamina(stamina),hitpoints(getMaxHP()),alive(true) {
    if(!human){
        if(texture == "1"){
            abstrCon = new StationeryController();
        }
        if(texture == "2"){
            abstrCon = new GuardianController();
        }
    }
}

Character::~Character(){

}

std::string Character::getTexture() const
{
    return texture;
}

Input_mov Character::move()
{
    return abstrCon->move();
}

Tile *Character::getChar_tile() const
{
    return char_tile;
}

void Character::setChar_tile(Tile *newChar_tile)
{
    char_tile = newChar_tile;
}

void Character::setMoveDirection(Input_mov newMoveDirection)
{
    moveDirection = newMoveDirection;
}

Input_mov Character::getMoveDirection() const
{
    return moveDirection;
}

bool Character::isHuman() const
{
    return human;
}

int Character::getMaxHP()
{
    return 20+(this->stamina*5);
}

int Character::getStrength() const
{
    return strength;
}

void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

int Character::getStamina() const
{
    return stamina;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}

void Character::setAlive(bool newAlive)
{
    alive = newAlive;
}

bool Character::isAlive() const
{
    return alive;
}
