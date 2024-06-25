#include "active.h"

Active::Active()
{

}

void Active::attach(Passive* p)
{
    for(auto passive: list_of_Passive){
        if(passive==p){
            return;
        }
    }
    list_of_Passive.push_back(p);
}

void Active::detach(Passive* p)
{
    for(std::size_t i = 0; i < list_of_Passive.size(); i++){
        if(list_of_Passive[i] == p){
            list_of_Passive.erase(list_of_Passive.begin()+i);
        }
    }
}

void Active::activate()
{
    for(auto passive: list_of_Passive){
        passive->notify();
    }
}

std::vector<Passive*> Active::getList_of_Passive() const
{
    return list_of_Passive;
}
