#pragma once
#include "abstractcontroller.h"
#include "abstractview.h"
#include "mainwindow.h"
#include "dungeoncrawler.h"

class GraphicalUI : public AbstractController, public AbstractView
{
public:
    GraphicalUI(MainWindow* mw);
    void draw(Level *level) override;
    virtual ~GraphicalUI() = default;
    Input move() override;

private:
    MainWindow* ui_m;
};
