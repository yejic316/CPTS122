#include "particle.h"

//update all the positions for all the objects in our list 
//delete old particles 
void particleSystem::update()
{
	for (auto particle : list) //like a for-each loop
	{
		particle->pos += particle->velocity; //updates x,y positions for pos based on the velocity
	}
}

void particleSystem::draw(sf::RenderWindow &window)
{
	for (auto particle : list)
	{
		particle->setPosition(particle->pos * 5.f); 
		window.draw((*particle)); //drawing each particle
	}
}
//create new particles
void particleSystem::explosion(position snake_pos)
{
	for (int i = 0; i < 69; i++)
	{
		list.push_back(new particle); //adding new particles to list
	}
	for (auto particle : list)
	{
		particle->pos.x = snake_pos.x;
		particle->pos.y = snake_pos.y;
		/*particle->pos.x = 50;
		particle->pos.y = 50;*/
		
		particle->velocity.x = (rand() % 100) /100.f -0.5;
		particle->velocity.y = (rand() % 100) /100.f -0.5;
	}
	
}
