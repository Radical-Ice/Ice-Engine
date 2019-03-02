#pragma once
#include "BaseComponent.h"

class SpriteComponent;
class PhysicsComponent: public BaseComponent {
public:
	struct Vector2 {
		float x, y;
	};
	PhysicsComponent(SpriteComponent* sprite);
	const float gravityStrength = 0.1;
	bool gravityAffected = true;
	float mass = 1.0;
	Vector2 velocity;
	Vector2 totalForces;
	SpriteComponent* p_sprite;

	void Update();
	~PhysicsComponent();
};