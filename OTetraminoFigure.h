#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class OTetraminoFigure : public TetraminoFigure
	{
	public:
		OTetraminoFigure(int size) : TetraminoFigure(size)
		{
			for (int i = 0; i < this->size; i++)
			{
				for (int j = 0; j < this->size; j++)
				{
					this->figureSquares[i * this->size + j].setColor('1');
				}
			}
		}
	};
}
