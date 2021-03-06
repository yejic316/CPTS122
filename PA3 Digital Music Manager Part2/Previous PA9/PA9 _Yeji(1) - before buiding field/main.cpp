#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "food.h"
using std::cout;
using std::endl;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");

	Body *body = new Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(150, 250));
	Body bodyPart = Body(sf::Color::Green, sf::Vector2f(13, 13), sf::Vector2f(150, 250));
	Food food = Food(sf::Color::Magenta, sf::Vector2f(7, 7));
	food.set_position();
	Snake snake(body);
	int pressed = 0, i=0;
	bool not_lost = true;
	//Body *temp = snake.get_head();


	while (window.isOpen())
	{
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
					if (pressed != 1 && event.key.code == sf::Keyboard::W)
					{
						pressed = 1;
						snake.set_direction(1);
					}
					if (pressed != 4 && event.key.code == sf::Keyboard::A)
					{
						pressed = 4;
						snake.set_direction(4);
					}
					if (pressed != 3 && event.key.code == sf::Keyboard::S)
					{
						pressed = 3;
						snake.set_direction(3);
					}
					if (pressed != 2 && event.key.code == sf::Keyboard::D)
					{
						pressed = 2;
						snake.set_direction(2);
					}
				}
			}
			if (pressed != 0)
			{
				if (snake.get_direction() == 1)
				{
					//(*snake.get_head()).move(0, -0.1);
					Body *temp = snake.get_head();

					temp->move(0, -0.1);
					while (temp->get_next() != nullptr)
					{
						//temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x, temp->getPosition().y + HeadSize));
						temp->get_next()->set_bodyPosition(temp->get_bodyPosition());
						temp = temp->get_next();
					}		

				}
				if (snake.get_direction() == 2)
				{

					//(*snake.get_head()).move(0.1, 0);
					Body *temp = snake.get_head();

					temp->move(0.1, 0);
					while (temp->get_next() != nullptr)
					{
						//temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x - HeadSize, temp->getPosition().y));
						temp->get_next()->set_bodyPosition(temp->get_bodyPosition());

						temp = temp->get_next();
					}
				}
				if (snake.get_direction() == 3)
				{
					//(*snake.get_head()).move(0, 0.1);
					Body *temp = snake.get_head();

					temp->move(0, 0.1);
					while (temp->get_next() != nullptr)
					{
						//temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x, temp->getPosition().y - HeadSize));
						temp->get_next()->set_bodyPosition(temp->get_bodyPosition());

						temp = temp->get_next();
					}
				}
				if (snake.get_direction() == 4)
				{
					//(*snake.get_head()).move(-0.1, 0);
					Body *temp = snake.get_head();

					temp->move(-0.1, 0);
					while (temp->get_next() != nullptr)
					{
						//temp->get_next()->setPosition(sf::Vector2f(temp->getPosition().x + HeadSize, temp->getPosition().y));
						temp->get_next()->set_bodyPosition(temp->get_bodyPosition());
						temp = temp->get_next();
					}
				}

			}

			//getting the food
			if ( (snake.get_head()->getPosition().x <= food.getPosition().x && (snake.get_head()->getPosition().x + HeadSize) >= food.getPosition().x )
				&& (snake.get_head()->getPosition().y <= food.getPosition().y && (snake.get_head()->getPosition().y +HeadSize) >= food.getPosition().y) )
			{
				srand((unsigned int)time(NULL));
				int x_pos = rand() % 500 + 1;
				int y_pos = rand() % 500 + 1;
				food.setPosition(x_pos, y_pos);
				cout << "SKIGFH RKLU GLRE" << endl;
				snake.InsertATEnd();
			}

			window.clear();

			Body *temp = snake.get_head();
			while (temp != nullptr )
			{
				window.draw(*temp);
				//window.draw(*temp->get_next());
				temp = temp->get_next();
			}

			
			if (((*snake.get_head()).getPosition().x + (*snake.get_head()).getSize().x) >= window.getSize().x)
			{
				not_lost = false;
				cout << "GAME OVER" << endl;
			}
			else if ((*snake.get_head()).getPosition().x <= 0)
			{
				not_lost = false;
				cout << "GAME OVER" << endl;
			}
			if (((*snake.get_head()).getPosition().y + (*snake.get_head()).getSize().y) >= window.getSize().y)
			{
				not_lost = false;
				cout << "GAME OVER" << endl;
			}
			else if ((*snake.get_head()).getPosition().y <= 0)
			{
				not_lost = false;
				cout << "GAME OVER" << endl;
			}
			window.draw(food);
			window.display();
		}
	}

	return 0;
}


//frame rate
//	-QueryPerformanceCounter
//	-clock() or time()
//scale things on frame time

