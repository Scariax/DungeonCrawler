#include "graphicalui.h"
#include <iostream>
#include "level.h"


GraphicalUI::GraphicalUI(MainWindow* mw):ui_m(mw){}

void GraphicalUI::draw()
{
    ui_m->draw();
}

Input_mov GraphicalUI::move()
{
    Input_mov LC = ui_m->getLastClicked();
    return LC;
}
