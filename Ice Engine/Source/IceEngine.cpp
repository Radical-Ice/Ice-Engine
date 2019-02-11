#include "IceEngine.h"
#include "SpriteComponent.h"
#include "EventDispacher.h"
void IceEngine::InitGraphics() {
	std::cout << "~~[ Initializing Graphics Engine ]~~\r~" << std::endl;
	mainWindow.create(sf::VideoMode(1024, 768, 32), "Meow");

	if (state == SplashScreen)
	{
		splashScreen.Show(mainWindow);
	}
	std::cout << "~~[ Graphics Engine loaded ]~~" << std::endl;
	mainWindow.display();
}

void IceEngine::LoadSound(std::vector<std::string> Files)
{
	Audio.Load_Sounds_From_Files(Files);
	std::cout << "~~[ Sounds Loaded ]~~" << std::endl;
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
	std::cout << "~~[ Textures Loaded ]~~" << std::endl;
}

void IceEngine::SFML_Window()
{
	std::cout << "~~[ Game Window Loaded ]~~" << std::endl;
	while (mainWindow.isOpen())
	{
		elapsed = clock.restart();
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
			if (event.type == sf::Event::KeyPressed) {
				SpriteComponent* temp = static_cast<SpriteComponent*>((sceneNode.children.at(0))->components.at(1));
				SpriteComponent* temp2 = static_cast<SpriteComponent*>((sceneNode.children.at(0))->children.at(0)->components.at(1));
				switch (event.key.code) {
				case sf::Keyboard::Left:
					temp->sprite.move(-5, 0);
					EventDispacher::get()->SendEvent(MoveLeft);
					break;
				case sf::Keyboard::Right:
					temp->sprite.move(5, 0);
					EventDispacher::get()->SendEvent(MoveRight);
					break;
				case sf::Keyboard::Up:
					temp->sprite.move(0, -5);
					EventDispacher::get()->SendEvent(MoveUp);
					break;
				case sf::Keyboard::Down:
					temp->sprite.move(0, 5);
					EventDispacher::get()->SendEvent(MoveDown);
					break;
				case sf::Keyboard::A:
					temp->sprite.rotate(2);
					EventDispacher::get()->SendEvent(RotateLeft);
					break;
				case sf::Keyboard::D:
					temp->sprite.rotate(-2);
					EventDispacher::get()->SendEvent(RotateRight);
					break;
				case sf::Keyboard::G:
					temp2->sprite.rotate(2);
					break;
				case sf::Keyboard::H:
					temp2->sprite.rotate(-2);
					break;
				case sf::Keyboard::M:
					//Audio.Play_Sound_From_Loaded_Files(2, 100, true);
					break;
				}
				//sceneNode.children.at(0)->m_Transform->m_Rotation += 1;
				
				//temp->sprite.rotate(5);
				
			}
		}
		mainWindow.clear();
	
	//	sceneNode.children.at(0)->children.at(0)->m_Transform.m_Rotation += 1;
		sceneNode.Update(mainWindow);

		
		
		//mainWindow.draw(sprite);

		if (state == SplashScreen)
			splashScreen.Show(mainWindow);
		//if (state == SplashScreen)
		//	splashScreen.Show(mainWindow);

		ai.makeGrid(mainWindow);

		mainWindow.display();
	}
}

void IceEngine::InitEngine() {
	LoadSTexture();
	//LoadSound();
	MoveEvents test;
	RotateEvents test2;
	Audio.Play_Sound_From_Loaded_Files(1, 100, false);
	std::cout << "~~[ Initializing Game Window ]~~" << std::endl;
	SFML_Window();
}

void IceEngine::DoChecks(LPCSTR szWindowClass) {
	std::cout << "~~[ Initializing System Check ]~~" << std::endl << std::endl;
	MessageBox(NULL,
		_T("doing checks"),
		_T("-> Ice Engine.cpp"),
		NULL);
	checker->initChecks(szWindowClass, physicalRAMNeed, virtualRAMNeed, diskSpaceNeed);
	std::cout << std::endl << "~~[ Checking Done ]~~" << std::endl;
	state = nextScreen;
}
///<summary>Need index of the file you want to play; At what Volume; If its in loop;</summary>
///<param name="i">Index of file</param>
void IceEngine::Play_Sound(int i, float v, bool L)
{
	Audio.Play_Sound_From_Loaded_Files(i, v, L);
}

void IceEngine::LoadMusic(std::vector<std::string> Files, int Index, float Volume, bool IsLooping)
{
	Audio.LoadMusic(Files, Index, Volume, IsLooping);
	std::cout << "~~[ Music Loaded ]~~" << std::endl;
}
//
void IceEngine::PlayMusic()
{
	Audio.PlayMusic();
}
