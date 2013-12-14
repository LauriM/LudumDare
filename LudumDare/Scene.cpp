#include "Scene.h"

Scene::Scene()
{
	//Generate the world on launch

	Planet *tempPlanet = new Planet(Vector(200,200), 100);
	Planet *tempPlanet2 = new Planet(Vector(500,800), 150);

	planets.push_back(tempPlanet);
	planets.push_back(tempPlanet2);
}

void Scene::update()
{
	//calculate gravity from nearby planets

	for(int i = 0; i < planets.size(); ++i)
	{
		//get distance
		Vector vec = planets[i]->position - player.position;

		int dist = abs( vec.getLenght() );
		int radius = planets[i]->size;

		//TODO: Kill player if it collides with a planet, fix the hit detection! the origin is invalid
		if(dist < radius)
			printf("KILL");

		//if distance is larger than the size, no gravity applies
		if(dist / GRAVITY_MULTIPLIER > radius)
			continue;

		dist -= radius / 2; //gravity "starts" from the surface, not center

		float str = (dist * GRAVITY_MULTIPLIER) / 10000000.f;

		printf("# %f #",str);
		if(str < 0)
			continue;

		//apply force
		player.impulse(vec,str);
	}

	//get player input, apply velocity
	player.update();
}