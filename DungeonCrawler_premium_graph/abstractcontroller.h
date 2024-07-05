#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

enum Input_mov
{
    up,
    upleft,
    upright,
    down,
    downleft,
    downright,
    left,
    right,
    terminate,
    stand
};

class AbstractController
{
public:
    AbstractController();
    virtual Input_mov move() = 0;
    virtual ~AbstractController() = default;
};

#endif // ABSTRACTCONTROLLER_H
