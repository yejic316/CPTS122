#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML\System\Vector2.hpp>
#include <time.h>
#include <list>

using std::cout;
using std::endl;

typedef sf::Vector2<int> position;

class particle : public sf::RectangleShape
{
public:

	sf::Vector2f pos;
	sf::Vector2f velocity; //direction and length
	float lifetime;
};


class particleSystem 
{
	std::list<particle*> list;

	void update();
	void draw(sf::RenderWindow &window);
	void explosion(position snake_pos);
};