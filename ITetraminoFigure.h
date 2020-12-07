#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class ITetraminoFigure : public TetraminoFigure
	{
	public:
		ITetraminoFigure(int size) : TetraminoFigure(size)
		{
			for (int i = 0; i < this->size; i++)
			{
				this->figureSquares[i * this->size + int(this->size / 2)].setColor('1');
			}
		}
	};
}
