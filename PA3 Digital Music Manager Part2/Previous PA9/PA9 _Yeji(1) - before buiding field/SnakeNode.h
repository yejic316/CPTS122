#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using std::cout;
using std::endl;

class SnakeNode : public sf::RectangleShape
{
public:
	SnakeNode(const sf::Vector2f & position)
	{
		this->setFillColor(sf::Color::Green);
		this->setSize(sf::Vector2f(16, 16));
		this->setPosition(position);

		pNext = nullptr;
	}
	~SnakeNode()
	{
		cout << "SnakeNode is destroyed!" << endl;
	}



private:
	SnakeNode *pNext;


};