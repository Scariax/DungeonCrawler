#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "abstractcontroller.h"
#include <iostream>
#include <string>
#include "level.h"
#include "character.h"

class Character;
class Level;

class AttackController : public AbstractController
{
public:
    AttackController(Level* level);
    Input_mov move() override;
    ~AttackController() =default;
    void setTheZombie(Character *newTheZombie);
    std::pair<int,int> getZombiePosition();
    std::pair<int,int> getHumanPosition();

private:
    Level* level;
    Character* theZombie;
    int moves;
};

#endif // ATTACKCONTROLLER_H
