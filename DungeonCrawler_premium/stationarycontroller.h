#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H
#include "abstractcontroller.h"

class StationaryController : public AbstractController
{
public:
    StationaryController();
    Input_mov move() override;
    ~StationaryController();
};

#endif // STATIONARYCONTROLLER_H
