#ifndef HEADER_STACKER_H
#define HEADER_STACKER_H

#include "TetraminoFigure.h"
#include "Glass.h"
#include "Coordinator.h"

using namespace tetramino_figure;
using namespace glass;

namespace controller
{
    class Stacker
    {
    public:
        static void toStack(Glass &glassInstance, TetraminoFigure figure, Coordinator coordinator)
        {
            for (int i = 0; i < figure.getSize(); i++)
            {
                for (int j = 0; j < figure.getSize(); j++)
                {
                    int index = (coordinator.getYTetraminoFigure() + i) * glassInstance.getWidth() + (coordinator.getXTetraminoFigure() + j);
                    glassInstance.setIntoState(index, figure.getTetraminoSquares()[i * figure.getSize() + j].isColored());
                }
            }
        }

        static void toDelete(Glass &glassInstance, TetraminoFigure figure, Coordinator coordinator)
        {
            for (int i = 0; i < figure.getSize(); i++)
            {
                for (int j = 0; j < figure.getSize(); j++)
                {
                    int index = (coordinator.getYTetraminoFigure() + i) * glassInstance.getWidth() + (coordinator.getXTetraminoFigure() + j);
                    glassInstance.setIntoState(index, false);
                }
            }
        }
    };
}

#endif // HEADER_STACKER_H
