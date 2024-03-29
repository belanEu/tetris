#include "MovementAnalyzer.h"

using namespace controller;
using namespace tetramino_figure;
using namespace glass;

void MovementAnalyzer::analyzeStep(Glass &glassInstance, TetraminoFigure figure, Coordinator coordinator)
{
    if (!this->coloredSquaresAreOutOfBorders(
                                            figure,
                                            coordinator.getXTetraminoFigure(),
                                            coordinator.getYTetraminoFigure(),
                                            glassInstance.getWidth(),
                                            glassInstance.getHeight()
                                            )
        )
    {
        unsigned int* figureRows = this->numericViewOfFigure(figure, coordinator.getXTetraminoFigure(), glassInstance.getWidth());

        unsigned int* glassRows = this->numericViewOfSomeRowsWhithoutFigure(glassInstance, coordinator.getYTetraminoFigure(), figure.getSize());

        this->success = true;

        for (int i = 0; i < figure.getSize(); i++)
        {
            this->success = this->success && (figureRows[i] & glassRows[i]) == 0;
        }
    }
    else
    {
        this->success = false;
    }
}

/**
    Build numeric view of rows which include considering figure without already existing figures.
*/
unsigned int* MovementAnalyzer::numericViewOfFigure(TetraminoFigure figure, int xTetraminoFigure, int glassWidth)
{
    unsigned int* result = new unsigned int[figure.getSize()];
    unsigned int bit = 1;

    this->initializeByZero(result, figure.getSize());

    for (int i = 0; i < figure.getSize(); i++)
    {
        for (int j = 0; j < figure.getSize(); j++)
        {
            unsigned int tmp = 0;
            if (figure.getTetraminoSquares()[i * figure.getSize() + j].isColored())
            {
                // 0001 << 3 -> 1000
                tmp = bit << (glassWidth - j - xTetraminoFigure - 1);
            }
            result[i] += tmp;
        }
    }

    return result;
}

/**
    Build numeric view of rows where current figure stands without actually considering figure.
*/
unsigned int* MovementAnalyzer::numericViewOfSomeRowsWhithoutFigure(Glass &glassInstance, int yTetraminoFigure, int figureSize)
{
    unsigned int* result = new unsigned int[figureSize];
    unsigned int bit = 1;

    this->initializeByZero(result, figureSize);

    for (int i = yTetraminoFigure; i < yTetraminoFigure + figureSize; i++)
    {
        for (int j = 0; j < glassInstance.getWidth(); j++)
        {
            unsigned int tmp = 0;
            if (glassInstance.getState()[i * glassInstance.getWidth() + j])
            {
                tmp = bit << (glassInstance.getWidth() - j - 1);
            }
            result[i - yTetraminoFigure] += tmp;
        }
    }

    return result;
}

bool MovementAnalyzer::coloredSquaresAreOutOfBorders(
                                                     TetraminoFigure figure,
                                                     int xTetraminoFigure,
                                                     int yTetraminoFigure,
                                                     int glassWidth,
                                                     int glassHeight
                                                     )
{
    // to check the first vertical
    for (int i = 0; i < figure.getSize(); i++)
    {
        if (figure.getTetraminoSquares()[i * figure.getSize()].isColored() && xTetraminoFigure == 0)
        {
            return true;
        }
    }
    // to check the last vertical
    for (int i = 0; i < figure.getSize(); i++)
    {
        if (
            figure.getTetraminoSquares()[i * figure.getSize() + figure.getSize() - 1].isColored()
            && xTetraminoFigure == glassWidth - 1
            )
        {
            return true;
        }
    }
    // to check the first horizontal
    for (int j = 0; j < figure.getSize(); j++)
    {
        if (figure.getTetraminoSquares()[j].isColored() && yTetraminoFigure == 0)
        {
            return true;
        }
    }
    // to check the last horizontal
    for (int j = 0; j < figure.getSize(); j++)
    {
        if (
            figure.getTetraminoSquares()[(figure.getSize() - 1) * figure.getSize() + j].isColored()
            && yTetraminoFigure == glassHeight - 1
            )
        {
            return true;
        }
    }

    return false;
}

void MovementAnalyzer::initializeByZero(unsigned int* arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        arr[i] = 0;
    }
}
