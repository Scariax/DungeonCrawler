#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

enum Input{
    up,
    down,
    left,
    right,
    terminate
};

class AbstractController
{
public:
    AbstractController();
    virtual Input move() = 0;
};

#endif // ABSTRACTCONTROLLER_H
