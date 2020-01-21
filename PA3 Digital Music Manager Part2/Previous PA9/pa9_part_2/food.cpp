#include "food.h"



void Food::set_position()
{
	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> x_dist(0, 500);
	//std::uniform_int_distribution<int> y_dist(0, 500);
	//
	//this->x_pos = x_dist(generator);
	//this->y_pos = y_dist(generator);
	srand((unsigned int)time(NULL));
	x_pos = rand() % 500;
	y_pos = rand() % 500;
	this->setPosition(sf::Vector2f(x_pos, y_pos));
}
