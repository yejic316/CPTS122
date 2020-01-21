#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML\System\Vector2.hpp>
#include <time.h>

using std::cout;
using std::endl;

typedef sf::Vector2<int> position;

#define HeadSize 13


class Body : public sf::RectangleShape
{
public:
	Body(const sf::Color & color, sf::Vector2f const &size, const sf::Vector2f & position)
	{
		this->setFillColor(color);
		this->setSize(size);
		this->setPosition(position);
		
		pNext = nullptr;
	}
	~Body();
	Body*& get_next();
	void set_next(Body *pNext);
	sf::Vector2f get_bodyPosition();
	void set_bodyPosition(sf::Vector2f newBodyPosition);
private:
	Body* pNext;
	sf::Vector2f bodyPosition;// specific point of body 
};

class Snake
{
public:
	Snake();
	Snake(Body*& new_body);
	//~Snake();

	Body*& get_head();
	//Body*& get_tail();

	void set_direction(int direction);
	int get_direction();

	void InsertATEnd();
	//void drawSnake();
	void pop();

protected:
	//std::vector<position> snake_body;
	Body* pHead;
	//Body* pTail;
	int direction;

	void InsertATEnd(Body *pHead);
};



