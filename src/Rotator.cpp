#include "Rotator.h"
using namespace controller;

void Rotator::leftRotate(TetraminoFigure* figure)
{
	int size = figure->getSize();
	int jEnd, amountOfLevels = jEnd = int(size / 2);

	for (int level = 0; level < amountOfLevels; level++)
	{
		char temp;
		int notLastLevel = int(level != int(size));
		for (int j = level; j < jEnd + notLastLevel; j++)
		{
			temp = figure->getTetraminoSquares()[(size - level - 1) * size + (size - j - 1)].getColor();

			figure->getTetraminoSquares()[(size - level - 1) * size + (size - j - 1)]
				.setColor(
					figure->getTetraminoSquares()[(size - j - 1) * size + level].getColor()
				);

			figure->getTetraminoSquares()[(size - j - 1) * size + level]
				.setColor(
					figure->getTetraminoSquares()[level * size + j].getColor()
				);

			figure->getTetraminoSquares()[level * size + j]
				.setColor(
					figure->getTetraminoSquares()[j * size + (size - level - 1)].getColor()
				);

			figure->getTetraminoSquares()[j * size + (size - level - 1)].setColor(temp);
		}
	}
}

void Rotator::rightRotate(TetraminoFigure* figure)
{
	int size = figure->getSize();
	int jEnd, amountOfLevels = jEnd = int(size / 2);

	for (int level = 0; level < amountOfLevels; level++)
	{
		char temp;
		int notLastLevel = int(level != int(size));
		for (int j = level; j < jEnd + notLastLevel; j++)
		{
			temp = figure->getTetraminoSquares()[level * size + j].getColor();

			figure->getTetraminoSquares()[level * size + j]
				.setColor(
					figure->getTetraminoSquares()[(size - j - 1) * size + level].getColor()
				);

			figure->getTetraminoSquares()[(size - j - 1) * size + level]
				.setColor(
					figure->getTetraminoSquares()[(size - level - 1) * size + (size - j - 1)].getColor()
				);

			figure->getTetraminoSquares()[(size - level - 1) * size + (size - j - 1)]
				.setColor(
					figure->getTetraminoSquares()[j * size + (size - level - 1)].getColor()
				);

			figure->getTetraminoSquares()[j * size + (size - level - 1)].setColor(temp);
		}
	}
}
