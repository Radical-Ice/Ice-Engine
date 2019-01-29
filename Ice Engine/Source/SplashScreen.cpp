#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {

	//"Assets/" for Pic
	
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, renderWindow.getSize().x, renderWindow.getSize().y));
	//sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(0, 0);
	//sprite.setScale(0.5,0.5);
	renderWindow.draw(sprite);
	//renderWindow.display();
	
}

SplashScreen::SplashScreen()
{
	if (!texture.loadFromFile("Assets/snowflake.png")) {
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
