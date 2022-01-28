#include "apple.h"

Apple::Apple()
{
    random_generate();
}

void Apple::random_generate()
{
    coordinates.rx() = rand() % WIDTH;
    coordinates.ry() = rand() % HEIGHT;
}
