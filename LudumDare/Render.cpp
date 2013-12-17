#include "Render.h"

#include <SFML/Graphics.hpp>

#define LOADTEXTURE(p_var, p_sprite, p_file) if(! p_var.loadFromFile( p_file ) ){ printf("Failed to load texture %s",p_file); return false; } p_sprite.setTexture(p_var); printf("loaded file: " p_file "\n");

bool Render::init()
{
	printf("loading resources...\n");

	LOADTEXTURE(texturePlayer, spritePlayer, "../gfx/ship.png");
	LOADTEXTURE(textureFuel, spriteFuel, "../gfx/Fuel.png");
	LOADTEXTURE(texturePickup, spritePickup, "../gfx/Pickup.png");

	spritePlayer.setOrigin(16,16);

	if (!font.loadFromFile("../gfx/arial.ttf"))
	{
		printf("Cannot load the font!");
		return false;
	}

	view.zoom(3.0f);

	return true;
}

void Render::update()
{
	window->setView(view);
	bounds();
	background();

	//center camera to player
	Vector camPos = scene->getPlayer()->position;

	camPos += scene->getPlayer()->direction * 750;

	view.setCenter(camPos.getSfml());
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

	EntityList *entities = scene->getEntities();

	shape.setRadius(30);

	for(int i = 0; i < entities->size(); ++i)
	{
		shape.setFillColor(sf::Color::Green);
		shape.setOrigin(15,15);
		shape.setPosition(entities->at(i)->position.getSfml());
		//printf("pos: %i,%i\n",entities->at(i)->position.getSfml().x, entities->at(i)->position.getSfml().y);

		//window->draw(shape);

		if (entities->at(i)->type == ENTITYTYPE_FUEL)
		{
			spriteFuel.setPosition(entities->at(i)->position.getSfml());
			window->draw(spriteFuel);
		}
		else
		{
			spritePickup.setPosition(entities->at(i)->position.getSfml());
			window->draw(spritePickup);
		}
	}

	//Draw the player

	if (scene->getPlayer()->hp > 1)
	{

		spritePlayer.setPosition(scene->getPlayer()->position.x, scene->getPlayer()->position.y);
		spritePlayer.setRotation((scene->getPlayer()->direction.getAngle()) * 180 / PI);

		window->draw(spritePlayer);
	}

	//Always set the view so the rotation updates

	//Draw the HUD
	window->setView(hudView);

	sf::Text text;

	text.setFont(font);
	text.setCharacterSize(25);
	text.setColor(sf::Color::White);
	Vector pos;

	text.setString(std::string("Points: ") + std::to_string((long double)scene->getPlayer()->points) );
	text.setPosition(sf::Vector2f(0, 0));
	window->draw(text);

	text.setString(std::string("Fuel: ") + std::to_string((long double)scene->getPlayer()->fuel));
	text.setPosition(sf::Vector2f(0, 30));
	window->draw(text);

	text.setString(std::string("HP: ") + std::to_string((long double)scene->getPlayer()->hp));
	text.setPosition(sf::Vector2f(0, 60));
	window->draw(text);

	window->setView(view);
}

bool Render::getNextStarStatus()
{
	++starStatusTick;

	if(starStatusTick > STARSTATUS_PRECACHE_SIZE)
		starStatusTick = 0;

	return starStatus[starStatusTick];
}

void Render::background()
{
	Vector offset;

	//Reset the star counter.
	starStatusTick = 0;

	sf::CircleShape shape(3.f);
	shape.setFillColor(sf::Color::White);

	//level 1j
	for(int x = 0; x < WORLD_WIDTH; x += 250)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 250)
		{
			if(getNextStarStatus())
				continue;

			shape.setPosition(x , y);
			window->draw(shape);
		}
	}

	//Parlax level 2
	shape.setRadius(2.f);
	for(int x = 0; x < WORLD_WIDTH; x += 350)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 350)
		{
			if(getNextStarStatus())
				continue;

			offset = scene->getPlayer()->position;
			offset.x -= WORLD_WIDTH / 2;
			offset.y -= WORLD_HEIGHT / 2;

			shape.setPosition(x + offset.x * 0.4, y + offset.y * 0.4);
			window->draw(shape);
		}
	}

	//Parlax level 3
	shape.setRadius(1.f);
	for(int x = 0; x < WORLD_WIDTH; x += 550)
	{
		for(int y = 0; y < WORLD_HEIGHT; y += 550)
		{
			if(getNextStarStatus())
				continue;

			offset = scene->getPlayer()->position;
			offset.x -= WORLD_WIDTH / 2;
			offset.y -= WORLD_HEIGHT / 2;

			shape.setPosition(x + offset.x * 0.2, y + offset.y * 0.2);
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

