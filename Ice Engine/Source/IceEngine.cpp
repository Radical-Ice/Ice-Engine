#include "IceEngine.h"

void IceEngine::InitGraphics() {
	mainWindow.create(sf::VideoMode(1024, 768, 32), "Meow");

	if (state == SplashScreen)
	{
		splashScreen.Show(mainWindow);
	}
	std::cout << "~~[Graphic loaded]~~" << std::endl;
	mainWindow.display();
}

void IceEngine::LoadSound(std::vector<std::string> Files)
{
	audio.Load_Sounds_From_Files(Files);
	std::cout << "~~[Sounds Loaded]~~" << std::endl;
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
	std::cout << "~~[Textures Loaded]~~" << std::endl;
}

void IceEngine::SFML_Window()
{
	std::cout << "~~[Loaded Window]~~" << std::endl;
	while (mainWindow.isOpen())
	{
		elapsed = clock.restart();
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2 position = sf::Mouse::getPosition(mainWindow);
				std::cout << (position).x << " : " << position.y<< std::endl;
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				std::cout << "This" << std::endl;
			}
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
	audio.Play_Sound_From_Loaded_Files(0, 100, false);//WILL MOVE TO GAME COMP
	std::cout << "~~[Loading Window]~~" << std::endl;
	SFML_Window();
}

void IceEngine::DoChecks(LPCSTR szWindowClass) {
	MessageBox(NULL,
		_T("doing checks"),
		_T("-> Ice Engine.cpp"),
		NULL);
	checker->initChecks(szWindowClass, physicalRAMNeed, virtualRAMNeed, diskSpaceNeed);
	std::cout << "~~[Checking Done]~~" << std::endl;
	state = nextScreen;
}