#ifndef SCENE_H
#define SCENE_H

#include "Player.h"

#include "Planet.h"

#include <vector>

//typedef PlanetList std::vector<*Planet>;
typedef std::vector<Planet*> PlanetList;

class Scene 
{
private:
	Player player;

	PlanetList planets;

public:
	Scene();

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