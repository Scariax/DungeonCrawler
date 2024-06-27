#include "graphicalui.h"
#include "level.h"
#include <iostream>
#include "mainwindow.h"

GraphicalUI::GraphicalUI(MainWindow* mw):
    ui_m(mw)
{}

void GraphicalUI::draw()
{
    ui_m->draw();
}

GraphicalUI::~GraphicalUI()
{
    ui_m = nullptr;
}

Input_mov GraphicalUI::move()
{
    Input_mov LC = ui_m->getLastClicked();
    return LC;
}
