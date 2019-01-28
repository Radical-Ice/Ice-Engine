#pragma once
#include <vector>
#include "TransformComponent.h"
#include "SceneGraph.h"
class SceneGraph;
class GameObject
{
public:
	
	GameObject(SceneGraph* sceneNode);
	GameObject(GameObject* parent);
	TransformComponent transform;
	void AddChild(GameObject* gameObject);
	void Update();
	std::vector<GameObject*> children;

	std::vector<BaseComponent> components{ transform };

	~GameObject();
};

