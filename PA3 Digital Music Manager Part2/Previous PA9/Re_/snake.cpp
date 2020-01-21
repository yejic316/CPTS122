#include "snake.h"

//Snake::Snake()
//{
//	pHead = nullptr;
////	pTail = nullptr;
//	this->pHead->set_direction(1);
//}
//
//Snake::Snake(Body *& new_body)
//{
//pHead = new_body;
////pTail = new_body;
//this->pHead->set_direction(1);
////pHead->set_bodyPosition(sf::Vector2f(pHead->getPosition()));
//InsertATEnd();
//
//}
//
//Body*& Snake::get_head()
//{
//	return pHead;
//}
////Body*& Snake::get_tail()
////{
////	return pTail;
////}
//
//void Snake::set_direction(int direction)
//{
//	this->pHead->set_direction(direction);
//}
//
//int Snake::get_direction()
//{
//	return this->pHead->get_direction();
//}
//
//Body::~Body()
//{
//}
//
//Body *& Body::get_next()
//{
//	return this->pNext;
//}
//void  Body::set_next(Body * pNext)
//{
//	this->pNext = pNext;
//}
//
//Body *& Body::get_prev()
//{
//	return pPrev;
//}
//
//void Body::set_prev(Body * pPrev)
//{
//	this->pPrev = pPrev;
//}
//
//int Body::get_direction()
//{
//	return this->direction;
//}
//
//void Body::set_direction(int newDirection)
//{
//	this->direction = newDirection;
//}
//
//sf::Vector2f Body::get_prevPosition()
//{
//	return this->prevPosition;
//}
//
//void Body::set_prevPosition(sf::Vector2f newBodyPosition)
//{
//	this->prevPosition = newBodyPosition;
//}
//
//int Body::get_prevDirection()
//{
//	return prevDirection;
//}
//
//void Body::set_prevDirection(int newDirection)
//{
//	prevDirection = newDirection;
//}
//
//
//void Snake::InsertATEnd()
//{
//	InsertATEnd(get_head());
//
//}
//
//void Snake::updateBody()
//{
//	Body* temp = pHead, *cur = pHead->get_next();
//	int x = 0, x2 = 0;
//	if (cur != nullptr)
//	{
//		x = cur->get_direction();
//		cur->set_direction(temp->get_direction());
//		temp = cur;
//		cur = cur->get_next();
//	}
//	while (cur != nullptr)
//	{
//		x2 = cur->get_direction();
//		cur->set_direction(x);
//		x = x2;
//		temp = cur;
//		cur = cur->get_next();
//	}
//}
//updating: if we ate food (then make snake 1 longer) and move food
//also checks if snake hit itself
void Snake::update(Food &food, bool &not_lost)
{
	for (auto pos : snake_body)
	{
		if (pos == food.pos)
		{
			food.moveRandomly();
			snake_body.push_back(position(-1,-1));
			bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(-1, -1))); //hiding new body part for first "event" then afterwards goes into correct position
		}
	}
	//checking boundaries (only the head)
	if (snake_body[0].x >= 100 || snake_body[0].x < 0)
	{
		not_lost = false;
	}
	if (snake_body[0].y >= 100 || snake_body[0].y < 0)
	{
		not_lost = false;
	}
}

//drawing the rectangle(s) for each snake body part
void Snake::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < snake_body.size(); i++)
	{
		bodyParts[i]->setPosition(sf::Vector2f(snake_body[i] *5));
		window.draw((*bodyParts[i])); //drawing each bodypart
	}
}


void Snake::move(position direction)
{
	if (direction.x == 0 && direction.y == 0)
	{
		return;
	}
	for (int i = snake_body.size(); i >= 1; i--) //dealing with game tiles (0-100) so work with snake_body
	{
		snake_body[i] = snake_body[i - 1];
	}
	snake_body[0] += direction;
}

//void Snake::InsertATEnd(Body *pHead)
//{
//	Body *pCur = pHead, *pMem = nullptr;
//	while (pCur ->get_next()!= nullptr)
//	{
//		pCur = pCur->get_next();
//	}
//
//	if (pCur->get_direction() == 1)
//	{
//		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
//		//pMem->setPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
//		//pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y + HeadSize));
//	}
//	else if (pCur->get_direction() == 2)
//	{
//		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
//		//pMem->setPosition(sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
//		//pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x - HeadSize, pCur->getPosition().y));
//	}
//	else if (pCur->get_direction() == 3)
//	{
//		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
//		//pMem->setPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
//		//pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x, pCur->getPosition().y - HeadSize));
//	}
//	else if (pCur->get_direction() == 4)
//	{
//		pMem = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y) );
//		//pMem->setPosition(sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y));
//		//pMem->set_bodyPosition(sf::Vector2f(pCur->getPosition().x + HeadSize, pCur->getPosition().y));
//	}
//	pMem->set_direction(pCur->get_direction());
//	pCur->set_next(pMem);
//	pMem->set_prev(pCur);
//	//this->pTail = pMem;
//	cout << "added" << endl;
//}
//
