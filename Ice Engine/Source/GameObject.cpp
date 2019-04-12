#include "GameObject.h"
#include <Windows.h>
GameObject::GameObject(GameObject* parent)
{
	
	parent->children.push_back(this);
	m_Transform = new TransformComponent(parent->m_Transform);

	//transform = &m_Transform;
	components.push_back(m_Transform);
}

GameObject::GameObject(SceneGraph* sceneNode) {
	sceneNode->children.push_back(this);
	m_Transform = new TransformComponent();

	//transform = &m_Transform;
	components.push_back(m_Transform);
}

void GameObject::AddChild(GameObject* gameObject) {
	children.push_back(gameObject);
}
void GameObject::Update(sf::RenderWindow & renderWindow) {
	if (!active) {
		return;
	}
	for (auto item : components) {
		if (item != NULL) {

			item->Update();
		}
	}
	for (auto item : children) {
		item->Update(renderWindow);

	}

}

GameObject::~GameObject()
{
}

