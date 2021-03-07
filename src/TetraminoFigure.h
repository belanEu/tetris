#ifndef TETRAMINO_FIGURE_H
#define TETRAMINO_FIGURE_H

#include "TetraminoSquare.h"
#include <iostream>
using namespace std;

namespace tetramino_figure
{
	class TetraminoFigure
	{
	protected:
		int size;
		TetraminoSquare* figureSquares = nullptr;

	protected:
		void initializeFigure();

	public:
		TetraminoFigure(int size)
		{
			this->size = size;
			this->figureSquares = new TetraminoSquare[size * size];
		}

		int getSize()
		{
			return this->size;
		}

		TetraminoSquare* getTetraminoSquares()
		{
			return this->figureSquares;
		}
	};
}

#endif // !TETRAMINO_FIGURE_H
