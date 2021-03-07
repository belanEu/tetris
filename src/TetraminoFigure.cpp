#include "TetraminoFigure.h"
using namespace tetramino_figure;

void TetraminoFigure::initializeFigure()
{
	for (int i = 0; i < this->size * this->size; i++)
	{
		this->figureSquares[i].setSettings(int(i / this->size), int(i % this->size));
	}
}
