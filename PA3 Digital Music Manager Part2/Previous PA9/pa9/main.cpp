#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "food.h"
using std::cout;
using std::endl;


int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
	//sf::RectangleShape head(sf::Vector2f(50, 50)); //sets size of head of snake
	//head.setFillColor(sf::Color::Green); //sets color of snake to green
	//head.setPosition(150, 250); //sets starting position of snake
	
	/*sf::Time stop_time = sf::seconds(10.0f);
	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	float sec = time.asSeconds(); */

	time_t timer;
	struct tm time = { 0 };

	
	Body *body = new Body(sf::Color::Green, sf::Vector2f(10, 10), sf::Vector2f(150, 250));
	Body bodyPart = Body(sf::Color::Green, sf::Vector2f(10, 10), sf::Vector2f(150, 250));
	Snake snake(body);
	bool pressed = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (!pressed && event.key.code == sf::Keyboard::W)
				{
					pressed = true;
					snake.set_direction(1);
				}
				if (!pressed && event.key.code == sf::Keyboard::A)
				{
					pressed = true;
					snake.set_direction(4);
				}
				if (!pressed && event.key.code == sf::Keyboard::S)
				{
					pressed = true;
					snake.set_direction(3);
				}
				if (!pressed && event.key.code == sf::Keyboard::D)
				{
					pressed = true;
					snake.set_direction(2);
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (pressed && event.key.code == sf::Keyboard::W)
				{
					pressed = false;
				}
				if (pressed && event.key.code == sf::Keyboard::A)
				{
					pressed = false;
				}
				if (pressed && event.key.code == sf::Keyboard::S)
				{
					pressed = false;
				}
				if (pressed && event.key.code == sf::Keyboard::D)
				{
					pressed = false;
				}

			}
		}
		
		cout << "Time: " << sec << endl;

		if(time >= stop_time)
		//if (pressed == true)
		{
			
			if (snake.get_direction() == 1)
			{
				(*snake.get_head()).move(0, -0.1);
			}
			if (snake.get_direction() == 2)
			{
				(*snake.get_head()).move(0.1, 0);
			}
			if (snake.get_direction() == 3)
			{
				(*snake.get_head()).move(0, 0.1);
			}
			if (snake.get_direction() == 4)
			{
				(*snake.get_head()).move(-0.1, 0);
			}
			//time = clock.restart();
		}

		
		//cout << "Direction: " << snake.get_direction() << endl;
		Body *temp = snake.get_head();
		while (temp != nullptr)
		{
			window.clear();
			window.draw((*temp));
			temp = temp->get_next();
		}
		window.display();
	}


	return 0;
}


//frame rate
//	-QueryPerformanceCounter
//	-clock() or time()
//scale things on frame time

