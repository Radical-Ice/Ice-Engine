#pragma once
#include "SFML/Graphics.hpp"

class AIComponent
{
public:
	void makeGrid(sf::RenderWindow& window);
	//void draw(sf::RectangleShape grid);
private:
	int col = 15;
	int row = 20;
	std::vector< std::vector<sf::RectangleShape>> grid;

};
