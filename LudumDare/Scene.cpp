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

		float str = planets[i]->size + (planets[i]->size * 5) - dist;

		if(str < 0)
			str = 0;

		str /= 1000000;


		//apply force
		player.impulse(vec,str);
		printf("# %f #",str);
	}

	//get player input, apply velocity
	player.update();
}