#pragma once
#include "BaseComponent.h"
#include "PhysicsEngine.h"
#include "Vector2.h"
class PhysicsEngine;
class SpriteComponent;

class PhysicsComponent: public BaseComponent {
public:

	PhysicsComponent(SpriteComponent* sprite, PhysicsEngine* engine);
	int tag=0;
	Vector2 gravity{ 0, 9.8f };
	bool gravityAffected = true;
	bool grounded;
	float mass = 1.0;
	float bounciness = .8f;
	PhysicsEngine* engine;
	Vector2 currentVelocity = { 0,0 };
	Vector2 velocity = { 0,0 };
	Vector2 totalForces = { 0,0 };
	SpriteComponent* p_sprite;

	void Integrate(float dT);
	bool IsGrounded();
	void AddForce(Vector2 force);

	void Update();
	~PhysicsComponent();
};