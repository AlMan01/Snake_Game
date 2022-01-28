#ifndef WALL_H
#define WALL_H

#include "apple.h"

class Wall
{
private:
    QVector<QPoint> wall_coordinates;
public:
    Wall();
    QPoint rand_wall_coord();
    void push(QPoint);
    int size();
    int left(int);
    int right(int);
};

#endif // WALL_H
