#include "TransformComponent.h"



TransformComponent::TransformComponent() :
	m_Position{ 0,0 },
	m_Rotation{ 0 },
	m_Scale{ 1,1 },
	m_WorldPosition{0,0},
	m_WorldRotation{ 0 },
	m_WorldScale{ 1,1 }

{


}
TransformComponent::TransformComponent(TransformComponent* parentTransform) :
	m_Position{ 0,0 },
	m_Rotation{ 0 },
	m_Scale{ 1,1 }
{
	m_ParentTransform = parentTransform;

	m_WorldPosition = parentTransform->m_WorldPosition;

	m_WorldRotation = parentTransform->m_WorldRotation;

	m_WorldScale = parentTransform->m_WorldScale;
}
void TransformComponent::Update() {

	if (m_ParentTransform) {

		m_WorldPosition.x = m_ParentTransform->m_WorldPosition.x + m_Position.x;

		m_WorldPosition.y = m_ParentTransform->m_WorldPosition.y + m_Position.y;
		m_WorldRotation = m_ParentTransform->m_WorldRotation + m_Rotation;
		
		m_WorldScale.x = m_ParentTransform->m_WorldScale.x * m_Scale.x;
		m_WorldScale.y = m_ParentTransform->m_WorldScale.y * m_Scale.y;


	}else{
		m_WorldPosition.x = m_Position.x;

		m_WorldPosition.y =  m_Position.y;
		m_WorldRotation =  m_Rotation;

		m_WorldScale.x =  m_Scale.x;
		m_WorldScale.y =  m_Scale.y;
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
