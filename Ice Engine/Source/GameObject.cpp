#include "GameObject.h"
#include <Windows.h>
GameObject::GameObject(GameObject* parent)
{
	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			("failed to load image texture"),
			(" -> GameObject.cpp"),
			NULL);
		return;
	}

	parent->children.push_back(this);
}

GameObject::GameObject(SceneGraph* sceneNode) {

	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			("failed to load image texture"),
			(" -> GameObject.cpp"),
			NULL);
		return;
	}
	sceneNode->children.push_back(this);
}

void GameObject::AddChild(GameObject* gameObject) {
	children.push_back(gameObject);
}
void GameObject::Update(sf::RenderWindow & renderWindow) {
	for (auto item : children) {
		item->Update(renderWindow);


	}
	Show(renderWindow, 40, 40, 50, 50);
}

GameObject::~GameObject()
{
}

void GameObject::Show(sf::RenderWindow & renderWindow,float x,float y,float width, float height) {

	//"Assets/" for Pic

	sprite.setTexture(texture);

	//sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));

	//sprite.setPosition(0, 0);

	renderWindow.draw(sprite);


}