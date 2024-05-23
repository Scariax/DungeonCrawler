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
    Input move();
};

#endif // ABSTRACTCONTROLLER_H
