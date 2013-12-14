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
	bounds();
	background();

	//center camera to player
	view.setCenter(scene->getPlayer()->position.x,scene->getPlayer()->position.y);
	float rotation = scene->getPlayer()->direction.getAngle() * 180 / PI;

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
	Vector offset;

	sf::CircleShape shape(3.f);
	shape.setFillColor(sf::Color::White);

	//level 1j
	for(int x = 0; x < WORLD_WIDTH; x += 300)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 300)
		{
			shape.setPosition(x , y);
			window->draw(shape);
		}
	}

	//Parlax level 2
	shape.setRadius(2.f);
	for(int x = 0; x < WORLD_WIDTH; x += 100)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 100)
		{
			offset = scene->getPlayer()->position;
			offset.x -= WORLD_WIDTH / 2;
			offset.y -= WORLD_HEIGHT / 2;

			shape.setPosition(x + offset.x * 0.2, y + offset.y * 0.2);
			window->draw(shape);
		}
	}

	//Parlax level 3
	shape.setRadius(1.f);
	for(int x = 0; x < WORLD_WIDTH; x += 150)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 150)
		{
			offset = scene->getPlayer()->position;
			offset.x -= WORLD_WIDTH / 2;
			offset.y -= WORLD_HEIGHT / 2;

			shape.setPosition(x + offset.x * 0.1, y + offset.y * 0.1);
			window->draw(shape);
		}
	}
}

void Render::bounds()
{
	sf::RectangleShape shape;

	shape.setSize(sf::Vector2f(10,WORLD_HEIGHT));
	shape.setPosition(-10,-10);
	shape.setFillColor(sf::Color::Green);

	window->draw(shape);

	shape.setSize(sf::Vector2f(WORLD_WIDTH,10));
	shape.setPosition(-10,-10);
	shape.setFillColor(sf::Color::Green);

	window->draw(shape);


	shape.setSize(sf::Vector2f(10,WORLD_HEIGHT));
	shape.setPosition(WORLD_WIDTH,-10);
	shape.setFillColor(sf::Color::Green);

	window->draw(shape);

	shape.setSize(sf::Vector2f(WORLD_WIDTH,10));
	shape.setPosition(-10,WORLD_HEIGHT);
	shape.setFillColor(sf::Color::Green);

	window->draw(shape);
}

