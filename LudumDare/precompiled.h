#include "Vec2.h"

#include "ParticleSystem.h"

#define PI 3.14159265359

typedef Vec2<float> Vector;

int randomRange(int min,int max);

#define USE_PARTICLESYSTEM extern ParticleSystem particleSystem;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

#define WORLD_WIDTH 5001
#define WORLD_HEIGHT 5001

//#define PLANET_COUNT randomRange(5,8);
#define PLANET_COUNT randomRange(2,2);

#define GRAVITY_MULTIPLIER 4

#define PLAYER_ROTATION_SPEED 2.f
#define PLAYER_ACCEL 0.35

#define SCENE_PICKUP_COUNT 10
#define SCENE_FUEL_COUNT 5

#define FUEL_PER_CANISTER 100