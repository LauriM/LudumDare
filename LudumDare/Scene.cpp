#include "Scene.h"

Scene::Scene()
:level(0)
{
	//Generate the world on launch
	resetScene();
}

void Scene::resetScene()
{
	//Empty the state data
	particleSystem.empty();

	for (int i = 0; i < entities.size(); ++i) 
	{
		delete entities[i];
	}

	for (int i = 0; i < planets.size(); ++i)
	{
		delete planets[i];
	}

	entities.clear();
	planets.clear();

	//Reset player
	player = Player();

	int count = 3 + (level * 2);
	bool hit = false;

	Planet* tempPlanet;

	while(count > 0)
	{
		--count;

		tempPlanet = new Planet( Vector( randomRange(0,WORLD_WIDTH), randomRange(0,WORLD_HEIGHT) ), randomRange(100,250 ) ) ;

		//Check that the planet is not on top of other planes
		for( int i = 0; i < planets.size(); ++i)
		{
			Vector vec = tempPlanet->position - planets[i]->position;
			float dist = abs ( vec.getLenght() );

			dist -= planets[i]->size;
			dist -= tempPlanet->size;

			if(dist < 0){
				//Hit! break from the loop
				hit = true;
			}
		}

		if(hit)
		{
			printf("planet collision!");
			delete tempPlanet;
		}
		else
		{
			printf("planet creation");
			planets.push_back(tempPlanet);
		}

		hit = false;
	}

	//Then add the pickups.
	count = SCENE_PICKUP_COUNT; //10 pickups

	hit = false;

	Entity *ent;

	while( count > 0 )
	{
		//Entity *ent = new Entity(Vector( randomRange(0,WORLD_WIDTH), randomRange(0,WORLD_HEIGHT)), ENTITYTYPE_PICKUP);
		ent = new Entity();

		ent->position = Vector( (float)randomRange(0,WORLD_WIDTH), (float)randomRange(0,WORLD_HEIGHT));
		ent->type = ENTITYTYPE_PICKUP;

//		printf("|%f %f|\n",ent->position.x,ent->position.y);

		//Check that the pickup is not inside a planet
		for( int i = 0; i < planets.size(); ++i)
		{
			Vector vec = ent->position - planets[i]->position;
			float dist = abs ( vec.getLenght() );

			dist -= planets[i]->size;
			dist -= 150; //Some space between the planets and pickups...

			if(dist < 0){
				//Hit! break from the loop
				//printf("planet collision!");
				hit = true;
			}
		}

		if(hit)
		{
			delete ent;
		}
		else
		{
			entities.push_back(ent);
		}

		--count;
		hit = false;
	}

	printf("entities.size() : %i \n", entities.size());

	count = SCENE_FUEL_COUNT; //5 fuel

	while( count > 0 )
	{
		//Entity *ent = new Entity(Vector( randomRange(0,WORLD_WIDTH), randomRange(0,WORLD_HEIGHT)), ENTITYTYPE_PICKUP);
		ent = new Entity();

		ent->position = Vector( (float)randomRange(0,WORLD_WIDTH), (float)randomRange(0,WORLD_HEIGHT));
		ent->type = ENTITYTYPE_FUEL;

//		printf("|%f %f|\n",ent->position.x,ent->position.y);

		//Check that the pickup is not inside a planet
		for( int i = 0; i < planets.size(); ++i)
		{
			Vector vec = ent->position - planets[i]->position;
			float dist = abs ( vec.getLenght() );

			dist -= planets[i]->size;
			dist -= 150; //Some space between the planets and pickups...

			if(dist < 0){
				//Hit! break from the loop
				printf("planet collision!");
				hit = true;
			}
		}

		if(hit)
		{
			delete ent;
		}
		else
		{
			entities.push_back(ent);
		}

		--count;
		hit = false;
	}

	printf("entities.size() : %i \n", entities.size());
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

		if (dist < radius)
		{
			if (player.hp > 0) //Don't kill the player if he is dead already.
			{
				--player.hp;
				particleSystem.addParticles(5, 10, player.position, Vector(0, 1), 360, 5, 10, 100, 200 / 2, sf::Color::White, 2);

				if (player.hp < 1)
				{
					//Player died on this frame! BETTER EXPLOSIONS!
					particleSystem.empty();
					particleSystem.addParticles(500, 500, player.position, Vector(0,1), 360, 5, 10, 20000, 20000 / 2, sf::Color::White, 2);

					level = 0;
				}
			}
		}

		//if distance is larger than the size, no gravity applies
		if(dist / GRAVITY_MULTIPLIER > radius)
			continue;

		dist -= radius / 2; //gravity "starts" from the surface, not center

		float str = dist / (1000000.f / 0.8);

		//printf("# %f #\n",str);
		if(str < 0)
			continue;

		//apply force
		player.impulse(vec,str);
	}

	//Check the entities

	for ( int i = 0; i < entities.size(); ++i )
	{
		Vector vec = entities[i]->position - player.position;
		int dist = abs( vec.getLenght() );

		if(dist < 65)
		{
			//printf("PICKUP!");
			printf("dist: %i", dist);

			if(entities[i]->type == ENTITYTYPE_PICKUP)
			{
				particleSystem.addParticles(200, 200, entities[i]->position , Vector(0,1) ,360,50,80,50,100,sf::Color::Green,4);
				++player.points;
			}

			if(entities[i]->type == ENTITYTYPE_FUEL)
			{
				particleSystem.addParticles(200, 200, entities[i]->position , Vector(0,1) ,360,30,50,50,100,sf::Color::Red,4);
				player.fuel += FUEL_PER_CANISTER;
			}

			delete entities[i];
			entities.erase(entities.begin() + i);
			--i;
		}
	}

	//Only update player if hp is positive
	if (player.hp > 0){
		player.update();
	}

	//If player wins! Reset the level and move to the next one

	if (player.points > 6)
	{
		//This may be bit reduntant as resetScene should handle these
		player.points = 0;
		player.hp = PLAYER_START_HP;
		player.fuel = PLAYER_START_FUEL;
		
		//Next difficulty!
		++level;

		resetScene();
	}
}