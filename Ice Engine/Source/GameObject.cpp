#include "GameObject.h"
#include <Windows.h>
GameObject::GameObject(GameObject* parent)
{
	
	parent->children.push_back(this);
}

GameObject::GameObject(SceneGraph* sceneNode) {
	sceneNode->children.push_back(this);
}

void GameObject::AddChild(GameObject* gameObject) {
	children.push_back(gameObject);
}
void GameObject::Update(sf::RenderWindow & renderWindow) {
	for (auto item : children) {
		item->Update(renderWindow);


	}

	for (auto item : components) {
		if(item!=NULL)
		item->Update(renderWindow);
	}
}

GameObject::~GameObject()
{
}

