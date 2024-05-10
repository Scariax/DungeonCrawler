#include "terminalui.h"

TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level *level)
{
    int r = level->getRows();
    int c = level->getColumns();
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            if(level->Playfield.at(i).at(j)->hasCharacter()){
                std::cout<<"X";
            }else{
                std::cout<<level->Playfield.at(i).at(j)->getTexture();
            }
        }
        std::cout<<std::endl;
    }
}

Input TerminalUI::move()
{
    while(true){
        std::cout<<"Your Turn to move(up - w,down - s, right - d, left - a, exit - x) :";
        char input{};
        std::cin>>input;
        std::cout<<std::endl;

        if(input=='w'){
            return up;
        }
        else if(input=='s'){
            return down;
        }
        else if(input=='a'){
            return left;
        }
        else if(input=='d'){
            return right;
        }
        else if(input=='x'){
            return exiting;
        }
        else{
            std::cout<<"Wrong Input, Please choose one of these(a,w,s,d,x)!"<<std::endl;
            continue;
        }
    }
}
