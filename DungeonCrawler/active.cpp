#include "active.h"

Active::Active()
{

}

Active::~Active()
{
    for(auto x:list_of_Passive){
        delete x;
    }
}

void Active::attach(Passive* p)
{
    bool p_found=false;
    for(auto passive: list_of_Passive){
        if(passive==p){
            p_found=true;
            break;
        }
    }
    if(!p_found){
        list_of_Passive.push_back(p);
    }
}

void Active::detach(Passive* p)
{
    std::vector<Passive*> new_list;
    for(auto passive: list_of_Passive){
        if(passive==p){
            continue;
        }
        new_list.push_back(passive);
    }
    list_of_Passive = new_list;
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
