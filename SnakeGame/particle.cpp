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

}
