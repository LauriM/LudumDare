#include "Render.h"

void Render::init()
{
	printf("loading resources...");

	if(!texturePlayer.loadFromFile("./gfx/ship.png"))
	{
		printf("error loading resources!");
	}
}

void Render::update()
{
	background();

	//Draw the player


}

void Render::background()
{
	sf::CircleShape shape(1.f);
	shape.setFillColor(sf::Color::White);

	//get reference coordinate
	sf::Vector2f pos(scene->getPlayer()->position.x,scene->getPlayer()->position.y);

	for(int x = 0; x < 100; ++x)
	{
		for(int y = 0; y < 100; ++y)
		{
			shape.setPosition(100*x + pos.x ,100*y + pos.y);
			window->draw(shape);
		}
	}
}