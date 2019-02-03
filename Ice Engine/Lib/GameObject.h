#pragma once
#include <vector>
#include "TransformComponent.h"
#include "SceneGraph.h"
#include "SFML/Graphics.hpp"
class SceneGraph;
class GameObject
{
public:
	
	GameObject(SceneGraph* sceneNode);
	GameObject(GameObject* parent);
	TransformComponent transform;
	void AddChild(GameObject* gameObject);
	void Update(sf::RenderWindow & renderWindow);
	std::vector<GameObject*> children;

	std::vector<BaseComponent> components{ transform };

	sf::Texture texture;
	void Show(sf::RenderWindow& window, float x, float y, float width, float height);
	sf::Sprite sprite;


	~GameObject();
};

