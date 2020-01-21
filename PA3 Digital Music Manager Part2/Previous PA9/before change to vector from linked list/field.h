#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class field
{
public:
	field();
	~field();
	sf::Vector2f get_field();
//	void set_field(sf::Vector2f newarr);
private:
	sf::Vector2f arr[38][38];


};
