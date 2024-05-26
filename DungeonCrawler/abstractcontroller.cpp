#include "abstractcontroller.h"
#include <iostream>

AbstractController::AbstractController() {}

Input AbstractController::move()
{
    while(true){
        std::cout << "Your turn to move(up - w, down - s, right - d, left - a, exit - x" << std::endl;
        char input{};
        std::cin >> input;
        std::cout << std::endl;

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

        default:
            std::cout << "Wrong Input, Please choose one of these (w,a,s,d,x)!" << std::endl << std::endl;
            continue;
        }
    }
}
