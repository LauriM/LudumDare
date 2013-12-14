#include "precompiled.h"

#include <stdio.h>
#include <math.h>

#include "Player.h"

USE_PARTICLESYSTEM;

void Player::update()
{
	position += velocity;

	//printf("Vel: %f,%f\n",velocity.x,velocity.y);
	printf("Rotation: %f,%f (%f) (%f)\n", direction.x, direction.y, direction.getAngle(), velocity.getLenght());
}

void Player::accelerate()
{
	velocity += (direction * PLAYER_ACCEL);

	//Move the flame behind the ship
	Vector pos = position - (direction * 20);

	particleSystem.addParticles(2,5,pos,0,0,-2,2,3,7,sf::Color::Red);
	particleSystem.addParticles(2,5,pos,0,0,-2,2,3,7,sf::Color::Yellow);
}

void Player::rotateLeft()
{
	direction.rotate(-PLAYER_ROTATION_SPEED);
}

void Player::rotateRight()
{
	direction.rotate(PLAYER_ROTATION_SPEED);
}