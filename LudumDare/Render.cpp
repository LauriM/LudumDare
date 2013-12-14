#include "Render.h"

#include <SFML/Graphics.hpp>

#define LOADTEXTURE(p_var, p_sprite, p_file) if(! p_var.loadFromFile( p_file ) ){ printf("Failed to load texture %s",p_file); return false; } p_sprite.setTexture(p_var); printf("loaded file: " p_file "\n");

bool Render::init()
{
	printf("loading resources...\n");

	LOADTEXTURE(texturePlayer, spritePlayer, "../gfx/ship.png");

	spritePlayer.setOrigin(16,16);

	view.zoom(1.8f);

	return true;
}

void Render::update()
{
	background();

	//center camera to player
	view.setCenter(scene->getPlayer()->position.x,scene->getPlayer()->position.y);
	float rotation = scene->getPlayer()->direction.getAngle() * 180 / PI;
	printf("rot: %f\n",rotation);
	view.setRotation(rotation + 90);

	//Draw planets
	PlanetList *planets = scene->getPlanets();

	sf::CircleShape shape(1.f);

	for(int i = 0; i < planets->size(); ++i)
	{
		shape.setFillColor(sf::Color::Red);
		shape.setRadius(planets->at(i)->size);
		shape.setOrigin(planets->at(i)->size, planets->at(i)->size);
		shape.setPosition(planets->at(i)->position.getSfml());

		window->draw(shape);
	}

	//Draw the player
	spritePlayer.setPosition(scene->getPlayer()->position.x,scene->getPlayer()->position.y);
	spritePlayer.setRotation((scene->getPlayer()->direction.getAngle()) * 180 / PI);

	window->setView(view);
	window->draw(spritePlayer);
}

void Render::background()
{
	sf::CircleShape shape(1.f);
	shape.setFillColor(sf::Color::White);

	for(int x = 0; x < WORLD_WIDTH; x += 100)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 100)
		{
			shape.setPosition(x , y);
			window->draw(shape);
		}
	}
}