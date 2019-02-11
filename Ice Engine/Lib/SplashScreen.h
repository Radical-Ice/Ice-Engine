#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
class SplashScreen
{
public:
	SplashScreen();
	sf::Texture texture;
	void Show(sf::RenderWindow& window);
	sf::Sprite sprite;
	~SplashScreen();
};

