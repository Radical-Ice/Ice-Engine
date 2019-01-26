#pragma once
#include "SFML/Graphics.hpp"
class SplashScreen
{
public:
	SplashScreen();
	sf::Texture texture;
	void Show(sf::RenderWindow& window);




	~SplashScreen();
};

