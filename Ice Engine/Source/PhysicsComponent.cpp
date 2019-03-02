#include "PhysicsComponent.h"
#include "SpriteComponent.h"

PhysicsComponent::PhysicsComponent(SpriteComponent* sprite)
{
	p_sprite = sprite;
}

void PhysicsComponent::Update()
{
	if (gravityAffected) {

		totalForces.y += gravityStrength;
	}
	p_sprite->sprite.move(totalForces.x, totalForces.y);
}

PhysicsComponent::~PhysicsComponent()
{
}
