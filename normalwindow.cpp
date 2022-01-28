#include "playwindow.h"
#include "ui_normalwindow.h"




NormalWindow::NormalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NormalWindow)
{
    ui->setupUi(this);
    //ui->lcdNumber->value();
    this->resize(400, 451);
    setup();
}

void NormalWindow::move_dir()
{
    for(int i = snake_coordinates.size() - 1; i > 0; --i)
    {
        snake_coordinates[i] = snake_coordinates[i - 1];
    }
    switch(move)
    {
        case LEFT:
            --snake_coordinates[0].rx();
            break;
        case UP:
            --snake_coordinates[0].ry();
            break;
        case DOWN:
            ++snake_coordinates[0].ry();
            break;
        case RIGHT:
            ++snake_coordinates[0].rx();
            break;
        default:
            break;
    }
}

void NormalWindow::check_field()
{
    if(snake_coordinates.size() > 10 && infinity_flag == false)
    {
        game_over = true;
    }
    for(int i = 1; i < snake_coordinates.size(); ++i)
    {
        if(snake_coordinates[0] == snake_coordinates[i] && infinity_flag == false)
            game_over = true;
        if(!lvl_1_flag)
        {
            if(snake_coordinates[0] == snake_coordinates[i] && infinity_flag == true)
                snake_coordinates.erase(snake_coordinates.begin() + i,snake_coordinates.end());
                //snake_coordinates.shrink_to_fit();
        }
    }

    if(!infinity_flag)
    {
        if(lvl_3_flag)
        {
            for(int i = 0; i < wl->size(); ++i)
            {
                if(snake_coordinates[0].x() == wl->left(i) && snake_coordinates[0].y() == wl->right(i))
                {
                    gameOver();
                }
            }
        }
        if(snake_coordinates[0].x() >= ap->WIDTH)
            game_over = true;
        else if(snake_coordinates[0].x() < 0)
            game_over = true;
        if(snake_coordinates[0].y() >= ap->HEIGHT)
            game_over = true;
        if(snake_coordinates[0].y() < 0)
            game_over = true;
    }
    else
    {
        for(int i = 1; i < snake_coordinates.size(); ++i)
        {
            if(snake_coordinates[0] == snake_coordinates[i])
                game_over = true;
        }
        if (snake_coordinates[0].x() >= ap->WIDTH)
        {
            snake_coordinates[0].rx() = 0;
        }
        else if (snake_coordinates[0].x() < 0)
        {
            snake_coordinates[0].rx() = ap->WIDTH - 1;
        }
        if (snake_coordinates[0].y() >= ap->HEIGHT)
        {
            snake_coordinates[0].ry() = 0;
        }
        else if (snake_coordinates[0].y() < 0)
        {
            snake_coordinates[0].ry() = ap->HEIGHT - 1;
        }
    }
    if(game_over) {
        killTimer(timerID);
    }
}

void NormalWindow::check_apple()
{
    if(ap->coordinates == snake_coordinates[0])
    {
        wl->push(wl->rand_wall_coord());
        score += 10;
        if(score == 30 && lvl_1_flag && !lvl_3_flag)
        {
            QMessageBox next_lvl;
            message(next_lvl);
            next_lvl.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            if(next_lvl.exec() == QMessageBox::No && lvl_1_flag && !lvl_3_flag)
            {
                NormalWindow* nw = new NormalWindow();
                nw->lvl_1_flag = false;
                nw->infinity_flag = false;
                nw->show();
                hide();
            }
        }
        if(score == 40 && !lvl_1_flag && !lvl_3_flag)
        {
            QMessageBox next_lvl;
            message(next_lvl);
            next_lvl.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            if(next_lvl.exec() == QMessageBox::No && !lvl_1_flag)
            {
                NormalWindow* nw = new NormalWindow();
                nw->lvl_3_flag = true;
                nw->infinity_flag = false;
                nw->show();
                hide();
            }
        }
        snake_coordinates.push_back(QPoint(0, 0));
        ap->random_generate();
    }
}

void NormalWindow::gameOver()
{
    go = new GameOver();
    go->setWindowTitle("Game over((");
    go->show();
    hide();
}

void NormalWindow::draw()
{
    QPainter ellipsePainter(this);
    if(!game_over)
    {
        if(lvl_3_flag)
        {
            for(int i = 0; i < wl->size(); ++i)
            {
                ellipsePainter.setBrush(Qt::black);
                ellipsePainter.drawRect(wl->left(i) * 20, wl->right(i) * 20, 20, 20);
            }
        }
        ellipsePainter.setBrush(Qt::red);
        ellipsePainter.drawEllipse(ap->coordinates.x() * ap->WIDTH, ap->coordinates.y() * ap->HEIGHT, ap->HEIGHT, ap->WIDTH);
        for(int i = 0; i < snake_coordinates.size(); ++i)
        {
            if(i == 0)
            {
                ellipsePainter.setBrush(Qt::black);
                ellipsePainter.drawEllipse(snake_coordinates[i].x() * ap->WIDTH, snake_coordinates[i].y() * ap->HEIGHT, ap->WIDTH, ap->HEIGHT);
            }
            else
            {
                ellipsePainter.setBrush(Qt::gray);
                ellipsePainter.drawEllipse(snake_coordinates[i].x() * ap->WIDTH, snake_coordinates[i].y() * ap->HEIGHT, ap->WIDTH, ap->HEIGHT);
            }
        }
        //lcd->setDigitCount(8);
        ui->lcdNumber->display(score);
    }
    else
    {
        gameOver();
    }
}



void NormalWindow::setup()
{
    //PlayWindow pw;
    get_delay();
    move = STOP;
    game_over = false;
    snake_coordinates.resize(1);
    snake_coordinates[0].rx() = ap->WIDTH / 2;
    snake_coordinates[0].ry() = ap->HEIGHT / 2;
    ap->random_generate();
    timerID = startTimer(DELAY);
}

void NormalWindow::message(QMessageBox& next_lvl)
{
    next_lvl.setText("CONGRATS! YOU PASSED!\n"
                     "Stay or go to next level\n"
                     "Stay?");
}



void NormalWindow::get_delay()
{
    //PlayWindow pw;
    if(slow_flag){
        DELAY = 200;
    }
    /*if(medium_flag){
        DELAY = 100;
    }
    if(fast_flag){
        DELAY = 70;
    }*/
}

void NormalWindow::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);
    int key = event->key();
    if((key == Qt::Key_Left || key == Qt::Key_A) && move != RIGHT)
    {
        move = LEFT;
    }
    if ((key == Qt::Key_Right || key == Qt::Key_D) && move != LEFT)
    {
        move = RIGHT;
    }
    if ((key == Qt::Key_Up || key == Qt::Key_W) && move != DOWN)
    {
        move = UP;
    }
    if ((key == Qt::Key_Down || key == Qt::Key_S) && move != UP)
    {
            move = DOWN;
    }
}

void NormalWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    draw();
}

void NormalWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if(!game_over)
    {
        check_apple();
        move_dir();
        check_field();
    }
    this->repaint();
}


NormalWindow::~NormalWindow()
{
    delete ui;
}

