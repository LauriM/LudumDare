#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "precompiled.h"

#include <SFML/Graphics.hpp>
#include <vector>

#define PARTICLE_MAX_COUNT 500

struct Particle
{
	Vector position;
	Vector velocity;
	int ttl;
	sf::Color color;
	int size;
};

class ParticleSystem
{
private:
	Particle particles[PARTICLE_MAX_COUNT];

public:
	ParticleSystem() {}

	void addParticles(int min, int max, Vector position, Vector direction, int spread, int minSpeed, int maxSpeed, int minTTL, int maxTTL, sf::Color color,int size)
	{
		addParticles(min, max, position, direction, spread, minSpeed, maxSpeed, minTTL, maxTTL, color,size,Vector(0,0) );
	}

	void addParticles(int min, int max, Vector position, Vector direction, int spread, int minSpeed, int maxSpeed, int minTTL, int maxTTL, sf::Color color,int size,Vector baseVelocity);

	void render(sf::RenderWindow* window); //handles also updating

	void empty();
};

#endif