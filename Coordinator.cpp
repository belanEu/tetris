#include "Coordinator.h"
using namespace controller;

void Coordinator::setXTetraminoFigure(int x)
{
    if (x < 0)
    {
        this->xTetraminoFigure = 0;
    }
    else if (x > this->glassWidth - this->tetraminoFigureSize)
    {
        this->xTetraminoFigure = this->glassWidth - this->tetraminoFigureSize
    }
    else
    {
        this->xTetraminoFigure = x;
    }
}

void Coordinator::setYTetraminoFigure(int y)
{
    if (y < 0)
    {
        this->yTetraminoFigure = 0;
    }
    else if (y > this->glassHeight - this->tetraminoFigureSize)
    {
        this->yTetraminoFigure = this->glassHeight - this->tetraminoFigureSize
    }
    else
    {
        this->yTetraminoFigure = y;
    }
}
