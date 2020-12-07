#include "TetraminoFigure.h"
#include "Glass.h"
#include "Coordinator.h"

using namespace tetramino_figure;
using namespace glass;

namespace controller
{
    class Painter
    {
    public:
        static void paint(TetraminoFigure figure, Glass glass, Coordinator coordinator)
        {
            for (int i = 0; i < figure.getSize(); i++)
            {
                for (int j = 0; j < figure.getSize(); j++)
                {
                    int index = (coordinator.getYTetraminoFigure() + i) * glass.getWidth() + (coordinator.getXTetraminoFigure() + j);
                    glass.getState()[index] = figure.getTetraminoSquares()[i * figure.getSize() + j].getColor() == '1';
                }
            }

            glass.printOut();
        }
    };
}
