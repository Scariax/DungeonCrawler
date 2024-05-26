#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractcontroller.h"
#include "abstractview.h"

class TerminalUI : public AbstractController, public AbstractView
{
public:
    TerminalUI();
    void draw(Level *) override;
    virtual ~TerminalUI() = default;
    Input move() override;
};

#endif // TERMINALUI_H
