#pragma once
#include "PhysicsComponent.h"
#include "SpriteComponent.h"

#include <iostream>

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
	 if (mass == 0) {
		 acceleration.x = 0;
		 acceleration.y = 0;
		 return;
	 }
	

	if (gravityAffected&& !IsGrounded()) {
		acceleration = gravity;
	}
	else {
		if (abs(currentVelocity.y) < 0.05f) currentVelocity.y = 0;
		
	}
	

	acceleration += totalForces / mass;
	
	Vector2 accelTime= (acceleration * dT);
	//((currentVelocity.x > 0) ? currentVelocity.x -= 0.05 : currentVelocity.x += 0.05);
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
	 if (this!=NULL&&mass!=0)
		 totalForces += force;
 }
PhysicsComponent::~PhysicsComponent()
{
}
