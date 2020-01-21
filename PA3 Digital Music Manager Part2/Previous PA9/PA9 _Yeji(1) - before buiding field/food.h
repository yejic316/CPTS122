#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include<stdlib.h>
#include<time.h>
#include <SFML\System\Vector2.hpp>
typedef sf::Vector2<int> position;
//std::default_random_engine generator;
//std::uniform_int_distribution<int> x_dist(0, 500);
//std::uniform_int_distribution<int> y_dist(0, 500);

class Food : public sf::RectangleShape
{
public:
	Food(const sf::Color &color, sf::Vector2f const &size)
	{
		this->setFillColor(color);
		this->setSize(size);
		/*this->x_pos = x_dist(generator);
		this->y_pos = y_dist(generator);
		this->setPosition(sf::Vector2f(x_pos, y_pos));*/
	}


	void set_position();

private:
	int x_pos;
	int y_pos;
};