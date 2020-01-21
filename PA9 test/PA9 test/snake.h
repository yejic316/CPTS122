#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML\System\Vector2.hpp>
#include <time.h>
#include "food.h"


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
	}

private:

};

class Snake
{
public:
	Snake()
	{
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(0, 0)));
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(0, 0)));
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(0, 0)));
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(0, 0)));
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(4, 4), sf::Vector2f(0, 0)));

	}
	//~Snake();

	//Body*& get_head();
	////Body*& get_tail();

	//void set_direction(int direction);
	//int get_direction();

	//void InsertATEnd();
	////void drawSnake();
	//void updateBody();

	////////////////////////////
	void update(Food &food, bool &not_lost);
	void draw(sf::RenderWindow &window);
	void move(position direction);


protected:
	std::vector<position> snake_body; //using game space
	std::vector<Body*> bodyParts; //using window space/screen
};



