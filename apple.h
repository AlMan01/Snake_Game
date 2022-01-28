#ifndef APPLE_H
#define APPLE_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QKeyEvent>


class Apple : public QWidget
{
public:
    QPoint coordinates;
    const int HEIGHT = 20;
    const int WIDTH = 20;
    Apple();
    void random_generate();
};

#endif // APPLE_H
