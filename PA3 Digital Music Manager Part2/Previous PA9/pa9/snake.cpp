#include "snake.h"

Snake::Snake()
{
	pHead = nullptr;
	pTail = nullptr;
	this->direction = 1;
}

Snake::Snake(Body *& new_body)
{
	pHead = new_body;
	pTail = new_body;
	this->direction = 1;
}

Body*& Snake::get_head()
{
	return pHead;
}
Body*& Snake::get_tail()
{
	return pTail;
}

void Snake::set_direction(int direction)
{
	this->direction = direction;
}

int Snake::get_direction()
{
	return this->direction;
}

Body *& Body::get_next()
{
	return pNext;
}
