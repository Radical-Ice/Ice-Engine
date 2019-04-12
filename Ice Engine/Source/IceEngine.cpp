#include "IceEngine.h"
#include "SpriteComponent.h"


#include "SFML-2.5.1/include/SFML/Graphics/Text.hpp"

void IceEngine::InitGraphics() {
	std::cout << "~~[ Initializing Graphics Engine ]~~\r~" << std::endl;
	mainWindow.create(sf::VideoMode(1024, 768, 32), "Meow");

	if (state == SplashScreen)
	{
		splashScreen.Show(mainWindow);
	}
	std::cout << "~~[ Graphics Engine loaded ]~~" << std::endl;
	mainWindow.display();
	mainWindow.setFramerateLimit(30);
}

void IceEngine::LoadSound(std::vector<std::string> Files)
{
	Audio.Load_Sounds_From_Files(Files);
	std::cout << "~~[ Sounds Loaded ]~~" << std::endl;
}


void IceEngine::SFML_Window()
{
	std::cout << "~~[ Game Window Loaded ]~~" << std::endl;
	while (mainWindow.isOpen())
	{
		elapsed = clock.restart();
		EventDispacher::get()->SendEvent(Update);
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
			if (event.type == sf::Event::KeyPressed) {

				switch (event.key.code) {
				case sf::Keyboard::Left:
					EventDispacher::get()->SendEvent(MoveLeft);
					break;
				case sf::Keyboard::Right:
					EventDispacher::get()->SendEvent(MoveRight);
					break;
				case sf::Keyboard::Up:
					EventDispacher::get()->SendEvent(MoveUp);
					break;
				case sf::Keyboard::Down:
					EventDispacher::get()->SendEvent(MoveDown);
					break;
				case sf::Keyboard::A:
					EventDispacher::get()->SendEvent(RotateLeft);
					break;
				case sf::Keyboard::D:
					EventDispacher::get()->SendEvent(RotateRight);
					break;
				}
			}if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::Left:
					EventDispacher::get()->SendEvent(LeftReleased);
					break;
				case sf::Keyboard::Right:
					EventDispacher::get()->SendEvent(RightReleased);
					break;
				case sf::Keyboard::Up:
					EventDispacher::get()->SendEvent(UpReleased);
					break;
				case sf::Keyboard::Down:
					EventDispacher::get()->SendEvent(DownReleased);
					break;
				}
			}
		}
		mainWindow.clear();
		
		
		
		//atext.setFont();
		//text.setString("HelloWorld");
		//text.setCharacterSize(20);
		//text.setStyle(sf::Text::Bold);
		
		//text.setPosition(50, 50);
		sceneNode.Update(mainWindow);
		physEngine.Update();
		//mainWindow.draw(sprite);
		for each(sf::Text* t in texts) {

			mainWindow.draw(*t);
		}
		//if (state == SplashScreen)
		//	splashScreen.Show(mainWindow);
		ai.makeGrid(mainWindow);

		mainWindow.display();
	}
}
void IceEngine::LoadScene(const char* fileName) {
	tinyxml2::XMLDocument doc;
	const char* name = "Assets/testXML.xml";
	doc.LoadFile(name);
}
void IceEngine::InitEngine() {
	//LoadSTexture();

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
void IceEngine::PlayMusic()
{
	Audio.PlayMusic();
}