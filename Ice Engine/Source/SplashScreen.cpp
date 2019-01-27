#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {

	//"Assets/" for Pic
	if (!SSTexture.loadFromFile("Assets/SplashScreen.jpg")) {
		MessageBox(NULL,
			("failed to load SplashScreen texture"),
			(" -> SplashScreen.cpp"),
			NULL);
		return;
	}
	sprite.setTexture(SSTexture);
	sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
	sprite.setPosition(100, 25);
}

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}
