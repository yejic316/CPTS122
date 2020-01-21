#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "food.h"
#include "particle.h"
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
#include <string>
#include <windows.h>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using sf::Text;
using std::string;
using std::fstream;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
	int gameWidth = 100; //for game screen (snake_body)
	int gameHeight = 100;

	Food food = Food(sf::Color::Magenta, sf::Vector2f(7, 7));
	Snake snake;
	particleSystem particle;
	int gameScore = 0; //overall game score
	bool not_lost = true, started = false, check = false;
	int highestScore = 0; //highest gameScore EVER!!!!!!!
	fstream filestream;

	filestream.open("highestScore.txt");
	if (filestream.is_open())
	{
		while (!filestream.eof())
		{
			filestream >> highestScore;
		}
		filestream.close();
	}

	while (window.isOpen())
	{
		position direction; //keeps track of direction(s) of snake
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
					if (event.key.code == sf::Keyboard::W && direction.y != 1)
					{
						started = true;
						direction.x = 0;
						direction.y = -1;
					}
					if (event.key.code == sf::Keyboard::A && direction.x != 1)
					{
						started = true;
						direction.x = -1;
						direction.y = 0;
					}
					if (event.key.code == sf::Keyboard::S && direction.y != -1)
					{
						started = true;
						direction.x = 0;
						direction.y = 1;
					}
					if (event.key.code == sf::Keyboard::D && direction.x != -1)
					{
						started = true;
						direction.x = 1;
						direction.y = 0;
					}
				}
			}
			_sleep(50); //sleep slows it down 
			snake.move(direction); //allows snake to keep moving by itself, b/c calling move every frame
			//update() updates the gameScore as well
			snake.update(food, not_lost, started, gameScore); //updates not_lost in this function too
			particle.update();

			window.clear();

			//makes window not responsible for drawing food/snake.
			//inverting the dependencies- snake and food know how to draw themselves, instead of window knowing how to draw them
			snake.draw(window);
			food.draw(window);
			//particle.draw(window);

			if (gameScore > highestScore)
			{
				highestScore = gameScore;
				filestream.open("highestScore.txt", 'w');
				if (filestream.is_open())
				{
					filestream << highestScore;
					filestream.close();
				}
			}


			sf::Font font;
			font.loadFromFile("Arial Bold.ttf"); // Declare and load a font
			sf::Text text("Score: ", font); // Create a text
			sf::Text text2("", font);
			sf::Text text3("High Score: ", font);
			sf::Text text4("", font);
			text2.setString(std::to_string(gameScore)); //converting gameScore to string so it can be printed to screen 
			text4.setString(std::to_string(highestScore)); //converting highestScore to string
			text.setCharacterSize(16);
			text.setStyle(sf::Text::Bold);
			text.setColor(sf::Color::White);
			text2.setCharacterSize(16);
			text2.setStyle(sf::Text::Bold);
			text2.setColor(sf::Color::White);
			text3.setCharacterSize(16);
			text3.setStyle(sf::Text::Bold);
			text3.setColor(sf::Color::White);
			text4.setCharacterSize(16);
			text4.setStyle(sf::Text::Bold);
			text4.setColor(sf::Color::White);
			text.setPosition(5, 482);
			text2.setPosition(65, 482);
			text3.setPosition(370, 482);
			text4.setPosition(473, 482);
			window.draw(text); //draw it
			window.draw(text2); //draw it 
			window.draw(text3); //draw it 
			window.draw(text4); //draw it 

			window.display();
			
			
		}

		position snakepos = snake.getHead();
		particle.explosion(snakepos);
		for (int i = 0; i <= 100; i++)
		{
			window.clear();
			particle.draw(window);
			window.display();
			particle.update();
			_sleep(15);
		}
		window.clear();
		if (not_lost == false)
		{
			int option = MessageBoxA(NULL, "Would you like to play again?!", "GAME OVER!", MB_RETRYCANCEL); //displays after game is over
			if (option == 2) //players hits cancel button
			{
				check = true;
			}
			else //player hits retry button
			{
				not_lost = true;
				gameScore = 0; //reset the game score back to 0
				snake.reset(); //resets snake
							   //reset the direction for the snake head
				direction.x = 0;
				direction.y = 0;
			}
		}
		if (check == true)
		{
			window.close(); //closes window when we hit boundaries, etc (game over)
		}
		
		
	}
	return 0;
}

