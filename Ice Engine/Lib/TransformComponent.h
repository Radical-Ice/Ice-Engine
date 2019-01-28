#pragma once
#include "BaseComponent.h"
class TransformComponent : public BaseComponent
{
public:
	struct Vector2 {
		float x;
		float y;
	};

	TransformComponent();
	TransformComponent(float x, float y, float rotation, float xScale, float yScale);
	Vector2 m_Position;
	Vector2 m_Scale;
	float	m_Rotation;
	
	~TransformComponent();

};

