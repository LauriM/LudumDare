#include "Scene.h"

Scene::Scene()
{
	//Generate the world on launch

	int count = PLANET_COUNT;

	Planet *tempPlanet ;

	while(count > 0)
	{
		tempPlanet = new Planet( Vector( randomRange(0,WORLD_WIDTH), randomRange(0,WORLD_HEIGHT) ), randomRange(50,250 ) ) ;

		planets.push_back(tempPlanet);

		--count;
	}
}

void Scene::update()
{
	//calculate gravity from nearby planets

	for(int i = 0; i < planets.size(); ++i)
	{
		//get distance from player
		Vector vec = planets[i]->position - player.position;

		int dist = abs( vec.getLenght() );
		int radius = planets[i]->size;

		//#######################
		//Planets generate particles!
		//particleSystem.addParticles(1,4,planets[i]->position,0,0,-2,2,radius / 10,radius / 5 + radius / 2, sf::Color::Red,3);
		//Disabled because it would "eat" all the avaivable slots with current setup.
		//#######################

		//TODO: Kill player if it collides with a planet, fix the hit detection! the origin is invalid
		if(dist < radius)
			printf("KILL");

		//if distance is larger than the size, no gravity applies
		if(dist / GRAVITY_MULTIPLIER > radius)
			continue;

		dist -= radius / 2; //gravity "starts" from the surface, not center

		float str = dist / 1000000.f;

		//printf("# %f #",str);
		if(str < 0)
			continue;

		//apply force
		player.impulse(vec,str);
	}

	//get player input, apply velocity
	player.update();
}