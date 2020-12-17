#include "Glass.h"
using namespace glass;

void Glass::printOut()
{
    cout << ' ';
    for (int i = 1; i < this->width - 1; i++)
    {
        cout << ' ' << i << ' ';
    }
    cout << ' ' << endl;

	for (int i = 1; i < this->height - 1; i++)
	{
		cout << '|';
		for (int j = 1; j < this->width - 1; j++)
		{
			cout << ' ' << this->state[i * this->width + j] << ' ';
		}
		cout << '|';

		cout << endl;
	}
	cout << '|';
	for (int j = 1; j < this->width - 1; j++)
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
