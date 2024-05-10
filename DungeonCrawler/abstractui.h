#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
#include "level.h"

enum Input{
    up,
    down,
    right,
    left,
    exiting
};

class AbstractUI
{
public:
    AbstractUI();
    virtual void draw(Level* level) = 0;
    virtual Input move() = 0;
};

#endif // ABSTRACTUI_H
