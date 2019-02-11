#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
class SpriteComponent : public BaseComponent
{
public:


	SpriteComponent(sf::RenderWindow* renderWindow, std::string filename,TransformComponent* transform,SpriteComponent* parentSprite);
	SpriteComponent::SpriteComponent(sf::RenderWindow* renderWindow, std::string filename, TransformComponent* transform);
	sf::RenderStates state;
	TransformComponent* m_Transform;
	sf::RenderWindow* m_Window ;
	sf::Texture texture;
	sf::Sprite sprite;
	SpriteComponent* pSprite;
	void Show(sf::RenderWindow* window);
	void Update();
	bool doOnce = false;
	bool test = false;
	//~SpriteComponent();

};