#include "snake.h"

Snake::Snake()
{
    this->resize(ap->WIDTH * ap->WIDTH, ap->HEIGHT * ap->HEIGHT);
    game_over = false;
    snake_coordinates.resize(1);
    snake_coordinates[0].rx() = ap->WIDTH / 2;
    snake_coordinates[0].ry() = ap->HEIGHT / 2;
}



