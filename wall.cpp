#include "wall.h"

Wall::Wall()
{
    wall_coordinates.resize(1);
}

QPoint Wall::rand_wall_coord()
{
    QPoint tmp;
    tmp.rx() = rand() % 20;
    tmp.ry() = rand() % 20;
    return tmp;
}

void Wall::push(QPoint q)
{
    wall_coordinates.push_back(q);
}

int Wall::size()
{
    return wall_coordinates.size();
}

int Wall::left(int i)
{
   return wall_coordinates[i].x();
}

int Wall::right(int i)
{
    return wall_coordinates[i].y();
}
