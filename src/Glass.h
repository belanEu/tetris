#ifndef HEADER_GLASS_H
#define HEADER_GLASS_H

#include "TetraminoFigure.h"
using namespace tetramino_figure;

namespace glass
{
	class Glass
	{
	protected:
		int width,
			height;
		bool* state = nullptr;

    public:
		Glass(int width, int height)
		{
			this->width = width;
			this->height = height;
			this->state = new bool[width * height];
			this->initState();
		};

		int getWidth()
		{
			return this->width;
		};

		int getHeight()
		{
			return this->height;
		};

		bool* getState()
		{
		    return this->state;
		}

		void setIntoState(int index, bool value)
		{
		    this->state[index] = value;
		}

    protected:
		void initState();
	};
}

#endif // HEADER_GLASS_H
