#include"SpriteComponent.h"
#include <Windows.h>
SpriteComponent::SpriteComponent(sf::RenderWindow* renderWindow, std::string filename, TransformComponent* transform, sf::Sprite* parentSprite) {
	m_Window = renderWindow;
	m_Transform = transform;
	pSprite = parentSprite;

	if (!texture.loadFromFile(filename)) {
		MessageBox(NULL,
			("failed to load image texture"),
			(" -> SpriteComponent.cpp"),
			NULL);
		return;
	}

}
SpriteComponent::SpriteComponent(sf::RenderWindow* renderWindow, std::string filename, TransformComponent* transform ) {
	m_Window = renderWindow;
	m_Transform = transform;
	test = true;
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
	if (!doOnce) {
	sprite.setOrigin(0, 0);
	sprite.setPosition(m_Transform->m_WorldPosition.x, m_Transform->m_WorldPosition.y);

	sprite.setRotation(m_Transform->m_WorldRotation);

	sprite.setScale(m_Transform->m_WorldScale.x, m_Transform->m_WorldScale.y);

	doOnce = true;
	}

	//sprite.setRotation(0);
	//sprite.setPosition(0, 0);
	//sprite.move(m_Transform->m_WorldPosition.x, m_Transform->m_WorldPosition.y);

	//sprite.rotate(m_Transform->m_WorldRotation);

	//sprite.scale(m_Transform->m_WorldScale.x, m_Transform->m_WorldScale.y);

	//sprite.rotate(m_Transform->m_Rotation);
	//sprite.move(m_Transform->m_Position.x, m_Transform->m_Position.y);
//	sprite.scale(m_Transform->m_Scale.x, m_Transform->m_Scale.y);
	sf::RenderStates state;
	if (pSprite) {
		state.transform = pSprite->getTransform()*sprite.getTransform();
		renderWindow->draw(sprite, state.transform);

	}
	else
		renderWindow->draw(sprite);

}
void SpriteComponent::Update() {

	Show(m_Window);
}
