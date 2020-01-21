#include "snake.h"

Snake::Snake()
{
	pHead = nullptr;
//	pTail = nullptr;
	this->pHead->set_direction(1);
}

Snake::Snake(Body *& new_body)
{
	pHead = new_body;
	//pTail = new_body;
	this->pHead->set_direction(1);
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
	this->pHead->set_direction(direction);
}

int Snake::get_direction()
{
	return this->pHead->get_direction();
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

Body *& Body::get_prev()
{
	return pPrev;
}

void Body::set_prev(Body * pPrev)
{
	this->pPrev = pPrev;
}

int Body::get_direction()
{
	return this->direction;
}

void Body::set_direction(int newDirection)
{
	this->direction = newDirection;
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

void Snake::updateBody()
{
	Body* temp = pHead;
	while (temp->get_next() != nullptr) {
		temp = temp->get_next();
	}
	while (temp != pHead) {
		temp->set_direction(temp->get_prev.get_direction());
		temp->set_bodyPosition(temp->get_prev.get_bodyPosition());
		temp = temp->get_prev();
	}
}

void Snake::InsertATEnd(Body *pHead)
{
	Body *pCur = pHead, *pMem = nullptr;
	while (pCur ->get_next()!= nullptr)
	{
		pCur = pCur->get_next();
	}

	if (pCur->get_direction() == 1)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
	}
	else if (pCur->get_direction() == 2)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
	}
	else if (pCur->get_direction() == 3)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
	}
	else if (pCur->get_direction() == 4)
	{
		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y) );
		pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y));
	}
	pCur->set_next(pMem);
	pMem->set_prev(pCur);
	//this->pTail = pMem;
	cout << "added" << endl;
}

