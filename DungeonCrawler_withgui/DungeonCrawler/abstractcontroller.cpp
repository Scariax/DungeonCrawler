#include "abstractcontroller.h"
#include <iostream>

AbstractController::AbstractController() {}

Input AbstractController::move(char input)
{
    while(true){
        switch(input){
        case 'w':
            return up;
            break;
        case 's':
            return down;
            break;
        case 'a':
            return left;
            break;
        case 'd':
            return right;
            break;
        case 'x':
            return terminate;
            break;
        }
    }
}
