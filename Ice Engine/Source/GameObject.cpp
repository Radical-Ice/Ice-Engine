#include "GameObject.h"
#include <Windows.h>
GameObject::GameObject(GameObject* parent)
{
	
	parent->children.push_back(this);
	m_Transform = new TransformComponent(parent->transform);
	transform = &m_Transform;
	components.push_back(transform);
}

GameObject::GameObject(SceneGraph* sceneNode) {
	sceneNode->children.push_back(this);
	m_Transform = new TransformComponent();
	transform = &m_Transform;
	components.push_back(transform);
}

void GameObject::AddChild(GameObject* gameObject) {
	children.push_back(gameObject);
}
void GameObject::Update(sf::RenderWindow & renderWindow) {
	for (auto item : children) {
		item->Update(renderWindow);

	}

	for (auto item : components) {
		if (item != NULL) {

			item->Update();
		}
	}
}

GameObject::~GameObject()
{
}

