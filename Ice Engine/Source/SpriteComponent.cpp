#include"SpriteComponent.h"
#include <Windows.h>
SpriteComponent::SpriteComponent(sf::RenderWindow* renderWindow, std::string filename, TransformComponent* transform) {
	m_Window = renderWindow;
	m_Transform = transform;
	if (!texture.loadFromFile(filename)) {
		MessageBox(NULL,
			("failed to load image texture"),
			(" -> SpriteComponent.cpp"),
			NULL);
		return;
	}

}
void SpriteComponent::Show(sf::RenderWindow* renderWindow) {

	//"Assets/" for Pic

	sprite.setTexture(texture);

	//sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));

	sprite.setPosition(m_Transform->m_WorldPosition.x, m_Transform->m_WorldPosition.y);

	sprite.setRotation(m_Transform->m_WorldRotation);
	sprite.setScale(m_Transform->m_WorldScale.x, m_Transform->m_WorldScale.y);
	renderWindow->draw(sprite);
}
void SpriteComponent::Update() {

	Show(m_Window);
}
