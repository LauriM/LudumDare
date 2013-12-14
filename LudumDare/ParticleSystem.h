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
};

class ParticleSystem
{
private:
	Particle particles[PARTICLE_MAX_COUNT];

public:
	ParticleSystem() {}

	void addParticles(int min, int max, Vector position, float direction, int spread, int minSpeed, int maxSpeed, int minTTL, int maxTTL, sf::Color color);

	void render(sf::RenderWindow* window); //handles also updating
};

#endif