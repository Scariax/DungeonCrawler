#ifndef ACTIVE_H
#define ACTIVE_H
#include <iostream>
#include <vector>
#include "passive.h"


class Active
{
public:
    Active();
    ~Active();

    void attach(Passive*);
    void detach(Passive*);
    void activate();

    std::vector<Passive*> getList_of_Passive() const;
private:
    std::vector<Passive*> list_of_Passive;
};

#endif // ACTIVE_H
