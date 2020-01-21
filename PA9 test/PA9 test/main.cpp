#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "food.h"
#include <Windows.h>

using std::cout;
using std::endl;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
	int gameWidth = 100;
	int gameHeight = 100;

	Body bodyPart = Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(150, 250));
	Food food = Food(sf::Color::Magenta, sf::Vector2f(4, 4));
	Snake snake;
	int i = 0;
	bool not_lost = true;

	MessageBoxA(NULL, "Do you want to try again?", "Game Over", MB_OK);
	//TextOut(NULL, 50, 50, (LPCWSTR)"text", 10);
	//MessageBoxW(NULL, (LPCWSTR)"Do you want to try again?", (LPCWSTR)"Game Over", MB_OK);
	while (window.isOpen())
	{
		position direction;
		sf::Event event;
		while (not_lost == true)
		{

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						//pressed = 1;
						direction.x = 0;
						direction.y = -1;
					}
					if (event.key.code == sf::Keyboard::A)
					{
						//pressed = 4;
						direction.x = -1;
						direction.y = 0;
					}
					if (event.key.code == sf::Keyboard::S)
					{
						//pressed = 3;
						direction.x = 0;
						direction.y = 1;
					}
					if (event.key.code == sf::Keyboard::D)
					{
						//pressed = 2;
						direction.x = 1;
						direction.y = 0;
					}

				}


			}
			_sleep(50); //sleep slows it down 
			snake.move(direction); //allows snake to keep moving by itself, b/c calling move every frame
			snake.update(food, not_lost);
			//if (pressed != 0)
			//{
			//	
			//	if (snake.get_head()->get_direction() == 1)
			//	{
			//		//(*snake.get_head()).move(0, -0.1);
			//		
			//		Body *temp = snake.get_head(), *cur = snake.get_head()->get_next();

			//		temp->move(0, -0.05);
			//		snake.updateBody();
			//		while (temp->get_next() != nullptr)
			//		{
			//			temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x, temp->getPosition().y + HeadSize));
			//			
			//			temp->get_next()->set_direction(temp->get_prevDirection());
			//			temp = temp->get_next();						
			//		}		


			//	}
			//	if (snake.get_direction() == 2)
			//	{
			//		//(*snake.get_head()).move(0.1, 0);
			//		
			//		Body *temp = snake.get_head();

			//		temp->move(0.05, 0);
			//		snake.updateBody();

			//		while (temp->get_next() != nullptr)
			//		{
			//			temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x - HeadSize, temp->getPosition().y));
			//			temp->get_next()->set_direction(temp->get_direction());
			//			temp = temp->get_next();
			//		}
			//	}
			//	if (snake.get_direction() == 3)
			//	{
			//		//(*snake.get_head()).move(0, 0.1);
			//		
			//		Body *temp = snake.get_head();

			//		temp->move(0, 0.05);
			//		snake.updateBody();

			//		while (temp->get_next() != nullptr)
			//		{
			//			temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x, temp->getPosition().y - HeadSize));
			//			temp->get_next()->set_direction(temp->get_direction());
			//			temp = temp->get_next();
			//		}
			//	}
			//	if (snake.get_direction() == 4)
			//	{
			//		//(*snake.get_head()).move(-0.1, 0);
			//		//snake.updateBody();
			//		
			//		Body *temp = snake.get_head();

			//		temp->move(-0.05, 0);
			//		snake.updateBody();

			//		while (temp->get_next() != nullptr)
			//		{
			//			temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x + HeadSize, temp->getPosition().y));
			//			temp->get_next()->set_direction(temp->get_direction());
			//			temp = temp->get_next();
			//		}
			//	}
			window.clear();

			//makes window not responsible for drawing food/snake.
			//inverting the dependencies- snake and food know how to draw themselves, instead of window knowing how to draw them
			snake.draw(window);
			food.draw(window);
			window.display();
		}
		window.close();
	}

	return 0;
}


//frame rate
//	-QueryPerformanceCounter
//	-clock() or time()
//scale things on frame time

