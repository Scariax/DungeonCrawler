#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"

class TerminalUI : public AbstractUI
{
public:
    TerminalUI();
    void draw(Level *) override;
    Input move() override;
    virtual ~TerminalUI() = default;
};

#endif // TERMINALUI_H
