#ifndef SCENE_H
#define SCENE_H

#include "precompiled.h"

#include "Player.h"
#include "Planet.h"
#include "Entity.h"

#include <vector>

//typedef PlanetList std::vector<*Planet>;
typedef std::vector<Planet*> PlanetList;
typedef std::vector<Entity*> EntityList;

USE_PARTICLESYSTEM;

class Scene 
{
private:
	Player player;

	PlanetList planets;
	EntityList entities;

public:
	Scene();

	void resetScene();

	void update();

	/* Getters & setters */

	Player* getPlayer()
	{
		return &player;
	}

	PlanetList* getPlanets()
	{
		return &planets;
	}
};

#endif