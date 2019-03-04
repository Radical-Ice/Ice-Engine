#pragma once
#include <iterator> 
#include <map> 
#include <string>
#include <vector>
#include "PhysicsComponent.h"
#include "SpriteComponent.h"
#include "Vector2.h"
class PhysicsComponent;
class PhysicsEngine {

public:
	

	/*struct Vector2 {
		float x, y;
		Vector2& operator+(const Vector2& a)
		{
			x = x + a.x;
			y = y + a.y;
			return *this;
		}
		Vector2& operator-(const Vector2& a)
		{
			x = x - a.x;
			y = y - a.y;
			return *this;
		}
	};*/
	struct CollisionPair {
		PhysicsComponent* rigidBodyA;
		PhysicsComponent* rigidBodyB;
		bool operator< (const CollisionPair& o) const {
			return
				this->rigidBodyA < o.rigidBodyA;
		}
	};

	struct CollisionInfo {
		Vector2 collisionNormal;
		float penetration;
	};

	std::map<CollisionPair, CollisionInfo> collisions;
	std::vector<PhysicsComponent*> rigidBodies;
	float groundedTol = 1.1f;
	void AddRigidBody(PhysicsComponent* rigidBody);
	void IntegrateBodies(float dT);
	void CheckCollisions();
	void ResolveCollisions();
	bool IsGrounded(PhysicsComponent* rigidBody);
	void PositionalCorrection(CollisionPair c);

	void Update();
};