#pragma once
#include "BaseComponent.h"
class TransformComponent : public BaseComponent
{
public:
	struct Vector2 {
		float x;
		float y;
		inline Vector2 operator+(Vector2 a) {
			x = a.x + x;
			y = a.y+y;
			return a;
		}
		inline Vector2 operator*(Vector2 a) {
			x = a.x * x;
			y = a.y * y;
			return a;
		}
	};

	TransformComponent();
	TransformComponent(TransformComponent* parentTransform);
	TransformComponent(float x, float y, float rotation, float xScale, float yScale);

	void Update();
	TransformComponent* m_ParentTransform;
	Vector2 m_Position;
	Vector2 m_Scale;
	float	m_Rotation;
	Vector2 m_WorldPosition;
	Vector2 m_WorldScale;
	float	m_WorldRotation;
	~TransformComponent();

};

