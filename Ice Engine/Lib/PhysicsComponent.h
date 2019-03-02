#pragma once
#include "BaseComponent.h"
#include "PhysicsEngine.h"
class PhysicsEngine;
class SpriteComponent;
class PhysicsComponent: public BaseComponent {
public:
	struct Vector2 {
		float x, y;
		Vector2& operator/(const float a)
		{
			x = x/ a;
			y = y/ a;
			return *this;
		}
		Vector2& operator+=(const Vector2& a)
		{
			x = x + a.x;
			y = y + a.y;
			return *this;
		}
		Vector2& operator*(const float a)
		{
			x = x * a;
			y = y * a;
			return *this;
		}
		/*Vector2& operator=(const sf::Vector2f a)
		{
			x =  a.x;
			y =  a.y;
			return *this;
		}*/
	};
	

	PhysicsComponent(SpriteComponent* sprite, PhysicsEngine* engine);
	Vector2 gravity{ 0, 9.8f };
	bool gravityAffected = true;
	bool grounded;
	float mass = 1.0;

	PhysicsEngine* engine;
	Vector2 currentVelocity;
	Vector2 velocity;
	Vector2 totalForces;
	SpriteComponent* p_sprite;

	void Integrate(float dT);
	bool IsGrounded();
	void Update();
	~PhysicsComponent();
};