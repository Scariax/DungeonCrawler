#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "level.h"
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QKeyEvent>
#include <QStatusBar>



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

            widget->setScaledContents(true);

            l->addWidget(widget, row, col, Qt::AlignCenter);
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

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->modifiers() & !Qt::KeypadModifier){
        return;
    }
    switch(event->key()){
    case(Qt::Key_1):
    {
        on_downleft_clicked();
        break;
    }

    case(Qt::Key_2):
    {
        on_down_clicked();
        break;
    }

    case(Qt::Key_3):
    {
        on_downright_clicked();
        break;
    }

    case(Qt::Key_4):
    {
        on_left_clicked();
        break;
    }

    case(Qt::Key_5):
    {
        on_turn_clicked();
        break;
    }

    case(Qt::Key_6):
    {
        on_right_clicked();
        break;
    }

    case(Qt::Key_7):
    {
        on_upleft_clicked();
        break;
    }

    case(Qt::Key_8):
    {
        on_up_clicked();
        break;
    }

    case(Qt::Key_9):
    {
        on_upright_clicked();
        break;
    }

    case(Qt::Key_X):
    {
        close();
    }

    default:{return;}
    }
}

void MainWindow::draw()
{
    //
    auto level = dc->getLevel();
    for (int row = 0; row < level->getRows(); row++)
    {
        for (int col = 0; col < level->getCols(); col++)
        {
            QWidget* widget1 = ui_m->tiles->itemAtPosition(row, col)->widget();

            QLabel* widget = qobject_cast<QLabel*>(widget1);

            std::string texture = level->getTile(row, col)->getTexture();
            char* tex_c= texture.data();

            int tmp = level->getTile(row, col)->getFloor_tile_typ();

            if(*tex_c=='.'){
                if(tmp%5 == 0){
                    widget->setPixmap(QPixmap(":/textures/floor/floor1.png"));
                }
                if(tmp%5 ==1){
                    widget->setPixmap(QPixmap(":/textures/floor/floor2.png"));
                }
                if(tmp%5 ==2){
                    widget->setPixmap(QPixmap(":/textures/floor/floor3.png"));
                }
                if(tmp%5 ==3){
                    widget->setPixmap(QPixmap(":/textures/floor/floor4.png"));
                }
                if(tmp%5 ==4){
                    widget->setPixmap(QPixmap(":/textures/floor/floor5.png"));
                }
            }
            else if(*tex_c=='#'){
                widget->setPixmap(QPixmap(":/textures/wall/wall1.png"));
            }
            else if(*tex_c=='<'){
                widget->setPixmap(QPixmap(":/textures/ramp.png"));
            }
            else if(*tex_c=='_'){
                widget->setPixmap(QPixmap(":/textures/pit.png"));
                widget->setStyleSheet("background: transparent;");
            }
            else if(*tex_c=='O'){
                int por_typ = level->getTile(row, col)->getPortal_type();
                if(por_typ%3==0){
                    widget->setPixmap(QPixmap(":/textures/portal/portal1.png"));
                }
                if(por_typ%3==1){
                    widget->setPixmap(QPixmap(":/textures/portal/portal2.png"));
                }
                if(por_typ%3==2){
                    widget->setPixmap(QPixmap(":/textures/portal/portal3.png"));
                }
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
            else if(*tex_c=='&'){
                widget->setPixmap(QPixmap(":textures/portal/portal3.png"));
            }
            if(level->getTile(row, col)->hasCharacter())
            {
                QLabel* charac = new QLabel(nullptr);

                if(level->getTile(row,col)->getCharacter()->isHuman()){
                    cur_pos_row=row;
                    cur_pos_col=col;

                    charac->setStyleSheet("background: transparent; border-image: none;");

                    Input_mov moved_dir = level->getTile(row, col)->getCharacter()->getMoveDirection();

                    if(moved_dir==up){
                        charac->setPixmap(QPixmap(":/textures/char/back/char_back_1.png"));
                    }
                    if(moved_dir==down){
                        charac->setPixmap(QPixmap(":/textures/char/front/char_front_1.png"));
                    }
                    if(moved_dir==right){
                        charac->setPixmap(QPixmap(":/textures/char/right/char_right_1.png"));
                    }
                    if(moved_dir==left){
                        charac->setPixmap(QPixmap(":/textures/char/left/char_left_1.png"));
                    }
                    if(moved_dir==terminate){
                        charac->setPixmap(QPixmap(":/textures/char/front/char_front_2.png"));
                    }
                }
                else{
                    charac->setStyleSheet("background: transparent; border-image: none;");

                    if(level->getTile(row,col)->getCharacter()->getTexture()=="1"){
                        charac->setPixmap(QPixmap(":/textures/zombie/zombie_left.png"));
                    }
                    if(level->getTile(row,col)->getCharacter()->getTexture()=="2"){
                        charac->setPixmap(QPixmap(":/textures/zombie/zombie_right.png"));
                    }
                }

                charac->setFixedSize(75,75);
                charac->setScaledContents(true);
                charac->setParent(nullptr);
                ui_m->tiles->addWidget(charac, row, col, Qt::AlignCenter);

                characters.push_back(std::make_pair(row,col));

                if(*tex_c=='_'){
                    charac->lower();
                }

            }
        }
    }

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
    QString HP = QString::number(dc->getLevel()->getCharacters().at(0)->getHitpoints());
    QString strength = QString::number(dc->getLevel()->getCharacters().at(0)->getStrength());
    QString stamina = QString::number(dc->getLevel()->getCharacters().at(0)->getStamina());

    ui_m->statusBar->showMessage(QString("HP: %1  Strength: %2  Stamina: %3").arg(HP, strength, stamina));
    ui_m->statusBar->setStyleSheet("background-color: rgb(255, 255, 255); border-image: none;"); // for Transparent Backgroung :  background: transparent;
}

void MainWindow::remove_exis_char()
{
    for(auto pos:characters){
        QWidget* widget = ui_m->tiles->itemAtPosition(pos.first,pos.second)->widget();
        ui_m->tiles->removeWidget(widget);
        widget->setParent(nullptr);
        delete widget;
        characters.erase(characters.begin());
    }
}

void MainWindow::on_upleft_clicked()
{
    remove_exis_char();
    LastClicked = upleft;
    dc->turn();
    this->draw();
}

void MainWindow::on_upright_clicked()
{
    remove_exis_char();
    LastClicked = upright;
    dc->turn();
    this->draw();
}

void MainWindow::on_up_clicked()
{
    remove_exis_char();
    LastClicked = up;
    dc->turn();
    this->draw();
}

void MainWindow::on_left_clicked()
{
    remove_exis_char();
    LastClicked = left;
    dc->turn();
    this->draw();
}

void MainWindow::on_right_clicked()
{
    remove_exis_char();
    LastClicked = right;
    dc->turn();
    this->draw();
}

void MainWindow::on_downright_clicked()
{
    remove_exis_char();
    LastClicked = downright;
    dc->turn();
    this->draw();
}

void MainWindow::on_downleft_clicked()
{
    remove_exis_char();
    LastClicked = downleft;
    dc->turn();
    this->draw();
}

void MainWindow::on_down_clicked()
{
    remove_exis_char();
    LastClicked = down;
    dc->turn();
    this->draw();
}


void MainWindow::on_turn_clicked()
{
    remove_exis_char();

    Input_mov curr_Direction = dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->getMoveDirection();

    switch (curr_Direction) {
    case up:
        dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(left);
        break;
    case down:
        dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(right);
        break;
    case right:
        dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(up);
        break;
    case left:
        dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(down);
        break;
    case terminate:
        dc->getLevel()->getTile(cur_pos_row, cur_pos_col)->getCharacter()->setMoveDirection(right);
        break;
    }
    this->draw();
}

Input_mov MainWindow::getLastClicked() const
{
    return LastClicked;
}

