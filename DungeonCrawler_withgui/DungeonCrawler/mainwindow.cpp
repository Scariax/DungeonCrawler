
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
                widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
                l->addWidget(widget, row, col, Qt::AlignRight| Qt::AlignBottom);
            }
            if(*tex_c == '<' || *tex_c == '_'){
                l->addWidget(widget, row, col, Qt::AlignLeft | Qt::AlignTop);
            }
            else{
                l->addWidget(widget, row, col, Qt::AlignRight| Qt::AlignBottom);
            }
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
            QWidget* widget1 = ui_m->tiles->itemAtPosition(row, col)->widget();

            QLabel* widget = qobject_cast<QLabel*>(widget1);

            QLabel* charac = new QLabel(nullptr);

            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();

            int tmp = (row + col)%5;

            if(*tex_c=='.'){
                if(tmp== 0){
                    widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
                }
                if(tmp==1){
                    widget->setPixmap(QPixmap(":/textures/floor/floor2.png"));
                }
                if(tmp==2){
                    widget->setPixmap(QPixmap(":/textures/floor/floor3.png"));
                }
                if(tmp==3){
                    widget->setPixmap(QPixmap(":/textures/floor/floor4.png"));
                }
                if(tmp==4){
                    widget->setPixmap(QPixmap(":/textures/floor/floor5.png"));
                }
            }
            else if(*tex_c=='#'){
                widget->setPixmap(QPixmap(":/textures/wall/wall1.png"));
            }
            else if(*tex_c=='<'){
                widget->setPixmap(QPixmap(":/textures/ramp.png"));
                widget->raise();
                charac->lower();
            }
            else if(*tex_c=='_'){
                widget->setPixmap(QPixmap(":/textures/pit.png"));
                widget->raise();
                charac->lower();
            }
            else if(*tex_c=='O'){
                widget->setPixmap(QPixmap(":/textures/portal/portal1.png"));
            }
            else if(*tex_c=='?'){
                widget->setPixmap(QPixmap(":/textures/switch.png"));
            }
            else if(*tex_c=='-'){
                widget->setPixmap(QPixmap(":/textures/doors/door1.png"));
            }
            else if(*tex_c=='\\'){
                widget->setPixmap(QPixmap(":/textures/doors/door2.png"));
            }
            if(level->getTile(row, col)->hasCharacter())
            {
                cur_pos_row=row;
                cur_pos_col=col;
                charac->setStyleSheet("background: transparent; border-image: none; "); //border-image:url(:/textures/char/front/char_front_2.png);
                charac->setPixmap(QPixmap(":/textures/char/front/char_front_2.png"));
                charac->setFixedSize(55,55);
                charac->setScaledContents(true);
                charac->setParent(nullptr);
                if(*tex_c == '<' || *tex_c == '_'){
                    ui_m->tiles->addWidget(charac, row, col, Qt::AlignRight | Qt::AlignBottom);
                }
                else{
                    ui_m->tiles->addWidget(charac, row, col, Qt::AlignLeft  | Qt::AlignTop);
                }
            }
        }
    }
}

void MainWindow::remove_exis_char()
{
    QWidget* widget = ui_m->tiles->itemAtPosition(cur_pos_row,cur_pos_col)->widget();
    ui_m->tiles->removeWidget(widget);
    widget->setParent(nullptr);
    delete widget;
}

void MainWindow::on_upleft_clicked()
{
    remove_exis_char();
    if(dc->turn(up))
        if(dc->turn(left))
            dc->turn(up);
    this->draw(dc->getLevel());
}

void MainWindow::on_upright_clicked()
{
    remove_exis_char();
    if(dc->turn(up))
        if(dc->turn(right))
            dc->turn(up);
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
    if(dc->turn(down))
        if(dc->turn(right))
            dc->turn(down);
    this->draw(dc->getLevel());
}

void MainWindow::on_downleft_clicked()
{
    remove_exis_char();
    if(dc->turn(down))
        if(dc->turn(left))
            dc->turn(down);
    this->draw(dc->getLevel());
}

void MainWindow::on_down_clicked()
{
    remove_exis_char();
    dc->turn(down);
    this->draw(dc->getLevel());
}

