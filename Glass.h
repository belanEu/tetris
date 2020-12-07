#ifndef HEADER_GLASS_H
#define HEADER_GLASS_H

#include "TetraminoFigure.h"
using namespace tetramino_figure;

namespace glass
{
	class Glass
	{
	private:
		int width,
			height;
		bool* state;

	public:
		Glass(int width, int height)
		{
			this->width = width;
			this->height = height;
			this->state = new bool[width * height];
			this->initState();
		};

		~Glass()
		{
		    delete[] this->state;
		}

		int getWidth()
		{
			return this->width;
		};

		int getHeight()
		{
			return this->height;
		};

		void initState();

		void printOut();
	};
}

#endif // HEADER_GLASS_H
