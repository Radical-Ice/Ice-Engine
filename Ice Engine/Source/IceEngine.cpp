#include "IceEngine.h"

void IceEngine::InitGraphics() {
	mainWindow.create(sf::VideoMode(1024, 768, 32), "Meow");

	if (state == SplashScreen)
	{
		splashScreen.Show(mainWindow);
	}
	mainWindow.display();
}

void IceEngine::LoadSound()
{
	audio.LoadSound("Assets/PewPew.wav");
}

void IceEngine::LoadSTexture()
{
	if (!texture.loadFromFile("Assets/cat.png")) {
		MessageBox(NULL,
			_T("Failed to load CAT texture"),
			_T("-> Ice Engine.cpp"),
			NULL);
	}
	
	sprite.setTexture(texture);
	sprite.setPosition(100, 25);
}

void IceEngine::SFML_Window()
{
	while (mainWindow.isOpen())
	{
		elapsed = clock.restart();
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		sceneNode.Update();
		mainWindow.clear();
		mainWindow.draw(sprite);
		if (state == SplashScreen)
			splashScreen.Show(mainWindow);
		ai.makeGrid(mainWindow);
		mainWindow.display();
	}
}

void IceEngine::InitEngine() {
	LoadSTexture();
	LoadSound();
	audio.PlayAudio(100, false);
	SFML_Window();
}

void IceEngine::DoChecks(LPCSTR szWindowClass) {
	MessageBox(NULL,
		_T("doing checks"),
		_T("-> Ice Engine.cpp"),
		NULL);
	checker->initChecks(szWindowClass, physicalRAMNeed, virtualRAMNeed, diskSpaceNeed);
	state = nextScreen;
}