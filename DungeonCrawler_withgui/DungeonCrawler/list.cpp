#include "list.h"
#include <stdexcept>



List::List(): Start(nullptr),End(nullptr),no_of_data(0) {}

List::~List(){
    while(!empty()){
        pop_front();
    }
}

void List::push_back(Level *lvl)
{
    if(Start==nullptr){
        Start =  new data{lvl,nullptr,nullptr};
        End = Start;
    }
    else{
        data* new_dat = new data{lvl,nullptr,End};
        End->next = new_dat;
        End = new_dat;
    }
    no_of_data++;
}

void List::push_front(Level *lvl)
{
    if(Start==nullptr){
        Start =  new data{lvl,nullptr,nullptr};
        End = Start;
    }
    else{
        data* new_dat = new data{lvl,Start,nullptr};
        Start->prev = new_dat;
        Start = new_dat;
    }
    no_of_data++;
}

void List::pop_back()
{
    if(this->empty()){
        throw std::invalid_argument("The list ist empty");
    }
    else{
        if(size()==1){
            delete Start;
            Start=nullptr;
            End =nullptr;
        }
        else{
            data* tmp = End->prev;
            tmp->next=nullptr;
            delete End;
            End = tmp;
        }
        no_of_data--;
    }
}


void List::pop_front()
{
    if(this->empty()){
        throw std::invalid_argument( "The list ist empty" );
    }
    else{
        if(size()==1){
            delete Start;
            End = nullptr;
            Start = nullptr;
        }
        else{
            data* tmp = Start->next;
            delete tmp->prev;
            Start = tmp;
            Start->prev =nullptr;
        }
        no_of_data--;
    }
}

bool List::empty()
{
    return (size() == 0);
}

size_t List::size()
{
    return no_of_data;
}

void List::remove(Level *lvl)
{
    if(this->empty()){
        throw std::invalid_argument( "The list ist empty" );
    }
    else{
        data* tmp = Start;
        bool removed{false};
        size_t i = this->size();
        while(i>0){
            if(*(tmp->level) == *lvl){
                data* tmp_n = tmp->next;
                data* tmp_p = tmp->prev;
                tmp_p->next = tmp_n;
                tmp_n->prev = tmp_p;
                delete tmp;
                tmp = tmp_n;
                this->no_of_data--;
                removed=true;
            }
        }
        if(!removed){
            throw std::invalid_argument( "The element was not found!" );
        }
    }
}

List::iterator List::begin()
{
    return iterator(Start,this);
}

List::iterator List::end()
{
    return iterator(nullptr,this);
}


data *List::iterator::getPointer() const
{
    return pointer;
}

void List::iterator::setPointer(data *newPointer)
{
    pointer = newPointer;
}

List::iterator::iterator(data *poi, List* par): pointer(poi), parent(par)
{}

List::iterator List::iterator::operator++()
{
    if(*this == parent->end()){
        return *this;
    }
    data* tmp = this->pointer->next;
    return List::iterator(tmp,this->getParent());
}

List::iterator List::iterator::operator--()
{
    if(*this == parent->end()){
        return List::iterator(parent->End,this->getParent());
    }
    else if(*this == parent->begin()){
        throw std::invalid_argument("The first element of the list!");
    }
    else{
        data* tmp = this->pointer->prev;
        return List::iterator(tmp,this->getParent());

    }
}

Level*& List::iterator::operator*()
{
    if(this->getPointer()==nullptr){
        throw std::invalid_argument("invalid element");
    }
    return this->getPointer()->level;
}

bool List::iterator::operator==(const List::iterator &rhs)
{
    if(this->getParent() == rhs.getParent() && this->getPointer()==rhs.getPointer())
        return true;
    return false;
}

bool List::iterator::operator!=(const List::iterator &rhs)
{
    if(this->getParent() == rhs.getParent() && this->getPointer()==rhs.getPointer())
        return false;
    return true;
}

List *List::iterator::getParent() const
{
    return parent;
}

