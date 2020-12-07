#include "Glass.h"
using namespace glass;

void Glass::printOut()
{
	for (int i = 0; i < this->height; i++)
	{
		cout << '|';
		for (int j = 0; j < this->width; j++)
		{
			cout << ' ' << this->state[i * this->width + j] << ' ';
		}
		cout << '|';

		cout << endl;
	}
	cout << '|';
	for (int j = 0; j < this->width; j++)
	{
		cout << "___";
	}
	cout << '|';
}

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
