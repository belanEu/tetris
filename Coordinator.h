namespace controller
{
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
