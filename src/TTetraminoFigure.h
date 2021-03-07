#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class TTetraminoFigure : public TetraminoFigure
	{
	public:
		TTetraminoFigure(int size) : TetraminoFigure(size)
		{
			for (int i = 0; i < this->size; i++)
			{
				this->figureSquares[int(this->size / 2) * this->size + i].setColor('1');
			}
			this->figureSquares[(this->size - 1) * this->size + int(this->size / 2)].setColor('1');
		}
	};
}
