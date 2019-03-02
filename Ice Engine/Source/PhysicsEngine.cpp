#pragma once
#include "PhysicsEngine.h"

void PhysicsEngine::AddRigidBody(PhysicsComponent* rigidBody) {

	rigidBodies.push_back(rigidBody);
}

void PhysicsEngine::IntegrateBodies(float dT) {
	for (PhysicsComponent* rb : rigidBodies) {
		rb->Integrate(dT);
	}
}

bool PhysicsEngine::IsGrounded(PhysicsComponent* rigidBody) {
	for (PhysicsComponent* rb : rigidBodies) {
		if (rb != rigidBody) {
			
			sf::FloatRect rect = rigidBody->p_sprite->sprite.getGlobalBounds();
			sf::FloatRect rectOther = rb->p_sprite->sprite.getGlobalBounds();
			if (rect.left < rectOther.left + rectOther.width
				&&rect.left + rect.width > rectOther.left
				&& abs(rect.top - rect.height - rectOther.top) <= groundedTol) {
				if (abs(rigidBody->currentVelocity.y) > groundedTol) {
					return true;

				}
			}
		}
	}
	return false;
}

void PhysicsEngine::Update()
{
	IntegrateBodies(0.2f);
}


