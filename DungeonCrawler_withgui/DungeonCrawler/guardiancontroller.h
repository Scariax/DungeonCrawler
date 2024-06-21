#ifndef GUARDIANCONTROLLER_H
#define GUARDIANCONTROLLER_H

#include "abstractcontroller.h"
#include <iostream>
#include <string>
#include <vector>

class GuardianController: public AbstractController
{
public:
    GuardianController();
    Input_mov move() override;

    std::string movem_str;
    std::vector<int> result;
};
#endif // GUARDIANCONTROLLER_H
