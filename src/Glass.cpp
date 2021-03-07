#include "Glass.h"
using namespace glass;

void Glass::initState()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			this->state[i * this->width + j] = false;
		}
	}
}
