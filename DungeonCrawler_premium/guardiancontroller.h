#ifndef GUARDIANCONTROLLER_H
#define GUARDIANCONTROLLER_H
#include "abstractcontroller.h"
#include <string>
#include <vector>

class GuardianController : public AbstractController
{
public:
    GuardianController(std::string move_str);
    Input_mov move() override;
    ~GuardianController();

private:
    std::string move_str;
    std::vector<int> results;
};

#endif // GUARDIANCONTROLLER_H
