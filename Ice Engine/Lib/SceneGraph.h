#pragma once
#include <vector>
#include "GameObject.h"
#include "SFML/Graphics.hpp"
class GameObject;
class SceneGraph
{
public:

	SceneGraph();

	std::vector<GameObject*> children;

	void Update(sf::RenderWindow & renderWindow);
	~SceneGraph();
};

