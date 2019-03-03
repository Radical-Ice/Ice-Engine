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
			float temp = rectOther.left + rectOther.width;
			float temp2 = abs(rect.top + rect.height - rectOther.top);
			float temp3 = rect.left + rect.width;
			if (rect.left < temp
				&& temp3 > rectOther.left 
				&& temp2 <= groundedTol) {
				if (abs(rigidBody->currentVelocity.y) > groundedTol) {
					return true;

				}
			}
		}
	}
	return false;
}

void PhysicsEngine::CheckCollisions() {
	for(PhysicsComponent* bodyA : rigidBodies) {
		for(PhysicsComponent* bodyB : rigidBodies) {// not sure what this says
			if (bodyA != bodyB) {
				CollisionPair pair;
				CollisionInfo colInfo;
				pair.rigidBodyA = bodyA; pair.rigidBodyB = bodyB;

				Vector2 distance;
				distance.x= bodyB->p_sprite->sprite.getPosition().x - bodyA->p_sprite->sprite.getPosition().x;
				distance.y = bodyB->p_sprite->sprite.getPosition().y - bodyA->p_sprite->sprite.getPosition().y;

				Vector2 halfSizeA;
				//halfSizeA.x = (bodyA->p_sprite->sprite.getGlobalBounds().width) / 2;// does not account for origin properly
				halfSizeA.x = (bodyA->p_sprite->sprite.getTexture()->getSize().x) / 4;
				//halfSizeA.y = (bodyA->p_sprite->sprite.getGlobalBounds().height) / 2;
				halfSizeA.y = (bodyA->p_sprite->sprite.getTexture()->getSize().y) / 4;
				Vector2 halfSizeB;
				//halfSizeB.x = (bodyB->p_sprite->sprite.getGlobalBounds().width) / 2;// does not account for origin properly
				//halfSizeB.y = (bodyB->p_sprite->sprite.getGlobalBounds().height) / 2;
				halfSizeB.x = (bodyB->p_sprite->sprite.getTexture()->getSize().x) / 2;
				halfSizeB.y = (bodyB->p_sprite->sprite.getTexture()->getSize().y) / 2;
				Vector2 temp = { abs(distance.x), abs(distance.y)};
				Vector2 gap = { 0,0 };
				Vector2 temp2 = { halfSizeA.x,halfSizeA.y };//halfSizeA; // + halfSizeB;
				gap ={ temp - temp2  };

				
				//Vector2 gap;

				// Seperating Axis Theorem test
				if (gap.x < 0.0f && gap.y < 0.0f) {
					//Debug.Log("Collided!!!");

					if (!(collisions.find(pair) == collisions.end())) {
						collisions.erase(pair);
					}

					if (gap.x > gap.y) {
						if (distance.x > 0.0f) {
							// ... Update collision normal
							colInfo.collisionNormal = { 1,0 };//added this line
						}
						else {
							// ... Update collision normal
							colInfo.collisionNormal = { -1,0 };//added this line
						}
						colInfo.penetration = gap.x;
					}
					else {
						if (distance.y > 0.0f) {
							// ... Update collision normal
							colInfo.collisionNormal = { 0,1 };//added this line
						}
						else {
							// ... Update collision normal
							colInfo.collisionNormal = { 0,-1 };
						}
						colInfo.penetration = gap.y;
					}
					collisions.insert(std::pair<CollisionPair, CollisionInfo>(pair, colInfo));
					//collisions[pair] = colInfo;

				}
				else if (collisions.find(pair) != collisions.end()) {
					//Debug.Log("removed");
				//	collisions.erase(pair);
				}

			}
		}
	}
}
void PhysicsEngine::ResolveCollisions() {

	std::vector<CollisionPair> v;
	for (std::map<CollisionPair, CollisionInfo>::iterator it = collisions.begin(); it != collisions.end(); ++it) {
		v.push_back(it->first);
	}
	for (CollisionPair pair : v) {


		float minBounce = pair.rigidBodyA->bounciness;
		//float velAlongNormal = Vector2.Dot(pair.rigidBodyB.currentVelocity - pair.rigidBodyA.currentVelocity, collisions[pair].collisionNormal);
		float velAlongNormal = pair.rigidBodyB->currentVelocity.y - pair.rigidBodyA->currentVelocity.y;
		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;
		float invMassA = 0; 
		float invMassB= 0;
		if (pair.rigidBodyA->mass == 0)
			invMassA = 0;
		else
			invMassA = 1 / pair.rigidBodyA->mass;

		if (pair.rigidBodyB->mass == 0)
			invMassB = 0;
		else
			invMassB = 1 / pair.rigidBodyB->mass;

		j /= invMassA + invMassB;

		Vector2 impulse =  collisions[pair].collisionNormal* j ;
		//Debug.Log("collisions[pair].collisionNormal" + collisions[pair].collisionNormal);
		//Debug.Log("velAlongNormal" + velAlongNormal);
		//Debug.Log("impulse" + impulse);
		//Debug.Log("j" + j);
		//pair.rigidBodyA.currentVelocity = -pair.rigidBodyA.currentVelocity*invMassA;
		//pair.rigidBodyB.currentVelocity = -pair.rigidBodyB.currentVelocity*invMassB;

		//else

		//pair.rigidBodyA.currentVelocity = new Vector2(-pair.rigidBodyA.currentVelocity.x,-pair.rigidBodyA.currentVelocity.y*j*invMassA)*invMassA;
		//pair.rigidBodyB.currentVelocity = new Vector2(-pair.rigidBodyB.currentVelocity.x,-pair.rigidBodyB.currentVelocity.y*j*invMassB)*invMassB;

		//Debug.Log(pair.rigidBodyA.currentVelocity + "pair.rigidBodyA.currentVelocity");
		if (impulse.x*impulse.x +impulse.y*impulse.y > 0.21) {
			pair.rigidBodyA->AddForce(impulse * (1 / 0.2f)*-1);// I like this way better than straight division
			pair.rigidBodyB->AddForce(impulse*(1 / 0.2f));
		}



		//pair.rigidBodyB.AddForce(-pair.rigidBodyB.currentVelocity);
		// ... update velocities

		if (abs(collisions[pair].penetration) > 0.001f) {
			PositionalCorrection(pair);
		}
	}
}
void PhysicsEngine::PositionalCorrection(CollisionPair c) {
	const float percent = .2f;

	float invMassA, invMassB;
	if (c.rigidBodyA->mass == 0)
		invMassA = 0;
	else
		invMassA = 1 / c.rigidBodyA->mass;

	if (c.rigidBodyB->mass == 0)
		invMassB = 0;
	else
		invMassB = 1 / c.rigidBodyB->mass;

	Vector2 correction = ((collisions[c].collisionNormal*-1)*(collisions[c].penetration / (invMassA + invMassB)) * percent) ;

	Vector2 temp;
	temp.x = c.rigidBodyA->p_sprite->sprite.getPosition().x;
	temp.y = c.rigidBodyA->p_sprite->sprite.getPosition().y;
	temp -= correction * invMassA  ;
	if(c.rigidBodyA->mass!=0)
		c.rigidBodyA->p_sprite->sprite.setPosition(temp.x,temp.y);

	temp.x = c.rigidBodyB->p_sprite->sprite.getPosition().x;
	temp.y = c.rigidBodyB->p_sprite->sprite.getPosition().y;
	temp +=  correction *invMassB  ;
	if (c.rigidBodyB->mass != 0)
		c.rigidBodyB->p_sprite->sprite.setPosition(temp.x,temp.y);
}



void PhysicsEngine::Update()
{
	CheckCollisions();
	ResolveCollisions();
	IntegrateBodies(0.1f);
}


