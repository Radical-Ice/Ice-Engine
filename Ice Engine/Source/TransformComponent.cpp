#include "TransformComponent.h"



TransformComponent::TransformComponent() :
	m_Position{ 0,0 },
	m_Rotation{ 0 },
	m_Scale{ 1,1 }
{


}
void TransformComponent::Update(sf::RenderWindow & renderWindow) {

}
TransformComponent::TransformComponent(float xPos, float yPos,float rotation, float xScale, float yScale) {
	m_Position.x = xPos;
	m_Position.y = yPos;
	m_Rotation = rotation;
	m_Scale.x = xScale;
	m_Scale.y = yScale;

}

TransformComponent::~TransformComponent(){
}
