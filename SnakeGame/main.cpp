#include <SFML/Graphics.hpp>
#include <time.h>
#include "snake.h"
#include "food.h"
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
#include <string>
#include <windows.h>

using std::cout;
using std::endl;
using sf::Text;
using std::string;

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Snake Game");
	int gameWidth = 100; //for game screen (snake_body)
	int gameHeight = 100;

	Food food = Food(sf::Color::Magenta, sf::Vector2f(7, 7));
	Snake snake;
	int gameScore = 0; //overall game score
	bool not_lost = true, started = false, check = false;

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
			Sleep(50); //sleep slows it down 
			snake.move(direction); //allows snake to keep moving by itself, b/c calling move every frame
			//update() updates the gameScore as well
			snake.update(food, not_lost, started, gameScore); //updates not_lost in this function too
			
			window.clear();

			//makes window not responsible for drawing food/snake.
			//inverting the dependencies- snake and food know how to draw themselves, instead of window knowing how to draw them
			snake.draw(window);
			food.draw(window);

			sf::Font font;
			font.loadFromFile("Arial.ttf"); // Declare and load a font
			sf::Text text("Score: ", font); // Create a text
			sf::Text text2("", font);
			text2.setString(std::to_string(gameScore)); //converting gameScore to string so it can be printed to screen 
			text.setCharacterSize(16);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::White);
			text2.setCharacterSize(16);
			text2.setStyle(sf::Text::Bold);
			text2.setFillColor(sf::Color::White);
			text.setPosition(5, 480);
			text2.setPosition(65, 480);
			window.draw(text); //draw it
			window.draw(text2); //draw it 

			window.display();
			
			if (not_lost == false)
			{
				int option = MessageBoxA(NULL, "Woudld you like to play again?!", "GAME OVER!", MB_RETRYCANCEL); //displays after game is over
				if (option == 2) //players hits cancel button
				{
					check = true;
				}
				else //player hits retry button
				{
					not_lost = true;
					gameScore = 0; //reset the game score back to 0
					snake.reset(); //resets snake
					direction.x = 0;
					direction.y = 0;
				}

			}
		}
		if (check == true)
		{
			window.close(); //closes window when we hit boundaries, etc (game over)
		}
		
		
	}
	return 0;
}

