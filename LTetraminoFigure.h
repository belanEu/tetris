#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class LTetraminoFigure : public TetraminoFigure
	{
	public:
		LTetraminoFigure(int size) : TetraminoFigure(size)
		{
			this->figureSquares[1].setColor('1');
			this->figureSquares[4].setColor('1');
			this->figureSquares[7].setColor('1');
			this->figureSquares[8].setColor('1');
		}
	};
}
