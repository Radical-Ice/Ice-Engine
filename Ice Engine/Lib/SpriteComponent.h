#pragma once
#include "BaseComponent.h"

class SpriteComponent : public BaseComponent
{
public:


	SpriteComponent(sf::RenderWindow & renderWindow, std::string filename);

	sf::Texture texture;
	sf::Sprite sprite;
	void Show(sf::RenderWindow& window);
	void Update(sf::RenderWindow & renderWindow);

	//~SpriteComponent();

};