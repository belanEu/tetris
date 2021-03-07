#include "TetraminoFigure.h"

namespace tetramino_figure
{
	class JTetraminoFigure : public TetraminoFigure
	{
	public:
		JTetraminoFigure(int size) : TetraminoFigure(size)
		{
			this->figureSquares[1].setColor('1');
			this->figureSquares[4].setColor('1');
			this->figureSquares[6].setColor('1');
			this->figureSquares[7].setColor('1');
		}
	};
}
