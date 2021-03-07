#include "TetraminoFigure.h"
using namespace tetramino_figure;

namespace controller
{
	class Rotator
	{
	public:
		static void leftRotate(TetraminoFigure* figure);
		static void rightRotate(TetraminoFigure* figure);
	};
}
