#include "TransformComponent.h"



TransformComponent::TransformComponent() :
	m_Position{ 0,0 },
	m_Rotation{ 0 },
	m_Scale{ 1,1 }
{


}
TransformComponent::TransformComponent(TransformComponent* parentTransform) {

	m_ParentTransform = parentTransform;

	m_Position = parentTransform->m_Position;
	m_Rotation = parentTransform->m_Rotation;
	m_Scale = parentTransform->m_Scale;
}
void TransformComponent::Update() {

	if (m_ParentTransform) {

		m_WorldPosition.x = m_ParentTransform->m_Position.x + m_Position.x;
		m_WorldPosition.y = m_ParentTransform->m_Position.y + m_Position.y;
		m_WorldRotation = m_ParentTransform->m_Rotation + m_Rotation;
		m_WorldScale = m_ParentTransform->m_Scale + m_Scale;
	}

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
