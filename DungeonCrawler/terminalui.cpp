#include "terminalui.h"
#include <iostream>
#include "level.h"

TerminalUI::TerminalUI(){

}

void TerminalUI::draw(Level* level){
    int r = level->getRows();
    int c = level->getCols();
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(level->getTile(i, j)->hasCharacter())
            {
                std::cout << "X";
            }
            else
            {
                std::cout << level->getTile(i, j)->getTexture();
            }
        }
        std::cout << std::endl;
    }
}

Input TerminalUI::move()
{
    return AbstractUI::move();
}
