#include"SpriteComponent.h"
#include <Windows.h>
SpriteComponent::SpriteComponent(sf::RenderWindow & renderWindow, std::string filename) {
	
	if (!texture.loadFromFile(filename)) {
		MessageBox(NULL,
			("failed to load image texture"),
			(" -> SpriteComponent.cpp"),
			NULL);
		return;
	}

}
void SpriteComponent::Show(sf::RenderWindow & renderWindow) {

	//"Assets/" for Pic

	sprite.setTexture(texture);

	//sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));

	//sprite.setPosition(0, 0);
	renderWindow.draw(sprite);
}
void SpriteComponent::Update(sf::RenderWindow & renderWindow) {

	Show(renderWindow);
}
