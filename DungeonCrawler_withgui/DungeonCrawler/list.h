 #ifndef LIST_H
#define LIST_H
#include "level.h"

class Level;

struct data{
    Level* level;
    data* next;
    data* prev;
};

class List
{

public:
    class iterator;
    List();
    ~List();
    void push_back(Level* lvl);
    void push_front(Level* lvl);
    void pop_back();
    void pop_front();
    bool empty();
    size_t size();
    void remove(Level* lvl);

    iterator begin();
    iterator end();
private:
    data* Start;
    data* End;
    size_t no_of_data;
public:
    class iterator{

    public:
        iterator(data *poi, List* par);

        data *getPointer() const;
        void setPointer(data *newPointer);

        iterator operator++();
        iterator operator--();
        Level*& operator*();
        bool operator==(const iterator& rhs);
        bool operator!=(const iterator& rhs);

        List *getParent() const;

    private:
        data* pointer;
        List* parent;
    };
};

#endif // LIST_H
