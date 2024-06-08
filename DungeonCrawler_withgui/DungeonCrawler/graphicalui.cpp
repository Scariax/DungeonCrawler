#include "graphicalui.h"
#include <iostream>
#include "level.h"

GraphicalUI::GraphicalUI(MainWindow* mw):ui_m(mw){}

void GraphicalUI::draw(Level* level)
{
    ui_m->draw(level);
}

Input GraphicalUI::move(char input)
{
    return AbstractController::move(input);
}
