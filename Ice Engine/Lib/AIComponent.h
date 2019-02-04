#pragma once
#include "SFML/Graphics.hpp"
#include "BaseComponent.h"
#include "GameObject.h"

class AIComponent : public BaseComponent
{
public:
	explicit AIComponent();
	void makeGrid(sf::RenderWindow& window);
	~AIComponent();
	
private:
	int col;
	int row;
	GameObject* m_gameObject;
	std::vector< std::vector<sf::RectangleShape>> grid;

};
