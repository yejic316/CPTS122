#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include<stdlib.h>
#include<time.h>
#include <SFML\System\Vector2.hpp>
typedef sf::Vector2<int> position;

using std::cout;
using std::endl;

class Food : public sf::RectangleShape
{
public:
	Food(const sf::Color &color, sf::Vector2f const &size)
	{
		this->setFillColor(color);
		this->setSize(size);
		moveRandomly(); //calls this so random pos to start with
	}
	~Food(); //destructor

	position pos; //x,y positions
	void draw(sf::RenderWindow &window);
	void moveRandomly();

private:
	//position pos;
};