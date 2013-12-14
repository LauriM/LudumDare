#include "ParticleSystem.h"

extern int randomRange(int min, int max);

//part system is global
ParticleSystem particleSystem;

void ParticleSystem::addParticles(int min, int max, Vector position, Vector direction, int spread, int minSpeed, int maxSpeed, int minTTL, int maxTTL, sf::Color color, int size, Vector baseVelocity)
{
	int count = randomRange(min,max);

	while(count > 0){
		--count;

		//Calculating the spread dir
		direction.rotate( randomRange(-spread,spread) );
		float speed = randomRange(minSpeed, maxSpeed);

		for(int i = 0;i < PARTICLE_MAX_COUNT; ++i)
		{
			if(particles[i].ttl < 1)
			{
				particles[i].velocity = baseVelocity;
				particles[i].velocity += direction * speed;
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