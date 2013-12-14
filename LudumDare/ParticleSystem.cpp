#include "ParticleSystem.h"

#include "Random.h"

//part system is global
ParticleSystem particleSystem;

void ParticleSystem::addParticles(int min, int max, Vector position, float direction, int spread, int minSpeed, int maxSpeed, int minTTL, int maxTTL, sf::Color color)
{
	int count = randomRange(min,max);

	while(count > 0){
		--count;

		/*
		int speed = randomRange(minSpeed, maxSpeed);

		float dir = direction + randomRange(-spread,spread);
		*/

		for(int i = 0;i < PARTICLE_MAX_COUNT; ++i)
		{
			if(particles[i].ttl < 1)
			{
				particles[i].velocity = Vector(randomRange(minSpeed,maxSpeed),randomRange(minSpeed,maxSpeed));
				particles[i].ttl = randomRange(minTTL,maxTTL);
				particles[i].position = position;
				particles[i].color = color;
				break;
			}
		}

	}
}

void ParticleSystem::render(sf::RenderWindow* window)
{
	sf::CircleShape dot(1.f);
//	dot.setFillColor(sf::Color::White);

	for(int i = 0; i < PARTICLE_MAX_COUNT; ++i)
	{
		if(particles[i].ttl > 0)
		{
			//move
			particles[i].position += particles[i].velocity;
			--particles[i].ttl;

			//render
			dot.setFillColor(particles[i].color);
			dot.setPosition(sf::Vector2f(particles[i].position.x, particles[i].position.y));
			window->draw(dot);
		}
	}

}