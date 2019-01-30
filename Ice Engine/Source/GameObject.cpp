#include "GameObject.h"

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
void GameObject::Update() {
	for (auto item : children) {
		item->Update();
	}
}

GameObject::~GameObject()
{
}

