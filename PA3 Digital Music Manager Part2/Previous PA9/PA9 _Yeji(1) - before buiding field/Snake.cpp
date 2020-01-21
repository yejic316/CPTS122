#include "snake.h"

Snake::Snake()
{
	pHead = nullptr;
//	pTail = nullptr;
	this->direction = 1;
}

Snake::Snake(Body *& new_body)
{
	pHead = new_body;
	//pTail = new_body;
	this->direction = 1;
	pHead->set_bodyPosition(sf::Vector2f(pHead->getPosition()));
	InsertATEnd();

}

Body*& Snake::get_head()
{
	return pHead;
}
//Body*& Snake::get_tail()
//{
//	return pTail;
//}

void Snake::set_direction(int direction)
{
	this->direction = direction;
}

int Snake::get_direction()
{
	return this->direction;
}

Body::~Body()
{
}

Body *& Body::get_next()
{
	return this->pNext;
}
void  Body::set_next(Body * pNext)
{
	this->pNext = pNext;
}

sf::Vector2f Body::get_bodyPosition()
{
	return this->bodyPosition;
}

void Body::set_bodyPosition(sf::Vector2f newBodyPosition)
{
	this->bodyPosition = newBodyPosition;
}


void Snake::InsertATEnd()
{
	InsertATEnd(get_head());

}
/*
void Snake::drawSnake()
{
	Body *pCur = this->get_head();
	while (pCur != nullptr)
	{
		window.clear();
		window.draw(*temp);
		//window.draw(*temp->get_next());
		cout << "how many body" << endl;
		temp = temp->get_next();
	}
}
*/
void Snake::pop()
{
}

void Snake::InsertATEnd(Body *pHead)
{
	Body *pCur = pHead, *pMem = nullptr;
	while (pCur ->get_next()!= nullptr)
	{
		pCur = pCur->get_next();
	}

	if (this->get_direction() == 1)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
	}
	else if (this->get_direction() == 2)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
	}
	else if (this->get_direction() == 3)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
	}
	else if (this->get_direction() == 4)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y) );
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y));
	}
	pCur->set_next(pMem);
	//this->pTail = pMem;
	cout << "added" << endl;
}

