#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"

class TerminalUI: public AbstractUI
{
public:
    TerminalUI();
    void draw(Level* level) override;
    Input move() override;
};

#endif // TERMINALUI_H
