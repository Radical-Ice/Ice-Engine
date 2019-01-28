#pragma once
#include <vector>
#include "GameObject.h"
class GameObject;
class SceneGraph
{
public:

	SceneGraph();

	std::vector<GameObject*> children;

	void Update();


	~SceneGraph();
};

