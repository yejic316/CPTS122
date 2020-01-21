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

#define HeadSize 7
 
//body class for snake
class Body : public sf::RectangleShape
{
public:
	Body(const sf::Color & color, sf::Vector2f const &size, const sf::Vector2f & position)
	{
		this->setFillColor(color);
		this->setSize(size);
		this->setPosition(position);
	}
};

//main class for snake
class Snake 
{
public:
	Snake()
	{
		//creates the head
		snake_body.push_back(position(0, 0));
		bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(0, 0)));
	}
	~Snake();
	position getHead(); //returns position of snake head (used for explosions)

	void update(Food &food, bool &not_lost, bool started, int &score);
	void draw(sf::RenderWindow &window);
	void move(position direction);
	void reset();


protected:
	std::vector<position> snake_body; //using game space
	std::vector<Body*> bodyParts; //using window space/screen
};



