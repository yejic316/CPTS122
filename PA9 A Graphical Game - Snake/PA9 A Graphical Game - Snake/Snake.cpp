#include "snake.h"

Snake::~Snake()
{
	cout << "in snake destructor" << endl;
	
}

position Snake::getHead()
{
	return snake_body[0];
}

//updating: if we ate food (then make snake 1 longer) and move food
//also checks if snake hit itself
void Snake::update(Food &food, bool &not_lost, bool started, int &score)
{
	for (auto pos : snake_body)
	{
		//did it this way so snake does not need to be directly on top of food in order to eat it
		if ((pos.x == food.pos.x && pos.y == food.pos.y))
		{
			score += 1;
			food.moveRandomly();
			//add 3 body parts each time
			/*
			snake_body.push_back(position(-1, -1));
			bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(0, 0)));
			snake_body.push_back(position(-2, -2));
			bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(-2, -2)));
			snake_body.push_back(position(-3, -3));
			bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(-3, -3)));
	*/
		}
			
		//else if((pos.x+7 <= food.pos.x + 7 && pos.x >= food.pos.x) && (pos.y <= food.pos.y + 7 && pos.y >= food.pos.y))
		//{
		//	score += 1;
		//	food.moveRandomly();

		//	//add 3 body parts each time
		//	/*snake_body.push_back(position(-1, -1));
		//	bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(-1, -1)));
		//	snake_body.push_back(position(-2, -2));
		//	bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(-2, -2)));
		//	snake_body.push_back(position(-3, -3));
		//	bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(-3, -3)));
		//	*/
		//}
	}
	//checking boundaries (only the head)
	if (snake_body[0].x >= 71 || snake_body[0].x < 0)
	{
		not_lost = false;
	}
	if (snake_body[0].y >= 71 || snake_body[0].y < 0)
	{
		not_lost = false;
	}

	//checking if snake hit itself
	if (started == true)
	{
		for (int i = 1; i < snake_body.size(); i++)
		{
			if (snake_body[0].x == snake_body[i].x && snake_body[0].y == snake_body[i].y)
			{
				not_lost = false;
			}
		}
	}
}

//drawing the rectangle(s) for each snake body part
void Snake::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < snake_body.size(); i++)
	{
		bodyParts[i]->setPosition(sf::Vector2f(snake_body[i] *7));
		window.draw((*bodyParts[i])); //drawing each bodypart
	}
}

void Snake::move(position direction)
{
	if (direction.x == 0 && direction.y == 0)
	{
		return;
	}
	for (int i = snake_body.size()-1; i >= 1; i--) //dealing with game tiles (0-100) so work with snake_body
	{
		snake_body[i] = snake_body[i - 1]; //moving all body parts except for the head
	}
	snake_body[0] += direction;
}

void Snake::reset()
{
	for (int i = 0; i < bodyParts.size(); i++)
	{
		delete bodyParts[i];
	}
	bodyParts.clear();
	snake_body.clear();

	//recreates the head
	snake_body.push_back(position(0, 0));
	bodyParts.push_back(new Body(sf::Color::Green, sf::Vector2f(7, 7), sf::Vector2f(0, 0)));
}

