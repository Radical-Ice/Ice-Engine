#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {

	//"Assets/" for Pic

	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(800, 0, 1024, 768));
	//sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(0, 0);
	renderWindow.draw(sprite);
	//renderWindow.display();
	sf::Event event;
}

SplashScreen::SplashScreen()
{
	if (!texture.loadFromFile("Assets/SplashScreen.jpg")) {
		MessageBox(NULL,
			("failed to load SplashScreen texture"),
			(" -> SplashScreen.cpp"),
			NULL);
		return;
	}
}


SplashScreen::~SplashScreen()
{
}
