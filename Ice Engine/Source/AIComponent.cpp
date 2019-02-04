#include "AIComponent.h"

AIComponent::AIComponent() :
	col (30),
	row(40),
	m_gameObject(nullptr)
{

}

void AIComponent::makeGrid(sf::RenderWindow& window)
{
	col = window.getSize().y / 32;
	row = window.getSize().x / 32;

	grid.resize(row);
	for (int n = 0; n < row; n++) {
		grid[n].resize(col);
	}

	sf::Vector2f cellSize(32.0f, 32.0f);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			grid[i][j].setSize(cellSize);
			grid[i][j].setFillColor(sf::Color::Transparent);
			grid[i][j].setOutlineColor(sf::Color::Green);
			grid[i][j].setOutlineThickness(1.0f);

			grid[i][j].setPosition(i*cellSize.x + 5.0f, j*cellSize.y + 5.0f);

			window.draw(grid[i][j]);

		}
	}

}

AIComponent::~AIComponent()
{

}