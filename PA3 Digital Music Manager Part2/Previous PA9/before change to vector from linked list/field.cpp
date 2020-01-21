#include "field.h"

field::field()
{
	int x = 3, y = 3;
	for (int i = 0; i < 38; ++i)
	{
		for (int j = 0; j < 38; ++j)
		{
			arr[i][j].x = x;
			arr[i][j].y = y;

			x = x + 13;
		}
		x = 3;
		y = y + 13;
	}
}

field::~field()
{

}
/*
sf::Vector2f field::get_field()
{
//	return this->arr;
}
*/

