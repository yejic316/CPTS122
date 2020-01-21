#include "food.h"

void Food::draw(sf::RenderWindow &window)
{
	
	setPosition(sf::Vector2f(pos * 5));
	window.draw(*this);
}

void Food::moveRandomly()
{
	srand((unsigned int)time(NULL));
	pos.x = rand() % 100; //game space coordinates
	pos.y = rand() % 100;
}
