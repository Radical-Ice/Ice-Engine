#pragma once
#include <iterator> 
#include <map> 
#include "PhysicsComponent.h"
#include "SpriteComponent.h"
class PhysicsComponent;
class PhysicsEngine {

public:

	float groundedTol = 0.1f;
	struct Vector2 {
		float x, y;
	};
	struct CollisionPair {
		PhysicsComponent* rigidBodyA;
		PhysicsComponent* rigidBodyB;
	};

	struct CollisionInfo {
		Vector2 collisionNormal;
		float penetration;
	};

	std::map<CollisionPair, CollisionInfo> collisions;
	std::vector<PhysicsComponent*> rigidBodies;

	void AddRigidBody(PhysicsComponent* rigidBody);
	void PhysicsEngine::IntegrateBodies(float dT);
	bool PhysicsEngine::IsGrounded(PhysicsComponent* rigidBody);
	void Update();
};