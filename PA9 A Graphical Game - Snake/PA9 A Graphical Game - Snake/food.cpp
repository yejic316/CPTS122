#include "food.h"

Food::~Food()
{
	cout << "in food destrcutor" << endl;
}

void Food::draw(sf::RenderWindow &window)
{
	setPosition(sf::Vector2f(pos * 7));
	window.draw(*this); //draws food
}

void Food::moveRandomly()
{
	//randomly assign x,y positions for the food each time
	srand((unsigned int)time(NULL));
	pos.x = rand() % 71; //game space coordinates
	pos.y = rand() % 71;
}
