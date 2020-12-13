#include "TetraminoFigure.h"
#include "Glass.h"
using namespace tetramino_figure;
using namespace glass;

namespace controller
{
	class Display
	{
	public:
		static void displayFigure(TetraminoFigure figure)
		{
			for (int i = 0; i < figure.getSize(); i++)
			{
				for (int j = 0; j < figure.getSize(); j++)
				{
					cout << ' ' << figure.getTetraminoSquares()[i * figure.getSize() + j].getColor() << ' ';
				}
				cout << endl;
			}
		}

		/*static void displayGlass(Glass* glass)
		{
		    for (int i = 0; i < glass->getHeight(); i++)
            {
                for (int j = 0; j < glass->getWidth(); j++)
                {

                }
            }
		}*/
	};
}
