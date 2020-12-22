#ifndef HEADER_MOVEMENTMAKER_H
#define HEADER_MOVEMENTMAKER_H

#include "Glass.h"
#include "TetraminoFigure.h"
#include "Coordinator.h"
#include "MovementAnalyzer.h"
#include "Stacker.h"

using namespace glass;
using namespace tetramino_figure;

namespace controller
{
    class MovementMaker
    {
    protected:
        MovementAnalyzer* movementAnalyzer = NULL;

    public:
        MovementMaker()
        {
            this->movementAnalyzer = new MovementAnalyzer;
        }

        ~MovementMaker()
        {
            delete this->movementAnalyzer;
        }

        void makeStep(
                      Glass &glassInstance,
                      TetraminoFigure figure,
                      Coordinator &current,
                      Coordinator next
                      );

        void stepDown(Glass &glassInstance, TetraminoFigure figure, Coordinator &coordinator);
        void stepLeft(Glass &glassInstance, TetraminoFigure figure, Coordinator &coordinator);
        void stepRight(Glass &glassInstance, TetraminoFigure figure, Coordinator &coordinator);

        void rotateLeft(Glass &glassInstance, TetraminoFigure figure, Coordinator &coordinator);
        void rotateRight(Glass &glassInstance, TetraminoFigure figure, Coordinator &coordinator);
    };
}

#endif // HEADER_MOVEMENTMAKER_H
