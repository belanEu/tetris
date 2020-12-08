#ifndef HEADER_MOVEMENTANALYZOR_H
#define HEADER_MOVEMENTANALYZOR_H

#include "TetraminoFigure.h"
#include "Glass.h"
#include "Coordinator.h"

using namespace tetramino_figure;
using namespace glass;

namespace controller
{
    class MovementAnalyzer
    {
    protected:
        bool success;

    public:
        MovementAnalyzer(): success(false)
        {
        }

        bool getResult()
        {
            return this->success;
        }

        void resetResult()
        {
            this->success = false;
        }

        void analyzeStep(Glass glassInstance, TetraminoFigure figure, Coordinator coordinator);

    protected:
        unsigned int* numericViewOfFigure(TetraminoFigure figure, int xTetraminoFigure, int glassWidth);
        unsigned int* numericViewOfSomeRowsWhithoutFigure(Glass glassInstance, int yTetraminoFigure, int figureSize);
        unsigned int* initializeByZero(unsigned int* array, int size);

    };
}

#endif // HEADER_MOVEMENTANALYZOR_H
