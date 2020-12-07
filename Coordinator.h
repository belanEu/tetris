#ifndef HEADER_COORDINATOR_H
#define HEADER_COORDINATOR_H

namespace controller
{
    /*
     TODO: maybe its need to hold the previous coordinates of the tetramino figure
     just to clear the figure presentation in glass state by them.
     */
    class Coordinator
    {
    protected:
        int xTetraminoFigure, yTetraminoFigure;
        int tetraminoFigureSize, glassWidth, glassHeight;

    public:
        Coordinator(int glassWidth, int glassHeight)
        {
            this->glassWidth = glassWidth;
            this->glassHeight = glassHeight;
            this->xTetraminoFigure = this->yTetraminoFigure = this->tetraminoFigureSize = 0;
        }

        int getXTetraminoFigure()
        {
            return this->xTetraminoFigure;
        }

        int getYTetraminoFigure()
        {
            return this->yTetraminoFigure;
        }

        void setTetraminoFigureSize(int size)
        {
            this->tetraminoFigureSize = size;
        }

        void setXTetraminoFigure(int x);
        void setYTetraminoFigure(int y);
    };
}

#endif // HEADER_COORDINATOR_H
