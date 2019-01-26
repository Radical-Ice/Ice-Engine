#include "../Lib/SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {


	if (!texture.loadFromFile("cat.png")) {

		return;
	}
	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 500, 500));
	//sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(100, 25);
	renderWindow.draw(sprite);
	renderWindow.display();
	sf::Event event;
}

SplashScreen::SplashScreen()
{

}


SplashScreen::~SplashScreen()
{
}
