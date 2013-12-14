#include "precompiled.h"

#include <stdio.h>
#include <math.h>

#include "Player.h"

USE_PARTICLESYSTEM;

void Player::update()
{
	position += velocity;

	//printf("Vel: %f,%f\n",velocity.x,velocity.y);
	//printf("Rotation: %f,%f (%f) (%f)\n", direction.x, direction.y, direction.getAngle(), velocity.getLenght());

	//Collisions with the borders

	if(position.x < 0)
	{
		position.x = 1;
		velocity.x = -velocity.x;
	}

	if(position.x > WORLD_WIDTH)
	{
		position.x = WORLD_WIDTH;
		velocity.x = -velocity.x;
	}

	if(position.y < 0)
	{
		position.y = 1;
		velocity.y = -velocity.y;
	}

	if(position.y > WORLD_HEIGHT)
	{
		position.y = WORLD_HEIGHT;
		velocity.y = -velocity.y;
	}

}

void Player::accelerate()
{
	velocity += (direction * PLAYER_ACCEL);

	//Move the flame behind the ship
	Vector pos = position - (direction * 20);

	particleSystem.addParticles(1, 3, pos, direction.getReverse() ,15,10,20,50,100,sf::Color::Red,2,velocity);
	particleSystem.addParticles(1, 3, pos, direction.getReverse() ,15,10,20,50,100,sf::Color::Yellow,2,velocity);
}

void Player::halt()
{
	velocity.x = 0;
	velocity.y = 0;
}

void Player::impulse(Vector dir, float force)
{
	velocity += (dir * force);
}

void Player::rotateLeft()
{
	direction.rotate(-PLAYER_ROTATION_SPEED);
}

void Player::rotateRight()
{
	direction.rotate(PLAYER_ROTATION_SPEED);
}