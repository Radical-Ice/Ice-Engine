#pragma once
#include "SFML/Graphics.hpp"
class BaseComponent
{
public:

	BaseComponent();
	virtual void Update(sf::RenderWindow & renderWindow);
	~BaseComponent();
};

