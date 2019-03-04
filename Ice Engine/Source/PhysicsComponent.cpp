#pragma once
#include "PhysicsComponent.h"
#include "SpriteComponent.h"



PhysicsComponent::PhysicsComponent(SpriteComponent* sprite, PhysicsEngine* engine)
{
	p_sprite = sprite;
	this->engine = engine;
	engine->AddRigidBody(this);
}




void PhysicsComponent::Update()
{

}

bool PhysicsComponent::IsGrounded()
{
	grounded = engine->IsGrounded(this);
	return grounded;
}

 void PhysicsComponent::Integrate(float dT) {
	 Vector2 acceleration = { 0,0 };

	// this part of the code checks the object is supposed to use gravity and starts its acceleration 
	// equal to gravity if thats the case however if the object is moving too slowly it sets the 
	// value of the current y velocity to 0 so an object doesn't try to fall through solid things

	if (gravityAffected&& !IsGrounded()) {
		acceleration = gravity;
	}
	else {
		if (abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
	}


	acceleration += totalForces / mass;
	if (mass == 0) {
		acceleration.x = 0;
		acceleration.y = 0;
	}
	Vector2 accelTime= (acceleration * dT);
	currentVelocity += accelTime;

	Vector2 temp = { 0,0 };
	sf::FloatRect rect = p_sprite->sprite.getGlobalBounds();
	temp.x = rect.left;
	temp.y = rect.top;
	temp += currentVelocity;
	if (mass!=0&&temp.x<1000) 
		p_sprite->sprite.setPosition( temp.x,temp.y);
	//SetAABB();????

	totalForces = { 0,0 };
}

 void PhysicsComponent::AddForce(Vector2 force)
 {
	 if (mass!=0)
		 totalForces += force;
 }
PhysicsComponent::~PhysicsComponent()
{
}
