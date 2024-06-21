#ifndef STATIONERYCONTROLLER_H
#define STATIONERYCONTROLLER_H

#include "abstractcontroller.h"

class StationeryController: public AbstractController
{
public:
    StationeryController();
    Input_mov move() override;
};

#endif // STATIONERYCONTROLLER_H
