#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class ZTetraminoFigure : public TetraminoFigure
	{
	public:
		ZTetraminoFigure(int size) : TetraminoFigure(size)
		{
			for (int i = 0; i < this->size - 1; i++)
			{
				int d = i & 1;
				for (int j = 0 + d; j < this->size - 1 + d; j++)
				{
					this->figureSquares[i * this->size + j].setColor('1');
				}
			}
		}
	};
}
