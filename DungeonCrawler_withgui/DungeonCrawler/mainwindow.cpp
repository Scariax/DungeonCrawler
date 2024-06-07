#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "level.h"
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QObject>



MainWindow::MainWindow(DungeonCrawler* dc, QWidget *parent)
    : QMainWindow{parent}
    , ui_m(new Ui::MainWindow)
    , dc(dc),cur_pos_row(0),cur_pos_col(0)
{
    ui_m->setupUi(this);

    this->setStyleSheet("background-color: rgb(0, 0, 0); border-image: url(:/textures/bloody_frame.png);");

    ui_m->verticalLayout->setContentsMargins(10,100,10,10);

    QGridLayout* l = ui_m->tiles;

    level = dc->getLevel();

    for(int row=0; row < level->getRows(); row++){
        for(int col=0; col < level->getCols(); col++){

            QLabel* widget = new QLabel(nullptr);

            widget->setFixedSize(80,60);
            widget->setScaledContents(true);

            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();
            if(*tex_c == 'X'){
                widget->setStyleSheet("border-image:url(:/textures/floor/floor1.png);");
            }
            l->addWidget(widget, row, col, Qt::AlignCenter);
            widget->lower();
        }
    }
    l->setAlignment(Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui_m;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    Level* level = dc->getLevel();

    const int w = ui_m->centralwidget->width() / level->getRows();
    const int h = ui_m->centralwidget->height() / level->getCols();

    const int opt = std::min(w, h);


    ui_m->verticalLayout->setContentsMargins(opt,opt*1.5,opt,opt*0.5);

    for (int row = 0; row < level->getRows(); row++)
    {
        for (int col = 0; col < level->getCols(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            widget->setFixedSize(opt*0.80, opt*0.80);
        }
    }

}

void MainWindow::draw(Level* level)
{
    for (int row = 0; row < level->getRows(); row++)
    {
        for (int col = 0; col < level->getCols(); col++)
        {
            QWidget* widget = ui_m->tiles->itemAtPosition(row, col)->widget();
            QLabel* charac = new QLabel(nullptr);
            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();

            switch (*tex_c) {
            case '.':
                widget->setStyleSheet("border-image:url(:/textures/floor/floor1.png);");
                break;
            case '#':
                widget->setStyleSheet("border-image:url(:/textures/wall/wall1.png);");
                break;
            case '<':
                widget->setStyleSheet("border-image:url(:/textures/ramp.png);");
                charac->lower();
                break;
            case '_':
                widget->setStyleSheet("border-image:url(:/textures/pit.png);");
                charac->lower();
                break;
            case 'O':
                widget->setStyleSheet("border-image:url(:/textures/portal/portal1.png);");
                break;
            case '?':
                widget->setStyleSheet("border-image:url(:/textures/switch.png);");
                break;
            case '-':
                widget->setStyleSheet("border-image:url(:/textures/doors/door1.png);");
                break;
            case '\\':
                widget->setStyleSheet("border-image:url(:/textures/doors/door2.png);");
                break;
            default:
                break;
            }
            if(level->getTile(row, col)->hasCharacter())
            {
                cur_pos_row=row;
                cur_pos_col=col;

                charac->setStyleSheet("background: transparent;border-image:url(:/textures/char/front/char_front_2.png);");
                charac->setFixedSize(55,55);
                charac->setScaledContents(true);
                charac->setParent(nullptr);
                ui_m->tiles->addWidget(charac, row, col, Qt::AlignCenter);
            }
        }
    }
}

void MainWindow::on_upleft_clicked()
{
    QWidget* widget = ui_m->tiles->itemAtPosition(cur_pos_row,cur_pos_col)->widget();
    ui_m->tiles->removeWidget(widget);
    widget->setParent(nullptr);
    delete widget;

    dc->turn(up);
    dc->turn(left);
    this->draw(dc->getLevel());
}

void MainWindow::remove_exis_char()
{
    QWidget* widget = ui_m->tiles->itemAtPosition(cur_pos_row,cur_pos_col)->widget();
    ui_m->tiles->removeWidget(widget);
    widget->setParent(nullptr);
    delete widget;
}

void MainWindow::on_upright_clicked()
{
    remove_exis_char();

    dc->turn(up);
    dc->turn(right);
    this->draw(dc->getLevel());
}

void MainWindow::on_up_clicked()
{
    remove_exis_char();

    dc->turn(up);
    this->draw(dc->getLevel());
}

void MainWindow::on_left_clicked()
{
    remove_exis_char();


    dc->turn(left);
    this->draw(dc->getLevel());
}

void MainWindow::on_right_clicked()
{
    remove_exis_char();

    dc->turn(right);
    this->draw(dc->getLevel());
}

void MainWindow::on_downright_clicked()
{
    remove_exis_char();

    dc->turn(down);
    dc->turn(right);
    this->draw(dc->getLevel());
}

void MainWindow::on_downleft_clicked()
{
    remove_exis_char();

    dc->turn(down);
    dc->turn(left);
    this->draw(dc->getLevel());
}

void MainWindow::on_down_clicked()
{
    remove_exis_char();

    dc->turn(down);
    this->draw(dc->getLevel());
}

