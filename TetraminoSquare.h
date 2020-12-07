#ifndef TETRAMINO_SQUARE_H
#define TETRAMINO_SQUARE_H

namespace tetramino_figure
{
	/**
	* Class TetraminoSquare describes a part (which is square) of a termino figure (see class TerminoFigure).
	*/
	class TetraminoSquare
	{
	protected:
		int x,
			y;
		unsigned char color;

	public:
		TetraminoSquare()
		{
			this->x = 0;
			this->y = 0;
			this->color = '0';
		}

		TetraminoSquare(int x, int y, unsigned char color = '0')
		{
			this->x = x;
			this->y = y;
			this->color = color;
		};

		int getX()
		{
			return this->x;
		};

		int getY()
		{
			return this->y;
		};

		unsigned char getColor()
		{
			return this->color;
		};

		void setSettings(int x, int y, unsigned char color = '0')
		{
			this->x = x;
			this->y = y;
			this->color = color;
		};

		void setX(int x)
		{
			this->x = x;
		};

		void setY(int y)
		{
			this->y = y;
		};

		void setColor(unsigned char color)
		{
			this->color = color;
		};
	};
}

#endif
