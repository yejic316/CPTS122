#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML\System\Vector2.hpp>
typedef sf::Vector2<int> position;


class Body : public sf::RectangleShape
{
public:
	Body(const sf::Color & color, sf::Vector2f const &size,
		const sf::Vector2f & position)
	{
		this->setFillColor(color);
		this->setSize(size);
		this->setPosition(position);
	}

	Body*& get_next();
private:
	Body* pNext;
};

class Snake
{
public:
	Snake();
	Snake(Body*& new_body);
	//~Snake();

	Body*& get_head();
	Body*& get_tail();
	
	void set_direction(int direction);
	int get_direction();



protected:
	//std::vector<position> snake_body;
	Body* pHead;
	Body* pTail;
	int direction;
};



