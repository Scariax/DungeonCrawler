#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class Level;

enum Input{
    up,
    down,
    left,
    right,
    terminate
};

class AbstractUI
{
public:
    AbstractUI();
    virtual void draw(Level* level) = 0;
    virtual Input move() = 0;
    virtual ~AbstractUI() = default;
};

#endif // ABSTRACTUI_H
