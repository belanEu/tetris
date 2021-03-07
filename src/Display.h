#include "Glass.h"
#include "Coordinator.h"
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

		static void displayFigureCoordinates(Coordinator coordinator)
		{
		    cout << "Figure x: " << coordinator.getXTetraminoFigure() << ", y: " << coordinator.getYTetraminoFigure();
		}

		static void displayGlass(Glass glassInstance)
		{
		    cout << "    ";
            for (int i = 1; i < glassInstance.getWidth() - 1; i++)
            {
                cout << ' ' << i << ' ';
            }
            cout << ' ' << endl;

            for (int i = 1; i < glassInstance.getHeight() - 1; i++)
            {
                if (i < 10)
                {
                    cout << ' ';
                }
                cout << i << " |";
                for (int j = 1; j < glassInstance.getWidth() - 1; j++)
                {
                    cout << ' ' << glassInstance.getState()[i * glassInstance.getWidth() + j] << ' ';
                }
                cout << '|';

                cout << endl;
            }
            cout << "   |";
            for (int j = 1; j < glassInstance.getWidth() - 1; j++)
            {
                cout << "___";
            }
            cout << '|';
		}

		static void displayGlassParameters(Glass glassInstance)
		{
		    cout << "Glass width: " << glassInstance.getWidth() << ", height: " << glassInstance.getHeight();
		}

		static void displayGameIteration(Glass glassInstance, Coordinator coordinator)
		{
		    Display::displayGlassParameters(glassInstance);
		    cout << endl;
		    Display::displayFigureCoordinates(coordinator);
		    cout << "\n\n";
		    Display::displayGlass(glassInstance);
		    cout << "\n\n\n";
		}
	};
}
